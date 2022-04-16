#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include "Macros.h"
#include "Resources.h"

class MenuScreen
{
public:
	//constructor
	MenuScreen();

	//print
	void display(sf::RenderWindow&);

	//click
	void manageHelpClick   (sf::Vector2f);
	void mangeMenuClick    (sf::Vector2f, int&);
	void manageClick       (int&, const sf::Vector2f);
	bool ClickesOnSoundIcon(const sf::Vector2f);

	//mouse move
	void truckOnMouse    (const sf::Vector2f);
	void truckOnMenuMouse(sf::Vector2f);
	void truckOnHelpMouse(sf::Vector2f);

	//set
	void setTruckingRec();
	void setBackground ();
	void setTruckingRec(const sf::Vector2f, const sf::Vector2f);

	//get 
	bool isOnMute() const;

private:
	//texture of background
	sf::Sprite		   m_soundIcon;
	sf::RectangleShape m_background; 
	sf::RectangleShape m_truckingRec;

	bool               m_inHelp;
	bool		       m_isMute; 
};