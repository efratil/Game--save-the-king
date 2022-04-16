#include "King.h"


//------------------------------------ constructor ----------------------------
// king c - tor
//-----------------------------------------------------------------------------
King::King(const sf::Vector2f loc) : Players(KING, loc), m_isOnThrone(false){}


//------------------------------------ handleCollision ------------------------
//double dispatch
//-----------------------------------------------------------------------------
void King::handleCollision(GameObject& gameObject)
{
    if (&gameObject == this) return;

    gameObject.handleCollision(*this);
}


//------------------------------------ getIsKingOnThrone ----------------------
//get function return the bvalue of the private member m_isOnThrone
//-----------------------------------------------------------------------------
bool King::getIsKingOnThrone() const
{
    return m_isOnThrone;
}


//------------------------------------ handleCollision ------------------------
//set function gets a boolian value and sets the private member
//-----------------------------------------------------------------------------
void King::handleCollision(Throne& gameObject)
{
    m_isOnThrone = true;
    gameObject.setDisposedMode(true);
}