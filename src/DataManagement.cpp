#include "DataManagement.h"
#include "Controller.h"


//------------------------------------ constructor ----------------------------
// DataManagment constructor 
//-----------------------------------------------------------------------------
DataManagement::DataManagement(Controller & sendedController)
{
	m_controller = &sendedController;
}


//-------------------------------------- resetSprite  --------------------------
//reset the sprite to default (relevant while switching players)
//-----------------------------------------------------------------------------
void DataManagement::resetSprite(const int enumPlayer)
{
	m_movingObjectsVec[enumPlayer]->setSpriteFrameDefault();
}


//-------------------------------- setObjectArray -----------------------------
//make uniqe accept the type: (player) and the location to constructor
//-----------------------------------------------------------------------------
void DataManagement::setObjectArray()
{
	//clear vectors 
	m_TeleportsIndex.clear();
	m_staticObjectsVec.clear();
	m_movingObjectsVec.clear();

	//set
	m_movingObjectsVec.resize(4);
	m_board.getVectorsOfObjects(*this);

	//gets and set teleport
	pairTeleports();
}


//------------------------------------- moveObjects  --------------------------
// move objects from all type and send to manage handle collision
//-----------------------------------------------------------------------------
void  DataManagement::moveObjects(const sf::Time& deltaTime, const int curPlayer)
{
	//move current player
	move(deltaTime, curPlayer, curPlayer);

	//move dwrfs
	for (auto i = PLAYERS; i < m_movingObjectsVec.size(); i++)
	{
		move(deltaTime, i, curPlayer);
	}

	//handle collision manage
	handleCollision(*m_movingObjectsVec[curPlayer], curPlayer);
}


//-------------------------------------- move  --------------------------------
//move the object, send the time factor and cur player loc(relevant for dwarfs)
//-----------------------------------------------------------------------------
void DataManagement::move(const sf::Time& deltaTime, const int indexObj, const int curPlayer)
{
	m_movingObjectsVec[indexObj]->move(deltaTime, m_movingObjectsVec[curPlayer]->getPosition());
}


//-------------------------------------- enterToVector  -----------------------
// gets location and char the syboles a tile, build an object and enter to the
// right vector, for dwarfs need to rand number for their speed. for telrport
// enter the index in static onject to the vector 
//-----------------------------------------------------------------------------
void DataManagement::enterToVector(const char tileChar, const sf::Vector2f loc, const int numOfObjects)
{
	switch (tileChar)
	{
		//------- staticOBjects -------
	case TELEPORT_C:     m_staticObjectsVec.emplace_back(std::make_unique<Teleport>(loc));
	                     m_TeleportsIndex.emplace_back(numOfObjects);
		break;

	case  KEY_C:         m_staticObjectsVec.emplace_back(std::make_unique<Key>(loc));
		break;

	case  ORC_C:         m_staticObjectsVec.emplace_back(std::make_unique<Orc>(loc));
		break;

	case  WALL_C:        m_staticObjectsVec.emplace_back(std::make_unique<Wall>(loc));
		break;

	case  FIRE_C:        m_staticObjectsVec.emplace_back(std::make_unique<Fire>(loc));
		break;

	case  THRONE_C:      m_staticObjectsVec.emplace_back(std::make_unique<Throne>(loc));
		break;

	case  GATE_C:        m_staticObjectsVec.emplace_back(std::make_unique<Gate>(loc));
		break;

	case  TIME_GIFT_C:   m_staticObjectsVec.emplace_back(std::make_unique<TimeGift>(loc));
		break;

	case  DWARF_GIFT_C: m_staticObjectsVec.emplace_back(std::make_unique<DwarfGift>(loc));
		break;

		//--------- players -------------
	case  KING_C:       m_movingObjectsVec[KING] = std::make_unique<King>(loc);
		break;

	case  MAGE_C:       m_movingObjectsVec[MAGE] = std::make_unique<Mage>(loc);
		break;

	case  THIEF_C:      m_movingObjectsVec[THIEF] = std::make_unique<Thief>(loc);
		break;

	case  WARRIOR_C:    m_movingObjectsVec[WARRIOR] = std::make_unique<Warrior>(loc);
		break;

		//----------- dwrfs -----------
	case  SMART_DWARF_C:m_movingObjectsVec.emplace_back(std::make_unique<SmartDwarf>(loc, ShapeSize*(rand()%5 +4)));
		break;

	default:            m_movingObjectsVec.emplace_back(std::make_unique<DumbDwarf>(loc, ShapeSize*(rand()%5 + 4)));
		break;
	}
}


