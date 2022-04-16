#include "MenuScreen.h"

//------------------------------------ constructor ----------------------------
// MenuScreen constructor 
//-----------------------------------------------------------------------------
MenuScreen::MenuScreen() : m_inHelp(false), m_isMute(false)
{
    setTruckingRec();
    setBackground(); 
}


//------------------------------ set Background ---------------------
//set the background of the menu (and volume)
//-------------------------------------------------------------------
void MenuScreen::setBackground()
{
    m_background.setTexture(Resources::getInstance().getBackgroud(MENU));
    m_background.setSize(BACKGROUND_SIZE);

    m_soundIcon.setTexture(*Resources::getInstance().getIcon(VOLUME));
    m_soundIcon.setPosition(SOUND_ICONE_LOC);
    m_soundIcon.scale(SOUND_ICONE_SCALE, SOUND_ICONE_SCALE);
}


//-------------------------- set Trucking Rec -----------------------
//set the trucking rectangle which when touched with the mouse on the
//menu, the rectangle will move
//-------------------------------------------------------------------
void MenuScreen::setTruckingRec()
{
    m_truckingRec.setFillColor(CLEAR);
    m_truckingRec.setOutlineColor(CLEAR);
    m_truckingRec.setOutlineThickness(12.f);
}


//-------------------------- set Trucking Rec -----------------------
//set the trucking rectangle which when touched with the mouse on the
//menu, the rectangle will move
//-------------------------------------------------------------------
void MenuScreen::setTruckingRec(const sf::Vector2f size, const sf::Vector2f loc)
{
    m_truckingRec.setOutlineColor(sf::Color::White);
    m_truckingRec.setFillColor(FADE_TRUCK_MOUSE);
    m_truckingRec.setSize(size);
    m_truckingRec.setPosition(loc); 
}


//-------------------------------- display --------------------------
//dislay the thing which sets above
//-------------------------------------------------------------------
void MenuScreen::display(sf::RenderWindow& gameWindow)
{
    gameWindow.clear();
    gameWindow.draw(m_background);
    gameWindow.draw(m_truckingRec);
    gameWindow.draw(m_soundIcon);
    gameWindow.display();
}


//--------------------------- truck On Mouse ------------------------
//choose where to truck the rectangle (mouse): help\menu 
//-------------------------------------------------------------------
void MenuScreen::truckOnMouse(const sf::Vector2f mousePos)
{
    setTruckingRec(); 

    if (m_inHelp)
    {
        truckOnHelpMouse(mousePos);
    }
    else
    {
        truckOnMenuMouse(mousePos);
    } 
}


//--------------------------- truck On Menu Mouse -------------------
//truck the mouse on the menu buttons, by position and check where
// the butttons is
//-------------------------------------------------------------------
void MenuScreen::truckOnMenuMouse(sf::Vector2f mousePos)
{
    sf::RectangleShape auxRec;
    auxRec.setSize(MENU_BUTTONS_SIZE);

    for (int i = 0; i < NUM_OF_MENU_BOTTONS; i++)
    {
        auxRec.setPosition(MENU_BUTTONS_LOC[i]);
        if (auxRec.getGlobalBounds().contains(mousePos))
        {
            setTruckingRec(MENU_BUTTONS_SIZE, MENU_BUTTONS_LOC[i]);
             break; 
        }
    }
}


//--------------------------- truck On Help Mouse -------------------
//truck the mouse on the help buttons, by position and check where
// the butttons is
//-------------------------------------------------------------------
void MenuScreen::truckOnHelpMouse(sf::Vector2f mousepos)
{
    sf::RectangleShape auxRec;
    auxRec.setSize(BACK_BUTTON_SIZE);
    auxRec.setPosition(BACK_BUTTON_LOC);

    if (auxRec.getGlobalBounds().contains(mousepos))
    {
        setTruckingRec(BACK_BUTTON_SIZE, BACK_BUTTON_LOC);
        return; 
    }
}


//---------------------------- manage Help Click --------------------
//manage the mouse click on help menu
//-------------------------------------------------------------------
void MenuScreen::manageHelpClick(sf::Vector2f loc)
{
    sf::RectangleShape auxRec;
    auxRec.setSize(BACK_BUTTON_SIZE);
    auxRec.setPosition(BACK_BUTTON_LOC);

    if (auxRec.getGlobalBounds().contains(loc))
    {
        m_inHelp = false;
        m_background.setTexture(Resources::getInstance().getBackgroud(MENU));
        if (!m_isMute) Resources::getInstance().playSound(CLICK_SOUND);
    }
}


//------------------------- manage menu click -----------------------
//manage the mouse click on menu including, the three options: start, 
//help and exit the game. Each of them is a button
//-------------------------------------------------------------------
void MenuScreen::mangeMenuClick(sf::Vector2f loc, int& gameMode)
{
    sf::RectangleShape auxRec;
    auxRec.setSize(MENU_BUTTONS_SIZE);

    //start button
    auxRec.setPosition(START_LOC);
    if (auxRec.getGlobalBounds().contains(loc))
    {
        gameMode = IN_GAME;
        if(!m_isMute)Resources::getInstance().playSound(CLICK_SOUND);
        Resources::getInstance().pauseSound(MENU);
        return;
    }

    //help button
    auxRec.setPosition(HELP_LOC);
    if (auxRec.getGlobalBounds().contains(loc))
    {
        m_background.setTexture(Resources::getInstance().getBackgroud(HELP));
        m_inHelp = true;
        if (!m_isMute)Resources::getInstance().playSound(CLICK_SOUND);
        return;
    }

    //exit button
    auxRec.setPosition(EXIT_LOC);
    if (auxRec.getGlobalBounds().contains(loc))
    {
        gameMode = EXIT;
        if (!m_isMute)Resources::getInstance().playSound(CLICK_SOUND);
    }
}


//--------------------------- manage Click --------------------------
//manage the click by dividing into the various options
//-------------------------------------------------------------------
void MenuScreen::manageClick(int& gameMode, const sf::Vector2f location)
{
    setTruckingRec(); 

    if (ClickesOnSoundIcon(location))
    {
        return; 
    }

    if (m_inHelp)
    {
        manageHelpClick(location);
    }

    else
    {
        mangeMenuClick(location, gameMode);
    }
}


//----------------------------- playMusic --------------------------
//Playing music in the appropriate places, using the resources department 
//and managing the start of the music stop by clicking on the sound icon
//-------------------------------------------------------------------
bool MenuScreen::ClickesOnSoundIcon(const sf::Vector2f location)
{
    if(m_soundIcon.getGlobalBounds().contains(location))
    {
        if (m_isMute)
        {
            m_soundIcon.setTexture(*Resources::getInstance().getIcon(VOLUME));
            Resources::getInstance().playMusic(MENU_SOUND);
            Resources::getInstance().playSound(CLICK_SOUND);
        }
        else
        {
            m_soundIcon.setTexture(*Resources::getInstance().getIcon(MUTE));
            Resources::getInstance().pauseSound(MENU_SOUND);
        }
        
        m_isMute = !m_isMute; 
        return true;
    }
    return false; 
}


//----------------------------- isOnMute ----------------------------
//
//-------------------------------------------------------------------
bool  MenuScreen::isOnMute() const
{
    return m_isMute;
}