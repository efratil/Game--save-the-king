#pragma once
#include "StaticObject.h"

class Key : public StaticObject
{
public:
	//c-tor
	Key(const sf::Vector2f);
	//d-tor
	~Key(){}

	//handleCollision
	void handleCollision(GameObject&);

private:

};