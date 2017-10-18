#include "stdafx.h"

using namespace sf;

Vector2f CartesianToIsometric2(Vector2f cartPos)
{
    Vector2f isometricPos;
    isometricPos.x = cartPos.x - cartPos.y;
    isometricPos.y = (cartPos.x + cartPos.y) / 2;

    return(isometricPos);
}

Vector3f CartesianToIsometric3(Vector3f cartPos)
{
    Vector3f isometricPos;
    isometricPos.x = cartPos.x - cartPos.y;
    isometricPos.y = (cartPos.x + cartPos.y) / 2;
    isometricPos.z = cartPos.z;

    return(isometricPos);
}

Vector2f IsometricToCartesian2(Vector2f isoPos)
{
    Vector2f cartesianPos;
    cartesianPos.x = (2 * isoPos.y + isoPos.x) / 2;
    cartesianPos.y = (2 * isoPos.y + isoPos.x) / 2;

    return(cartesianPos);
}

Vector3f IsometricToCartesian3(Vector3f isoPos)
{
    Vector3f cartesianPos;
    cartesianPos.x = (2 * isoPos.y + isoPos.x) / 2;
    cartesianPos.y = (2 * isoPos.y + isoPos.x) / 2;
    cartesianPos.z = isoPos.z;

    return(cartesianPos);
}
