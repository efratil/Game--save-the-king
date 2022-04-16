#pragma once

//library 
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Macros.h"

class DataManagement;

class Board
{
public:
	//c-tor
	Board();
	// d-tor
	~Board();

	//data about board file
	void setBoard(); 
	void reloadBoard();
	bool endOfStages();

	//get
	int  getLevelTime() const;
	void getVectorsOfObjects(DataManagement&);
	sf::Vector2f getLoc(const int, const int); 

private:
	int						 m_timeOfLevel; 
	std::ifstream            m_mapFile;
	std::vector<std::string> m_mapMatrix; 

	//aux functions 
	void checkFileValid();
	void readFile	   (); 
	bool isTile(const char)    const;
	bool isValid(sf::Vector2f) const;
};