#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

const char
//-- CHARECTERS ---
KING_C        = 'K',
WARRIOR_C     = 'W',
THIEF_C       = 'T',
MAGE_C        = 'M',
DUMB_DWARF_C  = '^',
SMART_DWARF_C = '%',
//---- -Tiles ----
FIRE_C        = '*',
ORC_C         = '!',
TELEPORT_C    = 'X',
WALL_C        = '=',
KEY_C         = 'F',
THRONE_C      = '@',
GATE_C        = '#',
SPACE_C       = ' ',
TIME_GIFT_C   = '~',
DWARF_GIFT_C  = '$';


//deltaTime const
constexpr auto ShapeSize = 32.f;
constexpr auto ShapeSpeed = ShapeSize * 5;


//game modes
const int EXIT = 0;
const int IN_GAME = 1;
const int IN_MENU = 2;


//EVENTS AND MOVEMENT
//events
const auto CLOSE_WINDOW = sf::Event::Closed;
const auto BUTTON_CLICKED = sf::Event::MouseButtonReleased;
const auto MOUSE_MOVED = sf::Event::MouseMoved;
const auto KEYBOARD_CLICK = sf::Event::KeyPressed;


//keyboard
const auto P_KEY = sf::Keyboard::P;
const auto RIGHT = sf::Keyboard::Right;
const auto LEFT = sf::Keyboard::Left;
const auto UP = sf::Keyboard::Up;
const auto DOWN = sf::Keyboard::Down;
const auto ESCAPE = sf::Keyboard::Escape;
const auto SPACE = sf::Keyboard::Space;


//movement 
const sf::Vector2f UP_MOVE{ 0, -1 };
const sf::Vector2f DOWN_MOVE{ 0, 1 };
const sf::Vector2f LEFT_MOVE{ -1,0 };
const sf::Vector2f RIGHT_MOVE{ 1, 0 };
const sf::Vector2u NONE_MOVE{ 0, 0 };


//BUTTOMS DATA
//buttons location 
const auto START_LOC = sf::Vector2f(735, 425);
const auto HELP_LOC = sf::Vector2f(735, 425 + 160 + 18);
const auto EXIT_LOC = sf::Vector2f(735, 425 + 320 + 36);
const auto BACK_BUTTON_LOC = sf::Vector2f(23, 15);


//buttons size
const auto BACKGROUND_SIZE   = sf::Vector2f(1920, 1080);
const auto MENU_BUTTONS_SIZE = sf::Vector2f(373, 155);
const auto BACK_BUTTON_SIZE  = sf::Vector2f(160, 90);


//buttons 
const int  NUM_OF_MENU_BOTTONS = 3;
const auto CLEAR = sf::Color(0, 0, 0, 0);
const auto FADE_TRUCK_MOUSE = sf::Color(244, 244, 244, 75);
const sf::Vector2f MENU_BUTTONS_LOC[3] = { START_LOC, HELP_LOC, EXIT_LOC };


//BOARD
const sf::Vector2f BOARD_SIZE(1350, 900);
const sf::Vector2f BOARD_LOCATION(440, 40);
const sf::Vector2f BOARD_RECT(1281, 835);
const sf::Color    BOARD_COLOR(244, 244, 244, 150);
const auto BOARD_WIDTH_RANGE = 440;
const auto BOARD_lENGTH_RANGE = 40;

//icones var
const int  SPRITE_SIZE = 32;
const int  SCALE = 2;


//sound icone
const auto SOUND_ICONE_SCALE = 0.1;
const auto SOUND_ICONE_LOC = sf::Vector2f(1800, 60);
const auto SOUND_ICONE_SIZE = sf::Vector2f(95, 80);

//timer print 
const sf::Vector2f TIMER_LOC(80, 200);
const int TIMER_SIZE = 120;

const int LEVELS = 3;
const int PLAYERS = 4;


//enum icones
enum icones
{
	KING, MAGE, THIEF, WARRIOR, FIRE, GATE, KEY, ORC, TELEPORT, THRONE, WALL, DUMB_DWARF, SMART_DWARF, GIFT, VOLUME, MUTE, LIVE, GAME
};


enum backgrounds
{
	OPEN, LEVEL1, LEVEL2, LEVEL3, NEW_LEVEL, MENU, HELP, WON, GAME_OVER
};


enum Sound
{
	MENU_SOUND, LEVEL1_SOUND, LEVEL2_SOUND, LEVEL3_SOUND, CLICK_SOUND, FIRE_SOUND, KEY_SOUND, OPEN_GATE_SOUND, TELEPORT_SOUND, NEW_LEVEL_SOUND, GAME_OVER_SOUND, LOSE_SOUND
};


//name vectors for resourses managment
const std::vector <std::string> PLAYERS_NAME                = { "queen", "mage", "thief", "warrior" };

const std::vector <std::string> ICONS_TEXTURE_NAMES         = { "king.png",     "mage.png",   "thief.png", "warrior.png" , "fire.png", "gate.png",   "key.png", "orc.png",
																"teleport.png", "throne.png", "wall.png",  "dumbDwarf.png", "smartDwarf.png",   "gift.png", "volume.png", "mute.png", "live.png", "gameIcon.png"};

const std::vector <std::string> UNARY_PLAYERS_TEXTURE_NAMES = { "kingPlayer.png", "magePlayer.png", "thiefPlayer.png", "warriorPlayer.png" };

const std::vector <std::string> BACKGROUND_TEXTURE_NAMES    = { "openPage.png", "level1.png", "level2.png", "level3.png", "nextLevelPage.png", "menuPage.png", "helpPage.png", "wonPage.png", "gameOver.png" };

const std::vector <std::string> MUSIC_NAMES                 = { "menuSound.wav","level1Sound.wav","level2Sound.wav", "level3Sound.wav", "clickSound.wav", "fireCollision.wav", "keySound.wav",
											                	"openGateSound.wav", "teleportSound.wav", "newLevelSound.wav", "gameOverSound.wav", "loseLevelSound.wav" };