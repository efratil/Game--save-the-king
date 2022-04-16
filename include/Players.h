#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "MovesObject.h"
#include "Resources.h"

class Players : public MovesObject
{
public:
	//c-tor
	Players(const int, const sf::Vector2f);
	//d-tor
	virtual ~Players(){}

	//handleCollision fits to all the players 
	virtual void handleCollision(TimeGift&)   override;
	virtual void handleCollision(DwarfGift&)  override;
	virtual void handleCollision(Teleport&)   override;

	//manage move 
	void move(const sf::Time&, const sf::Vector2f);
	sf::Vector2f getDirFromData(const sf::Vector2f = { 0,0 });
	void calcYFrame() override;


private:

};
