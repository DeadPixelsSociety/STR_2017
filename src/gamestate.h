#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "stdafx.h"

class GameBoard;
class GameGUItop;
class InputManager;

class GameState final : public IInputEvents
{
public:

    enum EGameState
    {
        INIT_MENU,
        MENU,
        INIT_GAME,
        PLAYING,
        PAUSE
    };

    explicit GameState  (void);

    void    Initialize  (sf::RenderWindow * pWindow);
    void    Release     (void);

    void    Update      (float dt);

    void    SetPause    (bool pause);
    bool    IsPaused    (void);

    virtual void    OnMouseRightPressed     (int x, int y) override;
    virtual void    OnMouseRightReleased    (int x, int y) override;

    virtual void    OnMouseLeftPressed      (int x, int y) override;
    virtual void    OnMouseLeftReleased     (int x, int y) override;

    virtual void    OnMouseMoved            (int x, int y) override;

private:

    bool            IsInGameBoard           (int x, int y);

private:

    EGameState          m_eGameState;

    sf::RenderWindow *  m_pWindow;
    sf::View            m_viewGameBoard;
    sf::View            m_viewGameGUItop;
    sf::View            m_viewGameGUIbottom;

    InputManager *      m_pInputs;
    GameBoard *         m_pGameBoard;
    GameGUItop *        m_pGameGUItop;

};

#endif // GAMESTATE_H
