#include "Preheader.h"
#include "Platform/GLFWindow/GWindow.h"

#include <GLFW/glfw3.h>
#include "EagleClaw/Renderer/GraphicsContext.h"

namespace EagleClaw {

GWindow::GWindow(const WindowProps& windowProps) : enableVSync_(false) {
    Init(windowProps);
}

GWindow::~GWindow() {
    ShutDown();
}

void GWindow::OnUpdate() {
}

void GWindow::SetEventCallback(EventCallback& callback) {
}

void GWindow::SetVSync(bool enabled) {
}

bool GWindow::IsVSync() const {
}

void GWindow::Init(const WindowProps& windowProps) {
    width_  = windowProps.width;
    height_ = windowProps.heigth;
    title_  = windowProps.title;
    EGC_ASSERT_MSG(glfwInit(), "GLFW Initialize Error");
    window_ = glfwCreateWindow(width_, height_, title_.c_str(), nullptr, nullptr);
    EGC_ASSERT_MSG(window_, "GLFW Create Window Error");
    auto windowPtr = GraphicsContext::Create(window_);
}

void GWindow::ShutDown() {
}

}  // namespace EagleClaw