#include "stdafx.h"
#include "gameboard.h"

using namespace std;

DrawManager g_drawManager;

int main()
{
    sf::RenderWindow window;

    window.create(sf::VideoMode(800, 600), "STR_2017");
    g_drawManager.SetWindow(&window);

    sf::View view1;
    view1.setSize(1920, 1080);
    window.setView(view1);

    GameBoard * pGameBoard = new GameBoard(25, 25);

    // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
    while (window.isOpen())
    {
        //pGameBoard->DbgDisplayGrid(window, true);

        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (window.pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        g_drawManager.Draw();
        window.display();
    }

    return 0;
}
