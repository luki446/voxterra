#include "window.hpp"

#include <string>

#include "block.hpp"
#include "player.hpp"
#include "raylib.h"
#include "voxconfig.h"

namespace Vox {

Window::Window(int width, int height) {
  SetTraceLogLevel(TraceLogLevel::LOG_WARNING);
  InitWindow(width, height, "Voxterra game");
}

void Window::run() {
  Vox::Player player{};

  const std::string title_version = "Voxterra " + std::string(VOX_VERSION);

  const Vox::Block block = Vox::Block().at({0.0f, 0.0f, 0.0f});

  DisableCursor();
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    player.update();

    if (IsKeyReleased(KEY_F11)) ToggleFullscreen();

    // clang-format off
    BeginDrawing();
      ClearBackground(SKYBLUE);

      BeginMode3D(player.get_camera_impl());

        DrawPlane((Vector3){0.0f, -0.5f, 0.0f}, (Vector2){32.0f, 32.0f}, LIGHTGRAY);

        block.draw();

      EndMode3D();

      DrawText(title_version.c_str(), 10, 10, 30, DARKGRAY);

    EndDrawing();
    // clang-format on
  }
}

Window::~Window() { CloseWindow(); }

}  // namespace Vox
