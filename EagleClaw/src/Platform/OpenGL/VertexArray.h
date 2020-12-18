#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray {
 public:
  VertexArray();
  ~VertexArray();

  void addBuffer(const VertexBuffer& buffer, const VertexBufferLayout& layout);
  void Bind() const;
  void Unbind() const;

 private:
  GLuint renderID_;
};