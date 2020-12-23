#include "Egcpch.h"

#include "Platform/GLFWindow/GWindow.h"

#include "EagleClaw/Renderer/GraphicsContext.h"

namespace EagleClaw
{
    static size_t windowCount = 0;

    GWindow::GWindow(const WindowProps& windowProps) : enableVSync_(false) { Init(windowProps); }

    GWindow::~GWindow() { ShutDown(); }

    void GWindow::OnUpdate() { 
        glfwPollEvents();
        context_->SwapBuffers();
    }

    void GWindow::SetEventCallback(EventCallback& callback) { }

    void GWindow::SetVSync(bool enabled) { 
        enableVSync_ = enabled; 
        if (enableVSync_)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);
    }

    bool GWindow::IsVSync() const { return enableVSync_; }

    void GWindow::Init(const WindowProps& windowProps)
    {
        width_  = windowProps.width;
        height_ = windowProps.heigth;
        title_  = windowProps.title;
        if (windowCount == 0) {
            EGC_ASSERT_MSG(glfwInit(), "GLFW Initialize Error");    
        }
        window_ = glfwCreateWindow(width_, height_, title_.c_str(), nullptr, nullptr);
        ++windowCount;
        EGC_ASSERT_MSG(window_, "GLFW Create Window Error");
        context_ = GraphicsContext::Create(window_);
        context_->Init();
        // now loss
        glfwSetWindowUserPointer(window_, nullptr);
        SetVSync(true);

        glfwSetWindowCloseCallback(window_, [](GLFWwindow* window) {

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