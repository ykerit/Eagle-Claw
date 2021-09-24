
#include "renderer/RendererAPI.h"

#include "GL/GLRendererAPI.h"
#include <memory>

namespace GRender {
std::unique_ptr<RendererAPI> RendererAPI::Create()
{
    return std::make_unique<GLRendererAPI>();
}
} // namespace GRender