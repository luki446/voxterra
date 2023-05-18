#include <iostream>
#include "window.hpp"
#include "shader.hpp"
#include "vao.hpp"
#include "vbo.hpp"
#include "vertexAttribBuilder.hpp"
#include "texture.hpp"


static std::string vertexShaderCode = R"(
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    TexCoord = aTexCoord;
}
)";

static std::string fragmentShaderCode = R"(
#version 330 core
in vec2 TexCoord;
out vec4 color;

uniform sampler2D texture1;

void main()
{
    color = texture(texture1, TexCoord);
}
)";

static float vertices[]{
    -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 
    0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,

    -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
    0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
    0.5, -0.5f, 0.0f, 1.0f, 0.0f
};

auto main() -> int
{
    Window window{640, 640, "Voxterra"};

    Shader basicShader{vertexShaderCode, fragmentShaderCode};
    basicShader.use();

    VAO vao{};
    vao.bind();

    VBO vboVertices{};
    vboVertices.bind();
    vboVertices.buffer_data(sizeof(vertices), vertices, GL_STATIC_DRAW);

    Texture dirt{"dirt.png"};
    
    basicShader.setUniformTexture("texture1", dirt, 0);

    VertexAttribBuilder()
        .index(0)
        .size(3)
        .type(GL_FLOAT)
        .stride(5 * sizeof(float))
        .pointer(nullptr)
        .build();
    
    VertexAttribBuilder()
        .index(1)
        .size(2)
        .type(GL_FLOAT)
        .stride(5 * sizeof(float))
        .pointer((void*)(3 * sizeof(float)))
        .build();

    vao.unbind();

    while(!window.should_close())
    {
        window.process_input();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        basicShader.use();
        vao.bind();
        glDrawArrays(GL_TRIANGLES, 0, 6);

        window.process_events();
    }

    return 0;
}
