#include "world.hpp"
#include <raylib.h>
#include <cmath>

namespace Vox {

World::World() {
  constexpr static int32_t START_POSITION = 0;

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

std::optional<Vector3> World::is_block_at(Vector3 const& position) const {
  const Vector3 position_rounded = {roundf(position.x), roundf(position.y),
                                    roundf(position.z)};

  if(this->blocks_structure.find(position_rounded) != this->blocks_structure.end()) {
    return position_rounded;
  } else {
    return {};
  }
}

void World::place_block(Vector3 position, BlockType type) {
  this->blocks_structure.insert({position, Block{type}});
}

}  // namespace Vox