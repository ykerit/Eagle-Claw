#include "Preheader.h"
#include "EagleClaw/Renderer/GraphicsContext.h"

#include "Platform/OpenGL/GLContext.h"

namespace EagleClaw {
std::unique_ptr<GraphicsContext> GraphicsContext::Create(void* window) {
    return std::make_unique<GLContext>(static_cast<GLFWwindow*>(window));
}
}  // namespace EagleClaw