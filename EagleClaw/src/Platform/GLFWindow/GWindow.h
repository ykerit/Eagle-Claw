#pragma once

#include "EagleClaw/Core/window.h"
#include "EagleClaw/Renderer/GraphicsContext.h"
#include <GLFW/glfw3.h>


namespace EagleClaw
{
    class GWindow : public Window
    {
    public:
        GWindow(const WindowProps& windowProps);
        ~GWindow();

        void OnUpdate() override;

        const size_t GetWidth() const override { return meta_.width; }

        const size_t GetHeight() const override { return meta_.height; }

        void SetEventCallback(const EventCallback& callback) override;

        void SetVSync(bool enabled) override;

        bool IsVSync() const override;

        void* GetNaiveWindow() const override { return window_; }

    private:
        void Init(const WindowProps& windowProps);
        void ShutDown();

        struct WindowMeta
        {
            size_t width;
            size_t height;
            std::string title;
            bool enableVSync;

            Window::EventCallback callback;
        };

        std::unique_ptr<GraphicsContext> context_;
        GLFWwindow* window_;
        WindowMeta meta_;
    };

}  // namespace EagleClaw