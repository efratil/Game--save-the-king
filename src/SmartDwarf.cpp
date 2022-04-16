#include "SmartDwarf.h"
#include <cmath>


//------------------------------------ constructor ----------------------------
// Dwarf constructor 
//-----------------------------------------------------------------------------
SmartDwarf::SmartDwarf(const sf::Vector2f loc, const int speed)
	: Dwarf(loc, SMART_DWARF, speed), m_curRange(0)
{}

//------------------------------------ MOVE -----------------------------------
// move the smart dwarf
//-----------------------------------------------------------------------------
void SmartDwarf::move(const sf::Time& deltaTime, const sf::Vector2f playerLoc)
{
	sf::Vector2f nextLocation = getDirFromData(playerLoc) * getSpeed() * deltaTime.asSeconds();

	if (iscontainInBoard(nextLocation) && m_curRange > 85)
	{
		setPreLoc(getPosition());
		spriteMove(nextLocation);
		setDirection(playerLoc.x - getPosition().x, playerLoc.y - getPosition().y);
		setSprite();
	}
}


//------------------------------------ handleCollision ------------------------
//collision of dwarf with thief
//-----------------------------------------------------------------------------
void SmartDwarf::handleCollision(Teleport& )
{
	setSpriteToBackPos();
}


//------------------------------------ handleCollision ------------------------
//double dispatch
//-----------------------------------------------------------------------------
void SmartDwarf::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;

	gameObject.handleCollision(*this);
}


//----------------------------------- getDir ----------------------------------
//calc the offset of the movmene by using regular distance between to  co-ordinates 
// dividing the distance between the two dots by the distance furmola
//-----------------------------------------------------------------------------
sf::Vector2f SmartDwarf::getDirFromData(const sf::Vector2f playerLoc)
{
	auto distance = playerLoc - getPosition();

	m_curRange = sqrt(std::pow(distance.x, 2) + std::pow(distance.y, 2) * 1.0);

	distance.x /= m_curRange;
	distance.y /= m_curRange;

	return distance;
}


//----------------------------------- getDir ----------------------------------
//sets the durection for the smart dwarfs. while in absolut the x vals are bigger
// so set the sprite to up or down else for right or left 
//-----------------------------------------------------------------------------
void SmartDwarf::setDirection(float xVal, float yVal)
{
	if (std::abs(xVal) >= std::abs(yVal))
	{
		if (xVal < 0.f)
			setDir(1);
		else
			setDir(2);
	}

	else
	{
		if (yVal < 0.f)
			setDir(3);
		else
			setDir(0);
	}
}