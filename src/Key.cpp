#include "Key.h"

//------------------------------------ constructor ----------------------------
//Key constructor 
//-----------------------------------------------------------------------------
Key::Key(const sf::Vector2f loc) : StaticObject(KEY, loc) {}


//------------------------------------ handleCollision ------------------------
// double dispatch
//-----------------------------------------------------------------------------
void Key::handleCollision(GameObject& gameObject)
{
    if (&gameObject == this) return;

    gameObject.handleCollision(*this);
}