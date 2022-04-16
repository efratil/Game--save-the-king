#pragma once
#include "Gifts.h"

//surprise gift
class DwarfGift : public Gifts
{
public:
	//c-tor
	DwarfGift(const sf::Vector2f);
	//d-tor 
	~DwarfGift(){}

	//handleCollision
	void handleCollision(GameObject& gameObject);

	//get the typeOfGift of dwarf
	int typeOfGift();

private:

};


