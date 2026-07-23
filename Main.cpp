#include "bits/stdc++.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

#include "Globals.cpp"
#include "Textures.cpp"
#include "Animation.cpp"
#include "menu.cpp"
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
			// Handle pause input inside event loop (must check KeyPressed events)

			switch (state)
			{
			case Main_menu:
				main_menu(event, mouse_pos);
				break;
			case Playing:
				// NPC interaction input is called after event loop below
				if (state == Playing && event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::P))
				{
					state = Paused;
				}
				Deer.input_once();
				Deer1.input_once();
				Boar.input_once();
				Black_grouse.input_once();
				Black_grouse1.input_once();
				Black_grouse2.input_once();
				Black_grouse3.input_once();
				Hare.input_once();
				Hare1.input_once();


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


		}
			// Call NPC input_once() AFTER event loop completes (for interaction input)
			if (state == Playing)
			{
				Hare.input_once();
				Hare1.input_once();
				Deer.input_once();
				Deer1.input_once();
				Boar.input_once();
				Black_grouse.input_once();
				Black_grouse1.input_once();
				Black_grouse2.input_once();
				Black_grouse3.input_once();
			}
		update();
		window.clear();
		draw(state);
		window.display();

	}
		return 0;
}








