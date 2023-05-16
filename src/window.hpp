#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>
#include <string_view>

class Window{
public:
    Window(size_t width, size_t height, std::string_view title);
    [[nodiscard]] auto should_close() const -> bool;
    auto process_input() const -> void;
    auto process_events() const -> void;
    ~Window();
private:

    auto swap_buffers() const -> void;
    auto poll_events() const -> void;
    GLFWwindow* window{nullptr};
};