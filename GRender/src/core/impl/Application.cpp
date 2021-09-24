#include "core/Application.h"
#include "renderer/Renderer.h"

namespace GRender {
Application *Application::instance_ = nullptr;

Application::Application(const std::string &name)
{
    EGC_ASSERT_MSG(!instance_, "Application already exists");
    instance_ = this;
    window_ = Window::Create(WindowProps(name));
    window_->SetEventCallback(BIND_EVENT_FUNC(Application::OnEvent));
    Renderer::Init();
}

Application::~Application()
{
    Renderer::ShutDown();
}

void Application::OnEvent(Event &event)
{
    EventDispatcher dispatcher(event);
    dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(Application::OnWindowClose));
    dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FUNC(Application::OnWindowResize));

    for (auto it = stack_.rbegin(); it != stack_.rend(); ++it)
    {
        if (event.handled)
            break;
        (*it)->OnEvent(event);
    }
}

void Application::PushLayer(Layer *layer) {}

void Application::PushLayerOverlay(Layer *layer)
{
    stack_.PushLayerOverlay(layer);
    layer->OnAttach();
}

void Application::Run()
{
    while (running_)
    {
        // User Interface frame update
        {
            for (auto &layer : stack_)
            {
                layer->OnUpdate();
            }
        }
        // ImGui update
        window_->OnUpdate();
    }
}

bool Application::OnWindowClose(WindowCloseEvent &e)
{
    running_ = false;
    return true;
}

bool Application::OnWindowResize(WindowResizeEvent &e)
{
    return false;
}

} // namespace GRender