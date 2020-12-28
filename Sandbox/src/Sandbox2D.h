#pragma once

#include "EagleClaw.h"

class Sandbox2D : public EagleClaw::Layer
{
public:
    Sandbox2D();
    ~Sandbox2D() = default;

    void OnAttach() override;
    void OnDetach() override;

    void OnUpdate() override;
    void OnImGuiRender() override;
    void OnEvent(EagleClaw::Event& event) override;

private:
    std::shared_ptr<EagleClaw::VertexArray> vertexArray_;
    std::shared_ptr<EagleClaw::Shader> shader_;
    std::shared_ptr<EagleClaw::Texture> texture_;
    glm::vec4 squareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};