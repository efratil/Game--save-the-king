#include "Controller.h"

//------------------------------------ constructor ----------------------------
// Controller constructor 
//-----------------------------------------------------------------------------
Controller::Controller() : m_window({ 1920,1080 }, "SAVE THE KING!"), m_event(),
						   m_inGame(false), m_levelNum(0), m_manageData(*this),
						   m_lives(3), m_timeOfGame(0), m_currentPlayer(KING), 
	                       m_soundVolume(true), m_pause(false)
{
	//set icon for window 
	sf::Image i = Resources::getInstance().getGameIcon();
	m_window.setIcon(i.getSize().x, i.getSize().y, i.getPixelsPtr());
}


//-------------------------------- run ----------------------------------------
//runs and set the game
//-----------------------------------------------------------------------------
void Controller::run()
{
	m_gameScreen.loadScreen(m_window, OPEN, 2);

	while (m_window.isOpen())
	{
		if (m_inGame)
		{
			runGame();
		}

		else
		{
			manageMenuscreenEvents();
			m_menuScreen.display(m_window);
		}
	}
}


//------------------------ manageMenuscreenEvents -----------------------------
//manage all the three options in the menu: close, button click and mouse moved
//-----------------------------------------------------------------------------
void Controller::manageMenuscreenEvents()
{
	while (m_window.pollEvent(m_event))
	{
		switch (m_event.type)
		{
		case CLOSE_WINDOW:
			handleExitEvent();
			break;

		case BUTTON_CLICKED:
			handleMenuClickEvent();
			break;

		case MOUSE_MOVED:
			handleMouseMovedEvent();
			break;
		}
	}
}


//----------------------------------- handleClickEvent ------------------------
//manage the location tf the mouse (x,y) and check where the user choose
// to click on
//-----------------------------------------------------------------------------
void Controller::handleMenuClickEvent()
{
	int button    = IN_MENU;
	auto mouseLoc = m_window.mapPixelToCoords({ m_event.mouseButton.x, m_event.mouseButton.y });
	m_menuScreen.manageClick(button, mouseLoc);

	//check if user clicked on exit/start
	if (button == EXIT)    handleExitEvent();
	if (button == IN_GAME) intiliesGameVaribles();
}


//------------------------------ intiliesGameVaribles -------------------------
//intilies the members in the game by the data in the beggining of the game
//-----------------------------------------------------------------------------
void Controller::intiliesGameVaribles()
{
	m_inGame        = true;
	m_currentPlayer = 0;
	m_lives         = 3; 
	m_levelNum      = 0; 
	m_manageData.reloadBoard();
}


//------------------------------ handleMouseMovedEvent ------------------------
//handle the mouse moved event by the location of the mouse
//-----------------------------------------------------------------------------
void Controller::handleMouseMovedEvent()
{
	auto mouseLoc = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
	m_menuScreen.truckOnMouse(mouseLoc);
}


//----------------------------------------runGame------------------------------
//the beggining of the game: run the game by set the first level and than in  
//case that the level end- coninue to the next level. check the timer data
//and less the lives by him
//-----------------------------------------------------------------------------
void Controller::runGame()
{
	//check if end game 
	if (m_manageData.isNoMoreLevels()) isGameOver();

	//set the level and load screen 
	setLevel();

	//run the game 
	while (m_inGame && m_lives > 0 && m_timeOfGame > 0 && !m_manageData.isLevelEnd())
	{
		manageGameScreenEvents();
		if (!m_pause)
		{
			timer();
			UpdateObjects();
		}
		displayGame();
	}

	//the level is end update the varibales
	if (m_timeOfGame <= 0)
	{
		m_lives--;
	}
	else if(m_manageData.isLevelEnd())
	{
		m_levelNum++;
	}

	//checl if game is end
	isGameOver();
}


//-------------------------------- setLevel -----------------------------------
//set the level 
//-----------------------------------------------------------------------------
void Controller::setLevel()
{
	Resources::getInstance().pauseSound(m_levelNum);
	
	if (m_timeOfGame <=0 && m_lives > 0 && m_levelNum != 0)
	{
		loseLevel();
	}
	else if(!m_manageData.isNoMoreLevels())
	{
		winLevel();
	}

	m_manageData.setObjectArray();
	m_currentPlayer = KING;
	Resources::getInstance().playMusic(m_levelNum);
	m_manageData.resetSprite(KING);
	m_timeOfGame = m_manageData.getLevelTime();
}


//----------------------------------is Game Over-------------------------------
//set the screen by the user situation: lose or win
//-----------------------------------------------------------------------------
void Controller::isGameOver()
{
	if (m_lives > 0 && m_levelNum <= LEVELS) return; 

	Resources::getInstance().pauseSound(m_levelNum);

	if (m_lives == 0)
	{
		m_gameScreen.loadScreen(m_window, GAME_OVER, 3);
	}
	else
	{ 
		m_gameScreen.loadScreen(m_window, WON, 4);
	}
	
	setBackToMenu();
}


//---------------------------------- lose level -------------------------------
//set the lose screen, called when the player is disqualified
//-----------------------------------------------------------------------------
void Controller::loseLevel()
{
	m_currentPlayer = KING;
	Resources::getInstance().playSound(LOSE_SOUND);
	sf::sleep(sf::seconds(2));
}


