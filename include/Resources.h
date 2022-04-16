#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Macros.h"

class Resources
{
public:
	//get to the data 
	static Resources& getInstance();

	//D-tor
	~Resources();

	//get functions
	sf::Texture*       getIcon(int);
	sf::Texture*       getCurrentPlayer(int);
	sf::Texture*       getBackgroud(int);
	sf::SoundBuffer*   getSound(int);
	sf::Font&          getFont();
	sf::Image          getGameIcon();

	void               playMusic (int);
	void               playSound (int);
	void               pauseSound(int);
	void               setVolume(bool);
	void               setVolumeToDefault();

private: 
	int                             m_volume;
	int                             m_clickvolume;
	sf::Sound                       m_sound;
	sf::Sound                       m_soundClick;

	//  TEXT 
	sf::Font                        m_font;  

	//  SOUND
	std::vector <sf::SoundBuffer>   m_soundBuffer;

	//  TEXTURE
	std::vector <sf::Texture>       m_icons;
	std::vector <sf::Texture>       m_currentPlayer;
	std::vector <sf::Texture>       m_backgrounds;

	//PRIVATE
	//c-tor, copy-c-tor, operator=
	Resources();
	Resources(const Resources&) = default; 
	Resources& operator=(const Resources&) = default; 

	//set functions
	void setSound();
	void setIcons();
	void setCurrentPlayer();
	void setBackground();
	void setFont();
};