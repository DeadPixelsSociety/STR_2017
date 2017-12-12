#ifndef ROBOT_H
#define ROBOT_H

#include "stdafx.h"
#include "gameboard.h"

class Robot
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

	RobotType	m_type;

	GameBoard *	m_pBoard;

	float		m_fx;
	float		m_fy;

	float		m_fxTarget;
	float		m_fyTarget;

	float		m_fDamage; // pourcentage
	float		m_fEnergy;

	bool		m_bSelected;

    std::vector<sf::Sprite> m_aSpriteList; // Sprite list for animation
    int m_iCurrentSpriteId;
    // use m_drawableSprite as current sprite to draw
};

#endif // ROBOT_H
