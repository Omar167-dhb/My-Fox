void menu_intialization()
{
	Main_Menu_Background.loadFromFile("GUI/Main_menu_background.png");
	Main_Menu_Background_Sprite.setTexture(Main_Menu_Background);
	font.loadFromFile("GUI/Cheese Milky.otf");
	for (auto& x : Main_Menu_texts)
	{
		x.setFont(font);
		x.setCharacterSize(50);
		x.setFillColor(sf::Color::White);
		x.setOutlineColor(sf::Color::Black);
		x.setOutlineThickness(1.5);
		x.setOrigin(x.getGlobalBounds().width / 2, x.getGlobalBounds().height / 2);
		x.setPosition(800, 200 + (&x - &Main_Menu_texts[0]) * 100);
	}
	Main_Menu_texts[0].setString("PLAY");
	Main_Menu_texts[1].setString("HOW TO PLAY");
	Main_Menu_texts[2].setString("OPTIONS");
	Main_Menu_texts[3].setString("CREDITS");
	Main_Menu_texts[4].setString("QUIT");
	Main_Menu_texts[0].setFillColor(sf::Color::Magenta);
	for (int i = 0; i < 6; i++)
	{
		if (i < 3)
		{
			Settings_texts[i].setFont(font);
			Settings_texts[i].setCharacterSize(80);
			Settings_texts[i].setFillColor(sf::Color::White);
			Settings_texts[i].setOutlineColor(sf::Color::Black);
			Settings_texts[i].setOutlineThickness(1.5);
			Settings_texts[i].setOrigin(Settings_texts[i].getGlobalBounds().width / 2, Settings_texts[i].getGlobalBounds().height / 2);

			Pause_text[i].setFont(font);
			Pause_text[i].setCharacterSize(80);
			Pause_text[i].setFillColor(sf::Color::White);
			Pause_text[i].setOutlineColor(sf::Color::Black);
			Pause_text[i].setOutlineThickness(1.5);
			Pause_text[i].setOrigin(Settings_texts[i].getGlobalBounds().width / 2, Settings_texts[i].getGlobalBounds().height / 2);
			Pause_text[i].setPosition(800, 200 + i * 100);


			Settings_texts1[i].setFont(font);
			Settings_texts1[i].setCharacterSize(80);
			Settings_texts1[i].setFillColor(sf::Color::White);
			Settings_texts1[i].setOutlineColor(sf::Color::Black);
			Settings_texts1[i].setOutlineThickness(1.5);
			Settings_texts1[i].setOrigin(Settings_texts1[i].getGlobalBounds().width / 2, Settings_texts1[i].getGlobalBounds().height / 2);
			Settings_texts[i].setPosition(600, 200 + i * 100);
			Settings_texts1[i].setPosition(1200, 200 + i * 100);
		}
		Inc_Dec[i].setFont(font);
		Inc_Dec[i].setCharacterSize(80);
		Inc_Dec[i].setFillColor(sf::Color::White);
		Inc_Dec[i].setOutlineColor(sf::Color::Black);
		Inc_Dec[i].setOutlineThickness(1.5);
		Inc_Dec[i].setOrigin(Inc_Dec[i].getGlobalBounds().width / 2, Inc_Dec[i].getGlobalBounds().height / 2);
		if (i % 2 == 0)
			Inc_Dec[i].setPosition(1100, 200 + (i / 2) * 100);
		else
			Inc_Dec[i].setPosition(1400, 200 + (i / 2) * 100);
	}
	Settings_texts[0].setString("Main_Volume : ");
	Settings_texts[1].setString("Sound_Volume : ");
	Settings_texts[2].setString("Music_Volume : ");

	Settings_texts1[0].setString(to_string(Main_volume));
	Settings_texts1[1].setString(to_string(sound_temp));
	Settings_texts1[2].setString(to_string(music_temp));

	Inc_Dec[0].setString("+");
	Inc_Dec[2].setString("+");
	Inc_Dec[4].setString("+");
	Inc_Dec[1].setString("-");
	Inc_Dec[3].setString("-");
	Inc_Dec[5].setString("-");

	Pause_text[0].setString("RESUME");
	Pause_text[1].setString("SETTINGS");
	Pause_text[2].setString("BACK TO MAIN MENU");

	// Recalculate origins now that strings are set so centering is correct
	for (auto& x : Main_Menu_texts)
	{
		x.setOrigin(x.getGlobalBounds().width / 2, x.getGlobalBounds().height / 2);
	}
	// Ensure first item in main menu starts selected (magenta)
	Main_Menu_texts[0].setFillColor(Color::Magenta);

	for (int i = 0; i < 3; ++i) {
		Settings_texts[i].setOrigin(Settings_texts[i].getGlobalBounds().width / 2, Settings_texts[i].getGlobalBounds().height / 2);
		Settings_texts1[i].setOrigin(Settings_texts1[i].getGlobalBounds().width / 2, Settings_texts1[i].getGlobalBounds().height / 2);
		Pause_text[i].setOrigin(Pause_text[i].getGlobalBounds().width / 2, Pause_text[i].getGlobalBounds().height / 2);
	}
	// Ensure first item in pause menu starts selected (magenta)
	Pause_text[0].setFillColor(Color::Magenta);

}

