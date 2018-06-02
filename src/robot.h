#ifndef ROBOT_H
#define ROBOT_H

#include "stdafx.h"
#include "gameboard.h"
#include "drawableobject.h"

class Robot : public DrawableObject
{
public:

    enum class RobotType
    {
        MINER,
        BUILDER,
        DEFENDER,
        RARE_ORE_TRANSPORTER,
        SPECIAL
    };

                Robot           (GameBoard * pGameboard, float x, float y);
    virtual		~Robot          (void);

    void		Select          (void);
    void		Deselect        (void);

    void		Update          (float dt);

    RobotType	GetType         (void) const;

    float		GetFx           (void) const;
    float		GetFy           (void) const;

    float		GetFDamage      (void) const;
    float		GetFEnergy      (void) const;

    bool		GetBSelected    (void) const;

private:
    enum Direction : size_t
    {
        SW = 0,
        NE = 1,
        NW = 2,
        SE = 3
    };

    virtual void UpdateSprites(float dt);

	RobotType	m_type;

	GameBoard *	m_pBoard;

	float		m_fx;
	float		m_fy;

	float		m_fxTarget;
	float		m_fyTarget;

	float		m_fDamage; // pourcentage
	float		m_fEnergy;

	bool		m_bSelected;
};

#endif // ROBOT_H
