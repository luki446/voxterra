#include "player.hpp"

namespace Vox {

Player::Player(World& world) : main_world(world) {
  this->camera_impl.position = (Vector3){0.0f, 2.0f, 4.0f};
  this->camera_impl.target = (Vector3){0.0f, 2.0f, 0.0f};
  this->camera_impl.up = (Vector3){0.0f, 1.0f, 0.0f};
  this->camera_impl.fovy = 60.0f;
  this->camera_impl.projection = CAMERA_PERSPECTIVE;
}

void Player::update() {
  UpdateCameraPro(&this->camera_impl,
                  (Vector3){
                      (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) *
                              0.1f -  // Move forward-backward
                          (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) * 0.1f,
                      (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) *
                              0.1f -  // Move right-left
                          (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) * 0.1f,
                      0.0f  // Move up-down
                  },
                  (Vector3){
                      GetMouseDelta().x * 0.05f,  // Rotation: yaw
                      GetMouseDelta().y * 0.05f,  // Rotation: pitch
                      0.0f                        // Rotation: roll
                  },
                  GetMouseWheelMove() * 0.9f);
}

}  // namespace Vox