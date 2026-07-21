void intializing_textures()
{
	// Load the textures for the fox's animations and set the initial texture and position of the fox sprite
	Fox_walking.loadFromFile("MAIN/My-Fox/Animals/Fox/Fox_Walk_with_shadow.png");
	Fox_running.loadFromFile("MAIN/My-Fox/Animals/Fox/Fox_Run_with_shadow.png");
	Fox_idle.loadFromFile("MAIN/My-Fox/Animals/Fox/Fox_Idle_with_shadow.png");
	Fox.setTexture(Fox_idle);
	Fox.setScale(4.0f, 4.0f);
	Fox.setTextureRect(sf::IntRect(0, 96, 128 / 4, 128));
	Fox.setPosition(7981, 6156);
	idle_total_width = Fox_idle.getSize().x;
	idle_total_hight = Fox_idle.getSize().y;
	walking_total_width = Fox_walking.getSize().x;
	walking_total_hight = Fox_walking.getSize().y + 50;
	running_total_width = Fox_running.getSize().x;
	running_total_hight = Fox_running.getSize().y + 50;
	// Set up the hitbox for the fox, which is used for collision detection
	Fox_hitbox.setSize(sf::Vector2f(80, 50));
	Fox_hitbox.setFillColor(sf::Color::Transparent);
	Fox_hitbox.setOrigin(Fox_hitbox.getSize().x / 2, Fox_hitbox.getSize().y / 2);
	// Load the textures for the main menu and game backgrounds, as well as a secondary background texture
	Game_Background.loadFromFile("MAIN/My-Fox/GUI/Map.png");
	Game_Background_Sprite.setTexture(Game_Background);
	secondary_background_texture.loadFromFile("MAIN/My-Fox/GUI/image (1).png");
	secondary_background_sprite.setTexture(secondary_background_texture);

	// load the textures of animated Keys for menus
	W_texture[1].loadFromFile("MAIN/My-Fox/GUI/Kb_buttons_W_1.png");
	A_texture[0].loadFromFile("MAIN/My-Fox/GUI/Kb_buttons_A_1.png");
	S_texture[1].loadFromFile("MAIN/My-Fox/GUI/Kb_buttons_S_1.png");
	D_texture[0].loadFromFile("MAIN/My-Fox/GUI/Kb_buttons_D_1.png");
	Shift_texture[1].loadFromFile("MAIN/My-Fox/GUI/Kb_buttons_Shift_1.png");
	E_texture[0].loadFromFile("MAIN/My-Fox/GUI/Kb_button_E_1.png");
	Esc_texture[0].loadFromFile("MAIN/My-Fox/GUI/Kb_buttons_Esc_1.png");
	W_texture[0].loadFromFile("MAIN/My-Fox/GUI/Kb_buttons_W_2.png");
	A_texture[1].loadFromFile("MAIN/My-Fox/GUI/Kb_buttons_A_2.png");
	S_texture[0].loadFromFile("MAIN/My-Fox/GUI/Kb_buttons_S_2.png");
	D_texture[1].loadFromFile("MAIN/My-Fox/GUI/Kb_buttons_D_2.png");
	Shift_texture[0].loadFromFile("MAIN/My-Fox/GUI/Kb_buttons_Shift_2.png");
	E_texture[1].loadFromFile("MAIN/My-Fox/GUI/Kb_button_E_2.png");
	Esc_texture[1].loadFromFile("MAIN/My-Fox/GUI/Kb_buttons_Esc_2.png");
	P_texture[1].loadFromFile("MAIN/My-Fox/GUI/Kb_buttons_P_2.png");
	W_sprite.setTexture(W_texture[0]);
	A_sprite.setTexture(A_texture[0]);
	S_sprite.setTexture(S_texture[0]);
	D_sprite.setTexture(D_texture[0]);
	Shift_sprite.setTexture(Shift_texture[0]);
	E_sprite.setTexture(E_texture[0]);
	Esc_sprite.setTexture(Esc_texture[0]);
	P_sprite.setTexture(P_texture[0]);

	Esc_sprite.setOrigin(Esc_sprite.getGlobalBounds().width / 2, Esc_sprite.getGlobalBounds().height / 2);
	Esc_sprite.setPosition(50, 50);
	Esc_sprite.setScale(2.0f, 2.0f);
	E_sprite.setOrigin(E_sprite.getGlobalBounds().width / 2, E_sprite.getGlobalBounds().height / 2);
	E_sprite.setScale(2.0f, 2.0f);
	W_sprite.setScale(2.0f, 2.0f);
	A_sprite.setScale(2.0f, 2.0f);
	S_sprite.setScale(2.0f, 2.0f);
	D_sprite.setScale(2.0f, 2.0f);
	Shift_sprite.setScale(2.0f, 2.0f);
	P_sprite.setScale(2.0f, 2.0f);
	W_sprite.setOrigin(W_sprite.getGlobalBounds().width / 2, W_sprite.getGlobalBounds().height / 2);
	A_sprite.setOrigin(A_sprite.getGlobalBounds().width / 2, A_sprite.getGlobalBounds().height / 2);
	S_sprite.setOrigin(S_sprite.getGlobalBounds().width / 2, S_sprite.getGlobalBounds().height / 2);
	D_sprite.setOrigin(D_sprite.getGlobalBounds().width / 2, D_sprite.getGlobalBounds().height / 2);
	Shift_sprite.setOrigin(Shift_sprite.getGlobalBounds().width / 2, Shift_sprite.getGlobalBounds().height / 2);
	P_sprite.setOrigin(P_sprite.getGlobalBounds().width / 2, P_sprite.getGlobalBounds().height / 2);
	W_sprite.setPosition(560, 440);
	A_sprite.setPosition(530, 470);
	S_sprite.setPosition(560, 470);
	D_sprite.setPosition(590, 470);
	Shift_sprite.setPosition(1050, 560);
	E_sprite.setPosition(700, 550);
	P_sprite.setPosition(500, 600);
	Esc_sprite1.setTexture(Esc_texture[0]);
	Esc_sprite1.setPosition(700, 600);
	Esc_sprite1.setOrigin(Esc_sprite1.getGlobalBounds().width / 2, Esc_sprite1.getGlobalBounds().height / 2);
	Esc_sprite1.setScale(2.0f, 2.0f);

}

