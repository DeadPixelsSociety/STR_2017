#include "stdafx.h"
#include "gameboard.h"
#include "inputmanager.h"

using namespace std;

DrawManager g_drawManager;

int main()
{
    sf::RenderWindow window;

    window.create(sf::VideoMode(800, 600), "STR_2017");
    g_drawManager.SetWindow(&window);
    window.setKeyRepeatEnabled(false); // OnKeyPressed

    sf::View view1;
    view1.setSize(1920, 1080);
    window.setView(view1);

    GameBoard * pGameBoard = new GameBoard(25, 25);
    InputManager * pInputs = new InputManager();
    pInputs->Initialize(pGameBoard);

    sf::Clock clock;

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (!pInputs->Update(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }
        }

        if (!pInputs->IsGamePaused())
        {
            pGameBoard->Update(dt);

            g_drawManager.Draw();

            //pGameBoard->DbgDisplayGrid(window, false);

            window.display();
        }
    }

    return 0;
}
