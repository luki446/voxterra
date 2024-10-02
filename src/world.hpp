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

constexpr inline size_t CHUNK_SIZE = 16;

class World {
 public:
  World();
  void draw() const;

 private:
  std::map<Vector3, Block, Vector3Comparator> blocks_structure{};
};

}  // namespace Vox