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

void Tile::SetPos(Vector2f pos)
{
    m_pos = pos;
}

Vector2f Tile::GetPos()
{
    return(m_pos);
}

Vector2f Tile::GetCartesianPos()
{
    return(m_cartesianPos);
}

Sprite Tile::GetSprite(void)
{
    return(m_sprite);
}
