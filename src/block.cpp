#include "block.hpp"

#include <raylib.h>
#include <rlgl.h>

#include "resource_manager.hpp"

namespace Core {

Block::Block() { position = {0.0f, 0.0f, 0.0f}; }

Block& Block::at(Vector3 const& position) {
  this->position = position;
  return *this;
}

void Block::draw() const {
  const float x = position.x;
  const float y = position.y;
  const float z = position.z;

  constexpr static float width = 1.0f;
  constexpr static float height = 1.0f;
  constexpr static float length = 1.0f;

  constexpr static Color color = RAYWHITE;

  rlSetTexture(ResourceManager::get_instance()
                   .textures[static_cast<uint32_t>(BlockType::DIRT)]
                   .id);

  // clang-format off
  rlBegin(RL_QUADS);
    rlColor4ub(color.r, color.g, color.b, color.a);

    // Front Face
    rlNormal3f(0.0f, 0.0f, 1.0f);  // Normal Pointing Towards Viewer
    rlTexCoord2f(0.0f, 0.0f);
    rlVertex3f(x - width / 2, y - height / 2, z + length / 2);
    rlTexCoord2f(1.0f, 0.0f);
    rlVertex3f(x + width / 2, y - height / 2, z + length / 2);
    rlTexCoord2f(1.0f, 1.0f);
    rlVertex3f(x + width / 2, y + height / 2, z + length / 2);
    rlTexCoord2f(0.0f, 1.0f);
    rlVertex3f(x - width / 2, y + height / 2, z + length / 2);
    // Back Face
    rlNormal3f(0.0f, 0.0f, -1.0f);  // Normal Pointing Away From Viewer
    rlTexCoord2f(1.0f, 0.0f);
    rlVertex3f(x - width / 2, y - height / 2, z - length / 2);
    rlTexCoord2f(1.0f, 1.0f);
    rlVertex3f(x - width / 2, y + height / 2, z - length / 2);
    rlTexCoord2f(0.0f, 1.0f);
    rlVertex3f(x + width / 2, y + height / 2, z - length / 2);
    rlTexCoord2f(0.0f, 0.0f);
    rlVertex3f(x + width / 2, y - height / 2, z - length / 2);
    // Top Face
    rlNormal3f(0.0f, 1.0f, 0.0f);  // Normal Pointing Up
    rlTexCoord2f(0.0f, 1.0f);
    rlVertex3f(x - width / 2, y + height / 2, z - length / 2);
    rlTexCoord2f(0.0f, 0.0f);
    rlVertex3f(x - width / 2, y + height / 2, z + length / 2);
    rlTexCoord2f(1.0f, 0.0f);
    rlVertex3f(x + width / 2, y + height / 2, z + length / 2);
    rlTexCoord2f(1.0f, 1.0f);
    rlVertex3f(x + width / 2, y + height / 2, z - length / 2);
    // Bottom Face
    rlNormal3f(0.0f, -1.0f, 0.0f);  // Normal Pointing Down
    rlTexCoord2f(1.0f, 1.0f);
    rlVertex3f(x - width / 2, y - height / 2, z - length / 2);
    rlTexCoord2f(0.0f, 1.0f);
    rlVertex3f(x + width / 2, y - height / 2, z - length / 2);
    rlTexCoord2f(0.0f, 0.0f);
    rlVertex3f(x + width / 2, y - height / 2, z + length / 2);
    rlTexCoord2f(1.0f, 0.0f);
    rlVertex3f(x - width / 2, y - height / 2, z + length / 2);
    // Right face
    rlNormal3f(1.0f, 0.0f, 0.0f);  // Normal Pointing Right
    rlTexCoord2f(1.0f, 0.0f);
    rlVertex3f(x + width / 2, y - height / 2, z - length / 2);
    rlTexCoord2f(1.0f, 1.0f);
    rlVertex3f(x + width / 2, y + height / 2, z - length / 2);
    rlTexCoord2f(0.0f, 1.0f);
    rlVertex3f(x + width / 2, y + height / 2, z + length / 2);
    rlTexCoord2f(0.0f, 0.0f);
    rlVertex3f(x + width / 2, y - height / 2, z + length / 2);
    // Left Face
    rlNormal3f(-1.0f, 0.0f, 0.0f);  // Normal Pointing Left
    rlTexCoord2f(0.0f, 0.0f);
    rlVertex3f(x - width / 2, y - height / 2, z - length / 2);
    rlTexCoord2f(1.0f, 0.0f);
    rlVertex3f(x - width / 2, y - height / 2, z + length / 2);
    rlTexCoord2f(1.0f, 1.0f);
    rlVertex3f(x - width / 2, y + height / 2, z + length / 2);
    rlTexCoord2f(0.0f, 1.0f);
    rlVertex3f(x - width / 2, y + height / 2, z - length / 2);
  rlEnd();
  // clang-format on

  rlSetTexture(0);
}

}  // namespace Core