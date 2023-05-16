#include "vao.hpp"

VAO::VAO()
{
    glGenVertexArrays(1, &this->vaoId);
}

VAO::~VAO()
{
    glDeleteVertexArrays(1, &this->vaoId);
}

auto VAO::bind() const -> void
{
    glBindVertexArray(this->vaoId);
}

auto VAO::unbind() const -> void
{
    glBindVertexArray(0);
}