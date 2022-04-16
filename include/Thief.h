#pragma once
#include "Players.h"
#include "Resources.h"
#include "Key.h"
#include "Gate.h"

class Thief : public Players
{
public:
	//c-tor
	Thief(const sf::Vector2f);
	//d-tor
	~Thief() {}

	//get
	bool getThiefHasAKey() const; 
	//set
	void setThiefHasAKey(const bool);

	//handleCollision
	void handleCollision(GameObject&);
	void handleCollision(Key&);
	void handleCollision(Gate&);

private:
	bool m_hasAKey; 

};
