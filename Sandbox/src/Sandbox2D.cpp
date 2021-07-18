#include "Sandbox2D.h"

Sandbox2D::Sandbox2D() : Layer("Sandbox2D")
{
    vertexArray_ = EagleClaw::VertexArray::Create();
    float postion[] = { -0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f };
    auto buffer = EagleClaw::VertexBuffer::Create(postion, sizeof(postion));
    EagleClaw::BufferLayout layout = { { EagleClaw::BufferDataType::Float3, "a_Position" } };
    buffer->SetLayout(layout);
    vertexArray_->AddVertexBuffer(buffer);
    uint32_t indices[] = { 0, 1, 2 };
    auto indexBuffer = EagleClaw::IndexBuffer::Create(indices, 3);
    vertexArray_->SetIndexBuffer(indexBuffer);
    shader_ = EagleClaw::Shader::Create("assets/shaders/triangle_vert.glsl", "assets/shaders/triangle_frag.glsl");
}

void Sandbox2D::OnAttach() { }

void Sandbox2D::OnDetach() { }

void Sandbox2D::OnUpdate()
{
    EagleClaw::RendererCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
    EagleClaw::RendererCommand::Clear();

    EagleClaw::Renderer::BeginScence();
    EagleClaw::Renderer::Submit(shader_, vertexArray_);
    EagleClaw::Renderer::EndScence();
}

void Sandbox2D::OnImGuiRender() { }

void Sandbox2D::OnEvent(EagleClaw::Event& event) { }
