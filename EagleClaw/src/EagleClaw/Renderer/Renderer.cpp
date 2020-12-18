#include "Renderer.h"
#include "common.h"

void Renderer::Clear() const
{
    GLCALL(glClearColor(0.0, 0.0, 0.0, 0.0));
    GLCALL(glClear(GL_COLOR_BUFFER_BIT));
    GLCALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader)
{
    shader.Bind();
    va.Bind();
    ib.Bind();
    GLCALL(glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr));
}
