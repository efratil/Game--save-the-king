#pragma once
#include "Players.h"
#include "Throne.h"

class King : public Players
{
public:
	//c-tor
	King(const sf::Vector2f);
	//d-tor
	~King() {}

	//handle Collision
	void handleCollision(Throne&);
	void handleCollision(GameObject&);

	//get
	bool getIsKingOnThrone() const; 

private:
	bool m_isOnThrone; 

};
