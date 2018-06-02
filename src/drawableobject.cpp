#include "drawableobject.h"

#include <cassert>

DrawableObject::DrawableObject(vecsize_t nStates)
: m_aSpriteStates(nStates)
, m_pCurrentSpr2Draw(nullptr)
, m_textureSize(0, 0)
, m_uNStates(nStates)
{
    assert(m_uNStates > 0);

    for (sf::Sprite& spr : m_aSpriteStates)
    {
        spr.setTexture(m_spriteSheet);
    }

    SetState(0);
}

///
/// \brief Draw du sprite
///
/*virtual*/ void DrawableObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    states.transform *= m_transform.getTransform();
    target.draw(*m_pCurrentSpr2Draw, states);
}

sf::Vector2f DrawableObject::GetPos(void) const
{
    return m_pos;
}

void DrawableObject::SetPos(sf::Vector2f pos)
{
    m_pos = pos;
    pos = CartesianToIsometric2(pos);
    m_transform.setPosition(pos.x / 2.f, pos.y);
}

void DrawableObject::SetOrigin(const sf::Vector2f& origin)
{
    m_transform.setOrigin(origin);
}


void DrawableObject::SetState(vecsize_t state)
{
    assert(state < m_uNStates);

    m_pCurrentSpr2Draw = &m_aSpriteStates[state];
}

bool DrawableObject::LoadTexture(const std::string& filename)
{
    bool res = m_spriteSheet.loadFromFile(filename);
    m_textureSize = m_spriteSheet.getSize();
    m_textureSize.y /= m_uNStates;

    sf::IntRect textureClip(0, 0, m_textureSize.x, m_textureSize.y);
    for (sf::Sprite& spr : m_aSpriteStates)
    {
        spr.setTextureRect(textureClip);
        textureClip.top += m_textureSize.y;
    }

    return res;
}
