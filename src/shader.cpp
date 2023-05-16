#include "shader.hpp"

Shader::Shader(std::string vertexCode, std::string fragmentCode)
{
    const GLchar* vShaderCode = vertexCode.c_str();
    const GLchar* fShaderCode = fragmentCode.c_str();

    GLuint vertex, fragment;
    GLint success;
    GLchar infoLog[512];

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, nullptr);
    glCompileShader(vertex);

    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertex, sizeof(infoLog), nullptr, infoLog);
        spdlog::error("Vertex shader compilation failed:\n{}", infoLog);
    }

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, nullptr);
    glCompileShader(fragment);

    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragment, sizeof(infoLog), nullptr, infoLog);
        spdlog::error("Fragment shader compilation failed:\n{}", infoLog);
    }

    this->programId = glCreateProgram();
    glAttachShader(this->programId, vertex);
    glAttachShader(this->programId, fragment);
    glLinkProgram(this->programId);

    glGetProgramiv(this->programId, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(this->programId, sizeof(infoLog), nullptr, infoLog);
        spdlog::error("Shader program linking failed:\n{}", infoLog);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

auto Shader::use() const -> void
{
    glUseProgram(this->programId);
}