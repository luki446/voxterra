#pragma once

#include <glad/glad.h>
#include <string>
#include <spdlog/spdlog.h>
#include "stb/stb_image.h"

class Texture {
public:
    Texture(std::string filePath);
    ~Texture();
    auto bind(uint32_t slot = 0) const -> void;
    auto unbind() const -> void;
private:
    GLuint textureId{0};
    std::string filePath{""};
    int32_t width, height, bpp;
};