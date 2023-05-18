#pragma once

#include <glad/glad.h>
#include <string>
#include <spdlog/spdlog.h> 
#include "texture.hpp"

class Shader {
public:
    Shader(std::string vertexCode, std::string fragmentCode);
    
    auto setUniformTexture(const std::string& name, Texture& text, GLint slot) const -> void;
    auto use() const -> void;
private:
    GLuint programId{0};
};