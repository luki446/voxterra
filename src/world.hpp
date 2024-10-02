#pragma once

#include <raylib.h>

#include <map>

#include "block.hpp"

namespace Vox {

struct Vector3Comparator {
  constexpr bool operator()(Vector3 const& lhs, Vector3 const& rhs) const {
    return std::tie(lhs.x, lhs.y, lhs.z) < std::tie(rhs.x, rhs.y, rhs.z);
  }
};

using GameMapStructure = std::map<Vector3, Block, Vector3Comparator>;

constexpr inline size_t CHUNK_SIZE = 16;

class World {
 public:
  World();
  void draw() const;

  inline GameMapStructure const& get_blocks_structure() const {
    return this->blocks_structure;
  }

 private:
  GameMapStructure blocks_structure{};
};

}  // namespace Vox