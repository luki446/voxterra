#include "raylib.h"

int main(int argc, char** argv) {
  InitWindow(800, 450, "Ralib example");

  while(!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawText("First Window!", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
  }
}
