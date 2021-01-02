#include "Egcpch.h"

#include "EagleClaw/Renderer/RendererAPI.h"

#include "Platform/OpenGL/GLRendererAPI.h"

namespace EagleClaw
{
    std::unique_ptr<RendererAPI> RendererAPI::Create() { return std::make_unique<GLRendererAPI>(); }
}  // namespace EagleClaw