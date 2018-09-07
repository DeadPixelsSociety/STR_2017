
///
/// \file dynamicobject.cpp
/// \brief DynamicObject class implementation
//

#include "../include/dynamicobject.h"

DynamicObject::DynamicObject(GameBoard* pGameBoard, float x, float y) : DrawableObject(), m_pBoard(pGameBoard)
{
    SetPos(sf::Vector2f(x, y));
}

///
/// \brief Select the object.
///
void DynamicObject::Select(void)
{
    m_bSelect = true;
}

///
/// \brief Deselect the object.
///
void DynamicObject::Deselect(void)
{
    m_bSelect = false;
}

///
/// \brief Return if the object is selected.
///
/// \return True if selected, false otherwise.
///
bool DynamicObject::GetBSelected(void) const
{
    return m_bSelect;
}
