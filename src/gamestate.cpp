#include "../include/gamestate.h"

#include "../include/gameboard.h"
#include "../include/gameguitop.h"
#include "../include/inputmanager.h"
#include "../include/spritemanager.h"

GameState::GameState(void)
: m_eGameState(INIT_MENU)
, m_pInputs(nullptr)
, m_pGameBoard(nullptr)
{
}

void GameState::Initialize(sf::RenderWindow * pWindow)
{
    m_pWindow = pWindow;
    m_pGameBoard = new GameBoard(3, 3, m_pWindow, &m_viewGameBoard);
    m_pGameGUItop = new GameGUItop(m_pWindow, &m_viewGameGUItop);
    m_pInputs = new InputManager();
    m_pInputs->Initialize(this);
}

void GameState::Release(void)
{
    delete(m_pInputs);
    delete(m_pGameGUItop);
    delete(m_pGameBoard);
}

void GameState::Update(float dt)
{
    // Poll events
    sf::Event event;
    while (m_pWindow->pollEvent(event))
    {
        if (!m_pInputs->Update(event))
        {
            if (event.type == sf::Event::Resized)
            {
                if (nullptr != g_cameraManager.GetCamera())
                {
                    g_cameraManager.GetCamera()->setSize((float)event.size.width, (float)event.size.height);
                }
            }
            else if (event.type == sf::Event::Closed)
            {
                m_pWindow->close();
            }
        }
    }

    switch(m_eGameState)
    {
        case INIT_MENU:
        {
            //TODO

            m_eGameState = MENU;
        }
        break;

        case MENU:
        {
            //TODO

            m_eGameState = INIT_GAME;
        }
        break;

        case INIT_GAME:
        {
            SpriteManager::GetInstance();

            m_viewGameBoard.setSize(1920, 1080);
            m_viewGameBoard.setCenter(0.0f, 0.0f);
            m_viewGameBoard.setViewport(sf::FloatRect(0.0f, 0.05f, 1.0f, 0.75f));

            m_viewGameGUItop.setSize(1920, 1080);
            m_viewGameGUItop.setCenter(0.0f, 0.0f);
            m_viewGameGUItop.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 0.05f));

            m_viewGameGUIbottom.setSize(1920, 1080);
            m_viewGameGUIbottom.setCenter(0.0f, 0.0f);
            m_viewGameGUIbottom.setViewport(sf::FloatRect(0.0f, 0.75f, 1.0f, 1.0f));

            m_pGameBoard->Initialize();

            g_cameraManager.Initialize(&m_viewGameBoard, m_pInputs, 10.0f);

            m_eGameState = PLAYING;
        }
        break;

        case PLAYING:
        {
            m_pGameBoard->Update(dt);
            g_cameraManager.Update(dt);

            // Draw
            m_pWindow->clear(sf::Color::Black);

            m_pGameBoard->Draw();
            m_pGameGUItop->Draw();
            // gui down draw
            //m_pWindow->draw(SpriteManager::GetInstance().GetSprite("GROUND_0"));
            m_pWindow->display();
        }
        break;

        case PAUSE:
        {

        }
        break;
    }
}

void GameState::SetPause(bool pause)
{
    if (pause && PLAYING == m_eGameState)
    {
        m_eGameState = PAUSE;
    }
    else if (!pause && PAUSE == m_eGameState)
    {
        m_eGameState = PLAYING;
    }
}

bool GameState::IsPaused(void)
{
    return(PAUSE == m_eGameState);
}

//-////////// MOUSE EVENTS //////////////-//

///
/// \brief GameState::IsInGameBoard
/// \param x
/// \param y
/// \return
///
bool GameState::IsInGameBoard(int x, int y)
{
    if (!m_pGameBoard || PLAYING != m_eGameState)
    {
        return(false);
    }

    // Check if is in game board or in GUI and call correct method (use fix % of place used by GUI ?)

    // if in gui
    // return(false);

    return(true);
}

///
/// \brief GameState::OnMouseRightPressed
/// \param x
/// \param y
///
void GameState::OnMouseRightPressed(int x, int y)
{
    if(IsInGameBoard(x, y))
    {
        m_pGameBoard->OnMouseRightPressed(x, y);
    }
}

///
/// \brief GameState::OnMouseRightReleased
/// \param x
/// \param y
///
void GameState::OnMouseRightReleased(int x, int y)
{
    if(IsInGameBoard(x, y))
    {
        m_pGameBoard->OnMouseRightReleased(x, y);
    }
}

///
/// \brief GameState::OnMouseLeftPressed
/// \param x
/// \param y
///
void GameState::OnMouseLeftPressed(int x, int y)
{
    if(IsInGameBoard(x, y))
    {
        m_pGameBoard->OnMouseLeftPressed(x, y);
    }
}

///
/// \brief GameState::OnMouseLeftReleased
/// \param x
/// \param y
///
void GameState::OnMouseLeftReleased(int x, int y)
{
    if(IsInGameBoard(x, y))
    {
        m_pGameBoard->OnMouseLeftReleased(x, y);
    }
}

///
/// \brief GameState::OnMouseMoved
/// \param x
/// \param y
///
void GameState::OnMouseMoved(int x, int y)
{
    if(IsInGameBoard(x, y))
    {
        m_pGameBoard->OnMouseMoved(x, y);
    }
}