//-------------------------------------- pairTeleports  -----------------------
// responsible to pair the teleports in the static objects vec together. 
// define to cases -> pair the teleports in jump of 2, 0-2 1-3..
// the num of teleports is even so the pairing in that optjion needs to define 
// in the num of iteration we did in the loop. even iteration means all the teleports
// got a pair while odd iteration means there are two teleports, the two last, 
// that waits to pair in that case they will pair together like 4,5 in 6 teleports
//-----------------------------------------------------------------------------
void DataManagement::pairTeleports()
{
	//case of two teleports only 
	if (m_TeleportsIndex.size() == 2)
	{
		setPairsOfTeleport(m_TeleportsIndex[0], m_TeleportsIndex[1]);
		return;
	}

	//pair teleports
	for (auto i = 0; i < m_TeleportsIndex.size() / 2; i++)
	{
		auto j = (__int64)2 * i;

		if (i % 2 == 0)
		{
			setPairsOfTeleport(m_TeleportsIndex[j], m_TeleportsIndex[j + 2]);
		}
		else
		{
			setPairsOfTeleport(m_TeleportsIndex[j - 1], m_TeleportsIndex[j + 1]);
		}
	}

	//case of odd num of iteration in the previos loop -> need to pair the last teleport together
	if ((m_TeleportsIndex.size() / 2) % 2 != 0)
	{
		setPairsOfTeleport(m_TeleportsIndex[m_TeleportsIndex.size() - 1], m_TeleportsIndex[m_TeleportsIndex.size() - 2]);
	}
}


//----------------------------------- setPairsOfTeleport ----------------------
// pairing the fits teleports pairs. Those teleports just entered to the smart
// pointers vector, in that case the pairing is between the last object to the
// one before him and same in the other way
//-----------------------------------------------------------------------------
void DataManagement::setPairsOfTeleport(const int loc1, const int loc2)
{
	static_cast<Teleport*>(m_staticObjectsVec[loc1].get())->setPair(static_cast<Teleport*>(m_staticObjectsVec[loc2].get()));
	static_cast<Teleport*>(m_staticObjectsVec[loc2].get())->setPair(static_cast<Teleport*>(m_staticObjectsVec[loc1].get()));
}


//-------------------------------------- display  -----------------------------
// display the viarbles in the vectors
//-----------------------------------------------------------------------------
void DataManagement::display(sf::RenderWindow& gameWindow)
{
	//print the static object
	for (auto& unmovable : m_staticObjectsVec)
	{
		gameWindow.draw(unmovable->getSprite());
	}

	//print the moving object
	for (auto& movable : m_movingObjectsVec)
	{
		gameWindow.draw(movable->getSprite());
	}
}


//-------------------------------------- getKeyData  --------------------------
//use RTTI in order to access the check if the thief has a key
//-----------------------------------------------------------------------------
bool DataManagement::getKeyData()
{
	return static_cast<Thief*> (m_movingObjectsVec[THIEF].get())->getThiefHasAKey();
}


//-------------------------------------- isLevelEnd ---------------------------
//use RTTI in order to access the check if the the king is on throne
//-----------------------------------------------------------------------------
bool DataManagement::isLevelEnd()
{
	return static_cast<King*> (m_movingObjectsVec[KING].get())->getIsKingOnThrone();
}


