#pragma once
#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	//c-tor
	Wall(const sf::Vector2f);
	//d-tor
	~Wall(){}

	//handleCollision
	void handleCollision(GameObject&);

private:

};
