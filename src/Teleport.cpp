#include "Teleport.h"


//------------------------------------ constructor ----------------------------
//teleport constructor 
//-----------------------------------------------------------------------------
Teleport::Teleport(const sf::Vector2f loc) 
    : StaticObject(TELEPORT, loc), m_lockMode(true), m_pairTeleport(nullptr){}


//------------------------------------ handleCollision ------------------------
//double dispatch
//-----------------------------------------------------------------------------
void Teleport::handleCollision(GameObject& gameObject)
{
    if (&gameObject == this) return;

    gameObject.handleCollision(*this);
}


//------------------------------------ setPair --------------------------------
//sets the member to a pointer to the fited pointer
//-----------------------------------------------------------------------------
void Teleport::setPair(Teleport* toPointOn)
{
    m_pairTeleport = toPointOn;
}


//------------------------------------ getPair --------------------------------
//returns the pointer to the fit teleport
//-----------------------------------------------------------------------------
Teleport* Teleport::getPair()const
{
    return m_pairTeleport; 
}


//------------------------------------ setLock --------------------------------
//sets the boolian value of the member ->  true open false close
//-----------------------------------------------------------------------------
void Teleport::setLock(const bool mode)
{ 
    m_lockMode = mode;
}


//------------------------------------ getLockMode ----------------------------
//returns the boolian value that the member holds
//-----------------------------------------------------------------------------
bool Teleport::getLockMode() const
{
    return m_lockMode;
}


//------------------------------------ getIsPairLockOpen ----------------------
//get the boolian value of the pair teleport lock
//-----------------------------------------------------------------------------
bool Teleport::getIsPairLockOpen()const
{
    return m_pairTeleport->getLockMode();
}