#ifndef STR_2017_SPRITEMANAGER_H
#define STR_2017_SPRITEMANAGER_H

///
/// \file spritemanager.h
/// \brief SpriteManager class header
///

#include <unordered_map>
#include <vector>

#include <SFML/Graphics/Sprite.hpp>


///
/// \class SpriteManager
/// \brief Handle sprites
///
/// This singleton store one instance of all sprites
/// to avoid duplications.
///
class SpriteManager
{
    public:
        static SpriteManager&   GetInstance(void);

        sf::Sprite&             GetSprite(const std::string& spriteName);

    private:
        SpriteManager(void);

        void AddSpriteSheet(const std::string& path, const std::string& spName, unsigned int spNumber);

    private:
        std::unordered_map<std::string, sf::Sprite> m_spriteMap;
        std::vector<sf::Texture> m_textureVector;

};

#endif //STR_2017_SPRITEMANAGER_H
