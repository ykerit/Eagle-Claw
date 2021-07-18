#pragma once

#include "renderer/Shader.h"
#include "renderer/VertexArray.h"

namespace GRender
{
    class Renderer
    {
    public:
        static void Init();
        static void ShutDown();
        static void OnWindowResize(size_t width, size_t height);
        static void BeginScence();
        static void EndScence();
        static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray,
                           const glm::mat4& transform = glm::mat4(1.0f));
    };

} // namespace GRender