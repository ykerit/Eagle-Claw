#pragma once

#include "EagleClaw/Renderer/Shader.h"

typedef unsigned int GLenum;

namespace EagleClaw {

class GLShader : public Shader {
public:
    GLShader(const std::string& filepath);
    GLShader(const std::string& name, const std::string& vertSrc, const std::string& fragmentSrc);
    ~GLShader();
    void Bind() const override;
    void Unbind() const override;

    const std::string GetName() const override {
        return name_;
    }

    void SetInt(const std::string& name, int value) override;

    void SetIntArray(const std::string& name, int* values, uint32_t count) override;

    void SetFloat(const std::string& name, float value) override;

    void SetFloat3(const std::string& name, const glm::vec3& value) override;

    void SetFloat4(const std::string& name, const glm::vec4& value) override;

    void SetMat4(const std::string& name, const glm::mat4& value) override;

private:
    std::string ReadFile(const std::string& file);
    std::unordered_map<GLenum, std::string> PreProcess(const std::string& source);
    void Compile(const std::unordered_map<GLenum, std::string>& shaderSrc);

    uint32_t rendererID_;
    std::string name_;
};

}  // namespace EagleClaw