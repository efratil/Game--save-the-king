#pragma once
#include "Players.h"
#include "Orc.h"

class Warrior : public Players
{
public:
	//c- tor 
	Warrior(const sf::Vector2f);
	//d-tor
	~Warrior() {}

	//handle Collision
	void handleCollision(Orc&);
	void handleCollision(GameObject&);

private:

};
