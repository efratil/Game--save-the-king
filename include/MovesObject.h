#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "GameObject.h"
#include "Resources.h"


class MovesObject : public GameObject
{
public:
	//c-tor
	MovesObject(const int, const sf::Vector2f);
	//d-tor
	virtual ~MovesObject(){}

	//virtual
	virtual void handleCollision(GameObject&) = 0;
	virtual void move(const sf::Time&, const sf::Vector2f = {0,0}) = 0;
	virtual sf::Vector2f getDirFromData(const sf::Vector2f = {0, 0}) = 0;

	//static
	virtual void handleCollision(Wall&)       override;
	virtual void handleCollision(Fire&)       override;
	virtual void handleCollision(Gate&)       override;
	virtual void handleCollision(Throne&)     override;
	virtual void handleCollision(Orc&)        override;
	virtual void handleCollision(Key&)        override {}

	//mives
	virtual void handleCollision(King&)       override;
	virtual void handleCollision(Mage&)       override;
	virtual void handleCollision(Warrior&)    override;
	virtual void handleCollision(Thief&)      override;
	virtual void handleCollision(SmartDwarf&) override;
	virtual void handleCollision(DumbDwarf&)  override;

	//set
	void setSpriteFrame       ();
	void setSpriteFrameDefault();
	void setSprite            ();
	void setFrameDirection (const sf::Vector2u);
	void setPreLoc         (const sf::Vector2f);
	void setYFrameDirection(const int);

	//for sprite cutting
	virtual void calcYFrame() = 0;
	        void calcXFrame();

	//for moving
	bool iscontainInBoard(sf::Vector2f);
	void setSpriteToBackPos();

	//get
	sf::Vector2f getPreLoc()        const;
	sf::Vector2u getFrameDirection() const;

private:
	sf::Vector2u     m_frameDirection;  //keep the indexes of the sprite cutting
	sf::Vector2f     m_preLoc;          //keep the last location before moving
};