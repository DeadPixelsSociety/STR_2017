///
/// \file drawerobject.cpp
/// \brief Implémentation de la classe DrawerObject
///

#include "../include/drawerobject.h"

using namespace sf;

///
/// \brief Constructeur
///
DrawerObject::DrawerObject(sf::RenderWindow * pWindow, sf::View * pView)
    : m_pWindow(pWindow)
    , m_pView(pView)
{
}

