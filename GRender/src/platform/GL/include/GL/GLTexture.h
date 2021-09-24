#pragma once

#include <glad/glad.h>

#include "renderer/Texture.h"

#include <string>

namespace GRender {
class GLTexture : public Texture
{
public:
    GLTexture(const size_t width, const size_t height);
    GLTexture(const std::string &filepath);
    ~GLTexture();

    void Bind(size_t slot) const override;

    void SetData(void *data, const size_t size) override;

    const size_t GetWidth() const override
    {
        return width_;
    }

    const size_t GetHeight() const override
    {
        return height_;
    }

    const size_t GetRendererID() const override
    {
        return rendererID;
    }

private:
    size_t width_, height_;
    std::string path_;
    uint32_t rendererID;
    GLenum internalFormat_, dataFormat_;
};

} // namespace GRender