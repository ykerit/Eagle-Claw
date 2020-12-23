#include "Egcpch.h"

#include "EagleClaw/Core/Application.h"
#include "EagleClaw/Renderer/Renderer.h"

namespace EagleClaw
{
    Application* Application::instance_ = nullptr;

    Application::Application(const std::string& name) { 
        EGC_ASSERT_MSG(!instance_, "Application already exists");
        instance_ = this;
        window_    = Window::Create(WindowProps(name));

        Renderer::Init();
    }

    Application::~Application() { Renderer::ShutDown();
    }

    void Application::OnEvent() { }

    void Application::PushLayer(Layer* layer) {
    }

    void Application::PushLayerOverlay(Layer* layer) { 
        stack_.PushLayerOverlay(layer);
        layer->OnAttach();
    }

    void Application::Run()
    {
        while (running_) {
            {
                for (auto& layer : stack_) {
                    layer->OnUpdate();
                }
            }
            // ImGui
            window_->OnUpdate();
        }
    }

}  // namespace EagleClaw