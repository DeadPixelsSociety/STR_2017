#ifndef ROBOT_H
#define ROBOT_H

#include "stdafx.h"
#include "dynamicobject.h"

class Robot : public DynamicObject
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

    void		Update          (float dt) override;

    RobotType	GetType         (void) const;

    float		GetFDamage      (void) const;
    float		GetFEnergy      (void) const;

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

	float		m_fxTarget;
	float		m_fyTarget;

	float		m_fDamage; // pourcentage
	float		m_fEnergy;
};

#endif // ROBOT_H
