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

#endif // STDAFX_H
