#ifndef GAMEGUITOP_H
#define GAMEGUITOP_H

#include "stdafx.h"

class GameGUItop : public DrawerObject
{
public:
    explicit GameGUItop (sf::RenderWindow * pWindow, sf::View * pView);
            ~GameGUItop (void);

    void Initialize     (void);

    virtual void Draw   (void) override;

private:

    // background sprite
    // resources texts

    // options buttons ?
};

#endif // GAMEGUITOP_H
