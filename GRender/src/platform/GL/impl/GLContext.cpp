
#include "GL/GLContext.h"

namespace GRender {
GLContext::GLContext(GLFWwindow *windowHandle)
    : windowHandle_(windowHandle)
{
    EGC_ASSERT_MSG(windowHandle_, "GLFW windowHandle is nullptr");
}

void GLContext::Init()
{
    glfwMakeContextCurrent(windowHandle_);
    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    EGC_ASSERT_MSG(status, "Glad Initialize Error");

    GD_CORE_INFO("OpenGL Info:");
    GD_CORE_INFO(" Vendor: {}", glGetString(GL_VENDOR));
    GD_CORE_INFO(" Renderer: {}", glGetString(GL_RENDERER));
    GD_CORE_INFO(" Version: {}", glGetString(GL_VERSION));
}

void GLContext::SwapBuffers()
{
    GLCALL(glfwSwapBuffers(windowHandle_));
}

} // namespace GRender