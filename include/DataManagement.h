#pragma once
#include "Board.h"

//tiles 
#include "Key.h"
#include "Fire.h"
#include "Gate.h"
#include "Orc.h"
#include "Fire.h"
#include "Wall.h"
#include "Throne.h"
#include "Teleport.h"
#include "DwarfGift.h"
#include "TimeGift.h"

#include "King.h"
#include "Mage.h"
#include "Thief.h"
#include "Warrior.h"
#include "SmartDwarf.h"
#include "DumbDwarf.h"

#include "StaticObject.h"
#include "MovesObject.h"

class Controller; 

//Managing the objects smart pointers vectors and 
//connects between board to controller
class DataManagement
{
public:
	//c-tor
	DataManagement(Controller&);
	//d-tor
	~DataManagement() {}

	//set
	void reloadBoard       ();
	void setBoard          ();
	void setObjectArray    ();
	void resetSprite       (const int = KING);
	void enterToVector     (const char, const sf::Vector2f, const int);

	//get data
	int  getLevelTime  ();
	bool getKeyData    ();
	bool isNoMoreLevels();
	bool isLevelEnd    ();

	//display
	void display(sf::RenderWindow&);

	//move
	void move(const sf::Time&, const int, const int);
	void moveObjects(const sf::Time&, const int);


private:
	Board       m_board; 
	Controller* m_controller;

	//holds the indexes of the teleports 
	std::vector <int> m_TeleportsIndex;

	//the objects of the game
	std::vector < std::unique_ptr <StaticObject>> m_staticObjectsVec;
	std::vector < std::unique_ptr <MovesObject>> m_movingObjectsVec;


	//handleCollision
	void handleCollision                 (MovesObject&, const int);
	void handleCollisionWithStaticObjects(MovesObject&, const int);
	void handleCollisionWithMovesObjects (MovesObject&);
	void handleCollisionWithDwarfs       (MovesObject&);


	//handleCollision events
	void giftEvent     (std::unique_ptr<StaticObject>&);
	void DwarfGiftEvent(std::unique_ptr<StaticObject>&);
	void timeGiftEvent (std::unique_ptr<StaticObject>&);
	void teleportEvent (std::unique_ptr<StaticObject>&);
	void dropAkeyEvent (StaticObject&, const int);
	void ChangeSpeed   (const float);


	//erase
	void eraseDwarf        ();
	void eraseMovesObjects ();
	void eraseStaticObjects();


	//teleports func
	void setPairsOfTeleport(const int, const int);
	void pairTeleports     ();
	bool isTeleportFree    (Teleport*);
};