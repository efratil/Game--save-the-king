#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Macros.h"
#include "Resources.h"


class GameScreen
{
public:
	//constructor & distructor
	GameScreen ();
	~GameScreen() {}

	//display
	void display   (sf::RenderWindow&, const int, const bool, const int, const int, const int, const bool);
	void loadScreen(sf::RenderWindow&, const int, const int);

	//set&print Gift data
	void setTimeGiftData (sf::RenderWindow&, const int);
	void setDwarfGiftData(sf::RenderWindow&, const int);

	//set for new level
	void setBackground(const int);

private:
	//holds the texture of levels 
	sf::Sprite         m_lives;
	sf::RectangleShape m_background;
	sf::RectangleShape m_boardSurface;
	sf::Text           m_timerText;
	sf::Text           m_Generaltext;
	sf::Text           m_PauseMode;
	sf::Text           m_MidBoardText;


	//sets texture & txt
	void setGiftText       ();
	void setLivesTexture   ();
	void setBoardBackground();
	void setTimeClockText  ();
	void setDataText       ();
	void setLevelNumText   (const int);
	void setCurPlayerText  (const int);
	void setloadBackground (const int);
	void setLoadSound      (const int);
	void setPauseText();


	//get & print
	sf::Sprite printCurPlayer (const int);
	void       printTimer     (const int);
	void       printKeyText   (const bool);
	void       printLives     (sf::RenderWindow&, const int);
	void       printDwarfsData(sf::RenderWindow&);
};