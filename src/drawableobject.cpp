#include "../include/drawableobject.h"

#include <cassert>

DrawableObject::DrawableObject() : m_state(0)
{
}

///
/// \brief Object draw.
///
/// An inherited class shouldn't override this method
/// except if you know what you're doing.
///
/// \param target The render target.
/// \param states The render states.
///
/*virtual*/ void DrawableObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    states.transform *= m_transform.getTransform();
    target.draw(m_anim.getActualSprite(), states);
}

///
/// \brief Return the current object position.
///
/// \return The position.
///
sf::Vector2f DrawableObject::GetPos(void) const
{
    return m_pos;
}

///
/// \brief Set the new object position.
///
/// \param pos The new position.
///
void DrawableObject::SetPos(sf::Vector2f pos)
{
    m_pos = pos;
    pos = CartesianToIsometric2(pos);
    m_transform.setPosition(pos.x / 2.f, pos.y);
}

///
/// \brief Set the new object origin.
///
/// \param origin the new origin.
///
void DrawableObject::SetOrigin(const sf::Vector2f& origin)
{
    m_transform.setOrigin(origin);
}

///
/// \brief Set the new animation state.
///
/// \param state The state index.
///
void DrawableObject::SetState(std::size_t state)
{
    m_anim.setState(state);
    m_state = state;
}

///
/// \brief Update the animation.
///
/// If this function is overriden in a derivated class
/// it must be called in the overriding method otherwise
/// animation won't works.
///
/// \param dt The delta t between frames.
///
void DrawableObject::Update(float dt)
{
    m_anim.update(dt);
}
