#include "StaticObject.h"

//------------------------------------ constructor ----------------------------
//Key constructor 
//-----------------------------------------------------------------------------
StaticObject::StaticObject(const int enumIcon, const sf::Vector2f loc) 
	: GameObject(enumIcon, loc)
{
	setScale(SCALE);
}


//------------------------------------ disstructor ----------------------------
//d-tor
//-----------------------------------------------------------------------------
StaticObject::~StaticObject() {}