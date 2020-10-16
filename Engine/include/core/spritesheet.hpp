#pragma once

#include <cstdarg>
#include <memory>
#include <string>
#include <unordered_map>
#include "nlohmann/json.hpp"

#include "core/resource.hpp"
#include "core/resourcemanager.hpp"
#include "core/texture2D.hpp"
#include "core/spriteinfo.hpp"

namespace engine
{
    class SpriteSheet : public Resource
    {
    private:
        Texture2D *texture;
        int frameCount;
        int frameWidth;
        int frameHeight;
        int rows;
        int columns;

        std::unordered_map<int, std::unique_ptr<SpriteInfo>> sprites;

        const std::unique_ptr<nlohmann::json> loadJsonDocument() const;
        const std::vector<int> createSprites(const nlohmann::json &spritesDocument);
        void createSpriteInformation(const nlohmann::json &spriteInformationsDocument, const std::vector<int> &spriteIds);

    public:
        SpriteSheet() {}
        SpriteSheet(const SpriteSheet &spriteSheet) = delete;
        ~SpriteSheet() {}

        virtual bool loadResource(ResourceManager &resourceManager, va_list args) override;
        virtual void unloadResource() override {}

        const Texture2D *getTexture() const;
        const int getFrameWidth() const;
        const int getFrameHeight() const;

        const SpriteInfo *getSpriteInfo(const int spriteId) const;
    };
} // namespace engine
