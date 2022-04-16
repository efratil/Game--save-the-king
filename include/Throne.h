#pragma once
#include "StaticObject.h"

class Throne : public StaticObject
{
public:
	//c-tor
	Throne(const sf::Vector2f);

	//d-tor
	~Throne(){}

	//handleCollision
	void handleCollision(GameObject&);

private:

};
