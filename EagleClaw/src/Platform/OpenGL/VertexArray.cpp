#include "VertexArray.h"

VertexArray::VertexArray() { GLCALL(glGenVertexArrays(1, &renderID_)); }

VertexArray::~VertexArray() { GLCALL(glDeleteVertexArrays(1, &renderID_)); }

void VertexArray::addBuffer(const VertexBuffer& buffer,
                            const VertexBufferLayout& layout) {
  Bind();
  buffer.Bind();
  const auto& elements = layout.getElements();
  size_t offset = 0;
  for (size_t i = 0; i < elements.size(); ++i) {
    glEnableVertexAttribArray(i);
    glVertexAttribPointer(i, elements[i].count, elements[i].type,
                          elements[i].normalized, layout.getStride(),
                          (void*)offset);
    offset += elements[i].count * VertexElement::getTypeSize(elements[i].type);
  }
}

void VertexArray::Bind() const { GLCALL(glBindVertexArray(renderID_)); }

void VertexArray::Unbind() const { GLCALL(glBindVertexArray(0)); }
