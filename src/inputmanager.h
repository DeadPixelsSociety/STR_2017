#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "stdafx.h"

class GameBoard;

class InputManager: public IInputEvents
{
public:
    InputManager();

    void    Initialize      (GameBoard * pGameBoard);
    bool    Update          (sf::Event & event);

    bool    IsGamePaused    (void);

private:

    bool            IsInGameBoard           (int x, int y);

    virtual void    OnMouseRightPressed     (int x, int y) override;
    virtual void    OnMouseRightReleased    (int x, int y) override;

    virtual void    OnMouseLeftPressed      (int x, int y) override;
    virtual void    OnMouseLeftReleased     (int x, int y) override;

    virtual void    OnMouseMoved            (int x, int y) override;

private:

    bool            m_iIsGamePaused;

    GameBoard *     m_pGameBoard;
    // GameGUI *    m_pGameGUI <- TODO
};

#endif // INPUTMANAGER_H
