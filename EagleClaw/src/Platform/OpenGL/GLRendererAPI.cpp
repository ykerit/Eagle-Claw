#include "Egcpch.h"

#include "Platform/OpenGL/GLRendererAPI.h"

#include <glad/glad.h>

namespace EagleClaw
{
    void OpenGLMSGCallback(unsigned source, unsigned type, unsigned id, unsigned severity, int length, const char* msg,
                           const void* userParam)
    {
        switch (severity)
        {
            case GL_DEBUG_SEVERITY_HIGH: EGC_CORE_DEBUG(msg); return;
            case GL_DEBUG_SEVERITY_MEDIUM: EGC_CORE_ERROR(msg); return;
            case GL_DEBUG_SEVERITY_LOW: EGC_CORE_WARN(msg); return;
            case GL_DEBUG_SEVERITY_NOTIFICATION: EGC_CORE_TRACE(msg); return;
        }
        EGC_ASSERT_MSG(false, "Unknown severity level");
    }

    void GLRendererAPI::Init()
    {
        // GLCALL(glEnable(GL_DEBUG_OUTPUT));
        // GLCALL(glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS));
        // GLCALL(glDebugMessageCallback(OpenGLMSGCallback, nullptr));
        // GLCALL(glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE));

        GLCALL(glEnable(GL_BLEND));
        GLCALL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_ALPHA));
        GLCALL(glEnable(GL_DEPTH_TEST));
    }

    void GLRendererAPI::SetViewport(size_t x, size_t y, size_t width, size_t height)
    {
        GLCALL(glViewport(x, y, width, height));
    }

    void GLRendererAPI::SetClearColor(const glm::vec4& color) { GLCALL(glClearColor(color.r, color.g, color.b, color.a)); }

    void GLRendererAPI::Clear() { GLCALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)); }

    void GLRendererAPI::DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray, size_t indexCount)
    {
        uint32_t count = indexCount ? indexCount : vertexArray->GetIndexBuffer()->GetCount();
        GLCALL(glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr));
        GLCALL(glBindTexture(GL_TEXTURE_2D, 0));
    }
}  // namespace EagleClaw