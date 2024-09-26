#pragma once

#include <cstdint>

#include "raylib.h"

namespace Core {

enum class BlockType : uint32_t {
  DIRT = 0,

  BLOCK_TYPE_COUNT,
};

class Block {
 public:
  Block();
  Block& at(Vector3 const& position);
  void draw() const;

 private:
  Vector3 position;
};

}  // namespace Core