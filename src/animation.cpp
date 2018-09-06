
///
/// \file animation.cpp
/// \brief Animation class implementation
///

#include <cassert>

#include "../include/animation.h"

Animation::Animation() : m_fCurrentTime(0.0f), m_currentState(0), m_currentStep(0)
{

}

///
/// \brief Add a state
///
/// \param sprite The sprite of the first step of the state.
/// \param duration Duration of the first step in seconds if the state have more than one step.
///
void Animation::addState(sf::Sprite& sprite, float duration)
{
    std::vector<AnimationStep> tmp;
    tmp.emplace_back(AnimationStep(sprite, duration));

    m_states.push_back(std::move(tmp));
}

///
/// \brief Add a step.
///
/// \param stateIndex The index of the state where the step will be added.
/// \param sprite The step sprite
/// \param duration The duration of the step in seconds.
///
void Animation::addStep(std::size_t stateIndex, sf::Sprite& sprite, float duration)
{
    assert(stateIndex < m_states.size());

    m_states[stateIndex].emplace_back(AnimationStep(sprite, duration));
}

///
/// \brief Set the current state.
///
/// The internal timer is reset and the state begin
/// at step 0.
///
/// \param stateIndex The index of the state.
///
void Animation::setState(std::size_t stateIndex)
{
    assert(stateIndex < m_states.size());

    m_currentState = stateIndex;
    m_currentStep = 0;
    m_fCurrentTime = 0.0f;
}

/// \brief Force a step in the current state.
///
/// The internal timer is reset.
///
/// \param stepIndex The index of the step
///
void Animation::setStep(std::size_t stepIndex)
{
    assert(stepIndex < m_states[m_currentState].size());

    m_currentStep = stepIndex;
    m_fCurrentTime = 0.0f;
}

///
/// \brief Remove the last added state.
///
void Animation::removeState(void)
{
    if(!m_states.empty())
    {
        if(m_currentState == m_states.size() - 1 )
        {
            setState(0);
        }

        m_states.pop_back();
    }
}

///
/// \brief Get the actual sprite.
///
/// Get the sprite of the current step.
///
/// \return The sprite.
///
sf::Sprite& Animation::getActualSprite(void) const
{
    return m_states[m_currentState][m_currentStep].sprite;
}

///
/// \brief Update steps.
///
/// \param dt The delta t between two frames
///
void Animation::update(float dt)
{
    if(m_fCurrentTime >= m_states[m_currentState][m_currentStep].stepDuration)
    {
        m_fCurrentTime = 0.0f;
        m_currentStep = (m_currentStep + 1 < m_states[m_currentState].size()) ? m_currentStep + 1 : 0;
    }

    m_fCurrentTime += dt;
}