//----------------------------------- handleCollision -------------------------
//handle collision between moves object and itself, and between moves object
//and static object
//-----------------------------------------------------------------------------
void DataManagement::handleCollision(MovesObject& gameObject, const int curPlayer)
{
	handleCollisionWithMovesObjects(gameObject);
	handleCollisionWithStaticObjects(gameObject, curPlayer);

	for (auto i = PLAYERS; i < m_movingObjectsVec.size(); i++)
	{
		// handle collision between dwarfs and moving object
		handleCollisionWithDwarfs(*m_movingObjectsVec[i]);
	}
}


//---------------------- handleCollisionWithDwarfs ----------------------------
//handle collision with dwarf
//-----------------------------------------------------------------------------
void DataManagement::handleCollisionWithDwarfs(MovesObject& gameObject)
{
	for (auto& unmovable : m_staticObjectsVec)
	{
		if (gameObject.checkCollision(*unmovable))
		{
			unmovable->handleCollision(gameObject);
		}
	}

	//check collision with other dwarfs and players
	handleCollisionWithMovesObjects(gameObject);
}


//---------------------- handleCollisionWithStaticObjects ---------------------
//handle collision with static objects
//-----------------------------------------------------------------------------
void DataManagement::handleCollisionWithStaticObjects(MovesObject& gameObject, const int curPlayer)
{
	for (auto& unmovable : m_staticObjectsVec)
	{
		if (gameObject.checkCollision(*unmovable))
		{
			unmovable->handleCollision(gameObject);
			dropAkeyEvent(*unmovable, curPlayer);
			giftEvent(unmovable);
		}
		else teleportEvent(unmovable);
	}

	eraseStaticObjects();
}


//----------------------- handleCollisionWithMovesObjects ---------------------
//handle collision with moves objects
//-----------------------------------------------------------------------------
void DataManagement::handleCollisionWithMovesObjects(MovesObject& gameObject)
{
	for (auto& movable : m_movingObjectsVec)
	{
		if (gameObject.checkCollision(*movable))
		{
			if (&gameObject != &(*movable))
			{
				movable->handleCollision(gameObject);
			}
		}
	}
}


//----------------------------------- dropAkeyEvent ---------------------------
//handling a case where the worrior collided with an orc, he should drop a key
//-----------------------------------------------------------------------------
void DataManagement::dropAkeyEvent(StaticObject& unmovable, const int curPlayer)
{
	if (typeid(Orc) == typeid(unmovable) && curPlayer == WARRIOR)
	{
		enterToVector(KEY_C, unmovable.getPosition(), 0);
	}
}


//----------------------------------- teleportEvent ---------------------------
//handling a case where there is a collision of the characters that they are allowed
//to pass through the teleport, with the teleport itself ant the pair 
//-----------------------------------------------------------------------------
void DataManagement::teleportEvent(std::unique_ptr<StaticObject>& unmovable)
{
	if (typeid(Teleport) == typeid(*unmovable))
	{
		Teleport* teleport = dynamic_cast<Teleport*> (unmovable.get());

		if (!teleport->getLockMode() && isTeleportFree(teleport->getPair()) && isTeleportFree(teleport))
		{
			teleport->setLock(true);
			teleport->getPair()->setLock(true);
		}
	}
}


//----------------------------------- isTeleportFree ---------------------------
//while in valid collision with teleport and player the teleport and its pair sets to lock 
// the time the lock will be open is only if there is none player on the second teleport that 
// distrub the transport -> runs on all the player and check if there is collision with
// the teleport pair
//-----------------------------------------------------------------------------
bool DataManagement::isTeleportFree(Teleport* obj)
{
	for (int i = 0; i < PLAYERS; i++)
	{
		if (m_movingObjectsVec[i]->checkCollision(*obj))
		{
			return false;
		}
	}
	return true;
}


//--------------------------------------- giftEvent ---------------------------
//handling a case where there is a conflict of the characters with the gifts.
//A distinction between the gift of time and the gift of dwarves.
//-----------------------------------------------------------------------------
void DataManagement::giftEvent(std::unique_ptr<StaticObject>& unmovable)
{
	if (typeid(TimeGift) == typeid(*unmovable))
	{
		timeGiftEvent(unmovable);
	}

	else if (typeid(DwarfGift) == typeid(*unmovable))
	{
		DwarfGiftEvent(unmovable);
	}
}


