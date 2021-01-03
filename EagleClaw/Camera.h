#pragma once

#include <glm/glm.hpp>

namespace EagleClaw
{
    class Camera
    {
    public:
        Camera() = default;
        Camera(const glm::mat4& projection) : projection_(projection) { }
        virtual ~Camera() = default;
        const glm::mat4& GetProjection() { return projection_; }

    private:
        glm::mat4 projection_{ 1.0f };
    };

}  // namespace EagleClaw