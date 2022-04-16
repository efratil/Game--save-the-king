#pragma once
#include "Dwarf.h"

//in each collosion with a
//object that is not key - throne - 
//rands another direction to walk to. 
//the functionality of rands and setting new direction 
//in each collision are uniqe only for dumb dwarfs

//the collision of dumb dwarf is defferent than all the 
//other moving object because of the randering direction

class DumbDwarf : public Dwarf
{
public:
	//c-tor
	DumbDwarf(const sf::Vector2f, const int);
	//d-tor
	~DumbDwarf() {}

	//handle collision
	virtual void handleCollision(Teleport&)   override;
	virtual void handleCollision(Wall&)       override;
	virtual void handleCollision(Fire&)       override;
	virtual void handleCollision(Gate&)       override;
	virtual void handleCollision(Orc&)        override;

	//mives
	virtual void handleCollision(King&)       override;
	virtual void handleCollision(Mage&)       override;
	virtual void handleCollision(Warrior&)    override;
	virtual void handleCollision(Thief&)      override;
	virtual void handleCollision(SmartDwarf&) override;
	virtual void handleCollision(DumbDwarf&)  override;
	virtual void handleCollision(GameObject&) override;

	//move
	virtual void move(const sf::Time&, const sf::Vector2f);
	virtual sf::Vector2f getDirFromData(const sf::Vector2f = { 0,0 });

private:

};