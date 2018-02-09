/// <summary>
/// 
/// </summary>
          
#include"EnemyFollow.h"
#include<iostream>
#include"Game.h"
#include"Globals.h"

EnemyFollow::EnemyFollow()
{
	isAlive = true;
	m_direction = 4;

	m_followerPosition = sf::Vector2f(100, 300);
	setUpSprites();
}

void EnemyFollow::update()
{
	boundaryCheck();
	move();

}

void EnemyFollow::boundaryCheck()
{

}

void EnemyFollow::move()
{
	if (m_followerPosition.x > m_targetPositionX)
	{
		m_followerPosition = m_followerPosition + LEFT_VELOCITY + SLOWDOWN;
		m_followerSprite.setPosition(m_followerPosition);
	}
	if (m_followerPosition.x < m_targetPositionX)
	{
		m_followerPosition = m_followerPosition + RIGHT_VELOCITY + SLOWDOWN;
		m_followerSprite.setPosition(m_followerPosition);
	}
	if (m_followerPosition.y < m_targetPositionY)
	{
		m_followerPosition = m_followerPosition + DOWNWARD_VELOCITY + SLOWDOWN;
		m_followerSprite.setPosition(m_followerPosition);
	}
	if (m_followerPosition.y > m_targetPositionY)
	{
		m_followerPosition = m_followerPosition + UPWARD_VELOCITY + SLOWDOWN;
		m_followerSprite.setPosition(m_followerPosition);
	}
}

void EnemyFollow::setUpSprites()
{
	if (!m_followerTextureUp.loadFromFile("ASSETS/IMAGES/FollowerUp.png"))
	{
		std::cout << "texture not loaded";
	}
	if (!m_followerTextureDown.loadFromFile("ASSETS/IMAGES/FollowerDown.png"))
	{
		std::cout << "texture not loaded";
	}
	if (!m_followerTextureLeft.loadFromFile("ASSETS/IMAGES/FollowerLeft.png"))
	{
		std::cout << "texture not loaded";
	}
	if (!m_followerTextureRight.loadFromFile("ASSETS/IMAGES/FollowerRight.png"))
	{
		std::cout << "texture not loaded";
	}
	m_followerSprite.setTexture(m_followerTextureDown);
	m_followerSprite.setPosition(m_followerPosition);
}

void EnemyFollow::setPlayerPosition(sf::Vector2f t_playerPosition)
{
	m_targetPositionX = t_playerPosition.x;
	m_targetPositionY = t_playerPosition.y;
}

void EnemyFollow::draw(sf::RenderWindow & t_window)
{
	t_window.draw(m_followerSprite);
}