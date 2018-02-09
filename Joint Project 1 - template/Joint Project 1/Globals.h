// Contains the game globals
#pragma once

#include "SFML\Graphics.hpp"

//The direction the sprite is moving in
const int static WEST = 1;
const int static EAST = 2; 
const int static NORTH = 3; 
const int static SOUTH = 4;

const sf::Vector2f DOWNWARD_VELOCITY(0, 2);// vector for the player moving down
const sf::Vector2f UPWARD_VELOCITY(0, -2);// vector for the player moving up
const sf::Vector2f RIGHT_VELOCITY(2, 0);// vector for the player moving right
const sf::Vector2f LEFT_VELOCITY(-2, 0);// vector for the player moving left
const sf::Vector2f LEFT_BOUNCE(10, 0);// vector for player bouncing off of objects to the left
const sf::Vector2f RIGHT_BOUNCE(-10, 0);// vector for player bouncing off of objects to the right
const sf::Vector2f DOWN_BOUNCE(0, -10);// vector for player bouncing off of objects downwards
const sf::Vector2f UP_BOUNCE(0, 10);// vector for player bouncing off of objects upwards
const sf::Vector2f SLOWDOWN(-0.5, -0.5);

const float SCREEN_WIDTH = 1000;   // the size of the screen in pixels used in the game
const float SCREEN_HEIGHT = 800;