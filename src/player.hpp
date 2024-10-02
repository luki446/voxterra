#pragma once

#include <raylib.h>

namespace Vox {

using RaylibCamera = struct Camera3D;

class Player {
 public:
  Player();
  void update();
  RaylibCamera const& get_camera_impl();

 private:
  RaylibCamera camera_impl{0};
};

}  // namespace Vox