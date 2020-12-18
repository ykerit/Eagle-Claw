#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const void* data, const size_t size) {
  GLCALL(glGenBuffers(1, &renderID_));
  GLCALL(glBindBuffer(GL_ARRAY_BUFFER, renderID_));
  GLCALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer() { GLCALL(glDeleteBuffers(1, &renderID_)); }

void VertexBuffer::Bind() const {
  GLCALL(glBindBuffer(GL_ARRAY_BUFFER, renderID_));
}

void VertexBuffer::Unbind() const { GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0)); }
