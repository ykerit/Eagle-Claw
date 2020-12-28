#include "Egcpch.h"
#include "EagleClaw/Renderer/VertexArray.h"

#include "Platform/OpenGL/GLVertexArray.h"


namespace EagleClaw
{
    VertexArray::VAOPtr VertexArray::Create() 
    { 
        return std::make_shared<GLVertexArray>();
    }
}
