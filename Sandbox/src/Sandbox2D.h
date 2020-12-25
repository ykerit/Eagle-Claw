#pragma once

#include "EagleClaw.h"

class Sandbox2D : EagleClaw::Layer
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
    std::shared_ptr<EagleClaw::VertexArray> 
};