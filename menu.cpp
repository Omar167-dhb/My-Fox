void menu_intialization()
{


	Main_Menu_Background.loadFromFile("MAIN/My-Fox/GUI/Main_menu_background.png");
	Main_Menu_Background_Sprite.setTexture(Main_Menu_Background);
	font.loadFromFile("MAIN/My-Fox/GUI/Cheese Milky.otf");
	font1.loadFromFile("MAIN/My-Fox/GUI/ByteBounce.ttf");
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
			Inc_Dec[i].setPosition(1000, 180 + (i / 2) * 100);
		else
			Inc_Dec[i].setPosition(1400, 180 + (i / 2) * 100);
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
	// Recalculate Inc_Dec origins now that strings are set so collision detection is correct
	for (int i = 0; i < 6; ++i) {
		Inc_Dec[i].setOrigin(Inc_Dec[i].getGlobalBounds().width / 2, Inc_Dec[i].getGlobalBounds().height / 2);
	}
	// Ensure first item in pause menu starts selected (magenta)
	Pause_text[0].setFillColor(Color::Magenta);

	for (auto& x : How_to_play_texts)
	{
		x.setFont(font);
		x.setCharacterSize(50);
		x.setFillColor(sf::Color::White);
		x.setOutlineColor(sf::Color::Black);
		x.setOutlineThickness(1.5);
		x.setOrigin(x.getGlobalBounds().width / 2, x.getGlobalBounds().height / 2);
		x.setPosition(400, 200 + (&x - &How_to_play_texts[0]) * 100);
	}
	string how_to_play_instructions[] = {
		"Hello lolo ^^)",
		"This is the controls of the game..",
		"Use \t\t to Move",
		"If you want to run just hold \t\t while you are moving",
		"If you will inetract with NPC (side character) you will press\t",
		"If you want to pause the game you can press \t or \t"
	};
	for (int i = 0; i < 6; i++)
	{
		How_to_play_texts[i].setString(how_to_play_instructions[i]);
	}
	Exit_text.setOrigin(Exit_text.getGlobalBounds().width / 2, Exit_text.getGlobalBounds().height / 2);
	Exit_text.setFillColor(sf::Color::White);
	Exit_text.setOutlineColor(sf::Color::Black);
	Exit_text.setOutlineThickness(1.5);
	Exit_text.setPosition(120, 40);

	String credits[] = {
		"Your Loyal Slave",
		" Omar Ahmed ",
		
	};
	for (auto& x : credits_text)
	{
		x.setFont(font);
		x.setCharacterSize(80);
		x.setFillColor(sf::Color::White);
		x.setOutlineColor(sf::Color::Black);
		x.setOutlineThickness(2);
		if((&x - &credits_text[0])%2 == 0)
			x.setString(credits[0]);
		else
			x.setString(credits[1]);
		x.setOrigin(x.getGlobalBounds().width / 2, x.getGlobalBounds().height / 2);
		x.setPosition(window_w / 2,  200 + (&x - &credits_text[0]) * 200);
	}
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
					last_state = Main_menu;
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

void how_to_play_menu(Event& event)
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

void How_to_play_menu_update()
{
	set_Static_animition(W_texture, keyboard_count, W_sprite, 2, W_sprite_timer);
	set_Static_animition(A_texture, keyboard_count, A_sprite, 2, A_sprite_timer);
	set_Static_animition(S_texture, keyboard_count, S_sprite, 2, S_sprite_timer);
	set_Static_animition(D_texture, keyboard_count, D_sprite, 2, D_sprite_timer);
	set_Static_animition(Shift_texture, keyboard_count, Shift_sprite, 2, Shift_sprite_timer);
	set_Static_animition(E_texture, keyboard_count, E_sprite, 2, E_sprite_timer);
	set_Static_animition(Esc_texture, keyboard_count, Esc_sprite, 2, Esc_sprite_timer);
	set_Static_animition(Esc_texture, keyboard_count, Esc_sprite1, 2, Esc1_sprite_timer);
	set_Static_animition(P_texture, keyboard_count, P_sprite, 2, P_sprite_timer);
}
void menu_update(game_state& state)
{
	
}
	
void sound_init()
{
	water.loadFromFile("MAIN/My-Fox/GUI/Goo2.mp3");
	walk.loadFromFile("MAIN/My-Fox/GUI/grass.mp3");
	menu.loadFromFile("MAIN/My-Fox/GUI/menu_sound.mp3");
	play.loadFromFile("MAIN/My-Fox/GUI/game_sound.mp3");
	felos.loadFromFile("MAIN/My-Fox/GUI/hane3mel eh.mp3");
	meme.loadFromFile("MAIN/My-Fox/GUI/3lawey.mp3");
	getout.loadFromFile("MAIN/My-Fox/GUI/GET OUTmp3.mp3");

	
	Goo2.setBuffer(water);
	grass.setBuffer(walk);
	Main.setBuffer(menu);
	Main.setLoop(true);
	game.setBuffer(play);
	game.setLoop(true);

	// Loop grass sound so it can be played continuously while the fox moves
	grass.setLoop(true);
	money.setBuffer(felos);
	alawey.setBuffer(meme);
	out.setBuffer(getout);
}
void sound_update()
{
	Goo2.setVolume(Sound_volume);
	grass.setVolume(Sound_volume);
	Main.setVolume(Music_volume);
	game.setVolume(Music_volume);
	money.setVolume(Sound_volume);
	alawey.setVolume(Sound_volume);
	out.setVolume(sound_temp);

}