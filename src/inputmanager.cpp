#include "inputmanager.h"
#include "gameboard.h"

using namespace sf;

InputManager::InputManager()
{
}

void InputManager::Initialize(GameBoard * pGameBoard)
{
    m_iIsGamePaused = false;
    m_pGameBoard = pGameBoard;
}

bool InputManager::Update(Event & event)
{
    bool isInputEvent = false;

    if (!m_iIsGamePaused)
    {
        switch(event.type)
        {
            case Event::KeyPressed:
            {
                isInputEvent= true;
            }
            break;

            case Event::KeyReleased:
            {
                if (Keyboard::P == event.key.code)
                {
                    m_iIsGamePaused = true;
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
                m_iIsGamePaused = false;
            }

            isInputEvent= true;
        }
    }

    return(isInputEvent);
}

bool InputManager::IsGamePaused(void)
{
    return(m_iIsGamePaused);
}

////////////////////////////////////////////
//////////// MOUSE EVENTS ://///////////////
////////////////////////////////////////////

bool InputManager::IsInGameBoard(int x, int y)
{
   // Check if is in game board or in GUI and call correct method (use fix % of place used by GUI ?)

    // if in gui
    // return(false);

    return(true);
}


void InputManager::OnMouseRightPressed(int x, int y)
{
    if(IsInGameBoard(x, y))
    {
        m_pGameBoard->OnMouseRightPressed(x, y);
    }
}

void InputManager::OnMouseRightReleased(int x, int y)
{
    if(IsInGameBoard(x, y))
    {
        m_pGameBoard->OnMouseRightReleased(x, y);
    }
}

void InputManager::OnMouseLeftPressed(int x, int y)
{
    if(IsInGameBoard(x, y))
    {
        m_pGameBoard->OnMouseLeftPressed(x, y);
    }
}

void InputManager::OnMouseLeftReleased(int x, int y)
{
    if(IsInGameBoard(x, y))
    {
        m_pGameBoard->OnMouseLeftReleased(x, y);
    }
}

void InputManager::OnMouseMoved(int x, int y)
{
    if(IsInGameBoard(x, y))
    {
        m_pGameBoard->OnMouseMoved(x, y);
    }
}

