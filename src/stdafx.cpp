///
/// \file stdafx.cpp
/// \brief Implémentations des fonctions usuelles
///

#include "stdafx.h"

using namespace sf;

///
/// \brief Transforme une coordonnée 2d cartésienne en coordonnée 2d isométrique
/// \return Coordonnée 2d isométrique
///
Vector2f CartesianToIsometric2(Vector2f cartPos)
{
    Vector2f isometricPos;
    isometricPos.x = cartPos.x - cartPos.y;
    isometricPos.y = (cartPos.x + cartPos.y) / 2;

    return(isometricPos);
}

///
/// \brief Transforme une coordonnée 3d cartésienne en coordonnée 3d isométrique
/// \return Coordonnée 3d isométrique
///
Vector3f CartesianToIsometric3(Vector3f cartPos)
{
    Vector3f isometricPos;
    isometricPos.x = cartPos.x - cartPos.y;
    isometricPos.y = (cartPos.x + cartPos.y) / 2;
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
    cartesianPos.x = (2 * isoPos.y + isoPos.x) / 2;
    cartesianPos.y = (2 * isoPos.y + isoPos.x) / 2;

    return(cartesianPos);
}

///
/// \brief Transforme une coordonnée 3d isométrique en coordonnée 3d cartésienne
/// \return Coordonnée 3d cartésienne
///
Vector3f IsometricToCartesian3(Vector3f isoPos)
{
    Vector3f cartesianPos;
    cartesianPos.x = (2 * isoPos.y + isoPos.x) / 2;
    cartesianPos.y = (2 * isoPos.y + isoPos.x) / 2;
    cartesianPos.z = isoPos.z;

    return(cartesianPos);
}
