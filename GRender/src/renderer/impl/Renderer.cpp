#include "renderer/Renderer.h"

#include "renderer/RendererCommand.h"

namespace GRender
{
    void Renderer::Init() { RendererCommand::Init(); }

    void Renderer::ShutDown() { }

    void Renderer::OnWindowResize(size_t width, size_t height) { RendererCommand::SetViewport(0, 0, width, height); }

    void Renderer::Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray,
                          const glm::mat4& transform)
    {
        shader->Bind();
        shader->SetMat4("u_ViewProjection", glm::mat4(1.0f));
        shader->SetMat4("u_Transform", transform);
        vertexArray->Bind();
        RendererCommand::DrawIndexed(vertexArray);
    }

    void Renderer::BeginScence() { }

    void Renderer::EndScence() { }

}  // namespace GRender