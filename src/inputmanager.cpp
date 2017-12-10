///
/// \file inputmanager.cpp
/// \brief Implémentation de la classe InputManager
///

#include "inputmanager.h"
#include "gameboard.h"

using namespace sf;

///
/// \brief Constructeur
///
InputManager::InputManager()
: m_pGameBoard(nullptr)
, m_bIsGamePaused(false)
, m_bCameraLeft(false)
, m_bCameraRight(false)
, m_bCameraDown(false)
, m_bCameraTop(false)
, m_iCameraZoom(0)
{
}

///
/// \briefInitialize
/// \param GameBoard pour l'appel des mouse events
///
void InputManager::Initialize(GameBoard * pGameBoard)
{
    m_bIsGamePaused = false;
    m_bCameraLeft = false;
    m_bCameraRight = false;
    m_bCameraDown = false;
    m_bCameraTop = false;

    m_iCameraZoom = 0;

    m_pGameBoard = pGameBoard;
}

///
/// \brief Update des inputs
/// \param sf::Event
/// \return vrai si l'event concernait les inputs
///
bool InputManager::Update(Event & event)
{
    bool isInputEvent = false;

    if (!m_bIsGamePaused)
    {
        switch(event.type)
        {
            case Event::KeyPressed:
            {
                switch(event.key.code)
                {
                    case Keyboard::Up:
                    case Keyboard::Z:
                    {
                        m_bCameraTop = true;
                    }
                    break;

                    case Keyboard::Left:
                    case Keyboard::Q:
                    {
                        m_bCameraLeft = true;
                    }
                    break;

                    case Keyboard::Down:
                    case Keyboard::S:
                    {
                        m_bCameraDown = true;
                    }
                    break;

                    case Keyboard::Right:
                    case Keyboard::D:
                    {
                        m_bCameraRight = true;
                    }
                    break;

                    default:
                    {
                    }
                }
                isInputEvent= true;
            }
            break;

            case Event::KeyReleased:
            {
                switch(event.key.code)
                {
                    case Keyboard::Up:
                    case Keyboard::Z:
                    {
                        m_bCameraTop = false;
                    }
                    break;

                    case Keyboard::Left:
                    case Keyboard::Q:
                    {
                        m_bCameraLeft = false;
                    }
                    break;

                    case Keyboard::Down:
                    case Keyboard::S:
                    {
                        m_bCameraDown = false;
                    }
                    break;

                    case Keyboard::Right:
                    case Keyboard::D:
                    {
                        m_bCameraRight = false;
                    }
                    break;

                    case Keyboard::P:
                    {
                       m_bIsGamePaused = true;
                    }
                    break;

                    default:
                    {
                    }
                }

                isInputEvent= true;
            }
            break;

            case Event::MouseButtonPressed:
            {
                if (Mouse::Right == event.mouseButton.button)
                {
                    OnMouseRightPressed(event.mouseButton.x, event.mouseButton.y);
                }
                else if (Mouse::Left == event.mouseButton.button)
                {
                    OnMouseLeftPressed(event.mouseButton.x, event.mouseButton.y);
                }
                isInputEvent= true;
            }
            break;

            case Event::MouseButtonReleased:
            {
            if (Mouse::Right == event.mouseButton.button)
            {
                OnMouseRightReleased(event.mouseButton.x, event.mouseButton.y);
            }
            else if (Mouse::Left == event.mouseButton.button)
            {
                OnMouseLeftReleased(event.mouseButton.x, event.mouseButton.y);
            }
                isInputEvent= true;
            }
            break;

            case Event::MouseMoved:
            {
                OnMouseMoved(event.mouseMove.x, event.mouseMove.y);
                isInputEvent= true;
            }
            break;

            case Event::MouseWheelScrolled:
            {
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
                {
                    //TODO add max & min
                    m_iCameraZoom = (int)event.mouseWheelScroll.delta;
                }
            }
            break;

            default:
            {
            }
        }
    }
    else
    {
        if (Event::KeyReleased == event.type)
        {
            if (Keyboard::isKeyPressed(Keyboard::P))
            {
                m_bIsGamePaused = false;
            }

            isInputEvent= true;
        }
    }

    return(isInputEvent);
}

///
/// \brief InputManager::IsGamePaused
/// \return
///
bool InputManager::IsGamePaused(void)
{
    return(m_bIsGamePaused);
}

///
/// \brief InputManager::IsCameraLeft
/// \return
///
bool InputManager::IsCameraLeft(void)
{
    return(m_bCameraLeft);
}

///
/// \brief InputManager::IsCameraRight
/// \return
///
bool InputManager::IsCameraRight(void)
{
    return(m_bCameraRight);
}

///
/// \brief InputManager::IsCameraTop
/// \return
///
bool InputManager::IsCameraTop(void)
{
    return(m_bCameraTop);
}

///
/// \brief InputManager::IsCameraDown
/// \return
///
bool InputManager::IsCameraDown(void)
{
    return(m_bCameraDown);
}

///
/// \brief InputManager::GetCameraZoom
/// \return
///
int InputManager::GetCameraZoom(void)
{
    int tmpZoom = m_iCameraZoom;
    m_iCameraZoom = 0;
    return(tmpZoom);
}

//-////////// MOUSE EVENTS :///////////////-//

///
/// \brief InputManager::IsInGameBoard
/// \param x
/// \param y
/// \return
///
bool InputManager::IsInGameBoard(int x, int y)
{
   // Check if is in game board or in GUI and call correct method (use fix % of place used by GUI ?)

    // if in gui
    // return(false);

    return(true);
}

///
/// \brief InputManager::OnMouseRightPressed
/// \param x
/// \param y
///
void InputManager::OnMouseRightPressed(int x, int y)
{
    if(IsInGameBoard(x, y))
    {
        m_pGameBoard->OnMouseRightPressed(x, y);
    }
}

///
/// \brief InputManager::OnMouseRightReleased
/// \param x
/// \param y
///
void InputManager::OnMouseRightReleased(int x, int y)
{
    if(IsInGameBoard(x, y))
    {
        m_pGameBoard->OnMouseRightReleased(x, y);
    }
}

///
/// \brief InputManager::OnMouseLeftPressed
/// \param x
/// \param y
///
void InputManager::OnMouseLeftPressed(int x, int y)
{
    if(IsInGameBoard(x, y))
    {
        m_pGameBoard->OnMouseLeftPressed(x, y);
    }
}

///
/// \brief InputManager::OnMouseLeftReleased
/// \param x
/// \param y
///
void InputManager::OnMouseLeftReleased(int x, int y)
{
    if(IsInGameBoard(x, y))
    {
        m_pGameBoard->OnMouseLeftReleased(x, y);
    }
}

///
/// \brief InputManager::OnMouseMoved
/// \param x
/// \param y
///
void InputManager::OnMouseMoved(int x, int y)
{
    if(IsInGameBoard(x, y))
    {
        m_pGameBoard->OnMouseMoved(x, y);
    }
}
