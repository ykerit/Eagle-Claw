#include "Sandbox2D.h"

Sandbox2D::Sandbox2D() : Layer("Sandbox2D")
{
    vertexArray_                   = EagleClaw::VertexArray::Create();
    float postion[]                = { 0.0f, 0.1f, 1.0f, -1.0f, -1.0f, -1.0f };
    auto buffer                    = EagleClaw::VertexBuffer::Create(postion, sizeof(postion));
    EagleClaw::BufferLayout layout = { { EagleClaw::BufferDataType::Float2, "a_Position" } };
    buffer->SetLayout(layout);
    vertexArray_->AddVertexBuffer(buffer);
    uint32_t indices[] = { 0, 1, 2 };
    auto indexBuffer   = EagleClaw::IndexBuffer::Create(indices, 3);
    vertexArray_->SetIndexBuffer(indexBuffer);

    std::string vertexSrc = R"(
        #version 330 core
        layout(location = 0) in vec2 a_Position;
        out vec3 v_Position;

        void main()
        {
            v_Position = vec3(a_Position, 1.0);
        }
    )";

    std::string fragmentSrc = R"(
        #version 330 core
        out vec4 color;
        in vec3 v_Position;

        void main()
        {
            color = vec4(0.2, 0.3, 0.9, 1.0);
        }
    )";

    shader_ = EagleClaw::Shader::Create("triangle", vertexSrc, fragmentSrc);
}

void Sandbox2D::OnAttach() { }

void Sandbox2D::OnDetach() { }

void Sandbox2D::OnUpdate() { 
    EagleClaw::RendererCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
    EagleClaw::RendererCommand::Clear();

    EagleClaw::Renderer::BeginScence();
    EagleClaw::Renderer::Submit(shader_, vertexArray_);
    EagleClaw::Renderer::EndScence();
}

void Sandbox2D::OnImGuiRender() { }

void Sandbox2D::OnEvent(EagleClaw::Event& event) { }
