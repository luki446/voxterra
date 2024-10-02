#pragma once

#include <cstdint>

#include "raylib.h"

namespace Vox {

enum class BlockType : uint32_t {
  DIRT = 0,

  BLOCK_TYPE_COUNT,
};

class Block {
 public:
  explicit Block(BlockType type);
  void draw_at(Vector3 const& position) const;

 private:
  BlockType type;
};

}  // namespace Vox