#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

///
/// \file inputmanager.h
/// \brief Header de la classe InputManager
///

#include "stdafx.h"

class GameState;

///
/// \class InputManager
/// \brief Gestion des inputs
///
class InputManager final: public IInputEvents
{
public:
    InputManager();

    void    Initialize      (GameState * pGameState);
    bool    Update          (sf::Event & event);

    bool    IsCameraLeft    (void);
    bool    IsCameraRight   (void);
    bool    IsCameraTop     (void);
    bool    IsCameraDown    (void);

    int     GetCameraZoom   (void);

private:

    virtual void    OnMouseRightPressed     (int x, int y) override;
    virtual void    OnMouseRightReleased    (int x, int y) override;

    virtual void    OnMouseLeftPressed      (int x, int y) override;
    virtual void    OnMouseLeftReleased     (int x, int y) override;

    virtual void    OnMouseMoved            (int x, int y) override;

private:

    bool            m_bCameraLeft;
    bool            m_bCameraRight;
    bool            m_bCameraDown;
    bool            m_bCameraTop;

    int             m_iCameraZoom;

    GameState *     m_pGameState;
};

#endif // INPUTMANAGER_H
