#ifndef STDAFX_H
#define STDAFX_H

///
/// \file stdafx.h
/// \brief Définition des fonctions usuelles et déclaration de la classe IInputEvents
///

//
// Common includes
#include <iostream>

//
// SFML
#include <SFML/Graphics.hpp>

//
// Game includes
#include "drawerobject.h"
#include "cameramanager.h"
#include "drawableobject.h"

//
// Global definitions
extern  CameraManager   g_cameraManager;

const sf::Vector2f  g_tileSize(128.f, 64.f);

//
// Common functions
sf::Vector2f CartesianToIsometric2(sf::Vector2f cartPos);
sf::Vector3f CartesianToIsometric3(sf::Vector3f cartPos);
sf::Vector2f IsometricToCartesian2(sf::Vector2f isoPos);
sf::Vector3f IsometricToCartesian3(sf::Vector3f isoPos);

//
// Common Interfaces

///
/// \class IInputEvents
/// \brief Interface pour les entrées souris
///
class IInputEvents
{
    virtual void    OnMouseRightPressed     (int x, int y) = 0;
    virtual void    OnMouseRightReleased    (int x, int y) = 0;

    virtual void    OnMouseLeftPressed      (int x, int y) = 0;
    virtual void    OnMouseLeftReleased     (int x, int y) = 0;

    virtual void    OnMouseMoved            (int x, int y) = 0;
};

#endif // STDAFX_H
