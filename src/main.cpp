#include <iostream>
#include "window.hpp"
#include "shader.hpp"
#include "vao.hpp"
#include "vbo.hpp"
#include "vertexAttribBuilder.hpp"


static std::string vertexShaderCode = R"(
#version 330 core
layout (location = 0) in vec3 aPos;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
)";

static std::string fragmentShaderCode = R"(
#version 330 core
out vec4 color;

void main()
{
    color = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}
)";

static float vertices[]{
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f,  0.5f, 0.0f
};

auto main() -> int
{
    Window window{1280, 720, "Voxterra"};

    Shader basicShader{vertexShaderCode, fragmentShaderCode};
    basicShader.use();

    VAO vao{};
    vao.bind();

    VBO vboVertices{};
    vboVertices.bind();
    vboVertices.buffer_data(sizeof(vertices), vertices, GL_STATIC_DRAW);

    VertexAttribBuilder()
        .index(0)
        .size(3)
        .type(GL_FLOAT)
        .stride(3 * sizeof(float))
        .pointer(nullptr)
        .build();
    
    vao.unbind();

    while(!window.should_close())
    {
        window.process_input();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        basicShader.use();
        vao.bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);

        window.process_events();
    }

    return 0;
}
