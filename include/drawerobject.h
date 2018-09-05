#ifndef DRAWEROBJECT_H
#define DRAWEROBJECT_H

///
/// \file drawerObject.h
/// \brief Header de la classe drawerObject
///

#include <SFML/Graphics.hpp>

class DrawableObject;

///
/// \class DrawerObject
/// \brief Gestion du rendu
///
class DrawerObject
{
public:
    DrawerObject(sf::RenderWindow * pWindow, sf::View * pView);

    virtual void    Draw                (void) = 0;

protected:
    sf::RenderWindow *  m_pWindow;
    sf::View *          m_pView;
};

#endif // DRAWEROBJECT_H
