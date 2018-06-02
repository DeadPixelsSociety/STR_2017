///
/// \file gameboard.cpp
/// \brief Implémentation de la classe GameBoard
///

#include "gameboard.h"
#include "tile.h"

#include <iostream>
#include <cmath>

using namespace std;
using namespace sf;

///
/// \brief Constructeur
/// \param Width du plateau
/// \param Height du plateau
/// \param Render Window
///
GameBoard::GameBoard(int width, int height, RenderWindow * pWindow)
: m_pWindow(pWindow)
, m_selectionArea(RectangleShape())
, m_bSelectionArea(false)
, m_iWidth(width)
, m_iHeight(height)
, m_aGameBoard(m_iWidth * m_iHeight)
{
}

GameBoard::~GameBoard(void)
{
//    for (Robot * r : m_aRobots)
//    {
//        delete r;
//    }
}

void GameBoard::Initialize(void)
{
    InitializeTiles();
//    InitializeRobots();
}

void GameBoard::InitializeTiles(void)
{
    Vector2f tilePos(0.0f, 0.0f);
    for (int i = 0; i < m_iHeight; ++i)
    {
        for (int j = 0; j < m_iWidth; ++j)
        {
            m_aGameBoard[Vec2Index(sf::Vector2u(j, i))].Initialize(tilePos, Tile::ETileType::GROUND);
            ++tilePos.x;
        }
        ++tilePos.y;
        tilePos.x = 0.0f;
    }
}

//void GameBoard::InitializeRobots(void)
//{
//    Robot * r = new Robot(this, .0f, .0f);
//    g_drawManager.AddRobotObject(r);
//    m_aRobots.push_back(r);
//}

///
/// \brief Update du plateau
/// \param Delta time
///
void GameBoard::Update(float dt)
{
    // Update all elements related to game board
}

//-////////// MOUSE EVENTS //////////////-//

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
    // Board iso coord
    Vector2f boardISo = m_pWindow->mapPixelToCoords(Vector2i(x,y), *g_cameraManager.GetCamera());

    // Board cartesian coord
    Vector2f boardCarte = IsometricToCartesian2(boardISo);

    // Trigger selection area
    m_selectionArea.setPosition(boardISo);
    m_selectionArea.setSize(Vector2f(0.0f, 0.0f));
    m_selectionArea.setOutlineThickness(3);
    m_selectionArea.setFillColor(Color::Transparent);
    g_drawManager.SetSelectionArea(&m_selectionArea);
    m_bSelectionArea = true;

    // DBG TEST - Get clicked tile
    Vector2f tempPt;
    x = round(boardCarte.x);
    y = round(boardCarte.y);

    if (x >= 0 && y >= 0 && x < m_iWidth && y < m_iHeight)
    {
        Tile& t = GetTile(sf::Vector2u(x, y));
        if (t.GetType() == Tile::ETileType::GROUND)
        {
            t.SetType(Tile::ETileType::ROAD);
        }
        else
        {
            t.SetType(Tile::ETileType::GROUND);
        }
    }
}

///
/// \brief GameBoard::OnMouseLeftReleased
/// \param x
/// \param y
///
void GameBoard::OnMouseLeftReleased(int x, int y)
{
    // Trigger selection area
    // Compute carte board area with origin & size.
    // Then check what is on it.
    m_bSelectionArea = false;
    g_drawManager.SetSelectionArea(nullptr);
}

///
/// \brief GameBoard::OnMouseMoved
/// \param x
/// \param y
///
void GameBoard::OnMouseMoved(int x, int y)
{
    // Board iso coord
    Vector2f boardISo = m_pWindow->mapPixelToCoords(Vector2i(x,y), *g_cameraManager.GetCamera());

    // Update selection area
    if (m_bSelectionArea)
    {
        Vector2f pos = m_selectionArea.getPosition();
        Vector2f size(boardISo.x - pos.x, boardISo.y - pos.y);

        m_selectionArea.setSize(size);
    }
}


// Debug function
void GameBoard::DbgDrawCenter(void)
{
    sf::RectangleShape tileShape(sf::Vector2f(5, 5));
    tileShape.setPosition(0, 0);
    tileShape.setOrigin(2.5, 2.5);
    m_pWindow->draw(tileShape);
}

Tile& GameBoard::GetTile(const sf::Vector2u& vec)
{
    return m_aGameBoard[Vec2Index(vec)];
}

size_t GameBoard::Vec2Index(const sf::Vector2u& vec) const
{
    return vec.y * m_iWidth + vec.x;
}
