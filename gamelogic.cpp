
void game_input_once() {

	if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P))
	{
		state = Paused;
	}
}
void game_update() {
	camera.setCenter(sf::Vector2f(Fox.getGlobalBounds().left + Fox.getGlobalBounds().width / 2.0f, Fox.getGlobalBounds().top + Fox.getGlobalBounds().height / 2.0f));

	Fox_hitbox.setPosition(Fox.getPosition().x + Fox.getGlobalBounds().width / 2, Fox.getPosition().y + Fox.getGlobalBounds().height / 2);
	// Handle movement input and running. Compute a velocity vector and normalize so diagonal isn't faster.
	float moveX = 0.0f, moveY = 0.0f;
	bool moving = false;
	if (Keyboard::isKeyPressed(Keyboard::W)) { moveY -= 1.0f; fox_direction = Up; moving = true; }
	if (Keyboard::isKeyPressed(Keyboard::S)) { moveY += 1.0f; fox_direction = Down; moving = true; }
	if (Keyboard::isKeyPressed(Keyboard::A)) { moveX -= 1.0f; fox_direction = Left; moving = true; }
	if (Keyboard::isKeyPressed(Keyboard::D)) { moveX += 1.0f; fox_direction = Right; moving = true; }

	bool runningInput = Keyboard::isKeyPressed(Keyboard::LShift) || Keyboard::isKeyPressed(Keyboard::RShift);

	if (moving) {
		// Set status and speed based on whether shift is held
		if (runningInput) {
			fox_status = Running;
			Fox_speed = Fox_base_speed * 1.5;
		}
		else {
			fox_status = Walking;
			Fox_speed = Fox_base_speed;
		}

		// normalize to avoid faster diagonal movement
		float len = std::sqrt(moveX * moveX + moveY * moveY);
		if (len > 0.0f) {
			moveX /= len; moveY /= len;
		}

		Fox.move(moveX * Fox_speed * Delta_time, moveY * Fox_speed * Delta_time);
	}
	else {
		// No movement keys pressed
		fox_status = Idle;
		Fox_speed = Fox_base_speed; // restore base speed
	}

	// If the animation state changed, reset the related timer/counter and set the initial frame
	if (previous_fox_status != fox_status) {
		if (fox_status == Idle) {
			Fox.setTexture(Fox_idle);
			Fox_Idle_counter = 0;
			Fox_idle_timer = 0;
			// Use current facing direction so we don't briefly show the wrong row
			int dirIndex = 0;
				switch (fox_direction) { case Right: dirIndex = 0; break; case Left: dirIndex = 1; break; case Up: dirIndex = 2; break; case Down: dirIndex = 3; break; }
												   Fox.setTextureRect(sf::IntRect(0, Fox_yoffset[dirIndex], idle_total_width / idle_framecount, idle_total_hight / idle_framecount));
		}
		else if (fox_status == Walking) {
			Fox.setTexture(Fox_walking);
			Fox_Walking_counter = 0;
			Fox_walking_timer = 0;
			int dirIndex = 0;
				switch (fox_direction) { case Right: dirIndex = 0; break; case Left: dirIndex = 1; break; case Up: dirIndex = 2; break; case Down: dirIndex = 3; break; }
												   Fox.setTextureRect(sf::IntRect(0, Fox_yoffset[dirIndex], walking_total_width / walking_framecount, walking_total_hight / walking_framecount));
		}
		else if (fox_status == Running) {
			Fox.setTexture(Fox_running);
			Fox_Running_counter = 0;
			Fox_running_timer = 0;
			int dirIndex = 0;
				switch (fox_direction) { case Right: dirIndex = 0; break; case Left: dirIndex = 1; break; case Up: dirIndex = 2; break; case Down: dirIndex = 3; break; }
												   Fox.setTextureRect(sf::IntRect(0, Fox_yoffset_run[dirIndex], running_total_width / running_framecount, running_total_hight / running_framecount));
		}
		previous_fox_status = fox_status;
	}
	switch (fox_status)
	{
	case Idle:

		Fox.setTexture(Fox_idle);
		animation_direction(fox_direction, Fox_idle_timer, Fox_Idle_counter, Fox, idle_framecount, idle_total_width / idle_framecount, idle_total_hight / idle_framecount, Fox_yoffset);
		break;
	case Walking:
		Fox.setTexture(Fox_walking);
		animation_direction(fox_direction, Fox_walking_timer, Fox_Walking_counter, Fox, walking_framecount, walking_total_width / walking_framecount, walking_total_hight / walking_framecount, Fox_yoffset);

		break;
	case Running:
		Fox.setTexture(Fox_running);
		animation_direction(fox_direction, Fox_running_timer, Fox_Running_counter, Fox, running_framecount, running_total_width / running_framecount, running_total_hight / running_framecount, Fox_yoffset_run);

		break;
	default:
		break;
	}
}

struct NPC
{
	Texture texure; Sprite sprite;
	RectangleShape hitbox;
	NPC(Texture &t, Sprite &s) {
		texure = t;
		sprite = s;
		sprite.setTexture(texure);
		hitbox.setSize(sf::Vector2f(sprite.getGlobalBounds().width-100, sprite.getGlobalBounds().height-100));
	}
	void collision()
	{
		if (Fox_hitbox.getGlobalBounds().intersects(hitbox.getGlobalBounds()))
		{
			// Handle collision response here
			// For example, you could stop the fox from moving or push it back
			 Fox.move(-Fox_speed * Delta_time, 0); // Example: push back to the left
		}
	}

};

void game_draw() {
	window.setView(camera);
	window.draw(Game_Background_Sprite);
	window.draw(Fox);
	window.draw(Fox_hitbox);
}