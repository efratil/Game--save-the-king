#pragma once
#include "StaticObject.h"

class Gate : public StaticObject
{
public:
	//c-tor
	Gate(const sf::Vector2f);
	//d-tor
	~Gate() {}

	//handleCollision
	void handleCollision(GameObject&);

private:

};