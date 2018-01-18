#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

///
/// \file drawmanager.h
/// \brief Header de la classe DrawManager
///

#include <SFML/Graphics.hpp>

#include "drawableobject.h"

class DrawableObject;

///
/// \class DrawManager
/// \brief Gestion du rendu
///
class DrawManager
{
public:
    DrawManager();

    void    Initialize          (sf::RenderWindow * pWindow);

    void    SetBackground       (sf::Sprite * pSprite);
    void    SetSelectionArea    (sf::RectangleShape * pArea);

    void    IsSelectionArea     (void);

    void    AddTileObject       (DrawableObject * pTile);
    void    AddBuildingObject   (DrawableObject * pBuilding);
    void    AddRobotObject      (DrawableObject * pRobot);
    void    Draw                (void);

private:

    void    DrawTiles       (void);
    void    DrawBuildings   (void);
    void    DrawRobots      (void);
    void    DrawGUI         (void);

private:

    sf::RenderWindow *      m_pWindow;

    sf::Sprite *            m_pBlackBackground;
    sf::RectangleShape *    m_pSelectionArea;

    std::vector<DrawableObject *>   m_aSpriteList;
    std::vector<DrawableObject *>   m_aBuildingList;
    std::vector<DrawableObject *>   m_aRobotList;

    // GUI: need to think about this
};

#endif // DRAWMANAGER_H
