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
: m_pWindow(pWindow)
, m_selectionArea(RectangleShape())
, m_bSelectionArea(false)
, m_iWidth(width)
, m_iHeight(height)
{
}

void GameBoard::Initialize(void)
{
    Vector2f tilePos(0.0f, 0.0f);
    for (int i = 0; i < m_iHeight; ++i)
    {
        vector<Tile *> raw;
        for (int j = 0; j < m_iWidth; ++j)
        {
            raw.push_back(new Tile(tilePos, Tile::ETileType::GROUND));
            raw[j]->Initialize();
            tilePos.x += TILE_WIDTH / 2; // ratio between tile width and height
        }
        m_aGameBoard.push_back(raw);
        tilePos.y += TILE_HEIGHT;
        tilePos.x = 0.0f;
    }

    // Background sprite
    m_blackBackgroundTexture.loadFromFile("../resources/fond_noir.png");
    m_blackBackgroundSprite = sf::Sprite(m_blackBackgroundTexture);
    m_blackBackgroundSprite.setOrigin(32.0f, 32.0f);
    m_blackBackgroundSprite.scale(10000.0f, 10000.0f);
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
    printf("%f, %f\n", boardISo.x, boardISo.y);

    // Board cartesian coord
    Vector2f boardCarte = IsometricToCartesian2(boardISo);
    printf("%f, %f\n", boardCarte.x, boardCarte.y);

    // Trigger selection area
    m_selectionArea.setPosition(boardISo);
    m_selectionArea.setSize(Vector2f(0.0f, 0.0f));
    m_selectionArea.setOutlineThickness(3);
    m_selectionArea.setFillColor(Color::Transparent);
    g_drawManager.SetSelectionArea(&m_selectionArea);
    m_bSelectionArea = true;



    // DBG TEST - Get clicked tile
    Vector2f tempPt;
    x = round(boardCarte.x / (TILE_WIDTH/2));
    y = round(boardCarte.y / TILE_HEIGHT);
    printf("%d, %d\n\n", x, y);
    if (x >= 0 && y >= 0 && x < m_iWidth && y < m_iHeight)
    {
        Tile::ETileType type = m_aGameBoard[y][x]->GetType();
        if (Tile::ETileType::GROUND == type)
        {
            m_aGameBoard[y][x]->SetType(Tile::ETileType::ROAD);
        }
        else
        {
            m_aGameBoard[y][x]->SetType(Tile::ETileType::GROUND);
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
    sf::RectangleShape tileShape = sf::RectangleShape(sf::Vector2f(5, 5));
    tileShape.setPosition(0, 0);
    tileShape.setOrigin(2.5, 2.5);
    m_pWindow->draw(tileShape);
}
