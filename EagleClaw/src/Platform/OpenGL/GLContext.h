#pragma once

#include "EagleClaw/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace EagleClaw
{
    class GLContext : public GraphicsContext
    {
    public:
        GLContext(GLFWwindow* windowHandle);

        void Init() override;
        virtual void SwapBuffers() override;

    private:
        GLFWwindow* windowHandle_;
    };

}  // namespace EagleClaw