// Game class declaration
#pragma once

#include "Player.h"   // include Player header file
#include "EnemyLeftRight.h"
#include "EnemyFollow.h"

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

#include "Globals.h"   // include Global header file

class Game
{
	// private data members

	// put your game objects here eg player object and 
	// array of enemy objects etc.

	sf::RenderWindow window;
	sf::RectangleShape m_titleBox;
	sf::RectangleShape m_healthPips[5];

	Player playerCharacter;
	EnemyLeftRight Dingus;
	EnemyFollow Nemesis;
	
public:
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen

public:	  // declaration of member functions	
	Game(); // default constructor
	void	loadContent();
	void	run();
	void	update();
	void	draw();
};
