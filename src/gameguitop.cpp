#include "../include/gameguitop.h"

GameGUItop::GameGUItop(sf::RenderWindow * pWindow, sf::View * pView)
    : DrawerObject(pWindow, pView)
{
}

GameGUItop::~GameGUItop(void)
{
}

void GameGUItop::Initialize(void)
{
    // Create sprites
}

void GameGUItop::Draw(void)
{
    m_pWindow->setView(*m_pView);

    // Background

    // Resources texts

    // Options menus
}
