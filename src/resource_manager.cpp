#include "resource_manager.hpp"
#include <raylib.h>
#include <cstdint>
#include "block.hpp"

namespace Vox {

ResourceManager::ResourceManager() { this->load_textures(); }

void ResourceManager::load_textures() {
  this->textures[static_cast<uint32_t>(BlockType::DIRT)] =
      LoadTexture("dirt.png");
  this->textures[static_cast<uint32_t>(BlockType::COBBLE)] = LoadTexture("cobble.png");
  this->textures[static_cast<uint32_t>(BlockType::WOOD)] = LoadTexture("wood.png");
  this->textures[static_cast<uint32_t>(BlockType::BRICKS)] = LoadTexture("bricks.png");
}

}  // namespace Vox