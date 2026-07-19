void intializing_textures()
{
	Fox_walking.loadFromFile("Animals/Fox/Fox_Walk_with_shadow.png");
	Fox_running.loadFromFile("Animals/Fox/Fox_Run_with_shadow.png");
	Fox_idle.loadFromFile("Animals/Fox/Fox_Idle_with_shadow.png");
	Fox.setTexture(Fox_idle);
	Fox.setScale(3.0f, 3.0f);
	Fox.setTextureRect(sf::IntRect(0, 96, 128 / 4, 128));
	Fox.setPosition(800, 400);
	idle_total_width = Fox_idle.getSize().x;
	idle_total_hight = Fox_idle.getSize().y;
	walking_total_width = Fox_walking.getSize().x;
	walking_total_hight = Fox_walking.getSize().y + 50;
	running_total_width = Fox_running.getSize().x;
	running_total_hight = Fox_running.getSize().y + 50;
	Fox_hitbox.setSize(sf::Vector2f(80, 50));
	Fox_hitbox.setFillColor(sf::Color::Transparent);
	Fox_hitbox.setOrigin(Fox_hitbox.getSize().x / 2, Fox_hitbox.getSize().y / 2);

	Game_Background.loadFromFile("GUI/Map.png");
	Game_Background_Sprite.setTexture(Game_Background);
}

