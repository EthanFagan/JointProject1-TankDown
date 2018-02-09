/// <summary>
/// 
/// </summary>
 
#include "EnemyLeftRight.h"
#include "SFML\Graphics.hpp"
#include<time.h>
#include<iostream>

EnemyLeftRight::EnemyLeftRight()
{
	isAlive = true;
	direction = 2;

	m_enemyPosition = sf::Vector2f(600, 400);
	m_enemyVelocity = UPWARD_VELOCITY;

	setUpSprite();

}

void EnemyLeftRight::boundaryCheck()
{
	if (m_enemyPosition.x <= 0)
	{
		m_enemyVelocity = RIGHT_VELOCITY;
	}
	//------------------------------------------
	if (m_enemyPosition.x >= SCREEN_WIDTH - 35)
	{
		m_enemyVelocity = LEFT_VELOCITY;
	}
	//------------------------------------------
	if (m_enemyPosition.y <= 0)
	{
		m_enemyVelocity = DOWNWARD_VELOCITY;
	}
	//------------------------------------------
	if (m_enemyPosition.y >= SCREEN_HEIGHT - 45)
	{
		m_enemyVelocity = UPWARD_VELOCITY;
	}
}

void EnemyLeftRight::dies()
{

}

void EnemyLeftRight::hit()
{

}

void EnemyLeftRight::draw(sf::RenderWindow & t_window)
{
	t_window.draw(m_enemySprite);
}


void EnemyLeftRight::move()
{

	m_enemyPosition = m_enemyPosition + m_enemyVelocity;
	m_enemySprite.setPosition(m_enemyPosition);
}

void EnemyLeftRight::update()
{
	move();
	boundaryCheck();
}

void EnemyLeftRight::setUpSprite()
{
	if (!m_enemyTextureUp.loadFromFile("ASSETS/IMAGES/DingusUp.png"))
	{
		std::cout << "texture not loaded";
	}
	if (!m_enemyTextureDown.loadFromFile("ASSETS/IMAGES/DingusDown.png"))
	{
		std::cout << "texture not loaded";
	}
	if (!m_enemyTextureLeft.loadFromFile("ASSETS/IMAGES/DingusLeft.png"))
	{
		std::cout << "texture not loaded";
	}
	if (!m_enemyTextureRight.loadFromFile("ASSETS/IMAGES/DingusRight.png"))
	{
		std::cout << "texture not loaded";
	}
	m_enemySprite.setTexture(m_enemyTextureLeft);
	m_enemySprite.setPosition(m_enemyPosition);
}