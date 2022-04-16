#include "GameScreen.h"

//------------------------------------ constructor ----------------------------
// c- tor
//-----------------------------------------------------------------------------
GameScreen::GameScreen()
{
    setGiftText();
    setTimeClockText();
    setDataText();
    setBackground(1);
    setBoardBackground();
    setLivesTexture(); 
}


//----------------------------- set lives texture  ----------------------------
//set the lives textures to defult range (scale)
//-----------------------------------------------------------------------------
void GameScreen::setLivesTexture()
{
    m_lives.setTexture(*Resources::getInstance().getIcon(LIVE));
    m_lives.setScale(2, 2);
}


//-------------------------------- set Background  ----------------------------
//set the backgound by the levels og the game
//-----------------------------------------------------------------------------
void GameScreen::setBackground(const int levelNum)
{
    m_background.setSize(BACKGROUND_SIZE);

    switch (levelNum % 3)
    {
    case 1: m_background.setTexture(Resources::getInstance().getBackgroud(LEVEL1));
        break;
    case 2:  m_background.setTexture(Resources::getInstance().getBackgroud(LEVEL2));
        break;
    case 0:  m_background.setTexture(Resources::getInstance().getBackgroud(LEVEL3));
        break;
    }
}


//----------------------------- set Board Background  -------------------------
//set the board background by the according to the size, location and color
//we chose
//-----------------------------------------------------------------------------
void GameScreen::setBoardBackground()
{
    m_boardSurface.setSize     (BOARD_SIZE);
    m_boardSurface.setPosition (BOARD_LOCATION);
    m_boardSurface.setFillColor(BOARD_COLOR);
}


//----------------------------- set Time Clock Text ---------------------------
//set the time clock text by the desire font, size, color and position
//-----------------------------------------------------------------------------
void GameScreen::setTimeClockText()
{
    m_timerText.setFont(Resources::getInstance().getFont());
    m_timerText.setCharacterSize (TIMER_SIZE);
    m_timerText.setFillColor     (sf::Color::White);
    m_timerText.setPosition      (TIMER_LOC);
}


//----------------------------- set Data Text  --------------------------------
//set the data text which shown in the bar menu on the board
//-----------------------------------------------------------------------------
void GameScreen::setDataText()
{
    m_Generaltext.setFont(Resources::getInstance().getFont());
    m_Generaltext.setCharacterSize(100);
    m_Generaltext.setFillColor(sf::Color::White);
}


//----------------------------- set Board Background  -------------------------
//set the text of each player, that will show to the user which player is moving
// now on the game
//-----------------------------------------------------------------------------
void GameScreen::setCurPlayerText(const int numOfPlayer)
{
    sf::Vector2f loc;

    switch (numOfPlayer)
    {
    case MAGE:loc = sf::Vector2f(100, 700);
        break;
    case KING:
    case THIEF:loc = sf::Vector2f(90, 700);
        break;
    case WARRIOR:loc = sf::Vector2f(30, 700);
        break;
    }

    m_Generaltext.setPosition(loc);
    m_Generaltext.setString(PLAYERS_NAME[numOfPlayer]);
}


//------------------------------ set Gift Text  -------------------------------
//set the text that shown when the user get a gift: which gift he get
//-----------------------------------------------------------------------------
void GameScreen::setGiftText()
{
    m_MidBoardText.setFont(Resources::getInstance().getFont());
    m_MidBoardText.setCharacterSize(TIMER_SIZE);
    m_MidBoardText.setFillColor(sf::Color::Black);
    m_MidBoardText.setPosition(sf::Vector2f(630, 350));
}


//--------------------------- set load Background -----------------------------
//load the backgorunds since the game bedin to the end of it
//-----------------------------------------------------------------------------
void GameScreen::setloadBackground(const int screen)
{
    if (screen == OPEN || screen == WON || screen == GAME_OVER)
    {
        m_background.setTexture(Resources::getInstance().getBackgroud(screen));
    }
    else
    {
        m_background.setTexture(Resources::getInstance().getBackgroud(NEW_LEVEL));
    }
}


//------------------------------- set Load Sound ------------------------------
//load the sound the sound that matches the current screen
//-----------------------------------------------------------------------------
void GameScreen::setLoadSound(const int screen)
{
    if (screen == OPEN)
    {
        Resources::getInstance().playMusic(MENU_SOUND);
    }
    else if (screen == GAME_OVER)
    {
        Resources::getInstance().playSound(GAME_OVER_SOUND);
    }
    else
    {
        Resources::getInstance().playSound(NEW_LEVEL_SOUND);
    }
}


//--------------------------- set Time Gift Data  -----------------------------
//set the time of the gift data: which gift the user get
//-----------------------------------------------------------------------------
void GameScreen::setTimeGiftData(sf::RenderWindow& gameWindow, const int time)
{
    if (time > 0)
    {
        m_MidBoardText.setString("YAY TIME ADDED +" + std::to_string(time));
        m_MidBoardText.setColor(sf::Color::Green);
    }

    if (time < 0)
    {
        m_MidBoardText.setString("OH TIME LOST " + std::to_string(time));
        m_MidBoardText.setColor(sf::Color::Red);
    }

    if (time == 0)
    {
        m_MidBoardText.setString("NO TIME ADDED!");
        m_MidBoardText.setColor(sf::Color::Blue);
    }

    printDwarfsData(gameWindow);
}


