#pragma once

#include "EagleClaw/Core/Base.h"
#include "EagleClaw/Core/window.h"
#include "EagleClaw/Core/LayerStack.h"

namespace EagleClaw
{
    class Application
    {
    public:
        Application(const std::string& name);

        virtual ~Application();

        void OnEvent();
        void PushLayer(Layer* layer);
        void PushLayerOverlay(Layer* layer);

        Window& GetWindow() { return *window_; }

        void Close() { running_ = false; }
        void Run();

        static Application& Get() { return *instance_; }

    private:
        std::unique_ptr<Window> window_;
        LayerStack stack_;
        bool running_ = true;
        static Application* instance_;
    };

    Application* CreateApplication();
}  // namespace EagleClaw