#pragma once
#include "SFML\Graphics.hpp"
#include "Globals.h"

class EnemyFollow
{
	sf::Texture m_followerTextureUp; // Texture for enemy
	sf::Texture m_followerTextureDown;
	sf::Texture m_followerTextureLeft;
	sf::Texture m_followerTextureRight;

	sf::Sprite m_followerSprite; // sprite used to represent enemy

	sf::Vector2f m_followerPosition;

	sf::Vector2f m_followerVelocity;

	int m_timesHit; // the number of times hit
	int m_direction; // the direction the enemy is facing
	int m_targetPositionX;
	int m_targetPositionY;
	bool isAlive;  //To see if the enemy is still alive 

public:

	EnemyFollow(); //constructor
	void draw(); //used to draw the enemy
	void update(); //updates every 60 frames
	void hit(); // enemy is hit by a bullet
	void dies(); // enemy dies
	void setUpSprites();
	void setPlayerPosition(sf::Vector2f t_playerPosition);
	void EnemyFollow::draw(sf::RenderWindow & t_window);
	void reSpawn(); // the enemy respawns somewhere randomly on the screen
	void move(); // the enemy follows the player
	void boundaryCheck(); //make sure the enemy does not go outside the screen boundary.

};