#include "Gate.h"

//------------------------------------ constructor ----------------------------
//Gate constructor 
//-----------------------------------------------------------------------------
Gate::Gate(const sf::Vector2f loc) : StaticObject(GATE, loc) {}


//------------------------------------ handleCollision ------------------------
// double dispatch
//-----------------------------------------------------------------------------
void Gate::handleCollision(GameObject& gameObject)
{
    if (&gameObject == this) return;

    gameObject.handleCollision(*this);
}