#include "GL/GLBuffer.h"

namespace GRender {
GLVertexBuffer::GLVertexBuffer(size_t size)
{
    GLCALL(glGenBuffers(1, &rendererID_));
    GLCALL(glBindBuffer(GL_ARRAY_BUFFER, rendererID_));
    GLCALL(glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW));
}
GLVertexBuffer::GLVertexBuffer(const float *vertices, const size_t size)
{
    GLCALL(glGenBuffers(1, &rendererID_));
    GLCALL(glBindBuffer(GL_ARRAY_BUFFER, rendererID_));
    GLCALL(glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_DYNAMIC_DRAW));
}

GLVertexBuffer::~GLVertexBuffer()
{
    GLCALL(glDeleteBuffers(1, &rendererID_));
}

void GLVertexBuffer::Bind() const
{
    GLCALL(glBindBuffer(GL_ARRAY_BUFFER, rendererID_));
}

void GLVertexBuffer::Unbind() const
{
    GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

void GLVertexBuffer::SetData(const void *data, size_t size)
{
    GLCALL(glBindBuffer(GL_ARRAY_BUFFER, rendererID_));
    GLCALL(glBufferSubData(GL_ARRAY_BUFFER, 0, size, data));
}

GLIndexBuffer::GLIndexBuffer(const uint32_t *indices, size_t count)
    : count_(count)
{
    GLCALL(glCreateBuffers(1, &rendererID_));
    GLCALL(glBindBuffer(GL_ARRAY_BUFFER, rendererID_));
    GLCALL(glBufferData(GL_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW));
}

GLIndexBuffer::~GLIndexBuffer()
{
    GLCALL(glDeleteBuffers(1, &rendererID_));
}

void GLIndexBuffer::Bind() const
{
    GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID_));
}

void GLIndexBuffer::Unbind() const
{
    GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

} // namespace GRender
