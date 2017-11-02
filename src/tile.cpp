
///                                             ///
/// \file tile.cpp                              ///
/// \brief Implémentation de la classe Tile     ///
///                                             ///

#include "tile.h"

using namespace sf;

Tile::Tile(Vector2f pos)
: m_cartesianPos(pos)
{
    m_pos = CartesianToIsometric2(pos);
    m_texture.loadFromFile("../resources/tile.png");
    m_sprite = Sprite(m_texture);
    m_sprite.setPosition(m_pos);
    m_sprite.setOrigin(TILE_WIDTH , TILE_HEIGHT / 2); // default origin 0,0 is left top corner
    g_drawManager.AddTileSprite(&m_sprite);
    printf("%f, %f / %f, %f\n", pos.x, pos.y, m_pos.x, m_pos.y);
}

///
/// \brief Règle la position de la case
/// \param pos La position en coordonnées isométrique
///

void Tile::SetPos(Vector2f pos)
{
    m_pos = pos;
}

///
/// \brief Renvoi la position de la case
/// \return La position en coordonnées isométrique
///

Vector2f Tile::GetPos(void)
{
    return(m_pos);
}

///
/// \brief Renvoi la position de la case en coordonnées cartésiennes
/// \return La position en coordonnées cartésiennes
///

Vector2f Tile::GetCartesianPos(void)
{
    return(m_cartesianPos);
}

///
/// \brief Renvoi le sprite de la case
/// \return Le sprite
///

Sprite Tile::GetSprite(void)
{
    return(m_sprite);
}
