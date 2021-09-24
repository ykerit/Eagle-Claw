#include "Sandbox2D.h"

Sandbox2D::Sandbox2D()
    : Layer("Sandbox2D")
{
    vertexArray_ = GRender::VertexArray::Create();
    float postion[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};
    auto buffer = GRender::VertexBuffer::Create(postion, sizeof(postion));
    GRender::BufferLayout layout = {{GRender::BufferDataType::Float3, "a_Position"}};
    buffer->SetLayout(layout);
    vertexArray_->AddVertexBuffer(buffer);
    uint32_t indices[] = {0, 1, 2};
    auto indexBuffer = GRender::IndexBuffer::Create(indices, 3);
    vertexArray_->SetIndexBuffer(indexBuffer);
    shader_ = GRender::Shader::Create("C:\\Users\\13186\\source\\repos\\GRender\\Sandbox\\assets\\shaders\\triangle_frag.glsl",
        "C:\\Users\\13186\\source\\repos\\GRender\\Sandbox\\assets\\shaders\\triangle_frag.glsl");
}

void Sandbox2D::OnAttach() {}

void Sandbox2D::OnDetach() {}

void Sandbox2D::OnUpdate()
{
    GRender::RendererCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1.0f});
    GRender::RendererCommand::Clear();

    GRender::Renderer::BeginScence();
    GRender::Renderer::Submit(shader_, vertexArray_);
    GRender::Renderer::EndScence();
}

void Sandbox2D::OnImGuiRender() {}

void Sandbox2D::OnEvent(GRender::Event &event) {}
