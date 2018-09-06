#ifndef TILE_H
#define TILE_H

///
/// \file tile.h
/// \brief Header de la classe Tile
///

#include "stdafx.h"

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

    explicit Tile (void);
    ~Tile(void);

    void            Initialize          (const sf::Vector2f & pos, ETileType tileType);

    ETileType       GetType             (void);
    void            SetType             (ETileType newType);

private:

        sf::Sprite&           GetSpriteFromType();

private:

    ETileType       m_eTileType;

    // TODO: Pointeur sur le building à stocker pour accès rapide au clic
};

#endif // TILE_H