//---------------------------set Dwarf Gift Data  -----------------------------
//set the dwarf of the gift data: which gift the user get
//-----------------------------------------------------------------------------
void GameScreen::setDwarfGiftData(sf::RenderWindow& gameWindow, const int type)
{
    switch (type)
    {
    case 0:    m_MidBoardText.setString("DELETE ALL DWARFS");
               m_MidBoardText.setColor(sf::Color::Green);
        break;
    case 1:    m_MidBoardText.setString("POP DWARF");
               m_MidBoardText.setColor(sf::Color::Red);
        break;
    case 2:    m_MidBoardText.setString("DELETE ONE DWARF");
               m_MidBoardText.setColor(sf::Color::Green);
        break;
    case 3:    m_MidBoardText.setString("SPEED DWARFS");
               m_MidBoardText.setColor(sf::Color::Red);
        break;
    case 4:    m_MidBoardText.setString("SLOW DOWN DWARFS");
               m_MidBoardText.setColor(sf::Color::Green);
        break;
    }

    printDwarfsData(gameWindow);
}


//--------------------------------- display  ----------------------------------
//print all the things we set above
//-----------------------------------------------------------------------------
void GameScreen::display(sf::RenderWindow& gameWindow, const int curPlayer, const bool hasAKey, 
                    const int timeOfGame, const int lives, const int level, const bool pauseMode)
{
    gameWindow.draw(m_background);
    gameWindow.draw(m_boardSurface);

    //pauseMode
    if (pauseMode)
    {
        setPauseText();
        gameWindow.draw(m_MidBoardText);
        return;
    }

    //timer
    printTimer(timeOfGame);
    gameWindow.draw(m_timerText);

    //cur player
    gameWindow.draw(printCurPlayer(curPlayer));
    gameWindow.draw(m_Generaltext);

    //isThief has a key
    printKeyText(hasAKey);
    gameWindow.draw(m_Generaltext);

    //lives
    printLives(gameWindow, lives);

    //LEVEL
    setLevelNumText(level);
    gameWindow.draw(m_Generaltext);
}


//--------------------------------- print Lives  ------------------------------
//print the hearts that reprecent the lives the user have
//-----------------------------------------------------------------------------
void GameScreen::printLives(sf::RenderWindow& gameWindow, const int lives)
{
    //for animation
    static sf::Clock spriteTimer;
    static  sf::Vector2u spriteFrame = { 0,0 };

    if (spriteTimer.getElapsedTime().asSeconds() > 0.5)
    {
        spriteTimer.restart();
        spriteFrame.x += 285;

        if (spriteFrame.x >= 855)
        {
            spriteFrame.x = 0;
        }
    }

    //set and scale 
    m_lives.setTextureRect(sf::IntRect(spriteFrame.x, spriteFrame.y, 285, 285));
    m_lives.setScale(0.35, 0.35);

    //print as much as needed 
    for (auto i = 0; i < lives; i++)
    {
        m_lives.setPosition(sf::Vector2f(40 + 100*(float)i, 12));
        gameWindow.draw(m_lives);
    }
}


//--------------------------------- print Lives  ------------------------------
//print the clock (timer) 
//-----------------------------------------------------------------------------
void GameScreen::printTimer(const int timeOfGame)
{
    if (timeOfGame % 60 < 0)
        m_timerText.setString("NO TIME");

    else if (timeOfGame % 60 < 10)
        m_timerText.setString("0" + std::to_string(timeOfGame / 60) + " : " + "0" + std::to_string(timeOfGame % 60));

    else
        m_timerText.setString("0" + std::to_string(timeOfGame / 60) + " : " + std::to_string(timeOfGame % 60));
}


//---------------------------- print Cur Player  ------------------------------
//print which player is move now on the game, shown in the bar on the board
//-----------------------------------------------------------------------------
sf::Sprite GameScreen::printCurPlayer(const int numOfPlayer)
{
    sf::Sprite player;

    player.setTexture(*Resources::getInstance().getCurrentPlayer(numOfPlayer));
    player.setPosition(sf::Vector2f(105, 520));
    player.scale(2,2);
    setCurPlayerText(numOfPlayer);

    return player;
}


//------------------------------ print Key Text  ------------------------------
//print if thief own a key or not, shown in the bar on the board
//-----------------------------------------------------------------------------
void GameScreen::printKeyText(const bool isHasAKey)
{
    if (isHasAKey)
    {
        m_Generaltext.setString("Yes");
    }
    else
    {
        m_Generaltext.setString("No");
    }

    m_Generaltext.setPosition(sf::Vector2f(140, 920));
}


//---------------------------------  load Screen ------------------------------
//load the screens in the game  
//-----------------------------------------------------------------------------
void GameScreen::loadScreen(sf::RenderWindow& gameWindow, const int screen, const int sec)
{
    if (screen == LEVEL1) return; //no load screen from menu to game 

    gameWindow.clear();

    setloadBackground(screen);
    setLoadSound(screen);

    gameWindow.draw(m_background);
    gameWindow.display();

    sf::sleep(sf::seconds(sec));
}


//--------------------------- print Dwarfs Data  ------------------------------
//print gift data -> print surface and text on it
//-----------------------------------------------------------------------------
void GameScreen::printDwarfsData(sf::RenderWindow& gameWindow)
{
    gameWindow.draw(m_boardSurface);
    gameWindow.draw(m_MidBoardText);
    gameWindow.display();
    sf::sleep(sf::seconds(0.75));
}


//--------------------------- setLevelNumText  --------------------------------
//set the level num
//-----------------------------------------------------------------------------
void GameScreen::setLevelNumText(const int level)
{
    m_Generaltext.setString(std::to_string(level));
    m_Generaltext.setPosition(1870, 950);
}


//--------------------------- setPauseText  -----------------------------------
//set Pause Text, rand color in each iteration while in paused
//-----------------------------------------------------------------------------
void GameScreen::setPauseText()
{
    m_MidBoardText.setString("     PAUSE MODE    ");
    m_MidBoardText.setColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
}