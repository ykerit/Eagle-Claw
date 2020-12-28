#pragma once

#include "EagleClaw/Renderer/Buffer.h"

namespace EagleClaw
{
    class GLVertexBuffer : public VertexBuffer
    {
    public:
        GLVertexBuffer(size_t size);
        GLVertexBuffer(const float* vertices, const size_t size);
        virtual ~GLVertexBuffer();

        void Bind() const override;
        void Unbind() const override;

        void SetData(const void* data, size_t size) override;

        const BufferLayout& GetLayout() const override { return layout_; }
        void SetLayout(const BufferLayout& layout) { layout_ = layout; }

    private:
        uint32_t rendererID_;
        BufferLayout layout_;
    };

    class GLIndexBuffer : public IndexBuffer
    {
    public:
        GLIndexBuffer(const uint32_t* indices, size_t count);
        ~GLIndexBuffer();

        void Bind() const override;
        void Unbind() const override;

        const size_t GetCount() const override { return count_; }

    private:
        uint32_t rendererID_;
        size_t count_;
    };

}  // namespace EagleClaw