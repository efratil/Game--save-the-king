#include "Mage.h"

//------------------------------------ constructor ----------------------------
// Mage constructor 
//-----------------------------------------------------------------------------
Mage::Mage(const sf::Vector2f loc) : Players(MAGE, loc) {}


//------------------------------------ handleCollision ------------------------
//double dispatch
//-----------------------------------------------------------------------------
void Mage::handleCollision(GameObject& gameObject)
{
    if (&gameObject == this) return;

    gameObject.handleCollision(*this);
}


//------------------------------------ handleCollision ------------------------
// handle collision thie with fire. tuen the fire dowm by turn the dispose mode
// of the fire
//-----------------------------------------------------------------------------
void Mage::handleCollision(Fire& gameObject)
{
    Resources::getInstance().playSound(FIRE_SOUND);
    gameObject.setDisposedMode(true);
}


//------------------------------------ handleCollision ------------------------
// handle collision thie with Teleport. The warrior is the only player that cant 
// sets from teleport to teleport. 
//-----------------------------------------------------------------------------
void Mage::handleCollision(Teleport& gameObject)
{
    if (gameObject.getLockMode())
    {
        gameObject.setLock(false);
        gameObject.getPair()->setLock(false);
    }
}