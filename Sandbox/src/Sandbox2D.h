#pragma once

#include "core/Application.h"
#include "core/Event.h"
#include "renderer/Shader.h"
#include "renderer/VertexArray.h"
#include "renderer/Texture.h"
#include "renderer/RendererCommand.h"
#include "renderer/Renderer.h"

class Sandbox2D : public GRender::Layer
{
public:
    Sandbox2D();
    ~Sandbox2D() = default;

    void OnAttach() override;
    void OnDetach() override;

    void OnUpdate() override;
    void OnImGuiRender() override;
    void OnEvent(GRender::Event &event) override;

private:
    std::shared_ptr<GRender::VertexArray> vertexArray_;
    std::shared_ptr<GRender::Shader> shader_;
    std::shared_ptr<GRender::Texture> texture_;
    glm::vec4 squareColor = {0.2f, 0.3f, 0.8f, 1.0f};
};