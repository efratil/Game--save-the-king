#include "TimeGift.h"


//------------------------------------ constructor ----------------------------
//Time Gift constructor 
//-----------------------------------------------------------------------------
TimeGift::TimeGift(const sf::Vector2f loc) :Gifts(loc){}


//------------------------------------ handleCollision ------------------------
// double dispatch
//-----------------------------------------------------------------------------
void TimeGift::handleCollision(GameObject& gameObject)
{
    if (&gameObject == this) return;
   
    gameObject.handleCollision(*this);
}


//------------------------------------ timeBonus -----------------------------
// return number from -15 to +15, the object is responsible to the time gifts. 
// add the number to the game time.
//-----------------------------------------------------------------------------
int TimeGift::timeBonus()
{
    return (rand() % 30 - 15);
}
