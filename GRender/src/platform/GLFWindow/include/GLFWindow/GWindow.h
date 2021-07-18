#pragma once

#include <glfw/glfw3.h>

#include "core/window.h"
#include "renderer/GraphicsContext.h"

namespace GRender
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

}  // namespace GRender