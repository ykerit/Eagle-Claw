#pragma once

#include "renderer/GraphicsContext.h"
#include <glad/glad.h>
#include <glfw/glfw3.h>

namespace GRender {
class GLContext : public GraphicsContext
{
public:
    GLContext(GLFWwindow *windowHandle);

    void Init() override;
    virtual void SwapBuffers() override;

private:
    GLFWwindow *windowHandle_;
};

} // namespace GRender