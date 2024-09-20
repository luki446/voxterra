#include "game_window.hpp"

#include "raylib.h"

GameWindow::GameWindow(int width, int height) {
  InitWindow(width, height, "Voxterra game");
}

void GameWindow::run() {
  while(!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawText("First Window!", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
  }
}

GameWindow::~GameWindow() {
  CloseWindow();
}

