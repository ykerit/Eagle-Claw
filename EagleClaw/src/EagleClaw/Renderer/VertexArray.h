#pragma once

#include "EagleClaw/Renderer/Buffer.h"

namespace EagleClaw
{
    class VertexArray
    {
    public:
        using VAOPtr = std::shared_ptr<VertexArray>;

        virtual ~VertexArray() = default;

        virtual void AddVertexBuffer(const VertexBuffer::VTBPtr& vertexBuffer) = 0;
        virtual void SetIndexBuffer(const IndexBuffer::IDBPtr& indexBuffer)    = 0;
        virtual void Bind() const                                              = 0;
        virtual void Unbind() const                                            = 0;

        virtual const std::vector<VertexBuffer::VTBPtr> GetVertexBuffers() const = 0;
        virtual const IndexBuffer::IDBPtr GetIndexBuffer() const                 = 0;

        static VAOPtr Create();
    };

}  // namespace EagleClaw
