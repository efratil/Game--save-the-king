#include "Fire.h"

//------------------------------------ constructor ----------------------------
// Fire constructor 
//-----------------------------------------------------------------------------
Fire::Fire(const sf::Vector2f loc) : StaticObject(FIRE, loc) {}


//------------------------------------ handleCollision ------------------------
//double dispatch
//-----------------------------------------------------------------------------
void Fire::handleCollision(GameObject& gameObject)
{
    if (&gameObject == this) return;

    gameObject.handleCollision(*this);
}