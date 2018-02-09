#pragma once
#include "SFML\Graphics.hpp"
#include<time.h>
#include"Globals.h"

class EnemyLeftRight
{
	sf::Texture m_enemyTextureUp; // Texture for enemy
	sf::Texture m_enemyTextureDown;
	sf::Texture m_enemyTextureRight;
	sf::Texture m_enemyTextureLeft;

	sf::Sprite m_enemySprite; // sprite used to represent enemy

	sf::Vector2f m_enemyPosition;

	sf::Vector2f m_enemyVelocity;  // the speed of the enemy
	int direction; // the direction the enemy is facing
	bool isAlive;  //To see if the enemy is still alive 
	//srand(static_cast<unsigned>(time(NULL)));


public:

	EnemyLeftRight(); //constructor
	void draw(sf::RenderWindow & t_window);
	void draw(); //used to draw the enemy
	void update(); //updates every 60 frames
	void hit(); // enemy is hit by a bullet
	void dies(); // enemy dies
	void reSpawn(); // the enemy respawns to a fixed position on the screen
	void move(); // the enemy moves left to right on the screen
	void boundaryCheck(); //make sure the enemy does not go outside the screen boundary.
	void setUpSprite();


};
