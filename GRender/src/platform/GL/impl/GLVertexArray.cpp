
#include "GL/GLVertexArray.h"

namespace GRender
{
    static GLenum BufferDateType2GLType(BufferDataType type)
    {
        switch (type)
        {
            case BufferDataType::Float: return GL_FLOAT;
            case BufferDataType::Float2: return GL_FLOAT;
            case BufferDataType::Float3: return GL_FLOAT;
            case BufferDataType::Float4: return GL_FLOAT;
            case BufferDataType::Int: return GL_INT;
            case BufferDataType::Int2: return GL_INT;
            case BufferDataType::Int3: return GL_INT;
            case BufferDataType::Int4: return GL_INT;
            case BufferDataType::Bool: return GL_BOOL;
            case BufferDataType::Mat3: return GL_FLOAT;
            case BufferDataType::Mat4: return GL_FLOAT;
        }
        EGC_ASSERT_MSG(false, "Unkown BufferDataType");
    }

    GLVertexArray::GLVertexArray() { GLCALL(glCreateVertexArrays(1, &renderID_)); }

    GLVertexArray::~GLVertexArray() { GLCALL(glDeleteVertexArrays(1, &renderID_)); }

    void GLVertexArray::AddVertexBuffer(const VertexBuffer::VTBPtr& vertexBuffer)
    {
        EGC_ASSERT_MSG(vertexBuffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout");
        GLCALL(glBindVertexArray(renderID_));
        vertexBuffer->Bind();

        const auto& layout = vertexBuffer->GetLayout();
        for (const auto& element : layout)
        {
            switch (element.type)
            {
                case BufferDataType::Float:
                case BufferDataType::Float2:
                case BufferDataType::Float3:
                case BufferDataType::Float4:
                case BufferDataType::Int:
                case BufferDataType::Int2:
                case BufferDataType::Int3:
                case BufferDataType::Int4:
                case BufferDataType::Bool:
                {
                    GLCALL(glEnableVertexAttribArray(vertexBufferIdx_));
                    glVertexAttribPointer(vertexBufferIdx_, element.GetComponentCount(), BufferDateType2GLType(element.type),
                                          element.normalized ? GL_TRUE : GL_FALSE, layout.GetStride(),
                                          (void*)element.offset);
                    ++vertexBufferIdx_;
                    break;
                }
                case BufferDataType::Mat3:
                case BufferDataType::Mat4:
                {
                    uint8_t count = element.GetComponentCount();
                    for (uint8_t i = 0; i < count; ++i)
                    {
                        glEnableVertexAttribArray(vertexBufferIdx_);
                        glVertexAttribPointer(vertexBufferIdx_, count, BufferDateType2GLType(element.type),
                                              element.normalized ? GL_TRUE : GL_FALSE, layout.GetStride(),
                                              (void*)(element.offset + sizeof(float) * count + i));
                        glVertexAttribDivisor(vertexBufferIdx_, 1);
                        ++vertexBufferIdx_;
                    }
                    break;
                }
                default: EGC_ASSERT_MSG(false, "Unkown BufferDataType");
            }
        }
        vertexBuffers_.push_back(vertexBuffer);
    }

    void GLVertexArray::SetIndexBuffer(const IndexBuffer::IDBPtr& indexBuffer)
    {
        GLCALL(glBindVertexArray(renderID_));
        indexBuffer->Bind();
        indexBuffer_ = indexBuffer;
    }

    void GLVertexArray::Bind() const { GLCALL(glBindVertexArray(renderID_)); }

    void GLVertexArray::Unbind() const { GLCALL(glBindVertexArray(0)); }
}  // namespace GRender
