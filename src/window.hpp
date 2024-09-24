#pragma once

#include <cstdint>

constexpr inline size_t SCREEN_WIDTH = 1280;
constexpr inline size_t SCREEN_HEIGHT = 720;

namespace Core {

class Window {
public:
    Window(int width = SCREEN_WIDTH, int height = SCREEN_HEIGHT);
    ~Window();
    void run();
};

} // namespace Core
