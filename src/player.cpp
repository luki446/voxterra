#include "player.hpp"
#include <raymath.h>
#include "raylib.h"
#include <cmath>

namespace Vox {

Player::Player(World& world) : main_world(world) {
  this->camera_impl.position = (Vector3){0.0f, 1.0f + 1.8f, 0.0f};
  this->camera_impl.target = (Vector3){0.0f, 1.0f + 1.8f, -1.0f};
  this->camera_impl.up = (Vector3){0.0f, 1.0f, 0.0f};
  this->camera_impl.fovy = 50.0f;
  this->camera_impl.projection = CAMERA_PERSPECTIVE;
}

void Player::update() {
    UpdateCamera(&this->camera_impl, CAMERA_FIRST_PERSON);

    if(IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
        if(auto raycast_hit = this->get_ray_hit_position_to_block()) {
            // TraceLog(LOG_INFO, "Ray hit position: %f %f %f", hit_ray->position.x, hit_ray->position.y, hit_ray->position.z);

            // Place block at hit position
            main_world.place_block(raycast_hit->position + raycast_hit->normal, BlockType::DIRT);
        }
    }
}

std::optional<RaycastHit> Player::get_ray_hit_position_to_block() {
    constexpr static float MAX_DISTANCE = 8.0f;

    const Vector2 screenMid{GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};

    auto [camera_position, camera_direction] = GetScreenToWorldRay(screenMid, this->camera_impl);

    Vector3 ray_dir = camera_direction;

    // Based on paper: "A Fast Voxel Traversal Algorithm for Ray Tracing"
    // by John Amanatides and Andrew Woo

    // PSA: When you need to cite a scientific paper in your little side project you know something went wrong

    // Coordinates of voxel containing camera position
    int32_t x = std::floor(camera_position.x);
    int32_t y = std::floor(camera_position.y);
    int32_t z = std::floor(camera_position.z);
    
    auto numerical_direction = [](float value) -> int32_t {
        return (value == 0.0f) ? 0 : std::signbit(value) ? -1 : 1;
    };

    // Numerical directions of ray
    int32_t step_x = numerical_direction(ray_dir.x);
    int32_t step_y = numerical_direction(ray_dir.y);
    int32_t step_z = numerical_direction(ray_dir.z);
    
    // Distance from camera position to next voxel boundary
    float next_voxel_boundary_x = (step_x > 0.0f) ? (x + 1.0f) : x;
    float next_voxel_boundary_y = (step_y > 0.0f) ? (y + 1.0f) : y;
    float next_voxel_boundary_z = (step_z > 0.0f) ? (z + 1.0f) : z;
    
    // tMax: value of t at which ray crosses the first voxel boundary
    float t_max_x = (ray_dir.x != 0) ? (next_voxel_boundary_x - camera_position.x) / ray_dir.x : INFINITY;
    float t_max_y = (ray_dir.y != 0) ? (next_voxel_boundary_y - camera_position.y) / ray_dir.y : INFINITY;
    float t_max_z = (ray_dir.z != 0) ? (next_voxel_boundary_z - camera_position.z) / ray_dir.z : INFINITY;
    
    // tDelta: how far along the ray we must move for each component to equal the width of a voxel
    float t_delta_x = (ray_dir.x != 0) ? std::fabsf(1.0f / ray_dir.x) : INFINITY;
    float t_delta_y = (ray_dir.y != 0) ? std::fabsf(1.0f / ray_dir.y) : INFINITY;
    float t_delta_z = (ray_dir.z != 0) ? std::fabsf(1.0f / ray_dir.z) : INFINITY;
    
    enum class BlockFace : uint32_t {
        POSITIVE_X = 0,
        NEGATIVE_X,
        POSITIVE_Y,
        NEGATIVE_Y,
        POSITIVE_Z,
        NEGATIVE_Z
    };

    constexpr static Vector3 FACE_NORMALS[6] = {
        Vector3{-1, 0, 0}, // +X
        Vector3{1, 0, 0},  // -X
        Vector3{0, -1, 0}, // +Y
        Vector3{0, 1, 0},  // -Y
        Vector3{0, 0, -1}, // +Z
        Vector3{0, 0, 1}   // -Z
    };

    // Face index for hit detection (0 = +X, 1 = -X, 2 = +Y, 3 = -Y, 4 = +Z, 5 = -Z)
    BlockFace face = BlockFace::POSITIVE_X;
    
    // Distance traveled along the ray
    float distance = 0.0f;
    
    // Ray traversal loop
    while (distance < MAX_DISTANCE) {
        // Check if current voxel contains a block
        Vector3 current_pos{static_cast<float>(x), static_cast<float>(y), static_cast<float>(z)};
        auto block_it = main_world.is_block_at(current_pos);
        
        if (block_it.has_value()) {
            return {
                RaycastHit{
                    .position = current_pos,
                    .normal = FACE_NORMALS[static_cast<uint32_t>(face)]
                }
            };
        }
        
        // Advance to next voxel based on tMax values
        if (t_max_x < t_max_y && t_max_x < t_max_z) {
            // X axis traversal
            distance = t_max_x;
            t_max_x += t_delta_x;
            x += step_x;
            face = (step_x > 0) ? BlockFace::POSITIVE_X : BlockFace::NEGATIVE_X; // +X or -X face
        } else if (t_max_y < t_max_z) {
            // Y axis traversal
            distance = t_max_y;
            t_max_y += t_delta_y;
            y += step_y;
            face = (step_y > 0) ? BlockFace::POSITIVE_Y : BlockFace::NEGATIVE_Y; // +Y or -Y face
        } else {
            // Z axis traversal
            distance = t_max_z;
            t_max_z += t_delta_z;
            z += step_z;
            face = (step_z > 0) ? BlockFace::POSITIVE_Z : BlockFace::NEGATIVE_Z; // -Z or +Z face
        }
    }
    
    // No block was hit within range
    return {};
}

}  // namespace Vox