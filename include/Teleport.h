#pragma once
#include "StaticObject.h"

//teleport is  an object -> has a constanst pair teleport
//ables to the player exept mage to move from the location
//of the first teleport to the location of the pair teleport
//the pair teleport is hold in a pointer private member
//the lock mode - true the teleport is open, false the 
//telport is occupied.

//in each collision of player(not mage) if the lock is open 
//the player can move and the teleport sets to lock (false).
//in each not collision with teleport and checking that any
//of the players arent standing on teleport sets the teleport 
//and his pair to open. 

class Teleport : public StaticObject
{
public:
	//c-tor
	Teleport(const sf::Vector2f);
	//d-tor
	~Teleport(){}

	//handleCollision
	void handleCollision(GameObject&);

	//get functions
	Teleport* getPair()      const;
	 bool getLockMode()      const;
	 bool getIsPairLockOpen()const;

	 //set functuins
	void setPair(Teleport*); 
	void setLock(const bool);

private:
	//lock of the teleport 
	bool       m_lockMode;
	//pointer to the pair teleport
	Teleport*  m_pairTeleport;
};
