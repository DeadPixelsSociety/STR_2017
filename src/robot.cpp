#include "robot.h"

Robot::Robot(GameBoard * pGameboard, float x, float y)
: m_fx(x)
, m_fy(y)
, m_fxTarget(x)
, m_fyTarget(y)
, m_fDamage(0)
, m_fEnergy(100)
, m_pBoard(pGameboard)
, m_iCurrentSpriteId(0)
{
}

Robot::~Robot(void)
{
}

void Robot::Select(void)
{
	m_bSelected = true;
}

void Robot::Deselect(void)
{
	m_bSelected = false;
}

void Robot::Update(float dt)
{
    // Update animation
}

float Robot::GetFx(void) const
{
	return m_fx;
}

float Robot::GetFy(void) const
{
	return m_fy;
}

float Robot::GetFDamage(void) const
{
	return m_fDamage;
}

float Robot::GetFEnergy(void) const
{
	return m_fEnergy;
}

bool Robot::GetBSelected(void) const
{
	return m_bSelected;
}

Robot::RobotType Robot::GetType(void) const
{
	return m_type;
}
