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
			if (state == Main_menu || (state == Settings&&last_state==Main_menu) || state == How_to_play || state == credits)
			{
				if (Main.getStatus() != sf::Sound::Playing)
					Main.play();
			}
			else Main.stop();

			if (state == Playing || state == Paused || (state == Settings && last_state == Paused))
			{
				if (game.getStatus() != sf::Sound::Playing)
					game.play();
			}else game.stop();

			switch (state)
			{
			case Main_menu:
				main_menu(event, mouse_pos);
				
				break;
			case Playing:
			{
				// NPC interaction input is called after event loop below
				if (state == Playing && event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::P))
				{
					state = Paused;
				}
				Deer.input_once();
				Deer1.input_once();
				if (Deer1.txt)
				{
					if (alawey.getStatus() != sf::Sound::Playing)
					{
						alawey.play();
					}
				}
				else
				{
					alawey.stop();
				}
				Boar.input_once();
				if (Boar.txt)
				{
					if (Boar.txt)
					{
						out.play();
					}
				}
				else out.stop();
				Black_grouse.input_once();
				Black_grouse1.input_once();
				Black_grouse2.input_once();
				Black_grouse3.input_once();
				Hare.input_once();
				Hare1.input_once();
				if (Hare1.txt)
				{
					if (money.getStatus() != sf::Sound::Playing)
					{
						money.play();
					}
				}
				else
				{
					money.stop();
				}
				sakura.input_once();
				// Handle well interactions and play Goo2 if any well text is open.
				bool anyWellTxt = false;
				for (int i = 0; i < 2; i++)
				{
					welll[i].input_once();
					if (welll[i].txt) anyWellTxt = true;
				}
				if (anyWellTxt)
				{
					if (Goo2.getStatus() != sf::Sound::Playing)
						Goo2.play();
				}
				else
				{
					Goo2.stop();
				}
			}
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
			// Update game state first so interaction flags are refreshed this frame
			update();

			// Hide mouse cursor while playing so it doesn't appear in-game
			window.setMouseCursorVisible(state != Playing);

			// Then handle per-frame input-based interactions (E key)
		window.clear();
		draw(state);
		window.display();

	}
		return 0;
}








