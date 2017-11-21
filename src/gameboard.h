#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "stdafx.h"

class Tile;

class GameBoard final: public IInputEvents
{
public:
    GameBoard(int width, int height, sf::RenderWindow * pWindow);

    void    Update  (float dt);

    virtual void    OnMouseRightPressed     (int x, int y) override;
    virtual void    OnMouseRightReleased    (int x, int y) override;

    virtual void    OnMouseLeftPressed      (int x, int y) override;
    virtual void    OnMouseLeftReleased     (int x, int y) override;

    virtual void    OnMouseMoved            (int x, int y) override;

    // DBG
    void    DbgDisplayGrid  (bool cartesian = true);
    void    DbgDrawCenter   (void);

private:

    sf::RenderWindow *  m_pWindow;

    sf::Texture         m_blackBackgroundTexture;
    sf::Sprite          m_blackBackgroundSprite;

    int                 m_iWidth;
    int                 m_iHeight;
    std::vector<std::vector<Tile *>> m_aGameBoard;
};

#endif // GAMEBOARD_H
