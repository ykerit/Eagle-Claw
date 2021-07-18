#pragma once

#include "renderer/RendererAPI.h"

namespace GRender
{
    class RendererCommand
    {
    public:
        static void Init() { rendererAPI_->Init(); }

        static void SetViewport(size_t x, size_t y, size_t width, size_t height)
        {
            rendererAPI_->SetViewport(x, y, width, height);
        }

        static void SetClearColor(const glm::vec4& color) { rendererAPI_->SetClearColor(color); }

        static void Clear() { rendererAPI_->Clear(); }

        static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray, uint32_t count = 0)
        {
            rendererAPI_->DrawIndexed(vertexArray, count);
        }

    private:
        static std::unique_ptr<RendererAPI> rendererAPI_;
    };
    } // namespace GRender