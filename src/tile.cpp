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
Tile::Tile(void)
: DrawableObject(1)
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
    SetPos(pos);
    LoadTexture(GetFileTextureFromType());
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
    LoadTexture(GetFileTextureFromType());
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
