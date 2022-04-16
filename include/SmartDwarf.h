#pragma once
#include "Dwarf.h"

//smart enemies know to 
class SmartDwarf : public Dwarf
{
public:
	//c-tor
	SmartDwarf(const sf::Vector2f, const int);
	//d-tor
	~SmartDwarf() {}

	//handle colliaion
	virtual void handleCollision(Teleport&)   override;
	virtual void handleCollision(GameObject&) override;
	virtual void handleCollision(SmartDwarf&) override {}
	 
	//move
	virtual void move(const sf::Time&, const sf::Vector2f);
	virtual sf::Vector2f getDirFromData(const sf::Vector2f);
	void setDirection(float, float);

private:
	float m_curRange;
};