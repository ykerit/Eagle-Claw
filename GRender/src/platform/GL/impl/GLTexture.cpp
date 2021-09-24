#include "GL/GLTexture.h"
#include "stb_image.h"

namespace GRender {
GLTexture::GLTexture(const size_t width, const size_t height)
    : width_(width)
    , height_(height)
{
    internalFormat_ = GL_RGBA;
    dataFormat_ = GL_RGBA;

    GLCALL(glCreateTextures(GL_TEXTURE_2D, 1, &rendererID));
    GLCALL(glTextureStorage2D(rendererID, 1, internalFormat_, width_, height_));

    GLCALL(glTextureParameteri(rendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GLCALL(glTextureParameteri(rendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST));

    GLCALL(glTextureParameteri(rendererID, GL_TEXTURE_WRAP_S, GL_REPEAT));
    GLCALL(glTextureParameteri(rendererID, GL_TEXTURE_WRAP_T, GL_REPEAT));
}

GLTexture::GLTexture(const std::string &filepath)
{
    int width, height, channels;
    stbi_set_flip_vertically_on_load(1);
    stbi_uc *data = stbi_load(filepath.c_str(), &width, &height, &channels, 0);
    EGC_ASSERT_MSG(data, "Failed to load image");
    width_ = width;
    height = height_;

    GLenum internalFormat = 0, dataFormat = 0;
    if (channels == 4)
    {
        internalFormat = GL_RGBA8;
        dataFormat = GL_RGBA;
    }
    else if (channels == 3)
    {
        internalFormat = GL_RGB8;
        dataFormat = GL_RGB;
    }

    internalFormat_ = internalFormat;
    dataFormat_ = dataFormat;

    EGC_ASSERT_MSG(internalFormat_ & dataFormat_, "Format not supported");

    glCreateTextures(GL_TEXTURE_2D, 1, &rendererID);
    glTextureStorage2D(rendererID, 1, internalFormat, width_, height_);

    glTextureParameteri(rendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTextureParameteri(rendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTextureParameteri(rendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTextureParameteri(rendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTextureSubImage2D(rendererID, 0, 0, 0, width_, height_, dataFormat, GL_UNSIGNED_BYTE, data);

    stbi_image_free(data);
}

GLTexture::~GLTexture()
{
    GLCALL(glDeleteTextures(1, &rendererID));
}

void GLTexture::Bind(size_t slot) const
{
    GLCALL(glBindTextureUnit(slot, rendererID));
}

void GLTexture::SetData(void *data, const size_t size)
{
    uint32_t bpp = dataFormat_ == GL_RGBA ? 4 : 3;
    EGC_ASSERT_MSG(size == width_ * height_ * bpp, "Data must be entire texture!");
    glTextureSubImage2D(rendererID, 0, 0, 0, width_, height_, dataFormat_, GL_UNSIGNED_BYTE, data);
}

} // namespace GRender