#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "stdafx.h"

class Tile;

class GameBoard: public IInputEvents
{
public:
    GameBoard(int width, int height);

    void    Update  (float dt);

    void    DbgDisplayGrid (sf::RenderWindow & window, bool cartesian = true);

    virtual void    OnMouseRightPressed     (int x, int y) override;
    virtual void    OnMouseRightReleased    (int x, int y) override;

    virtual void    OnMouseLeftPressed      (int x, int y) override;
    virtual void    OnMouseLeftReleased     (int x, int y) override;

    virtual void    OnMouseMoved            (int x, int y) override;

private:
    int m_iWidth;
    int m_iHeight;
    std::vector<std::vector<Tile *>> m_aGameBoard;
};

#endif // GAMEBOARD_H
