void set_animition(float& timer, int& counter, Sprite& sprite, int idle_framecount, int framewidth, int framehight, int yoffset)
{
	timer += Delta_time;
	if (timer >= 0.17)
	{
		timer = 0;
		counter = (counter + 1) % idle_framecount;
		sprite.setTextureRect(sf::IntRect(counter * framewidth, yoffset, framewidth, framehight));
	}
}
void set_Static_animition(Texture texture[], int& counter, Sprite& sprite, int framecount, float& timer)
{
	timer += Delta_time;
	if (timer >= 0.17)
	{
		timer = 0;
		counter = (counter + 1) % framecount;
		sprite.setTexture(texture[counter]);
	}
}
void animation_direction(last_direction& direction, float& timer, int& counter, Sprite& sprite, int framecount, int framewidth, int framehight, int yoffset[]) {
	switch (direction)
	{
	case Right:
		set_animition(timer, counter, sprite, framecount, framewidth, framehight, yoffset[0]);

		break;

	case Left:
		set_animition(timer, counter, sprite, framecount, framewidth, framehight, yoffset[1]);

		break;

	case Up:
		set_animition(timer, counter, sprite, framecount, framewidth, framehight, yoffset[2]);
		break;
	case Down:
		set_animition(timer, counter, sprite, framecount, framewidth, framehight, yoffset[3]);
		break;
	default:
		break;
	}
}
void set_NPC_animition(float& timer, int& counter, Sprite& sprite, int idle_framecount, int framewidth, int framehight, int yoffset)
{
	timer += Delta_time;
	if (timer >= 0.17)
	{
		timer = 0;
		counter = (counter + 1) % idle_framecount;
		sprite.setTextureRect(sf::IntRect(counter * framewidth, yoffset, framewidth, framehight));
	}
}
