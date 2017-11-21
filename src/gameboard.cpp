///
/// \file gameboard.cpp
/// \brief Implémentation de la classe GameBoard
///

#include "gameboard.h"
#include "tile.h"

using namespace std;
using namespace sf;

///
/// \brief Constructeur
/// \param Width du plateau
/// \param Height du plateau
/// \param Render Window
///
GameBoard::GameBoard(int width, int height, RenderWindow * pWindow)
: m_iWidth(width)
, m_iHeight(height)
, m_pWindow(pWindow)
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

    m_blackBackgroundTexture.loadFromFile("../resources/fond_noir.png");
    m_blackBackgroundSprite = sf::Sprite(m_blackBackgroundTexture);
    m_blackBackgroundSprite.setPosition(-500.0f, -500.0f);
    m_blackBackgroundSprite.scale(1000.0f, 1000.0f);
    g_drawManager.SetBackground(&m_blackBackgroundSprite);
}

///
/// \brief Update du plateau
/// \param Delta time
///
void GameBoard::Update(float dt)
{
    // Update all elements related to game board
}

//-////////// MOUSE EVENTS :///////////////-//

///
/// \brief GameBoard::OnMouseRightPressed
/// \param x
/// \param y
///
void GameBoard::OnMouseRightPressed(int x, int y)
{

}

///
/// \brief GameBoard::OnMouseRightReleased
/// \param x
/// \param y
///
void GameBoard::OnMouseRightReleased(int x, int y)
{
    // give order to selected robots
}

///
/// \brief GameBoard::OnMouseLeftPressed
/// \param x
/// \param y
///
void GameBoard::OnMouseLeftPressed(int x, int y)
{
    // begin selection area
    Vector2f map = m_pWindow->mapPixelToCoords(Vector2i(x,y), *g_cameraManager.GetCamera());
    printf("%f, %f\n", map.x, map.y);
}

///
/// \brief GameBoard::OnMouseLeftReleased
/// \param x
/// \param y
///
void GameBoard::OnMouseLeftReleased(int x, int y)
{
    // end selection area
}

///
/// \brief GameBoard::OnMouseMoved
/// \param x
/// \param y
///
void GameBoard::OnMouseMoved(int x, int y)
{
    // continue selection area
}


// Debug function
void GameBoard::DbgDisplayGrid(bool cartesian /* = true */)
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
            m_pWindow->draw(tileShape);
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
            m_pWindow->draw(tilePoint);
        }
    }
}

// Debug function
void GameBoard::DbgDrawCenter(void)
{
    sf::RectangleShape tileShape = sf::RectangleShape(sf::Vector2f(5, 5));
    tileShape.setPosition(0,0);
    tileShape.setOrigin(2.5, 2.5);
    m_pWindow->draw(tileShape);
}
