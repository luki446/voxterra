#include "window.hpp"
#include "GLFW/glfw3.h"
#include "spdlog/spdlog.h"

static auto glfw_error_callback(int error, const char* description) -> void
{
    spdlog::error("GLFW Error ({}): {}", error, description);
}

Window::Window(size_t width, size_t height, std::string_view title)
{
    glfwSetErrorCallback(glfw_error_callback);

    if(!glfwInit())
    {
        spdlog::error("Failed to initialize GLFW");
        std::exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    this->window = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
    if(this->window == nullptr)
    {
        spdlog::error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(this->window);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        spdlog::error("Failed to initialize GLAD");
    }
    glfwSwapInterval(1);
}

Window::~Window()
{
    glfwDestroyWindow(this->window);
    glfwTerminate();
}

auto Window::should_close() const -> bool
{
    return glfwWindowShouldClose(this->window);
}

auto Window::swap_buffers() const -> void
{
    glfwSwapBuffers(this->window);
}

auto Window::poll_events() const -> void
{
    glfwPollEvents();
}

auto Window::process_input() const -> void
{
    if(glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(this->window, true);
    }
}

auto Window::process_events() const -> void
{
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}