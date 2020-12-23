#pragma once

namespace EagleClaw
{
    class Texture
    {
    public:
        virtual void Bind(size_t slot) const                = 0;
        virtual void SetData(void* data, const size_t size) = 0;

        virtual const size_t GetWidth() const      = 0;
        virtual const size_t GetHeight() const     = 0;
        virtual const size_t GetRendererID() const = 0;
    };

}  // namespace EagleClaw