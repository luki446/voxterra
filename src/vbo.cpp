#include "vbo.hpp"

VBO::VBO()
{
    glGenBuffers(1, &this->vboId);
}

VBO::~VBO()
{
    glDeleteBuffers(1, &this->vboId);
}

auto VBO::bind() const -> void
{
    glBindBuffer(GL_ARRAY_BUFFER, this->vboId);
}

auto VBO::unbind() const -> void
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

auto VBO::buffer_data(GLsizeiptr size, const void* data, GLenum usage) const -> void
{
    glBufferData(GL_ARRAY_BUFFER, size, data, usage);
}