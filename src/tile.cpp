///
/// \file tile.cpp
/// \brief Implémentation de la classe Tile
///

#include "../include/tile.h"
#include "../include/spritemanager.h"

using namespace sf;

///
/// \brief Constructeur
/// \param Position cartesian de la tile
///
Tile::Tile(void)
: DrawableObject()
{
}

Tile::~Tile(void)
{
}

///
/// \brief Initialize
///
void Tile::Initialize(const Vector2f & pos, Tile::ETileType tileType)
{
    m_eTileType = tileType;
    m_anim.addState(GetSpriteFromType(), 1);

    SetPos(pos);
    SetOrigin(g_tileSize / 2.f); // default origin 0,0 is left top corner
    //printf("Tile initialization: (%f, %f)\n", m_pos.x, m_pos.y);
}

///
/// \brief Renvoi le type de la case
/// \return Le type ETileType
///
Tile::ETileType Tile::GetType(void)
{
    return(m_eTileType);
}

///
/// \brief Change le type de la case
///
void Tile::SetType(ETileType newType)
{
    m_eTileType = newType;
    m_anim.removeState();
    m_anim.addState(GetSpriteFromType(), 1);
}

sf::Sprite& Tile::GetSpriteFromType()
{
    switch(m_eTileType)
    {
        case ETileType::GROUND:    return(SpriteManager::GetInstance().GetSprite("GROUND_0"));
        case ETileType::ROAD:      return(SpriteManager::GetInstance().GetSprite("ROAD_0"));
        case ETileType::COAL:      return(SpriteManager::GetInstance().GetSprite("ROCK_0"));
        case ETileType::COPPER:    return(SpriteManager::GetInstance().GetSprite("ROCK_0"));
        case ETileType::IRON:      return(SpriteManager::GetInstance().GetSprite("ROCK_0"));
        case ETileType::URANIUM:   return(SpriteManager::GetInstance().GetSprite("ROCK_0"));

        case ETileType::WALL:
        case ETileType::BUILDED:
        default: return(SpriteManager::GetInstance().GetSprite("DEFAULT"));;
    }
}
