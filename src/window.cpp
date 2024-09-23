#include "window.hpp"

#include "player.hpp"
#include "raylib.h"
#include "voxconfig.h"
#include <string>

namespace Core {

Window::Window(int width, int height) {
  InitWindow(width, height, "Voxterra game");
}

void Window::run() {
  Core::Player player{};

  const std::string title_version = "Voxterra " + std::string(VOX_VERSION);
  std::string fps_info = "FPS: ";

  DisableCursor();
  SetTargetFPS(60);

  while(!WindowShouldClose()) {
    player.update();


    BeginDrawing();
      ClearBackground(SKYBLUE);
      
      BeginMode3D(player.get_camera_impl());

        DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, LIGHTGRAY);

        DrawCube((Vector3){ 0.0f, 1.0f, 0.0f }, 1., 1., 1., RED);
        DrawCubeWires((Vector3){ 0.0f, 1.0f, 0.0f }, 1., 1., 1., MAROON);

      EndMode3D();

      DrawText(title_version.c_str(), 10, 10, 30, DARKGRAY);

    EndDrawing();
  }
}

Window::~Window() {
  CloseWindow();
}

} // namespace Core