//---------------------------------- win level -------------------------------
//set the win screen, called when the player is win
//-----------------------------------------------------------------------------
void Controller::winLevel()
{
	if (m_levelNum == 0) m_levelNum++;

	m_gameScreen.loadScreen(m_window, m_levelNum, 3);
	m_gameScreen.setBackground(m_levelNum);
	m_manageData.setBoard();
}


//-------------------------------- timer --------------------------------------
//Prepares the timer to be displayed in the game
//-----------------------------------------------------------------------------
void Controller::timer()
{
	if (m_gameClock.getElapsedTime().asSeconds() > 1)
	{
		--m_timeOfGame;
		m_gameClock.restart();
	}
}


//--------------------------- manageMenuscreenEvents --------------------------
//manage the menu screen evevt: exit and keyboard event(p, ecs, space)
//-----------------------------------------------------------------------------
void Controller::manageGameScreenEvents()
{
	while (m_window.pollEvent(m_event))
	{
		switch (m_event.type)
		{
		case CLOSE_WINDOW:
			handleExitEvent();
			break;

		case KEYBOARD_CLICK:
			handleKeyboardEvent();
			break; 

		case BUTTON_CLICKED:
			handleGameClickEvent();
			break;
		}
	}
}


//----------------------------------- handleClickEvent ------------------------
//manage the location tf the mouse (x,y) and check where the user choose
// to click on
//-----------------------------------------------------------------------------
void Controller::handleGameClickEvent()
{
	sf::RectangleShape auxRec;
	auxRec.setSize(sf::Vector2f(80, 60));
	auto mouseLoc = m_window.mapPixelToCoords({ m_event.mouseButton.x, m_event.mouseButton.y });

	//+ button
	auxRec.setPosition(sf::Vector2f(1800, 70));
	if (auxRec.getGlobalBounds().contains(mouseLoc))
	{
		Resources::getInstance().setVolume(true);
		return;
	}
	
	//- button
	auxRec.setPosition(sf::Vector2f(1800, 130));
	if (auxRec.getGlobalBounds().contains(mouseLoc))
	{
		Resources::getInstance().setVolume(false);
		return; 
	}

	//pause button
	auxRec.setPosition(sf::Vector2f(1800, 190));
	if (auxRec.getGlobalBounds().contains(mouseLoc))
	{
		m_pause = !m_pause; 
		return;
	}
}


//---------------------------------- handleExitEvent --------------------------
//case the user press the exit button
//-----------------------------------------------------------------------------
void Controller::handleExitEvent()
{
	Resources::getInstance().pauseSound(m_levelNum);
	m_window.close();
}


//---------------------------------- handleKeyEvent ---------------------------
//case the user presses a key from the keyboard keys
//-----------------------------------------------------------------------------
void Controller::handleKeyboardEvent()
{
	if (m_event.key.code == ESCAPE) //end game 
		handleExitEvent();

	if (m_event.key.code == SPACE) //return to menu window
		setBackToMenu();

	if (m_event.key.code == P_KEY)  //switch character
		setCurPlayer();
}


//-------------------------------- backToMenu ---------------------------------
//if the user press on space he wants return to menu window
//-----------------------------------------------------------------------------
void Controller::setBackToMenu()
{
	Resources::getInstance().pauseSound(m_levelNum);

	m_inGame = false;
	Resources::getInstance().setVolumeToDefault();

	if (!m_menuScreen.isOnMute())
	{
		Resources::getInstance().playMusic(MENU_SOUND);
	}
}


//-------------------------------- setCurPlayer -------------------------------
//set the current player to next player
//-----------------------------------------------------------------------------
void Controller::setCurPlayer()
{
	m_manageData.resetSprite(m_currentPlayer);
	m_currentPlayer++;

	if (m_currentPlayer > PLAYERS - 1)
	{
		m_currentPlayer = 0;
	}
}


//----------------------------------- UpdateObjects ---------------------------
//update players to move with move(deltaTime)
//-----------------------------------------------------------------------------
void Controller::UpdateObjects()
{
	static sf::Clock moveClock;
	const auto deltaTime = moveClock.restart();

	m_manageData.moveObjects(deltaTime, m_currentPlayer);
}


//-------------------------------------- displayGame --------------------------
//manage all the game prints
//-----------------------------------------------------------------------------
void  Controller::displayGame()
{
	//delete screen
	m_window.clear();

	//display the game screen
	m_gameScreen.display(m_window, m_currentPlayer, m_manageData.getKeyData(), m_timeOfGame, m_lives, m_levelNum, m_pause);

	//print the objects only if not in pause mode
	if(!m_pause)m_manageData.display(m_window);

	m_window.display();
}


//--------------------------------------- giftEvent ---------------------------
// in gift event case needed to print msg
//-----------------------------------------------------------------------------
void Controller::GiftEvent(const int type)
{
	m_gameScreen.setDwarfGiftData(m_window, type);
}


//--------------------------------------- setTimer ----------------------------
// set the timer - add the game level clock the time
//-----------------------------------------------------------------------------
void Controller::setTimer(const int time)
{
	m_timeOfGame += time;
	m_gameScreen.setTimeGiftData(m_window, time);
}