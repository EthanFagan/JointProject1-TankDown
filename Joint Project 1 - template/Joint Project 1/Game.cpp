// Name: Ethan Fagan
// Login: C00232277
// Date: 01/28/2018
// Time taken: 
//---------------------------------------------------------------------------
// Project description: A top down tank game
// ---------------------------------------------------------------------------
// Known Bugs:
// ?

//////////////////////////////////////////////////////////// 
// include correct library file for release and debug versions
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 



#include "Game.h"   // include Game header file


int main()
{
	Game aGame;
	aGame.loadContent();
	aGame.run();

	return 0;
}

Game::Game() : window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Joint Project Game", sf::Style::Default)
// Default constructor
{
}

void Game::loadContent()
// load the font file & setup the message
{
	// attributes of the title box--------------------------------
	m_titleBox.setFillColor(sf::Color::Blue);
	m_titleBox.setOutlineThickness(2);
	m_titleBox.setOutlineColor(sf::Color::Magenta);
	m_titleBox.setPosition(sf::Vector2f(0, 0));
	m_titleBox.setSize(sf::Vector2f(150, 75));
	//------------------------------------------------------------
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file ";
	}

	// set up the message string 
	m_message.setFont(m_font);  // set the font for the text
	m_message.setCharacterSize(30); // set the text size
	m_message.setFillColor(sf::Color::Green); // set the text colour
	m_message.setPosition(6, 6);  // its position on the screen

	for (int index = 0; index < 5; index++)
	{
		m_healthPips[index].setFillColor(sf::Color::Black);
		m_healthPips[index].setSize(sf::Vector2f(10,25));
		m_healthPips[index].setOutlineThickness(2);
		if (index == 0)
		{
			m_healthPips[index].setPosition(sf::Vector2f(130,45));
			m_healthPips[index].setOutlineColor(sf::Color::Green);
		}
		if (index == 1)
		{
			m_healthPips[index].setPosition(sf::Vector2f(100, 45));
			m_healthPips[index].setOutlineColor(sf::Color::Yellow);
		}
		if (index == 2)
		{
			m_healthPips[index].setPosition(sf::Vector2f(70, 45));
			m_healthPips[index].setOutlineColor(sf::Color::Red);
		}
		if (index == 3)
		{
			m_healthPips[index].setPosition(sf::Vector2f(30, 45));
			m_healthPips[index].setSize(sf::Vector2f(5, 25));
		}
		if (index == 4)
		{
			m_healthPips[index].setPosition(sf::Vector2f(20, 55 ));
			m_healthPips[index].setSize(sf::Vector2f(25, 5));
		}
	}

}


void Game::run()
// This function contains the main game loop which controls the game. 
{


	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{

			update();
			draw();

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

}

void Game::update()
// This function takes the keyboard input and updates the game world
{ 
	Nemesis.setPlayerPosition(playerCharacter.getPlayerPosition());
	Nemesis.update();
	playerCharacter.update();
	Dingus.update();
	// update any game variables here ...

}

void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	window.clear();

	Nemesis.draw(window);
	Dingus.draw(window);
	playerCharacter.draw(window);
	window.draw(m_titleBox);
	m_message.setString("T A N K D O W N");
	window.draw(m_message);  // write message to the screen
	for (int index = 0; index < 5; index++)
	{
		window.draw(m_healthPips[index]);
	}
	
	
	window.display();
}
