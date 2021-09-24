#pragma once

#include <glm/glm.hpp>

#include "core/Base.h"
#include "core/Log.h"
#include "renderer/VertexArray.h"

namespace GRender {
class RendererAPI
{
public:
    virtual ~RendererAPI() = default;

    virtual void Init() = 0;
    virtual void SetViewport(size_t x, size_t y, size_t width, size_t height) = 0;
    virtual void SetClearColor(const glm::vec4 &color) = 0;
    virtual void Clear() = 0;
    virtual void DrawIndexed(const std::shared_ptr<VertexArray> &vertexArray, size_t indexCount = 0) = 0;

    static std::unique_ptr<RendererAPI> Create();
};
} // namespace GRender