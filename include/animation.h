#ifndef STR_2017_ANIMATION_H
#define STR_2017_ANIMATION_H

///
/// \file animation.h
/// \brief Animation class header
///

#include <vector>

#include <SFML/Graphics/Sprite.hpp>

///
/// \class Animation
/// \brief Handle sprites for animations.
///
/// A state can have one or more step, by default
/// when you add a state one step is created, its a static
/// animation. You can add more step to a state to create
/// pretty animation, the class automatically handle step
/// transition.
///
class Animation
{
    private : struct AnimationStep
    {
        sf::Sprite& sprite;
        float stepDuration;

        AnimationStep(sf::Sprite& sp, float duration) : sprite(sp), stepDuration(duration){};
    };

    public:
        Animation();

        void            addState        (sf::Sprite& sprite, float duration);

        void            addStep         (std::size_t stateIndex, sf::Sprite& sprite, float duration);

        void            setState        (std::size_t stateIndex);

        void            setStep         (std::size_t stepIndex);

        void            removeState     (void);

        sf::Sprite&     getActualSprite (void) const;

        void            update          (float dt);

    private:
        std::vector<std::vector<AnimationStep> > m_states;

        float       m_fCurrentTime;
        std::size_t m_currentState;
        std::size_t m_currentStep;
};

#endif //STR_2017_ANIMATION_H
