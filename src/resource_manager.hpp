#pragma once

#include <raylib.h>

#include <array>

#include "block.hpp"

namespace Vox {

class ResourceManager {
 public:
  static ResourceManager& get_instance() {
    static ResourceManager instance;
    return instance;
  }

  std::array<Texture2D, static_cast<uint32_t>(BlockType::BLOCK_TYPE_COUNT)>
      textures;

 private:
  ResourceManager();
  ResourceManager(ResourceManager const&) = delete;
  ResourceManager(ResourceManager&&) = delete;
  ResourceManager& operator=(ResourceManager const&) = delete;
  ResourceManager& operator=(ResourceManager&&) = delete;

  void load_textures();
};

}  // namespace Vox