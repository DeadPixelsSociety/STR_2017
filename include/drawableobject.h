#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

///
/// \file drawableobject.h
/// \brief DrawableObject class header
///

#include "stdafx.h"
#include "animation.h"

///
/// \class DrawableObject
/// \brief All drawable object must inherit from this class
///
/// A class that inherit from this must add its animations at initialisation time.
/// An inherited class should not need to care about graphics except at initialisation.
/// The inherited class should use the SetState() method to change the current animation.
///
class DrawableObject : public sf::Drawable
{
    public:

        DrawableObject();

        virtual void draw   (sf::RenderTarget& target, sf::RenderStates states) const override;

        virtual void Update(float dt);

        sf::Vector2f GetPos(void) const;
        void         SetPos(sf::Vector2f pos);

        void         SetOrigin(const sf::Vector2f& origin);

    protected:
        void SetState(std::size_t state);

    protected:
        sf::Vector2f    m_pos;
        Animation       m_anim;
        std::size_t     m_state;

    private:

        sf::Transformable m_transform;

};

#endif // DRAWABLEOBJECT_H
