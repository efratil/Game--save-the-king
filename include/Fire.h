#pragma once
#include "StaticObject.h"

class Fire : public StaticObject
{
public:
	//c-tor
	Fire(const sf::Vector2f);
	//d-tor
	~Fire() {}

	//handleCollision
	void handleCollision(GameObject&);	

private:

};