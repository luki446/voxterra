#pragma once

#include <glad/glad.h>
#include <string>
#include <spdlog/spdlog.h> 

class Shader {
public:
    Shader(std::string vertexCode, std::string fragmentCode);
    auto use() const -> void;
private:
    GLuint programId{0};
};