#pragma once
#include "Gifts.h"

//surprise gift
class TimeGift : public Gifts
{
public:
	//c-tor 
	TimeGift(const sf::Vector2f);
	//d-tor 
	~TimeGift(){}

	//handleCollision
	void handleCollision(GameObject& gameObject);

	//the bonus func 
	int timeBonus(); 

private:

};