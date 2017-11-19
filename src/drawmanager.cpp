#include "drawmanager.h"

DrawManager::DrawManager()
{
}

void DrawManager::Initialize(sf::RenderWindow * pWindow)
{
    m_pWindow = pWindow;
}

void DrawManager::SetBackground(sf::Sprite * pSprite)
{
    m_pBlackBackground = pSprite;
}

void DrawManager::AddTileSprite(sf::Sprite * pSprite)
{
    m_aSpriteList.push_back(pSprite);
}

void DrawManager::AddBuildingSprite(sf::Sprite * pSprite)
{
    m_aBuildingList.push_back(pSprite);
}

void DrawManager::Draw(void)
{
    // We can draw all element types one by one since we don't have sprite superposition (robot behind building)

    m_pWindow->draw(*m_pBlackBackground);

    DrawTiles();
    DrawBuildings();
    DrawRobots();
    DrawGUI();
}

void DrawManager::DrawTiles(void)
{
    size_t iTileCount = m_aSpriteList.size();
    for (size_t i = 0; i < iTileCount; ++i)
    {
        m_pWindow->draw(*m_aSpriteList[i]);
    }
}

void DrawManager::DrawBuildings(void)
{
    size_t iBuildingCount = m_aBuildingList.size();
    for (size_t i = 0; i < iBuildingCount; ++i)
    {
        m_pWindow->draw(*m_aBuildingList[i]);
    }
}

void DrawManager::DrawRobots(void)
{
    // TODO
}

void DrawManager::DrawGUI(void)
{
    // TODO
}
