#pragma once

#include "EagleClaw/Renderer/RendererAPI.h"

namespace EagleClaw
{
    class GLRendererAPI : public RendererAPI
    {
    public:
        void Init();
        void SetViewport(size_t x, size_t y, size_t width, size_t height);
        void SetClearColor(const glm::vec4& color);
        void Clear();
        void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray, size_t indexCount = 0);
    };
}  // namespace EagleClaw