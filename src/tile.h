#ifndef TILE_H
#define TILE_H

///
/// \file tile.h
/// \brief Header de la classe Tile
///

#include "stdafx.h"

#define TILE_WIDTH 32
#define TILE_HEIGHT 32

///
/// \class Tile
/// \brief Case affichable
///
/// Case servant de base pour l'affichage du terrain isométrique.
/// Possède une texture ainsi qu'un sprite.
/// Sa position peut être obtenue de façon standard ou cartésienne.
///
class Tile
{
public:
    Tile(sf::Vector2f pos);

    void            SetPos              (sf::Vector2f pos);
    sf::Vector2f    GetPos              (void);
    sf::Vector2f    GetCartesianPos     (void);

    sf::Sprite      GetSprite           (void);

private:

    sf::Vector2f m_cartesianPos; // TopDown coord
    sf::Vector2f m_pos;          // Isometric coord

    sf::Texture  m_texture;
    sf::Sprite   m_sprite;
};

#endif // TILE_H
