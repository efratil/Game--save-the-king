#include "Warrior.h"

//------------------------------------ constructor ----------------------------
//Warrior  c - tor
//-----------------------------------------------------------------------------
Warrior::Warrior(const sf::Vector2f loc) : Players(WARRIOR, loc) {}


//------------------------------------ handleCollision ------------------------
// handle collision warrior with orc
//-----------------------------------------------------------------------------
void Warrior::handleCollision(Orc& gameObject)
{
    gameObject.setDisposedMode(true);
}


//------------------------------------ handleCollision ------------------------
//double dispatch
//-----------------------------------------------------------------------------
void Warrior::handleCollision(GameObject& gameObject)
{
    if (&gameObject == this) return;

    gameObject.handleCollision(*this);
}