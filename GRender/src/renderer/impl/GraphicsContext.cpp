#include "renderer/GraphicsContext.h"
#include "GL/GLContext.h"

#include <memory>

namespace GRender
{
    std::unique_ptr<GraphicsContext> GraphicsContext::Create(void* window)
    {
        return std::make_unique<GLContext>(static_cast<GLFWwindow*>(window));
    }
}  // namespace GRender