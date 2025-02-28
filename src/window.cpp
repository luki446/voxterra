#include "window.hpp"

#include <string>

#include "player.hpp"
#include "raylib.h"
#include "voxconfig.h"
#include "world.hpp"

namespace Vox {

Window::Window(int width, int height) {
  InitWindow(width, height, "Voxterra game");
}

void Window::run() {
  Vox::World main_world{};
  Vox::Player main_player{main_world};

  const std::string title_version = "Voxterra " + std::string(VOX_VERSION);

  DisableCursor();
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    main_player.update();

    if (IsKeyReleased(KEY_F11)) ToggleFullscreen();

    // clang-format off
    BeginDrawing();
      ClearBackground(SKYBLUE);

      BeginMode3D(main_player.get_camera_impl());

        DrawGrid(64, 0.5f);

        main_world.draw();
      EndMode3D();

      DrawText(title_version.c_str(), 10, 10, 30, DARKGRAY);
    EndDrawing();
    // clang-format on
  }
}

Window::~Window() { CloseWindow(); }

}  // namespace Vox
