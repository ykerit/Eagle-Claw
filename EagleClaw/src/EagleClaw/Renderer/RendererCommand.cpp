#include "Egcpch.h"

#include "EagleClaw/Renderer/RendererCommand.h"

namespace EagleClaw
{
    std::unique_ptr<RendererAPI> RendererCommand::rendererAPI_ = RendererAPI::Create();
}