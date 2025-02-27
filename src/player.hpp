#pragma once

#include <raylib.h>
#include <optional>

#include "world.hpp"
namespace Vox {

using RaylibCamera = struct Camera3D;

struct RaycastHit {
  Vector3 position;
  Vector3 normal;
}; 

class Player {
 public:
  explicit Player(World& world);

  void update();
  constexpr RaylibCamera const& get_camera_impl() { return this->camera_impl; }

 private:
  std::optional<RaycastHit> get_ray_hit_position_to_block();

  RaylibCamera camera_impl{};
  World& main_world;
};

}  // namespace Vox