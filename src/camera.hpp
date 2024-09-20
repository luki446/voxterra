#pragma once

#include <raylib.h>

namespace Core {

using RaylibCamera = struct Camera3D;

class Camera {
public:
    Camera();
    void update();
    RaylibCamera const& get_impl();
private:
    RaylibCamera camera_impl{ 0 };
};

} // namespace Core