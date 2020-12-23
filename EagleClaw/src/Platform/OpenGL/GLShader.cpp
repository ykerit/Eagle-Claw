#include "Egcpch.h"

#include "Platform/OpenGL/GLShader.h"

#include <glad/glad.h>

namespace EagleClaw
{
    GLShader::GLShader(const std::string& filepath)
    {
        std::string source = ReadFile(filepath);
        auto shader        = PreProcess(source);
        Compile(shader);

        auto lastSlash = filepath.find_last_of("/\\");
        lastSlash      = lastSlash == std::string::npos ? 0 : lastSlash + 1;
        auto lastDot   = filepath.rfind(".");
        auto count     = lastDot == std::string::npos ? filepath.size() - lastSlash : lastDot - lastSlash;
        name_          = filepath.substr(lastSlash, count);
    }

    GLShader::GLShader(const std::string& name, const std::string& vertSrc, const std::string& fragmentSrc) : name_(name)
    {
        std::unordered_map<GLenum, std::string> sources;
        sources[GL_VERTEX_SHADER]   = vertSrc;
        sources[GL_FRAGMENT_SHADER] = fragmentSrc;
        Compile(sources);
    }

    GLShader::~GLShader() { GLCALL(glDeleteShader(rendererID_)); }

    void GLShader::Bind() const { GLCALL(glUseProgram(rendererID_)); }

    void GLShader::Unbind() const { GLCALL(glUseProgram(0)); }

    void GLShader::SetInt(const std::string& name, int value) { }

    void GLShader::SetIntArray(const std::string& name, int* values, uint32_t count) { }

    void GLShader::SetFloat(const std::string& name, float value) { }

    void GLShader::SetFloat3(const std::string& name, const glm::vec3& value) { }

    void GLShader::SetFloat4(const std::string& name, const glm::vec4& value) { }

    void GLShader::SetMat4(const std::string& name, const glm::mat4& value) { }

    std::string GLShader::ReadFile(const std::string& file)
    {
        std::string result;
        std::ifstream in(file, std::ios::in | std::ios::binary);
        if (in)
        {
            in.seekg(0, std::ios::end);
            size_t size = in.tellg();
            if (size != -1)
            {
                result.resize(size);
                in.seekg(0, std::ios::beg);
                in.read(&result[0], size);
            }
            else
            {
                EGC_CORE_ERROR("Could not read from file: {}", file);
            }
        }
        else
        {
            EGC_CORE_ERROR("Could not open file: {}", file);
        }
        return result;
    }

    static GLenum GetTypeFromStr(const std::string& type)
    {
        if (type == "vertex")
        {
            return GL_VERTEX_SHADER;
        }
        else if (type == "fragment")
        {
            return GL_FRAGMENT_SHADER;
        }
        EGC_ASSERT_MSG(false, "Shader Type Error");
    }

    std::unordered_map<GLenum, std::string> GLShader::PreProcess(const std::string& source)
    {
        std::unordered_map<GLenum, std::string> shaderSources;
        const char* typeToken = "#type";
        size_t typeTokenLen   = strlen(typeToken);
        size_t pos            = source.find(typeToken, 0);
        while (pos != std::string::npos)
        {
            size_t eof = source.find_first_of("\r\n", pos);
            EGC_ASSERT_MSG(eof != std::string::npos, "Synatx error");
            size_t begin     = pos + typeTokenLen + 1;
            std::string type = source.substr(begin, eof - begin);
            EGC_ASSERT(GetTypeFromStr(type));
            size_t nextLinePos = source.find_last_not_of("\r\n", eof);
            EGC_ASSERT_MSG(nextLinePos != std::string::npos, "Synatx error");
            pos = source.find(typeToken, nextLinePos);
            shaderSources[GetTypeFromStr(type)] =
                (pos == std::string::npos) ? source.substr(nextLinePos) : source.substr(nextLinePos, pos - nextLinePos);
        }
        return shaderSources;
    }

    void GLShader::Compile(const std::unordered_map<GLenum, std::string>& shaderSrc)
    {
        GLuint program;
        GLCALL(program = glCreateProgram());
        std::array<GLenum, 2> glShaderIDs;
        size_t glShaderIdx = 0;
        for (auto& kv : shaderSrc)
        {
            GLenum type               = kv.first;
            const std::string& source = kv.second;
            GLuint shader             = glCreateShader(type);
            const GLchar* sourceCstr  = source.c_str();
            GLCALL(glShaderSource(shader, 1, &sourceCstr, 0));
            GLCALL(glCompileShader(shader));

            GLint isCompiled = 0;
            GLCALL(glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled));
            if (isCompiled == GL_FALSE)
            {
                GLint length;
                GLCALL(glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length));
                char* msg = (char*)malloc(length * sizeof(char));
                GLCALL(glGetShaderInfoLog(shader, length, &length, msg));
                GLCALL(glDeleteShader(shader));
                EGC_CORE_ERROR("{}", msg);
                EGC_ASSERT_MSG(false, "Failed to compile shader");
                free(msg);
                break;
            }
            GLCALL(glAttachShader(program, shader));
            glShaderIDs[glShaderIdx++] = shader;
        }
        rendererID_ = program;
        GLCALL(glLinkProgram(rendererID_));

        GLint isLinked = 0;
        GLCALL(glGetProgramiv(rendererID_, GL_LINK_STATUS, &isLinked));
        if (isLinked == GL_FALSE)
        {
            GLint maxLength = 0;
            GLCALL(glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength));

            std::vector<GLchar> infoLog(maxLength);
            GLCALL(glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]));

            GLCALL(glDeleteProgram(program));

            for (auto id : glShaderIDs)
                GLCALL(glDeleteShader(id));

            EGC_CORE_ERROR("{0}", infoLog.data());
            EGC_ASSERT_MSG(false, "Shader link failure!");
            return;
        }
        for (auto id : glShaderIDs)
        {
            GLCALL(glDetachShader(program, id));
            GLCALL(glDeleteShader(id));
        }
    }

}  // namespace EagleClaw