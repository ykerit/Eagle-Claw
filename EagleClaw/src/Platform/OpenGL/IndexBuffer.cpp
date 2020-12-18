#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const GLuint* data, const size_t count) : count_(count)
{
    glGenBuffers(1, &renderID_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderID_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
    GLCALL(glDeleteBuffers(1, &renderID_));
}

void IndexBuffer::Bind() const
{
    GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderID_));
}

void IndexBuffer::Unbind() const
{
    GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

const size_t IndexBuffer::getCount() const
{
    return count_;
}
