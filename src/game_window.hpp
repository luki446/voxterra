#pragma once

constexpr inline size_t SCREEN_WIDTH = 1280;
constexpr inline size_t SCREEN_HEIGHT = 720;

class GameWindow {
public:
    GameWindow(int width = SCREEN_WIDTH, int height = SCREEN_HEIGHT);
    ~GameWindow();
    void run();
};