#include "Egcpch.h"

#include "Platform/OpenGL/GLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace EagleClaw
{
    GLContext::GLContext(GLFWwindow* windowHandle) : windowHandle_(windowHandle)
    {
        EGC_ASSERT_MSG(windowHandle_, "GLFW windowHandle is nullptr");
    }

    void GLContext::Init()
    {
        glfwMakeContextCurrent(windowHandle_);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        EGC_ASSERT_MSG(status, "Glad Initialize Error");

        EGC_CORE_INFO("OpenGL Info:");
        EGC_CORE_INFO(" Vendor: {}", glGetString(GL_VENDOR));
        EGC_CORE_INFO(" Renderer: {}", glGetString(GL_RENDERER));
        EGC_CORE_INFO(" Version: {}", glGetString(GL_VERSION));
    }

    void GLContext::SwapBuffers() { GLCALL(glfwSwapBuffers(windowHandle_)); }

}  // namespace EagleClaw