#pragma once
#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	//c-tor
	StaticObject(const int, const sf::Vector2f);
	// d-tor
	virtual ~StaticObject();

	//double dispatch  collision
	virtual void handleCollision(GameObject&) = 0;

	//moving objects
	virtual void handleCollision(King&)       override {}
	virtual void handleCollision(Mage&)       override {}
	virtual void handleCollision(Warrior&)    override {}
	virtual void handleCollision(Thief&)      override {}
	virtual void handleCollision(SmartDwarf&) override {}
	virtual void handleCollision(DumbDwarf&)  override {}

	//statoc objects
	virtual void handleCollision(Wall&)       override {}
	virtual void handleCollision(Fire&)       override {}
	virtual void handleCollision(Key&)        override {}
	virtual void handleCollision(Gate&)       override {}
	virtual void handleCollision(Throne&)     override {}
	virtual void handleCollision(Orc&)        override {}
	virtual void handleCollision(TimeGift&)   override {}
	virtual void handleCollision(DwarfGift&)  override {}
	virtual void handleCollision(Teleport&)   override {}

private:
};