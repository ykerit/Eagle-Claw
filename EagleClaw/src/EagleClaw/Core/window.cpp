#include "Egcpch.h"

#include "EagleClaw/Core/window.h"

#include "Platform/GLFWindow/GWindow.h"

namespace EagleClaw
{
    std::unique_ptr<Window> Window::Create(const WindowProps& props = WindowProps())
    {
        return std::make_unique<GWindow>(props);
    }
}  // namespace EagleClaw