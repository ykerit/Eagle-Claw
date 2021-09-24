#include "core/window.h"
#include "GLFWindow/GWindow.h"

namespace GRender {
std::unique_ptr<Window> Window::Create(const WindowProps &props = WindowProps())
{
    return std::make_unique<GWindow>(props);
}
} // namespace GRender