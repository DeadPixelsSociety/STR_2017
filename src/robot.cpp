#include "../include/robot.h"
#include "../include/spritemanager.h"

Robot::Robot(GameBoard * pGameboard, float x, float y)
: DynamicObject(pGameboard, x, y)
, m_type(RobotType::BUILDER)
, m_fxTarget(x)
, m_fyTarget(y)
, m_fDamage(0)
, m_fEnergy(100)
{
    m_anim.addState(SpriteManager::GetInstance().GetSprite("ROBOT_0"), 1);
    m_anim.addState(SpriteManager::GetInstance().GetSprite("ROBOT_1"), 1);
    m_anim.addState(SpriteManager::GetInstance().GetSprite("ROBOT_2"), 1);
    m_anim.addState(SpriteManager::GetInstance().GetSprite("ROBOT_3"), 1);
}

Robot::~Robot(void)
{
}

void Robot::Update(float dt)
{
    // Update animation
    DrawableObject::Update(dt);

    UpdateSprites(dt);
}

float Robot::GetFDamage(void) const
{
	return m_fDamage;
}

float Robot::GetFEnergy(void) const
{
	return m_fEnergy;
}

Robot::RobotType Robot::GetType(void) const
{
	return m_type;
}

void Robot::UpdateSprites(float dt)
{
    if (m_fxTarget < m_pos.x) {
        if (m_fyTarget < m_pos.y) {
            SetState(Direction::NW);
        } else {
            SetState(Direction::SW);
        }
    } else {
        if (m_fyTarget < m_pos.y) {
            SetState(Direction::NE);
        } else {
            SetState(Direction::SE);
        }
    }
}
