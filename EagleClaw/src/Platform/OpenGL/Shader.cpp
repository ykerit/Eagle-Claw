#include "Shader.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "glm/gtc/type_ptr.hpp"

Shader::Shader(const std::string& filepath) : rendererID_(0), bind_(false) {
  auto shaderSource = ParseShader(filepath);
  rendererID_ = CreateShader(shaderSource.first, shaderSource.second);
}

Shader::~Shader() { GLCALL(glDeleteProgram(rendererID_)); }

void Shader::Bind() const {
  if (bind_)
    return;
  GLCALL(glUseProgram(rendererID_));
  bind_ = true;
}

void Shader::Unbind() const {
  if (!bind_)
    return;
  GLCALL(glUseProgram(0));
  bind_ = false;
}

void Shader::setUniform1i(const std::string& name, int v) {
  if (!bind_)
    ASSERT(false);
  GLCALL(glUniform1i(getUniformLocation(name), v));
}

void Shader::setUniform1f(const std::string& name, float v) {
  if (!bind_)
    ASSERT(false);
  GLCALL(glUniform1f(getUniformLocation(name), v));
}

void Shader::setUniform4f(const std::string& name, float v0, float v1, float v2,
                          float v3) {
  if (!bind_)
    ASSERT(false);
  GLCALL(glUniform4f(getUniformLocation(name), v0, v1, v2, v3));
}

void Shader::setUniform4m(const std::string& name, const glm::mat4& mat) {
  if (!bind_)
    ASSERT(false);
  GLCALL(glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE,
                            glm::value_ptr(mat)));
}

GLuint Shader::CreateShader(const std::string& vertexShader,
                            const std::string& fragmentShader) {
  GLuint program = glCreateProgram();
  GLuint vertS = CompileShader(GL_VERTEX_SHADER, vertexShader);
  GLuint fragS = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

  glAttachShader(program, vertS);
  glAttachShader(program, fragS);
  glLinkProgram(program);
  glValidateProgram(program);

  glDetachShader(program, vertS);
  glDetachShader(program, fragS);
  return program;
}

GLuint Shader::CompileShader(const GLuint type, const std::string& source) {
  GLuint shader = glCreateShader(type);
  const char* str = source.c_str();
  glShaderSource(shader, 1, &str, nullptr);
  glCompileShader(shader);
  GLint result;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
  if (result == GL_FALSE) {
    GLint length;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
    char* msg = (char*)malloc(length * sizeof(char));
    glGetShaderInfoLog(shader, length, &length, msg);
    std::cout << "Failed to compile shader!" << std::endl;
    std::cout << msg << std::endl;
    free(msg);
    glDeleteShader(shader);
    return 0;
  }
  return shader;
}

std::pair<std::string, std::string> Shader::ParseShader(
    const std::string& filepath) {
  std::ifstream stream(filepath);
  enum class ShaderType { NONE = -1, VECTEX = 0, FRAGMENT = 1 };
  std::string line;
  ShaderType type = ShaderType::NONE;
  std::stringstream source[2];
  std::pair<std::string, std::string> pair;
  while (std::getline(stream, line)) {
    if (line.find("#shader") != std::string::npos) {
      if (line.find("vertex") != std::string::npos)
        type = ShaderType::VECTEX;
      else if (line.find("fragment") != std::string::npos)
        type = ShaderType::FRAGMENT;
    } else {
      source[(int)type] << line << '\n';
    }
  }
  return std::make_pair(source[(int)ShaderType::VECTEX].str(),
                        source[(int)ShaderType::FRAGMENT].str());
}

GLint Shader::getUniformLocation(const std::string& name) {
  if (locations_.find(name) != locations_.end())
    return locations_[name];
  GLint location;
  GLCALL(location = glGetUniformLocation(rendererID_, name.c_str()));
  if (location == -1)
    std::cout << "[OPENGL ERROR] (location is -1)" << std::endl;
  locations_[name] = location;
  return location;
}
