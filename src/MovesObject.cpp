#include "MovesObject.h"

//------------------------------------ constructor ----------------------------
// MovesObject constructor 
//-----------------------------------------------------------------------------
MovesObject::MovesObject(const int iconNum, const sf::Vector2f loc)
	: GameObject(iconNum, loc), m_frameDirection(0,0), m_preLoc(loc)
{
	setSpriteFrame(); 
	setScale(1.8);
}



//----------------------------------- iscontainInBoard ------------------------
//checks if the move is on tje board limit, using aux rectangle 
//-----------------------------------------------------------------------------
bool MovesObject::iscontainInBoard(sf::Vector2f nextLocation)
{
	sf::RectangleShape board;
	board.setSize(sf::Vector2f(1281, 835));
	board.setPosition(BOARD_LOCATION);
	sf::Vector2f loc = getSprite().getPosition() + nextLocation;

	return (board.getGlobalBounds().contains(loc));
}


//----------------------------------- setSpriteFrame --------------------------
//set the sprite frame - the calc for the moving rows, cols, the size of the SETS
//-----------------------------------------------------------------------------
void MovesObject::setSpriteFrame()
{
	setTextureRect(m_frameDirection);
}


//----------------------------------- setSpriteFrame --------------------------
// defualt move = face to the user.
//-----------------------------------------------------------------------------
void MovesObject::setSpriteFrameDefault()
{
	m_frameDirection = NONE_MOVE;
	setSpriteFrame();
}


//----------------------------------- setSprite -------------------------------
//set the sprite frame - call to calc x, y of the frame and set 
//-----------------------------------------------------------------------------
void MovesObject::setSprite()
{
	calcXFrame(); 
	calcYFrame();
	setSpriteFrame();
}


//----------------------------------- calcXFrame ------------------------------
// calc the x value of the frame of the sprite
//-----------------------------------------------------------------------------
void MovesObject::calcXFrame()
{
	m_frameDirection.x += SPRITE_SIZE;

	if (m_frameDirection.x >= SPRITE_SIZE*3)
	{
		m_frameDirection.x = 0;
	}
}


//---------------------------- setFrameDirection ------------------------------
// calc the x value of the frame of the sprite
//-----------------------------------------------------------------------------
void MovesObject::setFrameDirection(const sf::Vector2u frame)
{
	m_frameDirection = frame; 
}


//-------------------------------- getFrameDirection --------------------------
// returns the member in const
//-----------------------------------------------------------------------------
sf::Vector2u MovesObject::getFrameDirection() const
{ 
	return m_frameDirection;
}


//----------------------------------- getPreLoc ------------------------------
//return the last location
//-----------------------------------------------------------------------------
sf::Vector2f MovesObject::getPreLoc()const
{ 
	return m_preLoc;
};


//----------------------------------- setPreLoc -------------------------------
// set the member that holds the last location
//-----------------------------------------------------------------------------
void MovesObject::setPreLoc(const sf::Vector2f loc)
{ 
	m_preLoc = loc; 
};

//--------------------------- setYFrameDirection ------------------------------
// set the y value of the frameDirection
//-----------------------------------------------------------------------------
void MovesObject::setYFrameDirection(const int y)
{
	m_frameDirection.y = y; 
}

//---------------------------- setSpriteToBackPos -----------------------------
//return the speitr to the location before the move
//-----------------------------------------------------------------------------
void MovesObject::setSpriteToBackPos()
{
	setPosition(m_preLoc);
}


//handle collousion
//------------------------------------ handleCollision ------------------------
//with fire
//-----------------------------------------------------------------------------
void MovesObject::handleCollision(Fire&)
{
	setSpriteToBackPos();
}


//------------------------------------ handleCollision ------------------------
//with gate
//-----------------------------------------------------------------------------
void MovesObject::handleCollision(Gate&)
{
	setSpriteToBackPos();
}


//------------------------------------ handleCollision ------------------------
//with throne
//-----------------------------------------------------------------------------
void MovesObject::handleCollision(Throne&)
{
	setSpriteToBackPos();
}


//------------------------------------ handleCollision ------------------------
//with wall
//-----------------------------------------------------------------------------
void MovesObject::handleCollision(Wall&)
{
	setSpriteToBackPos();
}


//------------------------------------ handleCollision ------------------------
//with orc
//-----------------------------------------------------------------------------
void MovesObject::handleCollision(Orc&)
{
	setSpriteToBackPos();
}


//------------------------------------ handleCollision ------------------------
//with thief
//-----------------------------------------------------------------------------
void MovesObject::handleCollision(Thief&)
{
	setSpriteToBackPos();
}

//------------------------------------ handleCollision ------------------------
//with warrior
//-----------------------------------------------------------------------------
void MovesObject::handleCollision(Warrior&)
{
	setSpriteToBackPos();
}

//------------------------------------ handleCollision ------------------------
//with mage
//-----------------------------------------------------------------------------
void MovesObject::handleCollision(Mage&)
{
	setSpriteToBackPos();
}

//------------------------------------ handleCollision ------------------------
//with king
//-----------------------------------------------------------------------------
void MovesObject::handleCollision(King&)
{
	setSpriteToBackPos();
}


//------------------------------------ handleCollision ------------------------
//with dwarf
//-----------------------------------------------------------------------------
void MovesObject::handleCollision(SmartDwarf&)
{
	setSpriteToBackPos();
}

//------------------------------------ handleCollision ------------------------
//with dwarf
//-----------------------------------------------------------------------------
void MovesObject::handleCollision(DumbDwarf&)
{
	setSpriteToBackPos();
}