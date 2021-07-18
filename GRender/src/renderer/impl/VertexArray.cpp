
#include "renderer/VertexArray.h"
#include "GL/GLVertexArray.h"

#include <memory>

namespace GRender
{
    VertexArray::VAOPtr VertexArray::Create() { return std::make_shared<GLVertexArray>(); }
}  // namespace GRender
