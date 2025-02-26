#include "block.hpp"

#include <raylib.h>
#include <rlgl.h>

#include "resource_manager.hpp"

namespace Vox {

Block::Block(BlockType type) { this->type = type; }

void Block::draw_at(Vector3 const& pos) const {
  const float x = pos.x;
  const float y = pos.y;
  const float z = pos.z;

  constexpr static float width = 1.0f;
  constexpr static float height = 1.0f;
  constexpr static float length = 1.0f;

  constexpr static Color color = RAYWHITE;

  rlSetTexture(ResourceManager::get_instance()
                   .textures[static_cast<uint32_t>(this->type)]
                   .id);

  // clang-format off
  rlBegin(RL_QUADS);
    rlColor4ub(color.r, color.g, color.b, color.a);

    // Front Face
    rlNormal3f(0.0f, 0.0f, 1.0f);  // Normal Pointing Towards Viewer
    rlTexCoord2f(0.0f, 0.0f);
    rlVertex3f(x, y, z + length);
    rlTexCoord2f(1.0f, 0.0f);
    rlVertex3f(x + width, y, z + length);
    rlTexCoord2f(1.0f, 1.0f);
    rlVertex3f(x + width, y + height, z + length);
    rlTexCoord2f(0.0f, 1.0f);
    rlVertex3f(x, y + height, z + length);
    // Back Face
    rlNormal3f(0.0f, 0.0f, -1.0f);  // Normal Pointing Away From Viewer
    rlTexCoord2f(1.0f, 0.0f);
    rlVertex3f(x, y, z);
    rlTexCoord2f(1.0f, 1.0f);
    rlVertex3f(x, y + height, z);
    rlTexCoord2f(0.0f, 1.0f);
    rlVertex3f(x + width, y + height, z);
    rlTexCoord2f(0.0f, 0.0f);
    rlVertex3f(x + width, y, z);
    // Top Face
    rlNormal3f(0.0f, 1.0f, 0.0f);  // Normal Pointing Up
    rlTexCoord2f(0.0f, 1.0f);
    rlVertex3f(x, y + height, z);
    rlTexCoord2f(0.0f, 0.0f);
    rlVertex3f(x, y + height, z + length);
    rlTexCoord2f(1.0f, 0.0f);
    rlVertex3f(x + width, y + height, z + length);
    rlTexCoord2f(1.0f, 1.0f);
    rlVertex3f(x + width, y + height, z);
    // Bottom Face
    rlNormal3f(0.0f, -1.0f, 0.0f);  // Normal Pointing Down
    rlTexCoord2f(1.0f, 1.0f);
    rlVertex3f(x, y, z);
    rlTexCoord2f(0.0f, 1.0f);
    rlVertex3f(x + width, y, z);
    rlTexCoord2f(0.0f, 0.0f);
    rlVertex3f(x + width, y, z + length);
    rlTexCoord2f(1.0f, 0.0f);
    rlVertex3f(x, y, z + length);
    // Right face
    rlNormal3f(1.0f, 0.0f, 0.0f);  // Normal Pointing Right
    rlTexCoord2f(1.0f, 0.0f);
    rlVertex3f(x + width, y, z);
    rlTexCoord2f(1.0f, 1.0f);
    rlVertex3f(x + width, y + height, z);
    rlTexCoord2f(0.0f, 1.0f);
    rlVertex3f(x + width, y + height, z + length);
    rlTexCoord2f(0.0f, 0.0f);
    rlVertex3f(x + width, y, z + length);
    // Left Face
    rlNormal3f(-1.0f, 0.0f, 0.0f);  // Normal Pointing Left
    rlTexCoord2f(0.0f, 0.0f);
    rlVertex3f(x, y, z);
    rlTexCoord2f(1.0f, 0.0f);
    rlVertex3f(x, y, z + length);
    rlTexCoord2f(1.0f, 1.0f);
    rlVertex3f(x, y + height, z + length);
    rlTexCoord2f(0.0f, 1.0f);
    rlVertex3f(x, y + height, z);
  rlEnd();
  // clang-format on

  rlSetTexture(0);
}

}  // namespace Vox