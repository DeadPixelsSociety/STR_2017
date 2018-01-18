///
/// \file tile.cpp
/// \brief Implémentation de la classe Tile
///

#include "tile.h"

using namespace sf;

///
/// \brief Constructeur
/// \param Position cartesian de la tile
///
Tile::Tile(const Vector2f & pos, Tile::ETileType tileType)
: m_eTileType(tileType)
, m_cartesianPos(pos)
{
}

///
/// \brief Initialize
///
void Tile::Initialize()
{
    m_pos = CartesianToIsometric2(m_cartesianPos);
    m_texture.loadFromFile(GetFileTextureFromType());
    m_drawableSprite = Sprite(m_texture);
    m_drawableSprite.setPosition(m_pos);
    m_drawableSprite.setOrigin(TILE_WIDTH / 2 , TILE_HEIGHT / 2); // default origin 0,0 is left top corner
    g_drawManager.AddTileObject(this);
    printf("%f, %f / %f, %f\n", m_cartesianPos.x, m_cartesianPos.y, m_pos.x, m_pos.y);
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
    m_texture.loadFromFile(GetFileTextureFromType());
    m_drawableSprite = Sprite(m_texture);
    m_drawableSprite.setPosition(m_pos);
    m_drawableSprite.setOrigin(TILE_WIDTH / 2 , TILE_HEIGHT / 2); // default origin 0,0 is left top corner
}

///
/// \brief Renvoi la position de la case
/// \return La position en coordonnées isométrique
///
Vector2f & Tile::GetPos(void)
{
    return(m_pos);
}

///
/// \brief Renvoi la position de la case en coordonnées cartésiennes
/// \return La position en coordonnées cartésiennes
///
Vector2f & Tile::GetCartesianPos(void)
{
    return(m_cartesianPos);
}

///
/// \brief Renvoi le path de la texture correspondant au type
/// \return Le path vers la ressource correspondante
///
const char * Tile::GetFileTextureFromType()
{
    switch(m_eTileType)
    {
        case ETileType::GROUND:    return("../resources/ground.png");
        case ETileType::ROAD:      return("../resources/road.png");
        case ETileType::COAL:      return("../resources/rock.png");
        case ETileType::COPPER:    return("../resources/rock.png");
        case ETileType::IRON:      return("../resources/rock.png");
        case ETileType::URANIUM:   return("../resources/rock.png");

        case ETileType::WALL:
        case ETileType::BUILDED:
        default: return("../resources/nosprite_error.png");;
    }
}
