#ifndef STDAFX_H
#define STDAFX_H

//
// Common includes
#include <iostream>

//
// SFML
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

//
// Game includes
#include "drawmanager.h"

//
// Global definitions
extern DrawManager g_drawManager;

//
// Common functions
sf::Vector2f CartesianToIsometric2(sf::Vector2f cartPos);
sf::Vector3f CartesianToIsometric3(sf::Vector3f cartPos);
sf::Vector2f IsometricToCartesian2(sf::Vector2f isoPos);
sf::Vector3f IsometricToCartesian3(sf::Vector3f isoPos);

//
// Common Interfaces
class IInputEvents
{
    virtual void    OnMouseRightPressed     (int x, int y) = 0;
    virtual void    OnMouseRightReleased    (int x, int y) = 0;

    virtual void    OnMouseLeftPressed      (int x, int y) = 0;
    virtual void    OnMouseLeftReleased     (int x, int y) = 0;

    virtual void    OnMouseMoved            (int x, int y) = 0;
};

#endif // STDAFX_H
