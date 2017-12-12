#include "drawableobject.h"

DrawableObject::DrawableObject(void)
{
}

///
/// \brief Draw du sprite
///
/*virtual*/ void DrawableObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(m_drawableSprite, states);
}
