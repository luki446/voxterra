#pragma once

#include "raylib.h"
#include <cstdint>

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

} // namespace Core