void main_menu(Event& event, sf::Vector2i mouse_pos)
{
	if (event.type == Event::MouseMoved)
	{
		for (auto& x : Main_Menu_texts)
		{
			if (x.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
			{
				x.setFillColor(Color::Magenta);
				Main_Menu_counter_mouse = &x - &Main_Menu_texts[0];
			}
			else
				x.setFillColor(Color::White);
		}
	}
	if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
	{
		for (auto& x : Main_Menu_texts)
		{
			if (x.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
			{
				switch (&x - &Main_Menu_texts[0]) {
				case 0:
					state = Playing;
					break;
				case 1:
					state = How_to_play;
					break;
				case 2:
					state = Settings;
					break;
				case 3:
					state = credits;
					break;
				case 4:
					window.close();
					break;
				}
			}
		}
	}

	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up)
	{
		if (Main_Menu_counter_key > 0)
		{
			Main_Menu_texts[Main_Menu_counter_key].setFillColor(Color::White);
			Main_Menu_counter_key--;
			Main_Menu_counter_key %= 5;
			Main_Menu_texts[Main_Menu_counter_key].setFillColor(Color::Magenta);


		}
	}
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down)
	{
		if (Main_Menu_counter_key < 4)
		{
			Main_Menu_texts[Main_Menu_counter_key].setFillColor(Color::White);
			Main_Menu_counter_key++;
			Main_Menu_counter_key %= 5;
			Main_Menu_texts[Main_Menu_counter_key].setFillColor(Color::Magenta);

		}
	}
	if ((event.type == Event::KeyPressed && event.key.code == Keyboard::Enter))
	{
		last_state = Main_menu;
		switch (Main_Menu_counter_key)
		{
		case 0:
			state = Playing;
			break;
		case 1:
			state = How_to_play;
			break;
		case 2:
			state = Settings;
			break;
		case 3:
			state = credits;
			break;
		case 4:
			window.close();
			break;
		default:
			break;
		}
	}


}
void setting_menu(Event& event, sf::Vector2i mouse_pos)
{
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
	{
		if (last_state == Main_menu)
			state = Main_menu;
		else if (last_state == Paused)
		{
			state = Paused;
			last_state = Playing;
		}
	}
	for (auto& x : Inc_Dec)
	{
		if (x.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
		{
			x.setFillColor(sf::Color::Magenta);
			Inc_counter = &x - &Inc_Dec[0];
		}

		else
			x.setFillColor(sf::Color::White);

		if ((x.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y) && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left))
		{
			if (Inc_counter == 0)
			{
				if (Main_volume < 100)
					Main_volume += 10;
				if (Main_volume > Music_volume && Main_volume <= music_temp)
				{
					Music_volume += 10;

				}
				if (Main_volume > Sound_volume && Main_volume <= sound_temp)
				{
					Sound_volume += 10;

				}

			}
			else if (Inc_counter == 1)
			{
				if (Main_volume > 0)
					Main_volume -= 10;
				if (Main_volume < Music_volume)
				{
					Music_volume -= 10;
				}
				if (Main_volume < Sound_volume)
				{
					Sound_volume -= 10;
				}
			}
			else if (Inc_counter == 2)
			{
				if (Sound_volume < 100)
				{

					Sound_volume += 10;
					sound_temp = Sound_volume;
				}
			}
			else if (Inc_counter == 3)
			{
				if (Sound_volume > 0)
				{
					Sound_volume -= 10;
					sound_temp = Sound_volume;

				}
			}
			else if (Inc_counter == 4)
			{
				if (Music_volume < 100)
				{
					Music_volume += 10;
					music_temp = Music_volume;
				}
			}
			else if (Inc_counter == 5)
			{
				if (Music_volume > 0)
				{
					Music_volume -= 10;
					music_temp = Music_volume;
				}
			}
		}
	}

}

