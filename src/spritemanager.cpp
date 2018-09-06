
///
/// \file spritemanager.cpp
/// \brief SpriteManager class implementation
///

#include <SFML/Graphics/Texture.hpp>

#include "../include/spritemanager.h"

///
/// \brief Load all sprites and textures.
///
SpriteManager::SpriteManager(void)
{
    m_spriteMap["DEFAULT"] = sf::Sprite();
    AddSpriteSheet("../resources/robot.png", "ROBOT", 4);
    AddSpriteSheet("../resources/ground.png", "GROUND", 1);
    AddSpriteSheet("../resources/road.png", "ROAD", 1);
    //TODO Load all sprite into the map and all textures into vector
}

///
/// \brief Return the singleton instance.
///
/// \return Unique instance of SpriteManager.
///
SpriteManager& SpriteManager::GetInstance(void)
{
    static SpriteManager instance;

    return instance;
}

///
/// \brief Return a sprite by its name.
///
/// \param spriteName The name of the sprite to get.
///
/// \return The desired sprite if it exists, default sprite otherwise.
///
sf::Sprite& SpriteManager::GetSprite(const std::string& spriteName)
{
    auto it = m_spriteMap.find(spriteName);

    if(it != m_spriteMap.end())
    {
        return it->second;
    }

    return m_spriteMap["DEFAULT"];
}

///
/// \brief Load and add a sprite sheet.
///
/// \param path The path to the sprite sheet.
/// \param spName The name that will be given to sprites, it will by suffixed by number starting at 0.
/// \param spNumber The number of sprites on the sprite sheet.
///
void SpriteManager::AddSpriteSheet(const std::string& path, const std::string& spName, unsigned int spNumber)
{
    auto text = new sf::Texture;

    if(text->loadFromFile(path))
    {
        m_textureVector.push_back(text);

        sf::Vector2u textSize = text->getSize();
        textSize.y /= spNumber;

        sf::IntRect textureClip(0, 0, textSize.x, textSize.y);

        for(unsigned int i = 0; i < spNumber; ++i)
        {
            std::string spriteName = spName + "_" + std::to_string(i);
            m_spriteMap[spriteName] = sf::Sprite(*text);
            m_spriteMap[spriteName].setTextureRect(textureClip);

            textureClip.top += textSize.y;
        }
    }
}

SpriteManager::~SpriteManager(void)
{
    for(sf::Texture* t : m_textureVector)
    {
        delete t;
    }
}
