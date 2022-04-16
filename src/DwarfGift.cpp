#include "DwarfGift.h"


//------------------------------------ constructor ----------------------------
//Dwarf Gift constructor 
//-----------------------------------------------------------------------------
DwarfGift::DwarfGift(const sf::Vector2f loc) :Gifts(loc) {}


//------------------------------------ handleCollision ------------------------
// double dispatch
//-----------------------------------------------------------------------------
void DwarfGift::handleCollision(GameObject& gameObject)
{
    if (&gameObject == this) return;
   
    gameObject.handleCollision(*this);
}


//------------------------------------ typeOfGift -----------------------------
// return number {0,1,2,3,4}, the object is responsible to the dward gifts. 
// there are add dwarf, remove dwarf, delete all dward, fits to constans vals 
//-----------------------------------------------------------------------------
int DwarfGift::typeOfGift()
{
    return (rand() % 5);
}