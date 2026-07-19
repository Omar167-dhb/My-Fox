#include "bits/stdc++.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

#include "Globals.cpp"
#include "menu.cpp"
#include "Animation.cpp"
#include "Textures.cpp"
#include "gamelogic.cpp"


int main()
{


	intializing();
	while (window.isOpen())
	{
		Delta_time = clock1.restart().asSeconds();
		mouse_pos = sf::Mouse::getPosition(window);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();


			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F11)
			{
				if (isfullscreen)
				{
					window.create(desktop, " My Fox ^^)", sf::Style::Default);
					isfullscreen = false;
				}
				else
				{
					window.create(desktop, " My Fox ^^)", sf::Style::Fullscreen);
					isfullscreen = true;
				}
			}

			Input(event, mouse_pos);

		}
		update();

		draw();
	}
		return 0;
}








