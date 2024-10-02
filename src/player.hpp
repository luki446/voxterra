#pragma once

#include <raylib.h>

#include "world.hpp"
namespace Vox {

using RaylibCamera = struct Camera3D;

class Player {
 public:
  explicit Player(World& world);

  void update();
  constexpr RaylibCamera const& get_camera_impl() { return this->camera_impl; }

 private:
  RaylibCamera camera_impl{0};
  World& main_world;
};

}  // namespace Vox