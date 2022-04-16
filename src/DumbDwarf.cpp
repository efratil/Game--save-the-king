#include "DumbDwarf.h"


//------------------------------------ constructor ----------------------------
// Dwarf constructor 
//-----------------------------------------------------------------------------
DumbDwarf::DumbDwarf(const sf::Vector2f loc, const int speed)
	: Dwarf(loc, DUMB_DWARF, speed)
{}



//------------------------------------ handleCollision ------------------------
//double dispatch
//-----------------------------------------------------------------------------
void DumbDwarf::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;

	gameObject.handleCollision(*this);
}



//----------------------------------- getDir ----------------------------------
//get direction for the enemy frame
//-----------------------------------------------------------------------------
sf::Vector2f DumbDwarf::getDirFromData(const sf::Vector2f)
{
	if (GetCurDirection() == 0)
		return DOWN_MOVE;

	if (GetCurDirection() == 1)
		return LEFT_MOVE;

	if (GetCurDirection() == 2)
		return RIGHT_MOVE;

	if (GetCurDirection() == 3)
		return UP_MOVE;

	return { 0,0 };
}

//------------------,------------------ handleCollision ------------------------
//collision of dwarf with king
//-----------------------------------------------------------------------------
void DumbDwarf::handleCollision(King&)
{
	DwarfHandleCollision();
}


//------------------------------------ handleCollision ------------------------
//collision of dwarf with mage
//-----------------------------------------------------------------------------
void DumbDwarf::handleCollision(Mage&)
{
	DwarfHandleCollision();
}


//------------------------------------ handleCollision ------------------------
//collision of dwarf with warrior
//-----------------------------------------------------------------------------
void DumbDwarf::handleCollision(Warrior&)
{
	DwarfHandleCollision();
}


//------------------------------------ handleCollision ------------------------
//collision of dwarf with thief
//-----------------------------------------------------------------------------
void DumbDwarf::handleCollision(Thief&)
{
	DwarfHandleCollision();
}


//------------------------------------ handleCollision ------------------------
//collision of dwarf with thief
//-----------------------------------------------------------------------------
void DumbDwarf::handleCollision(Teleport&)
{
	DwarfHandleCollision();
}


//------------------------------------ handleCollision ------------------------
//collision of dwarf with wall
//-----------------------------------------------------------------------------
void DumbDwarf::handleCollision(Wall&)
{
	DwarfHandleCollision();
}


//------------------------------------ handleCollision ------------------------
//collision of dwarf with orc
//-----------------------------------------------------------------------------
void DumbDwarf::handleCollision(Orc&)
{
	DwarfHandleCollision();
}


//------------------------------------ handleCollision ------------------------
//collision of dwarf with fire
//-----------------------------------------------------------------------------
void DumbDwarf::handleCollision(Fire&)
{
	DwarfHandleCollision();
}


//------------------------------------ handleCollision ------------------------
//collision of dwarf with gate
//-----------------------------------------------------------------------------
void DumbDwarf::handleCollision(Gate&)
{
	DwarfHandleCollision();
}


//------------------------------------ handleCollision ------------------------
///collision of dwarf with dwarf
//-----------------------------------------------------------------------------
void DumbDwarf::handleCollision(SmartDwarf&)
{
	DwarfHandleCollision();
}


//------------------------------------ handleCollision ------------------------
//collision of dwarf with dwarf
//-----------------------------------------------------------------------------
void DumbDwarf::handleCollision(DumbDwarf&)
{
	DwarfHandleCollision();
}

//----------------------------------- move -------------------------------------
// move function
//-----------------------------------------------------------------------------
void DumbDwarf::move(const sf::Time& deltaTime, const sf::Vector2f)
{
	sf::Vector2f nextLocation = getDirFromData() * getSpeed() * deltaTime.asSeconds();

	if (iscontainInBoard(nextLocation))
	{
		setPreLoc(getSprite().getPosition());
		spriteMove(nextLocation);
		setSprite();
	}
	else setDir();
}