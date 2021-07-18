
#include "renderer/Shader.h"
#include "core/Base.h"

#include "GL/GLShader.h"

namespace GRender
{
    std::shared_ptr<Shader> Shader::Create(const std::string& filepath) { return std::make_shared<GLShader>(filepath); }

    std::shared_ptr<Shader> Shader::Create(const std::string& name, const std::string& vertexSrc,
                                           const std::string& fragmentSrc)
    {
        return std::make_shared<GLShader>(name, vertexSrc, fragmentSrc);
    }

    std::shared_ptr<GRender::Shader> Shader::Create(const std::string& vertexFile, const std::string& fragFile)
    {
        return std::make_shared<GLShader>(vertexFile, fragFile);
    }

    void ShaderManager::Add(const std::string& name, const std::shared_ptr<Shader>& shader)
    {
        EGC_ASSERT_MSG(!IsExists(name), "Shader already Exists");
        shaders_[name] = shader;
    }
    void ShaderManager::Add(const std::shared_ptr<Shader>& shader)
    {
        const auto& name = shader->GetName();
        Add(name, shader);
    }
    std::shared_ptr<Shader> ShaderManager::Load(const std::string& filepath)
    {
        auto shader = Shader::Create(filepath);
        Add(shader);
        return shader;
    }
    std::shared_ptr<Shader> ShaderManager::Load(const std::string& name, const std::string& filepath)
    {
        auto shader = Shader::Create(filepath);
        Add(name, shader);
        return shader;
    }
    std::shared_ptr<Shader> ShaderManager::Get(const std::string& name)
    {
        EGC_ASSERT_MSG(IsExists(name), "Shader not found");
        return shaders_[name];
    }
    bool ShaderManager::IsExists(const std::string& name) const { return shaders_.find(name) != shaders_.end(); }

}  // namespace GRender