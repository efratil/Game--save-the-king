#pragma once
//---------------- include  section ---------------
#include <SFML/Graphics.hpp>
#include "Resources.h"

//---------------- class section ------------------
//static
class Wall;
class Fire;
class Key;
class Gate;
class Throne;
class Orc;
class Teleport;
class DwarfGift;
class TimeGift;
//moves
class Warrior;
class King;
class Mage;
class Thief;
class SmartDwarf;
class DumbDwarf;

class GameObject
{
public:
	//constructor and distructor
	GameObject(const int, const sf::Vector2f);
	virtual ~GameObject() = default; 
	 
	//set
	void setSprite(const int, const sf::Vector2f);
	void setDisposedMode(const bool);
	void setScale        (const double);
	void setPosition     (const sf::Vector2f);
	void spriteMove      (const sf::Vector2f);
	void setTextureRect  (const sf::Vector2u);

    //get
	bool getIsDisposed()      const;
	sf::Vector2f getPosition()const; 
	sf::Sprite getSprite()    const;

	//handleCollision
	bool checkCollision(const GameObject&) const;
	virtual void handleCollision(GameObject&) = 0;
	//static obj
	virtual void handleCollision(Wall&)       = 0;
	virtual void handleCollision(Fire&)       = 0;
	virtual void handleCollision(Key&)        = 0;
	virtual void handleCollision(Gate&)       = 0;
	virtual void handleCollision(Throne&)     = 0;
	virtual void handleCollision(Orc&)        = 0;
	virtual void handleCollision(Teleport&)   = 0;
	virtual void handleCollision(DwarfGift&)  = 0;
	virtual void handleCollision(TimeGift&)   = 0;
	//moves obj
	virtual void handleCollision(King&)       = 0;
	virtual void handleCollision(Mage&)       = 0;
	virtual void handleCollision(Warrior&)    = 0;
	virtual void handleCollision(Thief&)      = 0;
	virtual void handleCollision(SmartDwarf&) = 0;
	virtual void handleCollision(DumbDwarf&)  = 0;

private:
	bool               m_isDisposed;
	sf::Sprite		   m_spriteOfObject;
};