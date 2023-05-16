#pragma once

#include <glad/glad.h>

class VertexAttribBuilder {
public:
    constexpr VertexAttribBuilder() = default;
    
    [[nodiscard]] constexpr auto index(GLuint index) -> VertexAttribBuilder& {
        this->_index = index;
        return *this;
    }

    [[nodiscard]] constexpr auto size(GLuint size) -> VertexAttribBuilder {
        this->_size = size;
        return *this;
    }

    [[nodiscard]] constexpr auto type(GLenum type) -> VertexAttribBuilder {
        this->_type = type;
        return *this;
    }

    [[nodiscard]] constexpr auto normalized(GLboolean normalized) -> VertexAttribBuilder {
        this->_normalized = normalized;
        return *this;
    }

    [[nodiscard]] constexpr auto stride(GLsizei stride) -> VertexAttribBuilder {
        this->_stride = stride;
        return *this;
    }

    [[nodiscard]] constexpr auto pointer(const GLvoid* pointer) -> VertexAttribBuilder {
        this->_pointer = pointer;
        return *this;
    }

    inline auto build() -> void {
        glVertexAttribPointer(this->_index, this->_size, this->_type, this->_normalized, this->_stride, this->_pointer);
        glEnableVertexAttribArray(this->_index);
    }
private:
    GLuint _index{0};
    GLuint _size{0};
    GLenum _type{GL_FLOAT};
    GLboolean _normalized{GL_FALSE};
    GLsizei _stride{0};
    const GLvoid* _pointer{nullptr};
};