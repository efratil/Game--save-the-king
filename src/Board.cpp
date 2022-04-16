#include"Board.h"
#include "DataManagement.h"

//									 COSTRUCTOR									//
//------------------------------------ constructor ----------------------------
// c- tor
//-----------------------------------------------------------------------------
Board::Board() :m_mapFile("Board.txt")
{
	checkFileValid();
}


//------------------------------------ distructor -----------------------------
// d- tor
//-----------------------------------------------------------------------------
Board::~Board()
{
	m_mapFile.close();
}


//--------------------------- check file valid --------------------------------
// This function check the file validation.
//-----------------------------------------------------------------------------
void Board::checkFileValid()
{
    if (m_mapFile.fail())
    {
        std::cout << "file can not be opened!";
        exit(EXIT_FAILURE);
    }
}


//------------------------------------ reloadBoard ----------------------------
// for restarting the game move the index of to the begin of the file 
//-----------------------------------------------------------------------------
void Board::reloadBoard()
{
	m_mapFile.clear();
	m_mapFile.seekg(0, std::ios::beg);
}


//---------------------------------- setBoard ---------------------------------
// set the char matrix that holds each level to empty and read new level from file
//-----------------------------------------------------------------------------
void  Board::setBoard()
{
	m_mapMatrix.clear();
    readFile(); 
}


//--------------------------------- readFile ----------------------------------
// read the char map from file by reading line by line, delets the 
//-----------------------------------------------------------------------------
void Board::readFile()
{
	std::string number;
	std::getline(m_mapFile, number); //eats the num of stage

	for (auto line = std::string(); std::getline(m_mapFile, line) && line.compare("") != 0; )
	{
		m_mapMatrix.push_back(line);
	}

	m_timeOfLevel = std::stoi(number);
}


//-------------------------------- getLevelTime -------------------------------
// return the time of the level
//-----------------------------------------------------------------------------
int Board::getLevelTime() const
{
	return m_timeOfLevel; 
}


//--------------------------- end of stages -----------------------------
// This function check when we arrived to the end of the file.
//-----------------------------------------------------------------------
bool Board::endOfStages()
{
	if (!m_mapFile.eof())
	{
		return false;
	}

	return true;
}


//--------------------------------- getLoc ------------------------------------
//The function get the col and the row of the object ib the char matrix and calc
// the current place in the board game display. the calculation consider the 
// the size of the sprite and its scale.
//-----------------------------------------------------------------------------
sf::Vector2f Board::getLoc(const int col, const int row)
{
	float x = BOARD_WIDTH_RANGE + (SPRITE_SIZE * (float)row * SCALE);
	float y = ((float)col* SPRITE_SIZE * SCALE) + BOARD_lENGTH_RANGE;

	return sf::Vector2f(x, y);
}


//--------------------------------- getVectorsOfObjects ------------------------
// the function responsible to run on the char matrix and for each charecter that
// is not space -> enter to the vector in Data Management. 
//more other counts all the static tiles for the teleport pairing in Data.
//-----------------------------------------------------------------------------
void Board::getVectorsOfObjects(DataManagement& data)
{
	int numOfStaticObjects = 0; 

	for (int i = 0; i < (int)m_mapMatrix.size(); i++)
	{
		for (int j = 0; j < (int)m_mapMatrix[i].size(); j++)
		{
			//none object
			if (m_mapMatrix[i][j] == SPACE_C) continue;

			//not includes in board sizes
			if(!isValid(getLoc(i, j))) continue;

			//static tile count+1
			if((isTile(m_mapMatrix[i][j]))) numOfStaticObjects++;
			
			//build an object abd enter to the right vec
			data.enterToVector(m_mapMatrix[i][j], getLoc(i,j), numOfStaticObjects-1);
		}
	}
}


//--------------------------------- getVectorsOfObjects ------------------------
//returns if the charecter is a tile or moving object
//-----------------------------------------------------------------------------
bool Board::isTile(const char tilechar) const
{
	return (tilechar != KING_C && tilechar != MAGE_C && tilechar != THIEF_C && 
	    tilechar != WARRIOR_C && tilechar != DUMB_DWARF_C && tilechar != SMART_DWARF_C);
}


//--------------------------------- isValid ----------------------------------
//gets location of a object and return if it includes in board limits
//-----------------------------------------------------------------------------
bool Board::isValid(sf::Vector2f loc) const
{
	sf::RectangleShape board;
	board.setSize(BOARD_RECT);
	board.setPosition(BOARD_LOCATION);

	return board.getGlobalBounds().contains(loc);
}