void how_to_play_menu(Event& event, sf::Vector2i mouse_pos)
{
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
	{
		state = Main_menu;
	}
}

void credits_menu(Event& event, sf::Vector2i mouse_pos)
{
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
	{
		state = Main_menu;
	}
}

void pause_menu(Event& event, sf::Vector2i mouse_pos)
{
	if ((event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) || (event.type == Event::KeyPressed && event.key.code == Keyboard::P))
	{
		state = Playing;
	}
	if (event.type == Event::MouseMoved)
		for (auto& x : Pause_text)
		{
			if (x.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
			{

				x.setFillColor(Color::Magenta);
				Pause_counter_mouse = &x - &Pause_text[0];
			}
			else
				x.setFillColor(Color::White);

		}
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up)
	{
		if (Pause_counter_key > 0)
		{
			Pause_text[Pause_counter_key].setFillColor(Color::White);
			Pause_counter_key--;
			Pause_text[Pause_counter_key].setFillColor(Color::Magenta);
			if (Pause_counter_key < 0)
				Pause_counter_key = 2;

		}
	}
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down)
	{
		if (Pause_counter_key < 2)
		{
			Pause_text[Pause_counter_key].setFillColor(Color::White);
			Pause_counter_key++;

			Pause_text[Pause_counter_key].setFillColor(Color::Magenta);
			if (Pause_counter_key > 2)
				Pause_counter_key = 0;
		}
	}
	if ((event.type == Event::KeyPressed && event.key.code == Keyboard::Enter))
	{
		switch (Pause_counter_key)
		{
		case 0:
			state = Playing;
			break;
		case 1:
			last_state = Paused;
			state = Settings;
			break;
		case 2:
			state = Main_menu;
			break;
		default:
			break;
		}
	}
	if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
		switch (Pause_counter_mouse) {
		case 0:
			state = Playing;
			break;
		case 1:
			last_state = Paused;
			state = Settings;
			break;
		case 2:
			state = Main_menu;
			break;
		}
}


void menu_Input(Event& event, sf::Vector2i mouse_pos)
{

	switch (state)
	{
	case Main_menu:
		main_menu(event, mouse_pos);
		break;
	case Settings:
		setting_menu(event, mouse_pos);
		break;
	case How_to_play:
		how_to_play_menu(event, mouse_pos);
		break;
	case credits:
		credits_menu(event, mouse_pos);
		break;
	case Paused:
		pause_menu(event, mouse_pos);
		break;
	case Playing:
		game_input_once();
		if ((event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) || (event.type == Event::KeyPressed && event.key.code == Keyboard::P))
		{
			state = Paused;
		}

		break;

	}
}
void menu_Update()
{
	Settings_texts1[0].setString(to_string(Main_volume));
	Settings_texts1[1].setString(to_string(sound_temp));
	Settings_texts1[2].setString(to_string(music_temp));
}
void menu_draw()
{
	switch (state)
	{
	case Main_menu:
	window.draw(Main_Menu_Background_Sprite);
	for (const auto& x : Main_Menu_texts)
	{
		window.draw(x);
	}
		break;
	case Paused:
		for (auto& x : Pause_text)
		{
			window.draw(x);
		}
		break;
	case Settings:
		window.draw(Main_Menu_Background_Sprite);
		for (int i = 0; i < 3; i++)
		{
			window.draw(Settings_texts[i]);
			window.draw(Settings_texts1[i]);
		}
		for (auto& x : Inc_Dec)
			window.draw(x);
		break;
	case How_to_play:
		break;
	case credits:
		break;
	default:
		break;
	}

}