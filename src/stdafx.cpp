///
/// \file stdafx.cpp
/// \brief Implémentations des fonctions usuelles
///

#include "../include/stdafx.h"

#include <cmath>

using namespace sf;

///
/// \brief Transforme une coordonnée 2d cartésienne en coordonnée 2d isométrique
/// \return Coordonnée 2d isométrique
///
Vector2f CartesianToIsometric2(Vector2f cartPos)
{
    Vector2f isometricPos;
    isometricPos.x = g_tileSize.x * (cartPos.x - cartPos.y);
    isometricPos.y = g_tileSize.y * (cartPos.x + cartPos.y) / 2.f;

    return(isometricPos);
}

///
/// \brief Transforme une coordonnée 3d cartésienne en coordonnée 3d isométrique
/// \return Coordonnée 3d isométrique
///
Vector3f CartesianToIsometric3(Vector3f cartPos)
{
    Vector3f isometricPos;
    isometricPos.x = g_tileSize.x * (cartPos.x - cartPos.y);
    isometricPos.y = g_tileSize.y * (cartPos.x + cartPos.y) / 2.f;
    isometricPos.z = cartPos.z;

    return(isometricPos);
}

///
/// \brief Transforme une coordonnée 2d isométrique en coordonnée 2d cartésienne
/// \return Coordonnée 2d cartésienne
///
Vector2f IsometricToCartesian2(Vector2f isoPos)
{
    Vector2f cartesianPos;
    cartesianPos.x = isoPos.y / g_tileSize.y + isoPos.x / g_tileSize.x;
    cartesianPos.y = isoPos.y / g_tileSize.y - isoPos.x / g_tileSize.x;

    return(cartesianPos);
}

///
/// \brief Transforme une coordonnée 3d isométrique en coordonnée 3d cartésienne
/// \return Coordonnée 3d cartésienne
///
Vector3f IsometricToCartesian3(Vector3f isoPos)
{
    Vector3f cartesianPos;
    cartesianPos.x = isoPos.y / g_tileSize.y + isoPos.x / g_tileSize.x;
    cartesianPos.y = isoPos.y / g_tileSize.y - isoPos.x / g_tileSize.x;
    cartesianPos.z = isoPos.z;

    return(cartesianPos);
}
