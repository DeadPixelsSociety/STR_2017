#include "stdafx.h"
#include "gameboard.h"
#include "inputmanager.h"

using namespace std;

DrawManager g_drawManager;
CameraManager g_cameraManager;

int main()
{
    sf::RenderWindow window;

    window.create(sf::VideoMode(800, 600), "STR_2017");
    g_drawManager.SetWindow(&window);
    window.setKeyRepeatEnabled(false); // OnKeyPressed only

    sf::View camera;
    camera.setSize(1920, 1080);
    camera.setCenter(0.0f, 0.0f);
    window.setView(camera);

    GameBoard * pGameBoard = new GameBoard(5, 5, &window);

    InputManager * pInputs = new InputManager();
    pInputs->Initialize(pGameBoard);

    g_cameraManager.Initialize(&camera, pInputs, 10.0f);

    sf::Clock clock;

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (!pInputs->Update(event))
            {
                // on attrape les évènements de redimensionnement
                if (event.type == sf::Event::Resized)
                {
                    g_cameraManager.GetCamera()->setSize(event.size.width, event.size.height);
                }
                else if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }
        }

        if (!pInputs->IsGamePaused())
        {
            pGameBoard->Update(dt);
            g_cameraManager.Update(dt);


            g_drawManager.Draw();

            //pGameBoard->DbgDisplayGrid(true);
            pGameBoard->DbgDrawCenter();

            window.display();
        }
    }

    return 0;
}
