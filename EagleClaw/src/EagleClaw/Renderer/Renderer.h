#pragma once

#include "EagleClaw/Renderer/Shader.h"
#include "EagleClaw/Renderer/VertexArray.h"

namespace EagleClaw
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

}  // namespace EagleClaw