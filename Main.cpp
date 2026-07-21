#include "bits/stdc++.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

#include "Globals.cpp"
#include "Animation.cpp"
#include "menu.cpp"
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
			switch (state)
			{
			case Main_menu:
				main_menu(event, mouse_pos);
				break;
			case Playing:
				game_input_once();
				break;
			case Paused:
				pause_menu(event, mouse_pos);
				break;
			case Settings:
				setting_menu(event, mouse_pos);
				break;
			case How_to_play:
				how_to_play_menu(event);
				break;
			case credits:
				credits_menu(event, mouse_pos);
				break;
			default:
				break;
			}
			//Input(event, mouse_pos);

		}
		update();
		window.clear();
		draw(state);
		window.display();

	}
		return 0;
}








