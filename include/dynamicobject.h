#ifndef STR_2017_DYNAMICOBJECT_H
#define STR_2017_DYNAMICOBJECT_H

///
/// \file dynamicobject.h
/// \brief DynamicObject class header
///

#include "../include/drawableobject.h"

class GameBoard;

///
/// \class DynamicObject
/// \brief Base class for dynamic objects, like robots, buildings ...
///
class DynamicObject : public DrawableObject
{
    public:
        DynamicObject(GameBoard * pGameBoard, float x, float y);

        void		Select          (void);
        void		Deselect        (void);

        bool		GetBSelected    (void) const;

    protected:
        GameBoard * m_pBoard;
        bool        m_bSelect;
};


#endif //STR_2017_DYNAMICOBJECT_H
