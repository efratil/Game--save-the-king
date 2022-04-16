#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>

#include "MenuScreen.h"
#include "GameScreen.h"
#include "GameObject.h"
#include "DataManagement.h"


class Controller
{
public:
	//constructor 
	Controller();
	~Controller() {}
	void run();

	//set 
	void setTimer (const int);
	void GiftEvent(const int);
	void setLevel            ();
	void setCurPlayer        ();
	void UpdateObjects       ();
	void setBackToMenu       ();
	void intiliesGameVaribles();


private:
	//run game members
	sf::RenderWindow m_window;
	sf::Event        m_event;
	sf::Clock        m_gameClock;

	//manage game members
	MenuScreen		 m_menuScreen;
	GameScreen		 m_gameScreen; 
	DataManagement   m_manageData;

	//game parameters 
	bool             m_pause;
	bool             m_inGame;
	int              m_levelNum;
	int              m_currentPlayer;
	int              m_timeOfGame;
	int              m_lives;
	bool             m_soundVolume;
	
	//~private func~
	//manage game 
	void timer      ();
	void runGame    ();
	void displayGame();


	//mange screens and event
	void manageMenuscreenEvents();
	void manageGameScreenEvents();
	void handleExitEvent       ();
	void handleMenuClickEvent  ();
	void handleMouseMovedEvent ();
	void handleKeyboardEvent   ();
	void handleGameClickEvent  ();


	//in game function
	void isGameOver();
	void loseLevel ();
	void winLevel  ();

};