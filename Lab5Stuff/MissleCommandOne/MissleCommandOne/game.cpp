/// <summary>
/// @Author Ethan Fagan
/// @ C00232277
/// 30/11/2017
/// est time:
/// time taken:
/// help gained:
/// </summary>

#include <SFML/Graphics.hpp>
#include "game.h"
#include "MyVector2D.h"
#include <iostream> 


Game::Game() :
	m_window(sf::VideoMode(800, 480), "One Missle Command"),
	m_explosion{ 50.0 },
	m_explosionActive{ false },
	m_laserRay{sf::Lines}, 
	m_gameover{ false } // set this to true  to see text in action remove this comment when you understand the initialiser list
	
{
	// the ground
	m_ground.setSize(sf::Vector2f{ 800.0f, 30.0f });
	m_ground.setPosition(0.0f, 450.0f);
	m_ground.setFillColor(sf::Color::Red);
	if (!m_arialFont.loadFromFile("c:\\windows\\fonts\\arial.ttf"))
	{
		std::cout << "problem loading font file";
	}
	// game over
	m_gameoverMessage.setFont(m_arialFont);
	m_gameoverMessage.setFillColor(sf::Color::Yellow);
	m_gameoverMessage.setPosition(300.0f, 220.0f);
	m_gameoverMessage.setCharacterSize(50);
	m_gameoverMessage.setString("Game Over");

	// power meter
	m_powerMeter.setSize(sf::Vector2f{ m_RectangleExtender,20.0f });
	m_powerMeter.setFillColor(sf::Color::Magenta);;
	m_powerMeter.setPosition(0.0f, 450.0f);
	m_powerMeter.setOutlineColor(sf::Color::Cyan);
	m_powerMeter.setOutlineThickness(6);

	// player box
	m_playerBox.setSize(sf::Vector2f{ 20.0f,20.0f });
	m_playerBox.setFillColor(sf::Color::White);
	m_playerBox.setPosition(380.0f, 430.0f);

	// players laser
	m_laserEnd = sf::Vertex(sf::Vector2f{ 300.0f, 200.0f }, sf::Color::Red);
	m_laserStart = sf::Vertex(sf::Vector2f{ 400.0f, 440.0f }, sf::Color::Red);

	// explosion circle
	m_explosion.setPosition(sf::Vector2f{ -200.0, -200.0 });
	m_explosion.setFillColor(sf::Color::Magenta);
	m_explosion.setOutlineColor(sf::Color::Cyan);
	m_explosion.setOutlineThickness(6);
}

	void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			if (!m_gameover)
			{
				update(timePerFrame);
			}
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event myEvent;
	while (m_window.pollEvent(myEvent))
	{
		if (myEvent.type == sf::Event::Closed)
		{
			m_window.close();

		}
		// creates an asteroid
		if (m_asteroidActive == false)
		{

		}

		// finds the point that the mouse clicks
		if (myEvent.type == sf::Event::MouseButtonPressed)
		{
			if (myEvent.mouseButton.button == sf::Mouse::Left)
			{
				m_targetPoint = sf::Vector2f(myEvent.mouseButton.x, myEvent.mouseButton.y);
				m_unitVector = (m_targetPoint - m_laserStart.position).unit();
				m_laserEnd.position = m_laserStart.position;
				m_laserActive = true;
			}
			
		}
	}
}

void Game::update(sf::Time t_deltaTime)
{
	// in order to draw the line we need to specify the begining and end points
	// to change the line we need to clear it and append two more vertexes 
	// remove this comment once you understand how to draw lines
	m_laserRay.clear();
	
	//
    if()
	m_RectangleExtender = m_RectangleExtender + m_RectangleExtender;
	m_powerMeter.setSize(sf::Vector2f{ m_RectangleExtender, 20.0f });
	// laser perameters------------------------------------------------------------
	if (m_laserActive == true)
	{
		if (m_laserEnd.position.y >= sf::Vector2f(m_targetPoint).y)
		{
			m_laserEnd.position = m_laserEnd.position + sf::Vector2f(m_unitVector);
			m_laserRay.append(m_laserStart);
			m_laserRay.append(m_laserEnd);
		}
		else
		{
			m_laserActive = false;
			m_explosionActive = true;
		}
		
		// explosions parameters----------------------------------------------------
	}
	if (m_explosionActive == true)
	{
		if (m_explosionRadius < 50)
		{
			m_explosion.setPosition(m_laserEnd.position);
			m_explosionRadius = m_explosionRadius + 1;
			m_explosion.setRadius(m_explosionRadius);

		}
		else
		{
			m_explosionActive = false;
			m_explosionRadius = 0.0f;
		}
	}
}

void Game::render()
{
	m_window.clear();
	m_window.draw(m_ground);
	m_window.draw(m_laserRay);
	
	m_window.draw(m_powerMeter);
	m_window.draw(m_playerBox);

	// makes the explosion disappear when its finished
	if (m_explosionActive == true)
	{
		m_window.draw(m_explosion);
	}

	// triggers game over message
	if (m_gameover)
	{
		m_window.draw(m_gameoverMessage);
	}
	m_window.display();
}
