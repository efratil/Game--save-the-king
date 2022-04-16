#pragma once
#include "MovesObject.h"
#include "King.h"
#include "Mage.h"

//the dwarfs takes place as enemies in the game.
//Enemies, stuck in the way of the players. 
//Walks on their own and 
class Dwarf : public MovesObject
{
public:
	//c-tor
	Dwarf(const sf::Vector2f, const int, const int);
	//d-tor
	virtual ~Dwarf(){}

	//movability func
	void setDir();
	void setDir(const int);
	void calcYFrame();
	int  GetCurDirection() const { return m_direction; }

	float getSpeed() const;
	void  setSpeed(const float);

	//handleCollision fits to all kinds of dwarfs
	virtual void handleCollision(Throne&)     override {}
	virtual void handleCollision(TimeGift&)   override {}
	virtual void handleCollision(DwarfGift&)  override {}
	        void DwarfHandleCollision();

private:
	int   m_direction; 
	float m_shapeSpeed;

};