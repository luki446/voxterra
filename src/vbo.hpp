#pragma once

#include <glad/glad.h>

class VBO{
public:
    VBO();
    ~VBO();

    auto bind() const -> void;
    auto unbind() const -> void;

    auto buffer_data(GLsizeiptr size, const void* data, GLenum usage) const -> void;
private:
    GLuint vboId{0};
};