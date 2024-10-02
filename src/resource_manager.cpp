#include "resource_manager.hpp"

namespace Vox {

ResourceManager::ResourceManager() { this->load_textures(); }

void ResourceManager::load_textures() {
  this->textures[static_cast<uint32_t>(BlockType::DIRT)] =
      LoadTexture("dirt.png");
}

}  // namespace Vox