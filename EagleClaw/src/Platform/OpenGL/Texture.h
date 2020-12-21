#pragma once

#include <iostream>

#include "common.h"

class Texture {
public:
    Texture(const std::string& filepath);
    ~Texture();

    void Bind(const size_t slot = 0) const;
    void Unbind() const;

    const int getWidth() const;
    const int getHeight() const;

private:
    uint8_t* image_;
    GLuint rendererID_;
    int width_;
    int height_;
    int bpp_;
};