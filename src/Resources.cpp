#include "Resources.h"

//constructor 
Resources::Resources()
	: m_volume(50), m_sound(), m_soundClick(), m_font(), m_soundBuffer(), m_clickvolume(100)
{
	//sound
	setSound();
	m_sound.setLoop(true);
	m_sound.setVolume(m_volume);
	m_soundClick.setVolume(m_volume);

	//set texture 
	setIcons();
	setCurrentPlayer();
	setBackground();

	//text
	setFont(); 
}


//the stsic function 
Resources& Resources::getInstance()
{
	static Resources instane;
	return instane;
}


//d_tor
Resources::~Resources() {}


//--------------------------- set sound -----------------------------
void Resources::setSound()
{
	sf::SoundBuffer soundBf; 

	for (size_t i = 0; i < MUSIC_NAMES.size(); i++)
	{
		soundBf.loadFromFile(MUSIC_NAMES[i]);
		m_soundBuffer.push_back(soundBf);
	}
	m_volume = 70;
}


sf::Image Resources::getGameIcon()
{
	sf::Image icon;
	icon.loadFromFile(ICONS_TEXTURE_NAMES[GAME]);
	return icon; 
}

//--------------------------- set icons -----------------------------
void Resources::setIcons()
{
	sf::Texture texture; 
	
	for (size_t i = 0; i < ICONS_TEXTURE_NAMES.size(); i++)
	{
		texture.loadFromFile(ICONS_TEXTURE_NAMES[i]);
		texture.setSmooth(true); 
		m_icons.emplace_back(texture); 
	}
}


//--------------------------- st current player ---------------------
void Resources::setCurrentPlayer()
{
	sf::Texture texture;

	for (size_t i = 0; i < PLAYERS; i++)
	{
		texture.loadFromFile(UNARY_PLAYERS_TEXTURE_NAMES[i]);
		texture.setSmooth(true);
		m_currentPlayer.emplace_back(texture);
	}
}


//--------------------------- set backround -------------------------
void Resources::setBackground()
{
	sf::Texture texture;

	for (size_t i = 0; i < BACKGROUND_TEXTURE_NAMES.size(); i++)
	{
		texture.loadFromFile(BACKGROUND_TEXTURE_NAMES[i]);
		texture.setSmooth(true);
		m_backgrounds.emplace_back(texture);
	}
}


//--------------------------- set font ------------------------------
void Resources::setFont()
{
	m_font.loadFromFile("font.ttf");
}


//----------------------------- get font ----------------------------
sf::Font& Resources::getFont()
{
	return m_font;
}


//----------------------------- get Icon ----------------------------
sf::Texture* Resources::getIcon(int enumIcone)
{
	return &(m_icons[enumIcone]);
}


//----------------------------get Current Player --------------------
sf::Texture* Resources::getCurrentPlayer(const int enumIcone)
{
	return &(m_currentPlayer[enumIcone]);
}


//----------------------------get Backgroud -------------------------
sf::Texture* Resources::getBackgroud(int enumIcone)
{
	return &(m_backgrounds[enumIcone]);
}


//----------------------------get music -----------------------------
sf::SoundBuffer* Resources::getSound(int enumSound)
{
	return &(m_soundBuffer[enumSound]);
}


//----------------------------play Sound-----------------------------
void Resources::playSound(int enumSound)
{
	m_soundClick.setBuffer(m_soundBuffer[enumSound]);
	m_soundClick.play();
}


//----------------------------play Music ----------------------------
void Resources::playMusic(int enumSound)
{
	if (enumSound > 3) enumSound % 3 + 1;
	m_sound.setBuffer(m_soundBuffer[enumSound]);
	m_sound.play();
}


//----------------------------get music -----------------------------
void Resources::pauseSound(int enumSound)
{
	m_sound.pause();
}


//----------------------------set Volume ---------------------------
void  Resources::setVolume(bool mode)
{

	if (mode)
	{
		if (m_volume != 100)      m_volume += 10;
		if (m_clickvolume != 100) m_clickvolume += 10;
	}

	else
	{
		if (m_volume != 0)      m_volume -= 10;
		if (m_clickvolume != 0) m_clickvolume -= 10;
	}

	m_sound.setVolume     (m_volume);
	m_soundClick.setVolume(m_clickvolume);
	playSound(CLICK_SOUND);
}


//----------------------------set Volume ---------------------------
void Resources::setVolumeToDefault()
{
	m_volume      = 40;
	m_clickvolume = 100;
	m_sound.setVolume(m_volume);
	m_soundClick.setVolume(m_volume);
}