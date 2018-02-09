// Player class declaration
#pragma once
#include "SFML/Graphics.hpp" 
#include "Globals.h"

class Player
{
	// private data members
	sf::Texture m_tankDownTexture;
	sf::Texture m_tankUpTexture;
	sf::Texture m_tankLeftTexture;
	sf::Texture m_tankRightTexture;

	sf::Sprite m_playerSprite;
	
	int health;// player health
	int speed;// player speed
	int score;// players score
	int direction;// the direction the player is facing currently
	bool isAlive;// checks if the player is dead
	
	// players current position
	sf::Vector2f m_playerPosition;

public:
	
    Player();
	void draw(sf::RenderWindow & t_window);
	void update();
	void shoot();
	void dies();
	void decreaseHealth();
	sf::Vector2f getPlayerPosition();
	void moveLeft();
	void moveRight();
    void moveUp();
	void moveDown();
	void boundaryCheck();
	void displayPlayerStats();
	void increaseScore();
	void decreaseScore();
	void setSprite();
	void isTankOutOfBounds();
};