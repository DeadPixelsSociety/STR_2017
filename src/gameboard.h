#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "stdafx.h"
#include "tile.h"

class GameBoard
{
public:
    GameBoard(int width, int height);

    void    DbgDisplayGrid (sf::RenderWindow & window, bool cartesian = true);

private:
    int m_iWidth;
    int m_iHeight;
    std::vector<std::vector<Tile *>> m_aGameBoard;
};

#endif // GAMEBOARD_H
