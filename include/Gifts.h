#pragma once
#include "StaticObject.h"

class Gifts : public StaticObject
{
public:
	//c-tor
	Gifts(const sf::Vector2f);
	//d-tor
	virtual ~Gifts() {}

	//handleCollision
	virtual void handleCollision(GameObject&) = 0;

private:
	
};