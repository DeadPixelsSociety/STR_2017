#ifndef TILE_H
#define TILE_H

#include "stdafx.h"

#define TILE_WIDTH 64
#define TILE_HEIGHT 64

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
