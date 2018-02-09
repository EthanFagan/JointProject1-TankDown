// author Peter Lowe
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	void Game::setupButtons(); // setup button propereties
	void Game::setupText(); // setup text properties

	// constant colour setup
	const sf::Color RED{ 180,0,0,255 };
	const sf::Color YELLOW{ 180,180,0,255 };
	const sf::Color GREEN{ 0,180,0,255 };
	const sf::Color BLUE{ 0,0,180,255 };
	const sf::Color WHITE{ 255,255,255,255 };

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	bool m_exitGame; // control exiting game
	sf::RectangleShape m_redSquare;// red button/ light
	sf::RectangleShape m_yellowSquare;// yellow button/ light
	sf::RectangleShape m_greenSquare;// greeen button/ light
	sf::RectangleShape m_blueSquare;// blue button/ light
	sf::Font m_impactFont;// font that the game will use
	sf::Text m_titleText;// text for the title
	sf::Text m_instructionsTextRed; // red menu text
	sf::Text m_instructionsTextYellow;// yellow menu text
	sf::Text m_instructionsTextGreen;// green menu text
	sf::Text m_instructionsTextBlue;// blue menu text
	sf::Text m_statusText;// status text
};

#endif // !GAME

