#pragma once

#include <array>

#include "block.hpp"
#include <raylib.h>

namespace Core {

class ResourceManager {
public:
    static ResourceManager& get_instance() {
        static ResourceManager instance;
        return instance;
    }

    std::array<Texture2D, static_cast<uint32_t>(BlockType::BLOCK_TYPE_COUNT)> textures;
private:
    ResourceManager();
    ResourceManager(ResourceManager const&) = delete;
    ResourceManager(ResourceManager&&) = delete;
    ResourceManager& operator=(ResourceManager const&) = delete;
    ResourceManager& operator=(ResourceManager&&) = delete;

    void load_textures();
};

} // namespace Core