#pragma once
#include "Players.h"
#include "Fire.h"
#include "Teleport.h"

class Mage : public Players
{
public:
	//c-tor
	Mage(const sf::Vector2f);
	//d-tor
	~Mage() {}

	//handleCollision
	void handleCollision(Fire&);
	void handleCollision(Teleport&);
	void handleCollision(GameObject&);

private:

};
