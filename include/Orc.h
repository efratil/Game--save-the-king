#pragma once
#include "StaticObject.h"

class Orc : public StaticObject
{
public:
	//c-tor
	Orc(const sf::Vector2f);
	//d-tor
	~Orc(){}

	//handleCollision
	void handleCollision(GameObject&);

private:

};