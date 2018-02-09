#ifndef GAME
#define GAME
// @author Ethan Fagan
// C00232277
// @date  Nov 2017
#include <SFML\Graphics.hpp>
#include "MyVector2D.h"

/// <summary>
/// Main game class for simple game
/// no game objects
/// all in one solutiuon
/// </summary>
class Game
{
public:
	Game();
	void run();
private:
	void    processEvents();
	void    update(sf::Time t_deltaTime);
	void    render();	

private:
	// display window
	sf::RenderWindow m_window;
	//-----------------------------------------------------------------------
	//explosion radius
	float m_explosionRadius{ 15.0f };
	//are we displaying the explosion plume
	bool m_explosionActive;
	// explosion blume
	sf::CircleShape  m_explosion;
	//-----------------------------------------------------------------------
	// Power Meter
	sf::RectangleShape m_powerMeter;
	// Is the power meter increasing
	bool m_powerActive{ true };
	// playerBox
	//-----------------------------------------------------------------------
	// allows the bar to increase
    float m_RectangleExtender{ 7.5f };
	// the power bar
	sf::RectangleShape m_playerBox;
	// ground
	sf::RectangleShape m_ground;
	//-----------------------------------------------------------------------
	// unit vector for use in shooting
	MyVector2D m_unitVector{ 0.0,0.0 };
	// laser 
	sf::VertexArray m_laserRay;
	//is the laser charged
	sf::Vertex m_laserStart;
	// laser end point
	sf::Vertex  m_laserEnd;
	// location of mouse click
	MyVector2D m_targetPoint{ 0.0f,0.0f};
	// determines if the laser is moving or not
	bool m_laserActive{ false };
	// laser size scaler( based on power bar)
	int laserScaler{ 0 };
	//-----------------------------------------------------------------------
	// the font we will be using arial
	sf::Font m_arialFont;
	// is the game over
	bool m_gameover;
	// text for gameover massage
	sf::Text m_gameoverMessage;
	//-----------------------------------------------------------------------
	// is the asteroid active
	bool m_asteroidActive{ false };
	// asteroid
	sf::VertexArray m_asteroid;
	

	
};

#endif // !GAME
