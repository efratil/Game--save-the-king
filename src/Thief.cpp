#include "Thief.h"

//------------------------------------ constructor ----------------------------
// Thief constructor 
//-----------------------------------------------------------------------------
Thief::Thief(const sf::Vector2f loc) : Players(THIEF, loc), m_hasAKey(false){}


//------------------------------------ getThiefHasAKey ------------------------
// returns the bool value that the member hasAkey holds.
//-----------------------------------------------------------------------------
bool Thief::getThiefHasAKey() const
{
    return m_hasAKey;
}


//------------------------------------ setThiefHasAKey ------------------------
// gets a boolian value to set to the private member hasAkey
//-----------------------------------------------------------------------------
void Thief::setThiefHasAKey(const bool mode)
{
    m_hasAKey = mode;
}


//------------------------------------ handleCollision ------------------------
//double dispatch
//-----------------------------------------------------------------------------
void Thief::handleCollision(GameObject& gameObject)
{
    if (&gameObject == this) return;

    gameObject.handleCollision(*this);
}


//------------------------------------ handleCollision ------------------------
// handle collision thie with key, thief can walk on key but for take the key 
// he needs to have no keys. while taking the key play sound, update the private 
// member and turn the dispose mode of the key.
//-----------------------------------------------------------------------------
void Thief::handleCollision(Key& gameObject)
{
    if (!m_hasAKey)
    {
        Resources::getInstance().playSound(KEY_SOUND);
        gameObject.setDisposedMode(true);
        setThiefHasAKey(true);
    }
    //else step on key
}


//------------------------------------ handleCollision ------------------------
//handle collision thie with gate, thief can open the gate only if he has a key. 
//while opening the gate he losethe key. block move without the key, update the key 
//private memvet of the king.
//-----------------------------------------------------------------------------
void Thief::handleCollision(Gate& gameObject)
{
    if (m_hasAKey)
    { 
        Resources::getInstance().playSound(OPEN_GATE_SOUND);
        gameObject.setDisposedMode(true);
        setThiefHasAKey(false);
    }
    else
    { //block move
        setSpriteToBackPos();
    }
}