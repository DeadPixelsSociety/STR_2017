#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "stdafx.h"

class GameBoard;

class InputManager final: public IInputEvents
{
public:
    InputManager();

    void    Initialize      (GameBoard * pGameBoard);
    bool    Update          (sf::Event & event);

    bool    IsGamePaused    (void);

    bool    IsCameraLeft    (void);
    bool    IsCameraRight   (void);
    bool    IsCameraTop     (void);
    bool    IsCameraDown    (void);

    int     GetCameraZoom   (void);

private:

    bool            IsInGameBoard           (int x, int y);

    virtual void    OnMouseRightPressed     (int x, int y) override;
    virtual void    OnMouseRightReleased    (int x, int y) override;

    virtual void    OnMouseLeftPressed      (int x, int y) override;
    virtual void    OnMouseLeftReleased     (int x, int y) override;

    virtual void    OnMouseMoved            (int x, int y) override;

private:

    bool            m_bIsGamePaused;

    bool            m_bCameraLeft;
    bool            m_bCameraRight;
    bool            m_bCameraDown;
    bool            m_bCameraTop;

    int             m_iCameraZoom;

    GameBoard *     m_pGameBoard;
    // GameGUI *    m_pGameGUI <- TODO
};

#endif // INPUTMANAGER_H