//--------------------------------------- DwarfGiftEvent ----------------------
//adding / reducing dwarfs and speed by accessing the DwarfGift class
//-----------------------------------------------------------------------------
void DataManagement::DwarfGiftEvent(std::unique_ptr<StaticObject>& unmovable)
{
	auto auxPtr = static_cast<DwarfGift*> (unmovable.get());
	int type = auxPtr->typeOfGift();

	//earse dwarfs 
	if (type == 0) eraseDwarf();

	//add onw dwarf
	if (type == 1) enterToVector(DUMB_DWARF_C, auxPtr->getPosition(), 0);

	//remove dwarf
	if (type == 2)
	{
		if (m_movingObjectsVec.size() > PLAYERS)
		{
			m_movingObjectsVec[PLAYERS].get()->setDisposedMode(true);
			eraseMovesObjects();
		}
	}

	//add speed
	if (type == 3) ChangeSpeed(3 * ShapeSize);

	//remove seed
	if (type == 4) ChangeSpeed(-3 * ShapeSize);

	m_controller->GiftEvent(type);
}


//------------------------------------ ChangeSpeed  ---------------------------
// gets speed and update all the dwarfs in the vec using rtti
//-----------------------------------------------------------------------------
void DataManagement::ChangeSpeed(const float speed)
{
	for (auto i = PLAYERS; i < m_movingObjectsVec.size(); i++)
	{
		static_cast<Dwarf*> (m_movingObjectsVec[i].get())->setSpeed(speed);
	}
}


//-------------------------------------- eraseDwarf ---------------------------
//erase the dwarf 
//-----------------------------------------------------------------------------
void DataManagement::eraseDwarf()
{
	for (auto i = PLAYERS; i < m_movingObjectsVec.size(); i++)
	{
		m_movingObjectsVec[i].get()->setDisposedMode(true);
	}

	eraseMovesObjects();
}


//--------------------------------eraseMovesObjects ---------------------------
//erase one of the moving object from the moves vector
//-----------------------------------------------------------------------------
void DataManagement::eraseMovesObjects()
{
	std::erase_if(m_movingObjectsVec, [](auto& movable)
	{
			return movable->getIsDisposed();
	});
}


//------------------------------- eraseStaticObjects --------------------------
//erase one of the moving object from the moves vector
//-----------------------------------------------------------------------------
void DataManagement::eraseStaticObjects()
{
	std::erase_if(m_staticObjectsVec, [](auto& unmovable)
	{
			return unmovable->getIsDisposed();
	});
}


//----------------------------------- timeGiftEvent ---------------------------
//adding / reducing time management by accessing the TimeGift class
//-----------------------------------------------------------------------------
void DataManagement::timeGiftEvent(std::unique_ptr<StaticObject>& unmovable)
{
	m_controller->setTimer(static_cast<TimeGift*> (unmovable.get())->timeBonus());
}


//-------------------------------------- setBoard  ----------------------------
// call to board to set the char matrix of the level
//-----------------------------------------------------------------------------
void DataManagement::setBoard()
{
	m_board.setBoard();
}


//-------------------------------------- reloadBoard  -------------------------
//calls to board to reload the file, move the index fron eof to the begginig
//-----------------------------------------------------------------------------
void DataManagement::reloadBoard()
{
	m_board.reloadBoard();
}


//------------------------------------ getLevelTime  --------------------------
//call to board to return rhe level time
//-----------------------------------------------------------------------------
int DataManagement::getLevelTime()
{
	return  m_board.getLevelTime();
}


//---------------------------------- isNoMoreLevels  --------------------------
// return if the file index is on eof()
//-----------------------------------------------------------------------------
bool DataManagement::isNoMoreLevels()
{
	return m_board.endOfStages();
}