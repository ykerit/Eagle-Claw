#include "Preheader.h"
#include <EagleClaw/Renderer/Buffer.h>

#include "Platform/OpenGL/GLBuffer.h"

using namespace EagleClaw;

VertexBuffer::VTBPtr VertexBuffer::Create(const size_t size) {
    return std::make_shared<GLVertexBuffer>(size);
}

VertexBuffer::VTBPtr VertexBuffer::Create(const float* vertices, const size_t size) {
    return std::make_shared<GLVertexBuffer>(vertices, size);
}

IndexBuffer::IDBPtr IndexBuffer::Create(const uint32_t* indices, const size_t count) {
    return std::make_shared<GLIndexBuffer>(indices, count);
}
