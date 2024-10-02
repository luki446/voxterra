#include "world.hpp"

namespace Vox {

World::World() {
  constexpr static int32_t START_POSITION =
      -(static_cast<int32_t>(CHUNK_SIZE) / 2);

  for (int32_t x = 0; x < CHUNK_SIZE; ++x) {
    for (int32_t z = 0; z < CHUNK_SIZE; ++z) {
      const Vector3 position = {static_cast<float>(START_POSITION + x), 0.0f,
                                static_cast<float>(START_POSITION + z)};

      this->blocks_structure.insert({position, Block(BlockType::DIRT)});
    }
  }
}

void World::draw() const {
  for (auto const& [pos, block] : this->blocks_structure) {
    block.draw_at(pos);
  }
}

}  // namespace Vox