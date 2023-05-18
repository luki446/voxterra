#include "texture.hpp"
#include <stdlib.h>

Texture::Texture(std::string filePath)
    : filePath{filePath}
{
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(filePath.c_str(), &this->width, &this->height, &this->bpp, 4);
    if(data == nullptr)
    {
        spdlog::error("Failed to load texture: {}", filePath);
        std::exit(EXIT_FAILURE);
    }

    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glGenerateMipmap(GL_TEXTURE_2D);

    this->unbind();

    stbi_image_free(data);
}

Texture::~Texture()
{
    glDeleteTextures(1, &textureId);
}

auto Texture::bind(uint32_t slot) const -> void
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, textureId);
}

auto Texture::unbind() const -> void
{
    glBindTexture(GL_TEXTURE_2D, 0);
}