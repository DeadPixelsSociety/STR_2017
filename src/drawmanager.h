#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

///
/// \file drawmanager.h
/// \brief Header de la classe DrawManager
///

#include <SFML/Graphics.hpp>

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

    void    AddTileSprite       (sf::Sprite * pSprite);
    void    AddBuildingSprite   (sf::Sprite * pSprite);
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

    std::vector<sf::Sprite *>   m_aSpriteList;
    std::vector<sf::Sprite *>   m_aBuildingList;

    // robot: vector<Robots *> and draw each current sprites ?

    // GUI: need to think about this
};

#endif // DRAWMANAGER_H
