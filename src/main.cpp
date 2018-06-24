#include "stdafx.h"

#include "gamestate.h"

///
/// \file main.cpp
/// \brief main
///

using namespace std;

CameraManager g_cameraManager;

///
/// \brief main
/// \return
///
int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "STR_2017");
    window.setKeyRepeatEnabled(false); // OnKeyPressed only

    GameState gameState;
    gameState.Initialize(&window);

    sf::Clock clock;

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        gameState.Update(dt);
    }

    gameState.Release();

    return 0;
}
