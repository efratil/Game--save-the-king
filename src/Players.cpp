#include "Players.h"
#include "Teleport.h"
#include "Dwarf.h"
#include "DwarfGift.h"
#include "TimeGift.h"
#include "Wall.h"


//------------------------------------ constructor ----------------------------
// king c - tor
//-----------------------------------------------------------------------------
Players::Players(const int iconNum, const sf::Vector2f loc)
	: MovesObject(iconNum, loc)
{}


//------------------------------------ handleCollision ------------------------
//all the players exept the mage can transport in the teleport, 
// can do only if the lock is open, set to lock.
//-----------------------------------------------------------------------------
void Players::handleCollision(Teleport& gameObj)
{
	if (gameObj.getLockMode())
	{
		gameObj.setLock(false);
		gameObj.getPair()->setLock(false);
		setPosition(gameObj.getPair()->getPosition());
		Resources::getInstance().playSound(TELEPORT_SOUND);
	}
}


//------------------------------------ handleCollision ------------------------
//only players can pick up gift
//-----------------------------------------------------------------------------
void Players::handleCollision(DwarfGift& gameObject)
{
	gameObject.setDisposedMode(true);
	setSpriteToBackPos();
}


//------------------------------------ handleCollision ------------------------
//only players can pick up gift
//-----------------------------------------------------------------------------
void Players::handleCollision(TimeGift& gameObject)
{
	gameObject.setDisposedMode(true);
	setSpriteToBackPos();
}


//----------------------------------- dirFromKey ------------------------------
//move the players by the keyboard press
//-----------------------------------------------------------------------------
sf::Vector2f Players::getDirFromData(const sf::Vector2f)
{
	if (sf::Keyboard::isKeyPressed(DOWN))
		return DOWN_MOVE;

	if (sf::Keyboard::isKeyPressed(RIGHT))
		return RIGHT_MOVE;

	if (sf::Keyboard::isKeyPressed(LEFT))
		return LEFT_MOVE;

	if (sf::Keyboard::isKeyPressed(UP))
		return UP_MOVE;

	return { 0, 0 };
}




//----------------------------------- move ------------------------------------
//move the playes at a certain speed by delta time to the next location
//in the board
//-----------------------------------------------------------------------------
void Players::move(const sf::Time& deltaTime, const sf::Vector2f)
{
	sf::Vector2f nextLocation = getDirFromData() * ShapeSpeed * deltaTime.asSeconds();

	if (iscontainInBoard(nextLocation))
	{
		setPreLoc(getSprite().getPosition());
		spriteMove(nextLocation);

		if (getDirFromData() != sf::Vector2f{0, 0})
				setSprite();
	}
}


//----------------------------------- calcYFrame ------------------------------
//calc the y value of the frame fits to the key the user pressed on
//-----------------------------------------------------------------------------
void Players::calcYFrame()
{
	if (sf::Keyboard::isKeyPressed(DOWN))
		setYFrameDirection(0);

	if (sf::Keyboard::isKeyPressed(RIGHT))
		setYFrameDirection(2);

	if (sf::Keyboard::isKeyPressed(LEFT))
		setYFrameDirection(1);

	if (sf::Keyboard::isKeyPressed(UP))
		setYFrameDirection(3);
}