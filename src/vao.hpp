#pragma once

#include <glad/glad.h>

class VAO {
public:
    VAO();
    ~VAO();

    auto bind() const -> void;
    auto unbind() const -> void;
private:
    GLuint vaoId{0};
};