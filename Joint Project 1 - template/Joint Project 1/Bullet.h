#pragma once
#include "SFML\Graphics.hpp"

class Bullet
{
	sf::Texture bullettexture; // Texture for bullet

	sf::Sprite bulletsprite; // sprite used to represent bullet

	int speed;  // the speed of the bullet
	int direction; // the direction of the bullet
	bool isAlive;  //To see if the bullet is still alive 

public:

	Bullet(); //constructor
	void draw(); //used to draw the enemy
	void update(); //updates every 60 frames
	void hit(); // the bullet has hit something
	void fired(); // the bullet is fired
	void move(); // the bullet moves
	void boundaryCheck(); //make sure the bullet does not go outside the screen boundary

};