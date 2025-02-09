#include "player.hpp"
#include "raylib.h"

namespace Vox {

Player::Player(World& world) : main_world(world) {
  this->camera_impl.position = (Vector3){0.0f, 2.0f, 4.0f};
  this->camera_impl.target = (Vector3){0.0f, 2.0f, 0.0f};
  this->camera_impl.up = (Vector3){0.0f, 1.0f, 0.0f};
  this->camera_impl.fovy = 60.0f;
  this->camera_impl.projection = CAMERA_PERSPECTIVE;
}

void Player::update() {
    UpdateCamera(&this->camera_impl, CAMERA_FIRST_PERSON);
}

}  // namespace Vox