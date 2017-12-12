#ifndef ROBOT_H
#define ROBOT_H

#include "stdafx.h"
#include "gameboard.h"

class Robot
{
public:
				Robot(GameBoard& gameboard, float x, float y);
	virtual		~Robot();

	void		select(void);
	void		deselect(void);

	void		update(void);

	RobotType	getType(void) const;

	float		getFx(void) const;
	float		getFy(void) const;

	float		getFDamage(void) const;
	float		getFEnergy(void) const;

	bool		getBSelected(void) const;

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
};

#endif // ROBOT_H
