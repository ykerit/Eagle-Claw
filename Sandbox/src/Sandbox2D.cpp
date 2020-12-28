#include "Sandbox2D.h"

Sandbox2D::Sandbox2D() : Layer("Sandbox2D")  {

}

void Sandbox2D::OnAttach()
{
    float postion[] = {

    };
    auto buffer = EagleClaw::VertexBuffer::Create(postion, sizeof(postion));
}

void Sandbox2D::OnDetach() { }

void Sandbox2D::OnUpdate() { }

void Sandbox2D::OnImGuiRender() { }

void Sandbox2D::OnEvent(EagleClaw::Event& event) { }
