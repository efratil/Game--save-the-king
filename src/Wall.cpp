#include "Wall.h"

//------------------------------------ constructor ----------------------------
//wall constructor 
//-----------------------------------------------------------------------------
Wall::Wall(const sf::Vector2f loc) : StaticObject(WALL, loc) {}


//------------------------------------ handleCollision ------------------------
//double dispatch
//-----------------------------------------------------------------------------
void Wall::handleCollision(GameObject& gameObject)
{
     if (&gameObject == this) return;

    gameObject.handleCollision(*this);
}