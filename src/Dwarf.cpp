#include "Dwarf.h"


//------------------------------------ constructor ----------------------------
// Dwarf constructor 
//-----------------------------------------------------------------------------
Dwarf::Dwarf(const sf::Vector2f loc, const int enumType, const int speed) 
	: MovesObject(enumType, loc), m_direction(rand()%4), m_shapeSpeed(speed)
{}


//------------------------------------ handleCollision ------------------------
//collision of dwarf with dwarf
//-----------------------------------------------------------------------------
void Dwarf::DwarfHandleCollision()
{
	setSpriteToBackPos();
	setDir();
}


//------------------------------------ setDir ---------------------------------
//rand a number modulo 4, {0,1,2,3}.  each num has a constant fit direction.
//switch direction on colision, to promise good playing, rand dir until gets a
// new direction different from the last one.
//-----------------------------------------------------------------------------
void Dwarf::setDir()
{
	int aux; 

	while (true)
	{
		aux = rand() % 4;

		if (aux != m_direction) break;
	}

	m_direction = aux;
	setSprite();
}


//------------------------------------ setDir ---------------------------------
// gets num of direction and sets as this curr direction 
//-----------------------------------------------------------------------------
void Dwarf::setDir(const int dir)
{
	if (dir >= 0 && dir <= 3)
	{
		m_direction = dir;
	}
}


//----------------------------------- calcYFrame ------------------------------
//calc the y value of the frame fits to the key the user pressed on
//-----------------------------------------------------------------------------
void Dwarf::calcYFrame()
{
	setYFrameDirection(GetCurDirection());
}


//----------------------------------- getSpeed --------------------------------
//return the speed
//-----------------------------------------------------------------------------
float Dwarf::getSpeed() const
{
	return m_shapeSpeed;
}


//----------------------------------- setSpeed --------------------------------
//set speed of dwarf
//-----------------------------------------------------------------------------
void Dwarf::setSpeed(const float speed)
{
	if (m_shapeSpeed + speed < 3*ShapeSize)  return; 
	if (m_shapeSpeed + speed <9 * ShapeSize) return;

	m_shapeSpeed += speed;
}