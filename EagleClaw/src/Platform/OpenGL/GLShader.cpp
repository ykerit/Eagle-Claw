#include "Platform/OpenGL/GLShader.h"

#include "Preheader.h"

namespace EagleClaw {

GLShader::GLShader(const std::string& filepath) {
}

GLShader::GLShader(const std::string& name, const std::string& vertSrc,
                   const std::string& fragmentSrc) {
}

GLShader::~GLShader() {
}

void GLShader::Bind() const {
}

void GLShader::Unbind() const {
}

const std::string GLShader::GetName() const {
}

void GLShader::SetInt(const std::string& name, int value) {
}

void GLShader::SetIntArray(const std::string& name, int* values, uint32_t count) {
}

void GLShader::SetFloat(const std::string& name, float value) {
}

void GLShader::SetFloat3(const std::string& name, const glm::vec3& value) {
}

void GLShader::SetFloat4(const std::string& name, const glm::vec4& value) {
}

void GLShader::SetMat4(const std::string& name, const glm::mat4& value) {
}

std::string GLShader::ReadFile(const std::string& file) {
    std::string result;
    std::ifstream in(file, std::ios::in | std::ios::binary);
    if (in) {
        in.seekg(0, std::ios::end);
        size_t size = in.tellg();
        if (size != -1) {
            result.resize(size);
            in.seekg(0, std::ios::beg);
            in.read(&result[0], size);
        } else {
            EGC_CORE_ERROR("Could not read from file: {}", file);
        }
    } else {
        EGC_CORE_ERROR("Could not open file: {}", file);
    }
    return result;
}

std::unordered_map<GLenum, std::string> GLShader::PreProcess(const std::string& source) {
    std::unordered_map<GLenum, std::string> shaderSources;
    const char* typeToken = "#type";
    return shaderSources;
}

void GLShader::Compile(const std::unordered_map<GLenum, std::string>& shaderSrc) {
    GLuint program;
    GLCALL(program = glCreateProgram());
    std::array<GLenum, 2> glShaderIDs;
    size_t glShaderIdx = 0;
    for (auto& kv : shaderSrc) {
        GLenum type               = kv.first;
        const std::string& source = kv.second;
        GLuint shader             = glCreateShader(type);
        const GLchar* sourceCstr  = source.c_str();
        GLCALL(glShaderSource(shader, 1, &sourceCstr, 0));
        GLCALL(glCompileShader(shader));

        GLint isCompiled = 0;
        GLCALL(glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled));
        if (isCompiled == GL_FALSE) {
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
    if (isLinked == GL_FALSE) {
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
    for (auto id : glShaderIDs) {
        GLCALL(glDetachShader(program, id));
        GLCALL(glDeleteShader(id));
    }
}

}  // namespace EagleClaw