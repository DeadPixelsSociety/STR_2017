///
/// \file drawmanager.cpp
/// \brief Implémentation de la classe DrawManager
///

#include "drawmanager.h"

using namespace sf;

///
/// \brief Constructeur
///
DrawManager::DrawManager()
: m_pWindow(nullptr)
, m_pSelectionArea(nullptr)
{
}

///
/// \brief Initialize
/// \param Render Window
///
void DrawManager::Initialize(RenderWindow * pWindow)
{
    m_pWindow = pWindow;
}

///
/// \brief Set de la zone de selection
/// \param RectangleShape de la zone
///
void DrawManager::SetSelectionArea(RectangleShape * pArea)
{
    m_pSelectionArea = pArea;
}

///
/// \brief Ajoute une tuile dans la liste
/// \param DrawableObject
////
void DrawManager::AddTileObject(DrawableObject * pTile)
{
    m_aSpriteList.push_back(pTile);
}

///
/// \brief Ajoute un bâtiment dans la liste
/// \param DrawableObject
///
void DrawManager::AddBuildingObject(DrawableObject * pBuilding)
{
    m_aBuildingList.push_back(pBuilding);
}

///
/// \brief Ajoute un robot dans la liste
/// \param DrawableObject
///
void DrawManager::AddRobotObject(DrawableObject * pRobot)
{
    m_aRobotList.insert(pRobot);
}

void DrawManager::RemoveRobotObject(DrawableObject* pRobot)
{
    m_aRobotList.erase(pRobot);
}

///
/// \brief Draw des sprites
///
void DrawManager::Draw(void)
{
    // We can draw all element types one by one since we don't have sprite superposition (robot behind building)

    m_pWindow->clear(Color::Black);

    DrawTiles();
    DrawBuildings();
    DrawRobots();

    if (nullptr != m_pSelectionArea)
    {
        m_pWindow->draw(*m_pSelectionArea);
    }

    DrawGUI();
}

///
/// \brief Sous-Draw des tuiles
///
void DrawManager::DrawTiles(void)
{
    size_t iTileCount = m_aSpriteList.size();
    for (size_t i = 0; i < iTileCount; ++i)
    {
        m_aSpriteList[i]->draw(*m_pWindow, RenderStates::Default);
    }
}

///
/// \brief Sous-Draw des bâtiments
///
void DrawManager::DrawBuildings(void)
{
    size_t iBuildingCount = m_aBuildingList.size();
    for (size_t i = 0; i < iBuildingCount; ++i)
    {
        m_aBuildingList[i]->draw(*m_pWindow, RenderStates::Default);
    }
}

///
/// \brief Sous-Draw des robots
///
void DrawManager::DrawRobots(void)
{
    for (DrawableObject * r : m_aRobotList)
    {
        r->draw(*m_pWindow, RenderStates::Default);
    }
}

///
/// \brief Sous-Draw de la GUI
///
void DrawManager::DrawGUI(void)
{
    // TODO
}
