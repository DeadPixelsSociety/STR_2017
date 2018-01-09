#ifndef TILE_H
#define TILE_H

///
/// \file tile.h
/// \brief Header de la classe Tile
///

#include "stdafx.h"

#define TILE_WIDTH 128
#define TILE_HEIGHT 64

///
/// \class Tile
/// \brief Case affichable
///
/// Case servant de base pour l'affichage du terrain isométrique.
/// Possède une texture ainsi qu'un sprite.
/// Sa position peut être obtenue de façon standard ou cartésienne.
///
class Tile : public DrawableObject
{
public:

    enum class ETileType
    {
        GROUND,     // Default type
        ROAD,
        WALL,       // Every blocker block
        BUILDED,
        COAL,
        COPPER,
        IRON,
        URANIUM
    };

    explicit Tile (const sf::Vector2f & pos, ETileType tileType);

    void            Initialize          (void);

    ETileType       GetType             (void);
    void            SetType             (ETileType newType);

    sf::Vector2f &  GetPos              (void);
    sf::Vector2f &  GetCartesianPos     (void);

private:

    const char *          GetFileTextureFromType();

private:

    ETileType       m_eTileType;
    sf::Vector2f    m_cartesianPos; // TopDown coord
    sf::Vector2f    m_pos;          // Isometric coord

    sf::Texture     m_texture;
    // Pointeur sur le building à stocker pour accès rapide au clic
};

#endif // TILE_H
