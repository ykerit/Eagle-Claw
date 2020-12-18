#pragma once

#include <string>
#include <unordered_map>

#include "common.h"
#include "glm/glm.hpp"

class Shader {
 public:
  Shader(const std::string& filepath);
  ~Shader();

  void Bind() const;
  void Unbind() const;

  void setUniform1i(const std::string& name, int v);
  void setUniform1f(const std::string& name, float v);
  void setUniform4f(const std::string& name, float v0, float v1, float v2,
                    float v3);
  void setUniform4m(const std::string& name, const glm::mat4& mat);

 private:
  GLuint CreateShader(const std::string& vertexShader,
                      const std::string& fragmentShader);
  GLuint CompileShader(const GLuint type, const std::string& source);
  std::pair<std::string, std::string> ParseShader(const std::string& filepath);

  GLint getUniformLocation(const std::string& name);

  GLuint rendererID_;
  std::unordered_map<std::string, GLint> locations_;
  mutable bool bind_;
};