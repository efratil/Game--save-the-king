#include "GameObject.h"


//------------------------------------ constructor ----------------------------
// GameObject constructor 
//-----------------------------------------------------------------------------
GameObject::GameObject(const int iconNum, const sf::Vector2f loc) :m_isDisposed(false)
{ 
	setSprite(iconNum, loc);
}


//------------------------------------ get sprite -----------------------------
// get the sprite of the object
//-----------------------------------------------------------------------------
sf::Sprite GameObject::getSprite() const
{
	return m_spriteOfObject;
}


//------------------------------------ set sprite -----------------------------
// set the sprite of the object to the location anf fited texture
//-----------------------------------------------------------------------------
void GameObject::setSprite(const int iconNum, const sf::Vector2f loc)
{
	m_spriteOfObject.setTexture(*Resources::getInstance().getIcon(iconNum));
	m_spriteOfObject.setPosition(loc);
}



//------------------------------- check collision------------------------------
// check collision
//-----------------------------------------------------------------------------
bool GameObject::checkCollision(const GameObject& other)const
{
	if (&other == this) return false;

	return m_spriteOfObject.getGlobalBounds().intersects(other.m_spriteOfObject.getGlobalBounds()); 
}


//---------------------------------- getPosition-------------------------------
// return the location of the sprite object
//-----------------------------------------------------------------------------
sf::Vector2f GameObject::getPosition()const
{
	return m_spriteOfObject.getPosition(); 
}


//------------------------------ setDisposedMode-------------------------------
//gets a boolian value and update the private member
//-----------------------------------------------------------------------------
void GameObject::setDisposedMode(const bool mode)
{
	m_isDisposed = mode;
}


//----------------------------------- isDisposed-------------------------------
//returns the value of the private member
//-----------------------------------------------------------------------------
bool GameObject::getIsDisposed() const
{
	return m_isDisposed;
}


//------------------------------------ setScale -------------------------------
//get parameter to set the scale of the sprite
//-----------------------------------------------------------------------------
void GameObject::setScale(const double parmeter)
{
	m_spriteOfObject.scale(parmeter, parmeter);
}


//------------------------------------ setPosition -----------------------------
//get location to update the sprite
//-----------------------------------------------------------------------------
void GameObject::setPosition(const sf::Vector2f loc)
{
	m_spriteOfObject.setPosition(loc);
}


//------------------------------------ spriteMove -----------------------------
//get location to update the sprite
//-----------------------------------------------------------------------------
void GameObject::spriteMove(const sf::Vector2f nextLocation)
{
	m_spriteOfObject.move(nextLocation);
}


//------------------------------------ setTextureRect -------------------------
//
//-----------------------------------------------------------------------------
void GameObject::setTextureRect(const sf::Vector2u frameDirection)
{
	m_spriteOfObject.setTextureRect(sf::IntRect(frameDirection.x, frameDirection.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
}