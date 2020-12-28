#include "Egcpch.h"

#include "Platform/GLFWindow/GWindow.h"

#include "EagleClaw/Renderer/GraphicsContext.h"
#include "EagleClaw/Core/ApplicationEvent.h"

namespace EagleClaw
{
    static size_t windowCount = 0;

    GWindow::GWindow(const WindowProps& windowProps) { Init(windowProps); }

    GWindow::~GWindow() { ShutDown(); }

    void GWindow::OnUpdate() { 
        glfwPollEvents();
        context_->SwapBuffers();
    }

    void GWindow::SetEventCallback(const EventCallback& callback) { 
        meta_.callback = callback;
    }

    void GWindow::SetVSync(bool enabled) { 
        meta_.enableVSync = enabled;
        if (meta_.enableVSync)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);
    }

    bool GWindow::IsVSync() const { return meta_.enableVSync; }

    void GWindow::Init(const WindowProps& windowProps)
    {
        meta_.width  = windowProps.width;
        meta_.height = windowProps.heigth;
        meta_.title  = windowProps.title;
        if (windowCount == 0) {
            EGC_ASSERT_MSG(glfwInit(), "GLFW Initialize Error");    
        }
        window_ = glfwCreateWindow(meta_.width, meta_.height, meta_.title.c_str(), nullptr, nullptr);
        ++windowCount;
        EGC_ASSERT_MSG(window_, "GLFW Create Window Error");
        context_ = GraphicsContext::Create(window_);
        context_->Init();
        // now loss
        glfwSetWindowUserPointer(window_, &meta_);
        SetVSync(true);

        glfwSetWindowCloseCallback(window_, [](GLFWwindow* window) {
            auto& meta = *static_cast<WindowMeta*>(glfwGetWindowUserPointer(window));
            WindowCloseEvent event;
            meta.callback(event);
        });
    }

    void GWindow::ShutDown() { 
        glfwDestroyWindow(window_);
        --windowCount;
        if (windowCount == 0) {
            glfwTerminate();
        }
    }

}  // namespace EagleClaw