#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include "stdafx.h"

class DrawableObject : public sf::Drawable
{
public:
    using vecsize_t = std::vector<sf::Sprite>::size_type;

    DrawableObject      (vecsize_t nStates);

    virtual void draw   (sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::Vector2f GetPos(void) const;
    void         SetPos(sf::Vector2f pos);

    void         SetOrigin(const sf::Vector2f& origin);

protected:
    void SetState(vecsize_t state);
    bool LoadTexture(const std::string& filename);

    // TODO: Replace sprites with animations
    std::vector<sf::Sprite>  m_aSpriteStates;
    sf::Vector2f m_pos;

private:
    sf::Sprite *             m_pCurrentSpr2Draw;
    sf::Texture              m_spriteSheet;
    sf::Vector2u             m_textureSize;

    sf::Transformable        m_transform;

    const vecsize_t          m_uNStates;
};

#endif // DRAWABLEOBJECT_H
