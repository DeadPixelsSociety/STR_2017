#ifndef GAMEBOARD_H
#define GAMEBOARD_H

///
/// \file gameboard.h
/// \brief Header de la classe GameBoard
///

#include "stdafx.h"

class Tile;

///
/// \class GameBoard
/// \brief Gestion du plateau de jeu
///
class GameBoard final: public IInputEvents
{
public:
    explicit    GameBoard   (int width, int height, sf::RenderWindow * pWindow);
                ~GameBoard  (void);

    void        Update      (float dt);

    void        Initialize  (void);

    virtual void    OnMouseRightPressed     (int x, int y) override;
    virtual void    OnMouseRightReleased    (int x, int y) override;

    virtual void    OnMouseLeftPressed      (int x, int y) override;
    virtual void    OnMouseLeftReleased     (int x, int y) override;

    virtual void    OnMouseMoved            (int x, int y) override;

    // DBG
    void    DbgDrawCenter   (void);

private:
    void    InitializeTiles  (void);
    void    InitializeRobots (void);

    Tile&  GetTile   (const sf::Vector2u& vec);
    size_t Vec2Index (const sf::Vector2u& vec) const;

    sf::RenderWindow *   m_pWindow;

    sf::Texture          m_blackBackgroundTexture;
    sf::Sprite           m_blackBackgroundSprite;

    sf::RectangleShape   m_selectionArea;
    bool                 m_bSelectionArea;

    int                  m_iWidth;
    int                  m_iHeight;
    std::vector<Tile>  m_aGameBoard;
//    std::vector<Robot *> m_aRobots;
};

#endif // GAMEBOARD_H
