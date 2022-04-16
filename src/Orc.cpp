#include "Orc.h"

//------------------------------------ constructor ----------------------------
//Orc constructor 
//-----------------------------------------------------------------------------
Orc::Orc(const sf::Vector2f loc) : StaticObject(ORC, loc) {}


//------------------------------------ handleCollision ------------------------
//double dispatch
//-----------------------------------------------------------------------------
void Orc::handleCollision(GameObject& gameObject)
{
    if (&gameObject == this) return;

    gameObject.handleCollision(*this);
}