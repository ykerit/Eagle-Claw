#include "Texture.h"

#include "stb_image/stb_image.h"

Texture::Texture(const std::string& filepath)
    : image_(NULL), rendererID_(0), width_(0), height_(0), bpp_(0) {
    stbi_set_flip_vertically_on_load(1);
    image_ = stbi_load(filepath.c_str(), &width_, &height_, &bpp_, 4);
    if (image_ == nullptr) {
        std::cout << "[OPENGL ERROR] (texture file path: " << filepath << " error!)" << std::endl;
        ASSERT(false);
    }
    GLCALL(glGenTextures(1, &rendererID_));
    GLCALL(glBindTexture(GL_TEXTURE_2D, rendererID_));
    // set texture attribute such as wrapping && filter
    GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
    // load and run
    GLCALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width_, height_, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                        image_));
    GLCALL(glGenerateMipmap(GL_TEXTURE_2D));
    GLCALL(glBindTexture(GL_TEXTURE_2D, 0))
    if (image_)
        stbi_image_free(image_);
}

Texture::~Texture() {
    GLCALL(glDeleteTextures(1, &rendererID_));
}

void Texture::Bind(const size_t slot) const {
    GLCALL(glActiveTexture(GL_TEXTURE0 + slot));
    GLCALL(glBindTexture(GL_TEXTURE_2D, rendererID_));
}

void Texture::Unbind() const {
    GLCALL(glBindTexture(GL_TEXTURE_2D, 0));
}

const int Texture::getWidth() const {
    return width_;
}

const int Texture::getHeight() const {
    return height_;
}
