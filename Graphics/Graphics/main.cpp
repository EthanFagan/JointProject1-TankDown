/// <summary>
/// 
/// 
/// 
/// </summary>
#include <SFML/Graphics.hpp>

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 




int main()
{
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	sf::CircleShape circle(50);
	circle.setPosition(100, 100);
	
	circle.setFillColor(sf::Color(100, 250, 50));
	
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
				window.close();
		}

		
		window.clear(sf::Color::Black);

		
		
		window.draw(circle);

		// end the current frame
		window.display();
	}

	return 0;
}