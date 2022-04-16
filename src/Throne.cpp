#include "Throne.h"

//------------------------------------ constructor ----------------------------
//Throne constructor 
//-----------------------------------------------------------------------------
Throne::Throne(const sf::Vector2f loc) : StaticObject(THRONE, loc) {}


//------------------------------------ handleCollision ------------------------
//double dispatch
//-----------------------------------------------------------------------------
void Throne::handleCollision(GameObject& gameObject)
{
    if (&gameObject == this) return;

    gameObject.handleCollision(*this);
}