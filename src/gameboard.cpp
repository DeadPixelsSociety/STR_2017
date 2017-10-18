#include "gameboard.h"

using namespace std;
using namespace sf;

GameBoard::GameBoard(int width, int height)
: m_iWidth(width)
, m_iHeight(height)
{
    Vector2f tilePos(0.0f, 0.0f);
    for (int i = 0; i < m_iWidth; ++i)
    {
        vector<Tile *> raw;
        for (int j = 0; j < m_iHeight; ++j)
        {
            raw.push_back(new Tile(tilePos));
            tilePos.x += TILE_WIDTH;
        }
        m_aGameBoard.push_back(raw);
        tilePos.y += TILE_HEIGHT;
        tilePos.x = 0.0f;
    }
}

void GameBoard::DbgDisplayGrid(RenderWindow & window, bool cartesian /* = true */)
{
    for (int i = 0; i < m_iWidth; ++i)
    {
        for (int j = 0; j < m_iHeight; ++j)
        {
            Vector2f pos;
            if (cartesian)
            {
                // pos is left top corner
                pos = m_aGameBoard[i][j]->GetCartesianPos();
            }
            else
            {
                // pos is top one corner
                pos = m_aGameBoard[i][j]->GetPos();
            }

            RectangleShape tileShape = RectangleShape(Vector2f(TILE_WIDTH, TILE_HEIGHT));
            tileShape.setPosition(pos);
            tileShape.setOutlineThickness(5);
            tileShape.setOutlineColor(sf::Color(250, 150, 100));
            tileShape.setOrigin(TILE_WIDTH / 2, TILE_HEIGHT / 2);
            window.draw(tileShape);
        }
    }

    for (int i = 0; i < m_iWidth; ++i)
    {
        for (int j = 0; j < m_iHeight; ++j)
        {
            Vector2f pos;
            if (cartesian)
            {
                pos  = m_aGameBoard[i][j]->GetCartesianPos();
            }
            else
            {
                pos = m_aGameBoard[i][j]->GetPos();
            }

            CircleShape tilePoint = CircleShape(5);
            tilePoint.setPosition(pos);
            tilePoint.setFillColor(sf::Color(250, 0, 0));
            tilePoint.setOrigin(TILE_WIDTH / 2, TILE_HEIGHT / 2);
            window.draw(tilePoint);
        }
    }
}
