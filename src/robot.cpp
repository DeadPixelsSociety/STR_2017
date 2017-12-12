#include "robot.h"

Robot::Robot(GameBoard &gameboard, float x, float y) :
	m_fx(x),
	m_fy(y),
	m_fxTarget(x),
	m_fyTarget(y),
	m_fDamage(0),
	m_fEnergy(100),
	m_pBoard(&gameboard)
{

}

Robot::~Robot()
{

}

void Robot::select()
{
	m_bSelected = true;
}

void Robot::deselect()
{
	m_bSelected = false;
}

void Robot::update()
{

}

float Robot::getFx() const
{
	return m_fx;
}

float Robot::getFy() const
{
	return m_fy;
}

float Robot::getFDamage() const
{
	return m_fDamage;
}

float Robot::getFEnergy() const
{
	return m_fEnergy;
}

bool Robot::getBSelected() const
{
	return m_bSelected;
}

RobotType Robot::getType() const
{
	return m_type;
}
