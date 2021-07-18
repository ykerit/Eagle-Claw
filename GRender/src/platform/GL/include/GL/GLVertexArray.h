#pragma once

#include <glad/glad.h>

#include "renderer/VertexArray.h"

namespace GRender {
    class GLVertexArray : public VertexArray
    {
    public:
        GLVertexArray();
        ~GLVertexArray();
        void AddVertexBuffer(const VertexBuffer::VTBPtr& vertexBuffer) override;
        void SetIndexBuffer(const IndexBuffer::IDBPtr& indexBuffer) override;
        void Bind() const override;
        void Unbind() const override;
        const IndexBuffer::IDBPtr GetIndexBuffer() const override { return indexBuffer_; }
        const std::vector<VertexBuffer::VTBPtr> GetVertexBuffers() const override { return vertexBuffers_; }

    private:
        uint32_t renderID_;
        uint32_t vertexBufferIdx_ = 0;
        std::vector<VertexBuffer::VTBPtr> vertexBuffers_;
        IndexBuffer::IDBPtr indexBuffer_;
    };
} // namespace GRender