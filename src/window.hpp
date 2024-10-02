#pragma once

#include <cstdint>

constexpr inline size_t SCREEN_WIDTH = 1280;
constexpr inline size_t SCREEN_HEIGHT = 720;

namespace Vox {

class Window {
 public:
  Window(int width = SCREEN_WIDTH, int height = SCREEN_HEIGHT);

  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;

  ~Window();
  void run();
};

}  // namespace Vox
