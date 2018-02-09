

#include "Player.h"   // include Player header file
#include <iostream>
#include "SFML\Graphics.hpp"

// Player function definitions here

Player::Player()
{

 health = 3;
 speed = 2;
 score = 0;
 direction = 3;
 isAlive = true;
 m_playerPosition = sf::Vector2f(455, 365);
 

 setSprite();
}

void Player::draw(sf::RenderWindow & t_window)
{
	t_window.draw(m_playerSprite);
}

// moves player tank upwards
void Player::moveUp()
{
	if (direction != 3)
	{
		direction = 3;
	}
	m_playerPosition = m_playerPosition + UPWARD_VELOCITY;
	m_playerSprite.setPosition(m_playerPosition);
	m_playerSprite.setTexture(m_tankUpTexture,true);
}

// moves player tank downwards
void Player::moveDown()
{
	if (direction != 4)
	{
		direction = 4;
	}
	m_playerPosition = m_playerPosition + DOWNWARD_VELOCITY;
	m_playerSprite.setPosition(m_playerPosition);
	m_playerSprite.setTexture(m_tankDownTexture,true);
}

// moves player tank to the left
void Player::moveLeft()
{
	if (direction != 1)
	{
		direction = 1;
	}
	m_playerPosition = m_playerPosition + LEFT_VELOCITY;
	m_playerSprite.setPosition(m_playerPosition);
	m_playerSprite.setTexture(m_tankLeftTexture,true);
}

// moves player tank to the right
void Player::moveRight()
{
	if (direction != 2)
	{
		direction = 2;
	}
	m_playerPosition = m_playerPosition + RIGHT_VELOCITY;
	m_playerSprite.setPosition(m_playerPosition);
	m_playerSprite.setTexture(m_tankRightTexture, true);
}

// sets up player sprite
void Player::setSprite()
{
	if (!m_tankDownTexture.loadFromFile("ASSETS/IMAGES/tankDown.png"))
	{
		std::cout << "texture not loaded";
	}
	if (!m_tankUpTexture.loadFromFile("ASSETS/IMAGES/tankUp.png"))
	{
		std::cout << "texture not loaded";
	}
	if (!m_tankLeftTexture.loadFromFile("ASSETS/IMAGES/tankLeft.png"))
	{
		std::cout << "texture not loaded";
	}
	if (!m_tankRightTexture.loadFromFile("ASSETS/IMAGES/tankRight.png"))
	{
		std::cout << "texture not loaded";
	}

	m_playerSprite.setTexture(m_tankDownTexture);
	m_playerSprite.setPosition(m_playerPosition);
}

// checks if player is colliding with the edge of the screen
void Player::isTankOutOfBounds()
{
	if (m_playerPosition.x <= 0)
	{
		m_playerPosition = m_playerPosition + LEFT_BOUNCE;
	}
	//------------------------------------------
	if (m_playerPosition.x >= SCREEN_WIDTH - 35)
	{
		m_playerPosition = m_playerPosition + RIGHT_BOUNCE;
	}
	//------------------------------------------
	if (m_playerPosition.y <= 0)
	{
		m_playerPosition = m_playerPosition + UP_BOUNCE;
	}
	//------------------------------------------
	if (m_playerPosition.y >= SCREEN_HEIGHT - 45)
	{
		m_playerPosition = m_playerPosition + DOWN_BOUNCE;
	}
	//------------------------------------------
	else
	{
		
	}
}
void Player::update()
{
	//--Check for if the player is out of bounds-
	isTankOutOfBounds();
	//-------------------------------------------

	// get keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		moveLeft();
	}
	//-----------------------------
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		moveRight();
	}
	//-----------------------------
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
	    moveUp();
	}
	//-----------------------------
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		moveDown();
	}
	//-----------------------------
}

sf::Vector2f Player::getPlayerPosition()
{
	return m_playerPosition;
}