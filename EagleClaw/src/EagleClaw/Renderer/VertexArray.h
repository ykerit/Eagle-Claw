#pragma once

#include <memory>

#include "EagleClaw/Renderer/Buffer.h"

namespace
{
    class VertexArray
    {
    public:
        using VAOPtr = std::shared_ptr<VertexArray>;

        virtual ~VertexArray() = default;

        virtual void AddVertexBuffer(const VTBPtr& vertexBuffer) = 0;
        virtual void SetIndexBuffer(const IDBPtr& indexBuffer)   = 0;
        virtual void Bind() const                                = 0;
        virtual void Unbind() const                              = 0;

        virtual const std::vector<VTBPtr> GetVertexBuffers() const = 0;
        virtual const IDBPtr GetIndexBuffer() const                = 0;

        static VAOPtr Create();
    };

}  // namespace
