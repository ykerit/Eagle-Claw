
#include "renderer/RendererCommand.h"
#include <memory>

namespace GRender
{
    std::unique_ptr<RendererAPI> RendererCommand::rendererAPI_ = RendererAPI::Create();
}