#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include "stdafx.h"

class DrawableObject : public sf::Drawable
{
public:
    DrawableObject      (void);

    virtual void draw   (sf::RenderTarget& target, sf::RenderStates states) const override;

protected:

    //TODO check if it's ok for robot class to have a simple object for currentSprite
    sf::Sprite  m_drawableSprite;
};

#endif // DRAWABLEOBJECT_H
