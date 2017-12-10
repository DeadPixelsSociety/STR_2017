///
/// \file drawmanager.cpp
/// \brief Implémentation de la classe DrawManager
///

#include "drawmanager.h"

///
/// \brief Constructeur
///
DrawManager::DrawManager()
: m_pWindow(nullptr)
, m_pBlackBackground(nullptr)
, m_pSelectionArea(nullptr)
{
}

///
/// \brief Initialize
/// \param Render Window
///
void DrawManager::Initialize(sf::RenderWindow * pWindow)
{
    m_pWindow = pWindow;
}

///
/// \brief Set du background de la map
/// \param Sprite du background
///
void DrawManager::SetBackground(sf::Sprite * pSprite)
{
    m_pBlackBackground = pSprite;
}

///
/// \brief Set de la zone de selection
/// \param RectangleShape de la zone
///
void DrawManager::SetSelectionArea(sf::RectangleShape * pArea)
{
    m_pSelectionArea = pArea;
}

///
/// \brief Ajoute un sprite de tuile dans la liste
/// \param Sprite de la tuile
////
void DrawManager::AddTileSprite(sf::Sprite * pSprite)
{
    m_aSpriteList.push_back(pSprite);
}

///
/// \brief Ajoute un sprite de bâtiment dans la liste
/// \param Sprite du bâtiment
///
void DrawManager::AddBuildingSprite(sf::Sprite * pSprite)
{
    m_aBuildingList.push_back(pSprite);
}

///
/// \brief Draw des sprites
///
void DrawManager::Draw(void)
{
    // We can draw all element types one by one since we don't have sprite superposition (robot behind building)

    m_pWindow->draw(*m_pBlackBackground);

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
        m_pWindow->draw(*m_aSpriteList[i]);
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
        m_pWindow->draw(*m_aBuildingList[i]);
    }
}

///
/// \brief Sous-Draw des robots
///
void DrawManager::DrawRobots(void)
{
    // TODO
}

///
/// \brief Sous-Draw de la GUI
///
void DrawManager::DrawGUI(void)
{
    // TODO
}
