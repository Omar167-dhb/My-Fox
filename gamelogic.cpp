struct button
{
	Texture bot_texture[2];
	Sprite bot_sprite;
	void set_texture(Texture t[])
	{
		bot_texture[0] = t[0];
		bot_texture[1] = t[1];
		bot_sprite.setTexture(bot_texture[0]);
		bot_sprite.setOrigin(bot_sprite.getGlobalBounds().width / 2, bot_sprite.getGlobalBounds().height / 2);
	}
	button()
	{
		// Texture will be set via set_texture() before use
		bot_sprite.setScale(3, 3);
	}
};
struct Decor
{
	Texture texure;
	Texture &back_text = text_background_texture;
	Sprite sprite,back;
	RectangleShape hitbox,interaction_box;
	button interact_button;
	Typewriter text=Typewriter(font1);
	bool interact = false, txt = false;
	int counter = 0;
	float timer = 0;
	int yoffset = 0;
	int key_counter = 0;
	float key_timer = 0;
	void intialize( Texture& t)
	{
		texure = t;
		//sprite.setTexture(texure);
		//hitbox.setSize(sf::Vector2f(sprite.getGlobalBounds().width-100, sprite.getGlobalBounds().height-100));

		sprite.setTexture(texure);
		//sprite.setTextureRect(sf::IntRect(0, height, 128/4, 128/4));
		sprite.setOrigin(0, sprite.getGlobalBounds().height );
		hitbox.setSize(sf::Vector2f(sprite.getGlobalBounds().width/2-50 , sprite.getLocalBounds().height /3));
		hitbox.setFillColor(sf::Color::Transparent);
		hitbox.setOrigin(0, hitbox.getSize().y );
		//hitbox.setPosition(Vector2f(sprite.getPosition().x+130, sprite.getPosition().y-90));
	}
	void animation_init(int frame_width, int frame_height, int frame_count)
	{
		sprite.setTextureRect(sf::IntRect(0, yoffset, frame_width, frame_height));
	}
	void animation( int frame_width, int frame_height, int frame_count)
	{
		set_NPC_animition(timer, counter, sprite, frame_count, frame_width, frame_height, yoffset);
	}
	void collision()
	{
		if (Fox_hitbox.getGlobalBounds().intersects(hitbox.getGlobalBounds()))
		{
			// Directional collision response
			sf::FloatRect foxBounds = Fox_hitbox.getGlobalBounds();
			sf::FloatRect objBounds = hitbox.getGlobalBounds();

			float dx = (foxBounds.left + foxBounds.width / 2) - (objBounds.left + objBounds.width / 2);
			float dy = (foxBounds.top + foxBounds.height / 2) - (objBounds.top + objBounds.height / 2);

			if (std::abs(dx) > std::abs(dy)) {
				// Horizontal collision - push back horizontally
				if (dx > 0) Fox.move(5, 0);
				else        Fox.move(-5, 0);
			} else {
				// Vertical collision - push back vertically
				if (dy > 0) Fox.move(0, 5);
				else        Fox.move(0, -5);
			}
		}
	}
	void interaction_init(string str)
	{
		//interaction_box.setSize(sf::Vector2f(45, 30));
		interaction_box.setFillColor(sf::Color::Transparent);
		//interaction_box.setOrigin(interaction_box.getSize().x / 2, interaction_box.getSize().y / 2);
		interaction_box.setSize(Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height));
		//interaction_box.setFillColor(sf::Color::Yellow);
		text.setText(str);
		this->interact_button.set_texture(E_texture);
		back.setTexture(back_text);
		back.setOrigin(0, back.getGlobalBounds().height );
		//back.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width, sprite.getPosition().y);
		text.text.setOrigin(0, text.text.getGlobalBounds().height );
		text.text.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width, sprite.getPosition().y);
		interaction_box.setPosition(sprite.getPosition().x-80, sprite.getPosition().y+100 );
		interaction_box.setOrigin(0, interaction_box.getSize().y );
	}
	void interaction()
	{
		if (interaction_box.getGlobalBounds().intersects(Fox_hitbox.getGlobalBounds()))
		{
			set_Static_animition(interact_button.bot_texture, key_counter, this->interact_button.bot_sprite, 2, key_timer);
			interact = true;
		}
		else
			interact = false;
		this->interact_button.bot_sprite.setPosition(sprite.getPosition().x + 20, sprite.getPosition().y + 50);
		if (!interact)
		{
			txt = false;
		}
		if (txt)
		{
			back.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width-200 , sprite.getPosition().y );
			text.text.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width , sprite.getPosition().y - 600);
			text.update();
		}
		else
			text.reset();
	}
	void input_once()
	{
		// Toggle the text only when the E key is pressed while in interaction range.
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E && interact)
		{
			txt = !txt;
		}
		// Do not start/stop sounds here; handle sound playback centrally to avoid retriggers from other events.
	}
	void update()
	{
		hitbox.setPosition(Vector2f(sprite.getPosition().x + 130, sprite.getPosition().y - 90));
		//collision();
	}
	void draw()
	{
		window.draw(interaction_box);
		window.draw(hitbox);
		window.draw(sprite);
		if (interact)
		{
			window.draw(interact_button.bot_sprite);
		}
		if (txt)
		{
			window.draw(back);
			window.draw(text.text);
		}
	}
};
Decor treee[73],treee1,treee2,treee3[9], fruit[13],fruit1[64], welll[2], christmas[10], boxes[4], cars[3], autumn1[15], autumn2[12], broken[2], autumn3[17], broken1, broken2, broken3[3], moss1, moss2, moss3, house1, house2, house3, house4,camp,camp1,flag,tnt2,tnt3[2],tnt4,lamp[4], fallen_lamp[2], broken_lamp[2],lakee[2], anvell, sakura,fenc[194],vertical_fence[155];
Decor burned;
struct NPC

{
	Texture texure;
	Texture &back_text = text_background_texture;
	Sprite sprite,back;
	RectangleShape hitbox,interaction_box;
	button interact_button;
	Typewriter text=Typewriter(font1);
	bool interact = false, txt = false;
	int counter = 0;
	float timer = 0;
	int yoffset = 0;
	int key_counter = 0;
	float key_timer = 0;
	void intialize( int height,string str,Texture& t)
	{
		texure = t;
		//sprite.setTexture(texure);
		//hitbox.setSize(sf::Vector2f(sprite.getGlobalBounds().width+200, sprite.getGlobalBounds().height+100));
		//interaction_box.setSize(sf::Vector2f(45, 30));
		//interaction_box.setFillColor(sf::Color::Red);
		//interaction_box.setOrigin(interaction_box.getSize().x / 2, interaction_box.getSize().y / 2);
		yoffset = height;
		sprite.setTexture(texure);
		sprite.setTextureRect(sf::IntRect(0, height, 128/4, 128/4));
		sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
		hitbox.setSize(sf::Vector2f(sprite.getGlobalBounds().width+100 , sprite.getLocalBounds().height+150 ));
		hitbox.setFillColor(sf::Color::Transparent);
		//hitbox.setOrigin(hitbox.getSize().x / 2, hitbox.getSize().y / 2);
		interaction_box.setSize(sf::Vector2f(150, 150));
		interaction_box.setFillColor(sf::Color::Transparent);
		//interaction_box.setOrigin(interaction_box.getSize().x / 2, interaction_box.getSize().y / 2);
		this->interact_button.set_texture(E_texture);
		text.setText(str);
		back.setTexture(back_text);
		back.setOrigin(back.getGlobalBounds().width / 2, back.getGlobalBounds().height / 2);
		back.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width, sprite.getPosition().y);
		//text.text.setOrigin(text.text.getGlobalBounds().width / 2, text.text.getGlobalBounds().height / 2);
		text.text.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width, sprite.getPosition().y);
	}

	void collision()
	{
		if (Fox_hitbox.getGlobalBounds().intersects(hitbox.getGlobalBounds()))
		{
			// Directional collision response
			sf::FloatRect foxBounds = Fox_hitbox.getGlobalBounds();
			sf::FloatRect objBounds = hitbox.getGlobalBounds();

			float dx = (foxBounds.left + foxBounds.width / 2) - (objBounds.left + objBounds.width / 2);
			float dy = (foxBounds.top + foxBounds.height / 2) - (objBounds.top + objBounds.height / 2);

			if (std::abs(dx) > std::abs(dy)) {
				// Horizontal collision - push back horizontally
				if (dx > 0) Fox.move(5, 0);
				else        Fox.move(-5, 0);
			} else {
				// Vertical collision - push back vertically
				if (dy > 0) Fox.move(0, 5);
				else        Fox.move(0, -5);
			}
		}
	}
	void interaction()
	{
		if (interaction_box.getGlobalBounds().intersects(Fox_hitbox.getGlobalBounds()))
		{
			set_Static_animition(interact_button.bot_texture,key_counter, this->interact_button.bot_sprite, 2, key_timer);
			interact = true;
		}
		else
			interact = false;
	}
	void input_once()
	{
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E && interact)
		{
			txt = !txt;
		}

	}
	void update(int high,  int framewidth=100, int frameheight=100, int framecount = 4)
	{	
		set_NPC_animition(timer, counter, sprite, framecount, framewidth, frameheight, high);
		hitbox.setPosition(sprite.getPosition());
		//interaction_box.setPosition(sprite.getPosition());
		this->interact_button.bot_sprite.setPosition(sprite.getPosition().x + 20, sprite.getPosition().y + 50);
		collision();
		interaction();
		input_once();
		if (!interact)
		{
			txt = false;
		}
		if (txt)
		{
			back.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width + 200, sprite.getPosition().y - 300);
			text.text.setPosition(back.getPosition().x + sprite.getGlobalBounds().width-550, back.getPosition().y-200);
			text.update();
		}
		else
			text.reset();

	}
	void draw()
	{
		window.draw(hitbox);
		window.draw(interaction_box);
		window.draw(sprite);
		if (interact)
		{
			window.draw(interact_button.bot_sprite);
		}
		if (txt)
		{
			window.draw(back);
			text.draw(window);
		}
	}

};

// NPCs
NPC Hare;
NPC Hare1;
NPC Deer;
NPC Deer1;
NPC Boar;
NPC Black_grouse;
NPC Black_grouse1;
NPC Black_grouse2;
NPC Black_grouse3;
void game_intialization() {

	Hare.sprite.setPosition(2353.83, 6796.67 - 100);
	Hare.intialize(0, "Prepare yourself for the bad news\n\nbut the Game is near to its end", Hare_texture);
	Hare.sprite.setScale(1.455, 1.67333);
	Hare.interaction_box.setScale(1.455, 1.67333);
	Hare1.sprite.setPosition(2477.5, 6986 - 100);
	Hare1.intialize(50, "Hello there,\ncould U do me a favor?\ncould U give me a few million EGP or Dollars\nAs U like ><)", Hare_texture);
	Hare1.sprite.setScale(1.45833, 1.495);
	Hare1.interaction_box.setScale(1.45833, 1.495);
	Hare1.interaction_box.setPosition(Hare1.sprite.getPosition().x -70 + Hare1.sprite.getGlobalBounds().width / 2, Hare1.sprite.getPosition().y + Hare1.sprite.getGlobalBounds().height / 2+30);
	Hare.interaction_box.setPosition(Hare.sprite.getPosition().x -70 + Hare.sprite.getGlobalBounds().width / 2, Hare.sprite.getPosition().y + Hare.sprite.getGlobalBounds().height / 2+30);


	Deer.sprite.setPosition(14262.5, 1510 - 100);
	Deer.intialize(0, "Hey Alaa\nNice to meet U\nI hope U enjoy the Game ^^)", Deer_texture);
	Deer.sprite.setScale(1.65, 1.425);
	Deer.interaction_box.setScale(1.65, 1.425);
	Deer1.sprite.setPosition(14092.5, 1595 - 100);
	Deer1.intialize(75, "Can U get me some \n\n\n\"3laawey 7abib galby ana 5ademkom Lesghayar\"\n\n\n pls? ", Deer_texture);
	Deer1.text.text.setCharacterSize(45);
	Deer1.sprite.setScale(1.5, 1.4);
	Deer1.interaction_box.setScale(1.5, 1.4);
	Boar.sprite.setPosition(3874+20, 3180 - 120);
	Boar.intialize(0, "Get the fuck out of here!\n\n\n(imagin him like anyone U dont like\n\n(I don't like him neither\n\'I know it looks like me but I'll deny\')", Boar_texture);
	Black_grouse.sprite.setPosition(15631.8,3198.48 - 100);
	Black_grouse.intialize(0, "I love U", Black_grouse_texture);
	Black_grouse.sprite.setScale(1.54545, 1.42424);
	Black_grouse.interaction_box.setScale(1.54545, 1.42424);
	Deer.interaction_box.setPosition(Deer.sprite.getPosition().x -70 + Deer.sprite.getGlobalBounds().width / 2, Deer.sprite.getPosition().y + Deer.sprite.getGlobalBounds().height / 2+30);
	Deer1.interaction_box.setPosition(Deer1.sprite.getPosition().x -70 + Deer1.sprite.getGlobalBounds().width / 2, Deer1.sprite.getPosition().y + Deer1.sprite.getGlobalBounds().height / 2+30);
	Boar.interaction_box.setPosition(3874, 3180+100);

	Black_grouse1.sprite.setPosition(15662.1, 3610.61 - 100);
	Black_grouse1.intialize(25, "ich liebe dich", Black_grouse_texture);
	Black_grouse1.sprite.setScale(1.69697, 1.60606);
	Black_grouse1.interaction_box.setScale(1.69697, 1.60606);
	Black_grouse2.sprite.setPosition(16465.2, 3346.97 - 100);
	Black_grouse2.intialize(50, "Ti amo", Black_grouse_texture);
	Black_grouse2.sprite.setScale(1.54545, 1.51515);
	Black_grouse2.interaction_box.setScale(1.54545, 1.51515);

	Black_grouse3.sprite.setPosition(16615.2, 3692.24-100);
	Black_grouse3.intialize(75, "Je t'aime", Black_grouse_texture);
	Black_grouse3.sprite.setScale(1.51515, 1.57576);
	Black_grouse3.interaction_box.setScale(1.51515, 1.57576);
	Black_grouse.interaction_box.setPosition(Black_grouse.sprite.getPosition().x -70 + Black_grouse.sprite.getGlobalBounds().width / 2, Black_grouse.sprite.getPosition().y + Black_grouse.sprite.getGlobalBounds().height / 2-30);
	Black_grouse1.interaction_box.setPosition(Black_grouse1.sprite.getPosition().x -70 + Black_grouse1.sprite.getGlobalBounds().width / 2, Black_grouse1.sprite.getPosition().y + Black_grouse1.sprite.getGlobalBounds().height / 2-30);
	Black_grouse2.interaction_box.setPosition(Black_grouse2.sprite.getPosition().x -70 + Black_grouse2.sprite.getGlobalBounds().width / 2, Black_grouse2.sprite.getPosition().y + Black_grouse2.sprite.getGlobalBounds().height / 2-30);
	Black_grouse3.interaction_box.setPosition(Black_grouse3.sprite.getPosition().x -70 + Black_grouse3.sprite.getGlobalBounds().width / 2, Black_grouse3.sprite.getPosition().y + Black_grouse3.sprite.getGlobalBounds().height / 2-30);

	
	treee[0].sprite.setPosition(7016, 7984);
	treee[1].sprite.setPosition(6888, 7832);
	treee[2].sprite.setPosition(6888, 7580);
	treee[3].sprite.setPosition(6888, 7336);
	treee[4].sprite.setPosition(6892, 7068);
	treee[5].sprite.setPosition(6892, 6788);
	treee[6].sprite.setPosition(6892, 6516);
	treee[7].sprite.setPosition(6896, 6272);
	treee[8].sprite.setPosition(6896, 6004);
	treee[9].sprite.setPosition(6908, 5736);
	treee[10].sprite.setPosition(6908, 5460);
	treee[11].sprite.setPosition(6920, 5176);
	treee[12].sprite.setPosition(7310.01, 5173.28);
	treee[13].sprite.setPosition(7704.38, 5181.31);
	treee[14].sprite.setPosition(8086.78, 5181.38);
	treee[15].sprite.setPosition(8481.21, 5181.4);
	treee[16].sprite.setPosition(8883.64, 5185.48);
	treee[17].sprite.setPosition(9284.07, 5181.53);
	treee[18].sprite.setPosition(9670.45, 5181.55);
	treee[19].sprite.setPosition(10076.9, 5181.62);
	treee[20].sprite.setPosition(10483.3, 5181.65);
	treee[21].sprite.setPosition(10885.7, 5185.72);
	treee[22].sprite.setPosition(11136, 5060);
	treee[23].sprite.setPosition(11158, 4764);
	treee[24].sprite.setPosition(11158, 4520);
	treee[25].sprite.setPosition(11162, 4252);
	treee[26].sprite.setPosition(11162, 3972);
	treee[27].sprite.setPosition(11162, 3700);
	treee[28].sprite.setPosition(11166, 3456);
	treee[29].sprite.setPosition(11166, 3188);
	treee[30].sprite.setPosition(11178, 2920);
	treee[31].sprite.setPosition(11178, 2644);
	treee[32].sprite.setPosition(7319.02, 7999.46);
	treee[33].sprite.setPosition(7713.39, 8007.49);
	treee[34].sprite.setPosition(8095.79, 8007.56);
	treee[35].sprite.setPosition(8490.22, 8007.58);
	treee[36].sprite.setPosition(8892.65, 8011.66);
	treee[37].sprite.setPosition(9293.08, 8007.71);
	treee[38].sprite.setPosition(9679.46, 8007.73);
	treee[39].sprite.setPosition(10085.9, 8007.8);
	treee[40].sprite.setPosition(10492.3, 8007.83);
	treee[41].sprite.setPosition(10894.7, 8011.9);
	treee[42].sprite.setPosition(11309.2, 8009.94);
	treee[43].sprite.setPosition(11707.6, 8015.95);
	treee[44].sprite.setPosition(12118.1, 8016.0);
	treee[45].sprite.setPosition(12331.2, 7900.06);
	treee[46].sprite.setPosition(12331.2, 7656.06);
	treee[47].sprite.setPosition(12335.2, 7388.06);
	treee[48].sprite.setPosition(12335.2, 7108.06);
	treee[49].sprite.setPosition(12335.2, 6836.06);
	treee[50].sprite.setPosition(12339, 6592.06);
	treee[51].sprite.setPosition(12339.2, 6324.06);
	treee[52].sprite.setPosition(12351.2, 6056.06);
	treee[53].sprite.setPosition(12351.2, 5780.06);
	treee[54].sprite.setPosition(12363.2, 5496.06);
	treee[55].sprite.setPosition(12512.0, 5252.0);
	treee[56].sprite.setPosition(12912.0, 5257.28);
	treee[57].sprite.setPosition(13306.4, 5265.31);
	treee[58].sprite.setPosition(13688.8, 5265.38);
	treee[59].sprite.setPosition(14083.2, 5265.4);
	treee[60].sprite.setPosition(14485.6, 5269.48);
	treee[61].sprite.setPosition(14886.1, 5265.53);
	treee[62].sprite.setPosition(15272.5, 5265.55);
	treee[63].sprite.setPosition(15678.9, 5265.62);
	treee[64].sprite.setPosition(16085.3, 5265.65);
	treee[65].sprite.setPosition(16487.7, 5269.72);
	treee[66].sprite.setPosition(16902.2, 5267.76);
	treee[67].sprite.setPosition(17300.6, 5273.77);
	treee[68].sprite.setPosition(17711.1, 5273.82);
	treee[69].sprite.setPosition(18118.0, 5289.28);
	treee[70].sprite.setPosition(18512.4, 5297.31);
	treee[71].sprite.setPosition(18926.8, 5293.38);
	treee[72].sprite.setPosition(19348.2, 5297.4);
	for (int i = 0; i < 73; i++)
	{
		treee[i].intialize(tree);
		treee[i].hitbox.setSize(treee[i].hitbox.getSize()+Vector2f(60,0));
		//treee[i].hitbox.setPosition(treee[i].hitbox.getPosition().x + 100, treee[i].hitbox.getPosition().y );
	}
	treee[12].hitbox.setScale(1.04899, 1.04899);
	treee[13].hitbox.setScale(1.04899, 1.04899);
	treee[14].hitbox.setScale(1.04899, 1.04899);
	treee[15].hitbox.setScale(1.04899, 1.04899);
	treee[16].hitbox.setScale(1.04899, 1.04899);
	treee[17].hitbox.setScale(1.04899, 1.04899);
	treee[18].hitbox.setScale(1.04899, 1.04899);
	treee[19].hitbox.setScale(1.04899, 1.04899);
	treee[20].hitbox.setScale(1.04899, 1.04899);
	treee[21].hitbox.setScale(1.04899, 1.04899);
	treee[32].hitbox.setScale(1.04899, 1.04899);
	treee[33].hitbox.setScale(1.04899, 1.04899);
	treee[34].hitbox.setScale(1.04899, 1.04899);
	treee[35].hitbox.setScale(1.04899, 1.04899);
	treee[36].hitbox.setScale(1.04899, 1.04899);
	treee[37].hitbox.setScale(1.04899, 1.04899);
	treee[38].hitbox.setScale(1.04899, 1.04899);
	treee[39].hitbox.setScale(1.04899, 1.04899);
	treee[40].hitbox.setScale(1.04899, 1.04899);
	treee[41].hitbox.setScale(1.04899, 1.04899);
	treee[42].hitbox.setScale(1.04899, 1.04899);
	treee[43].hitbox.setScale(1.04899, 1.04899);
	treee[44].hitbox.setScale(1.04899, 1.04899);

	treee[56].hitbox.setScale(1.04899, 1.04899);
	treee[57].hitbox.setScale(1.04899, 1.04899);
	treee[58].hitbox.setScale(1.04899, 1.04899);
	treee[59].hitbox.setScale(1.04899, 1.04899);
	treee[60].hitbox.setScale(1.04899, 1.04899);
	treee[61].hitbox.setScale(1.04899, 1.04899);
	treee[62].hitbox.setScale(1.04899, 1.04899);
	treee[63].hitbox.setScale(1.04899, 1.04899);
	treee[64].hitbox.setScale(1.04899, 1.04899);
	treee[65].hitbox.setScale(1.04899, 1.04899);
	treee[66].hitbox.setScale(1.04899, 1.04899);
	treee[67].hitbox.setScale(1.04899, 1.04899);
	treee[68].hitbox.setScale(1.04899, 1.04899);
	treee[69].hitbox.setScale(1.04899, 1.04899);
	treee[70].hitbox.setScale(1.04899, 1.04899);
	treee[71].hitbox.setScale(1.04899, 1.04899);
	treee[72].hitbox.setScale(1.04899, 1.04899);
	treee[12].sprite.setScale(1.04899, 1.04899);
	treee[13].sprite.setScale(1.04899, 1.04899);
	treee[14].sprite.setScale(1.04899, 1.04899);
	treee[15].sprite.setScale(1.04899, 1.04899);
	treee[16].sprite.setScale(1.04899, 1.04899);
	treee[17].sprite.setScale(1.04899, 1.04899);
	treee[18].sprite.setScale(1.04899, 1.04899);
	treee[19].sprite.setScale(1.04899, 1.04899);
	treee[20].sprite.setScale(1.04899, 1.04899);
	treee[21].sprite.setScale(1.04899, 1.04899);
	treee[32].sprite.setScale(1.04899, 1.04899);
	treee[33].sprite.setScale(1.04899, 1.04899);
	treee[34].sprite.setScale(1.04899, 1.04899);
	treee[35].sprite.setScale(1.04899, 1.04899);
	treee[36].sprite.setScale(1.04899, 1.04899);
	treee[37].sprite.setScale(1.04899, 1.04899);
	treee[38].sprite.setScale(1.04899, 1.04899);
	treee[39].sprite.setScale(1.04899, 1.04899);
	treee[40].sprite.setScale(1.04899, 1.04899);
	treee[41].sprite.setScale(1.04899, 1.04899);
	treee[42].sprite.setScale(1.04899, 1.04899);
	treee[43].sprite.setScale(1.04899, 1.04899);
	treee[44].sprite.setScale(1.04899, 1.04899);
	treee[56].sprite.setScale(1.04899, 1.04899);
	treee[57].sprite.setScale(1.04899, 1.04899);
	treee[58].sprite.setScale(1.04899, 1.04899);
	treee[59].sprite.setScale(1.04899, 1.04899);
	treee[60].sprite.setScale(1.04899, 1.04899);
	treee[61].sprite.setScale(1.04899, 1.04899);
	treee[62].sprite.setScale(1.04899, 1.04899);
	treee[63].sprite.setScale(1.04899, 1.04899);
	treee[64].sprite.setScale(1.04899, 1.04899);
	treee[65].sprite.setScale(1.04899, 1.04899);
	treee[66].sprite.setScale(1.04899, 1.04899);
	treee[67].sprite.setScale(1.04899, 1.04899);
	treee[68].sprite.setScale(1.04899, 1.04899);
	treee[69].sprite.setScale(1.04899, 1.04899);
	treee[70].sprite.setScale(1.04899, 1.04899);
	treee[71].sprite.setScale(1.04899, 1.04899);
	treee[72].sprite.setScale(1.04899, 1.04899);


	treee1.sprite.setPosition(13400.0, 4200.0);
	treee1.intialize(tree_1);
	treee1.sprite.setScale(2.26,2.2);
	//treee1.hitbox.setScale(2.26, 2.2);
	treee1.hitbox.setSize(Vector2f(treee1.sprite.getGlobalBounds().width-400, treee1.sprite.getGlobalBounds().height-450));
	treee2.sprite.setPosition(13536.0, 1968.0);
	treee2.intialize(tree_2);
	treee2.sprite.setScale(1.3,1.35);
	//treee2.hitbox.setScale(1.3, 1.35);
	treee2.hitbox.setSize(Vector2f(treee2.sprite.getGlobalBounds().width-800, treee2.sprite.getGlobalBounds().height-250));
	treee3[0].sprite.setPosition(14708.0, 1186.0);
	

	treee3[1].sprite.setPosition(16700.0, 3342.0);
	
	treee3[2].sprite.setPosition(16760.0, 3582);
	
	treee3[3].sprite.setPosition(16758, 3852.0);
	

	treee3[4].sprite.setPosition(17442, 4252);

	treee3[5].sprite.setPosition(18718.0, 1872);

	treee3[6].sprite.setPosition(17822, 992.0);

	treee3[7].sprite.setPosition(1516.06, 11256.1);

	treee3[8].sprite.setPosition(1367.58, 11874.2);
	for (int i = 0; i < 9; i++)
	{
		treee3[i].intialize(tree_3);
		treee3[i].hitbox.setSize(Vector2f(treee3[i].sprite.getGlobalBounds().width-150, treee3[i].sprite.getGlobalBounds().height-50));
	}
	treee3[0].sprite.setScale(0.55, 0.57);
	treee3[0].hitbox.setScale(0.55, 0.57);
	treee3[1].sprite.setScale(0.55, 0.57);
	treee3[1].hitbox.setScale(0.55, 0.57);
	treee3[2].sprite.setScale(0.55, 0.57);
	treee3[2].hitbox.setScale(0.55, 0.57);
	treee3[3].sprite.setScale(0.55, 0.57);
	treee3[3].hitbox.setScale(0.55, 0.57);




	fruit[0].sprite.setPosition(6121.0, 9281.5);
	fruit[1].sprite.setPosition(8424, 11932);
	fruit[2].sprite.setPosition(9288, 11492);
	fruit[3].sprite.setPosition(9744, 12020);
	fruit[4].sprite.setPosition(10256, 11340);
	fruit[5].sprite.setPosition(10872, 11940);
	fruit[6].sprite.setPosition(11344, 11372);
	fruit[7].sprite.setPosition(11848, 11948);
	fruit[8].sprite.setPosition(12584, 11316);
	fruit[9].sprite.setPosition(13200, 11908);
	fruit[10].sprite.setPosition(13332.0, 1500.0);
	fruit[11].sprite.setPosition(14500, 3900);
	fruit[12].sprite.setPosition(18284, 1348);

	fruit1[0].sprite.setPosition(1430.3, 5642.42);
	fruit1[1].sprite.setPosition(1430.3, 5936.36);
	fruit1[2].sprite.setPosition(1651.52, 5581.82);
	fruit1[3].sprite.setPosition(1754.55, 5615.15);
	fruit1[4].sprite.setPosition(1778.79, 5715.15);
	fruit1[5].sprite.setPosition(1651.52, 5806.06);
	fruit1[6].sprite.setPosition(1715.15, 5827.27);
	fruit1[7].sprite.setPosition(1775.76, 5906.06);
	fruit1[8].sprite.setPosition(1778.79, 5975.76);
	fruit1[9].sprite.setPosition(1733.33, 6027.27);
	fruit1[10].sprite.setPosition(1651.52, 6060.61);
	fruit1[11].sprite.setPosition(4140.0, 6048);
	fruit1[12].sprite.setPosition(4264, 6048);
	fruit1[13].sprite.setPosition(4428, 6068);
	fruit1[14].sprite.setPosition(4324, 6248);
	fruit1[15].sprite.setPosition(4408, 6188);
	fruit1[16].sprite.setPosition(4512, 6124);
	fruit1[17].sprite.setPosition(4536, 6176);
	fruit1[18].sprite.setPosition(4516, 6308);
	fruit1[19].sprite.setPosition(4492, 6440);
	fruit1[20].sprite.setPosition(4984, 6488);
	fruit1[21].sprite.setPosition(4884, 6380);
	fruit1[22].sprite.setPosition(4800, 6284);
	fruit1[23].sprite.setPosition(4724, 6200);
	fruit1[24].sprite.setPosition(4664, 6116);
	fruit1[25].sprite.setPosition(4592, 6004);
	fruit1[26].sprite.setPosition(4532, 5932);
	fruit1[27].sprite.setPosition(4492, 5804);
	fruit1[28].sprite.setPosition(4476, 5708);
	fruit1[29].sprite.setPosition(4476, 5596);
	fruit1[30].sprite.setPosition(4520, 5540);
	fruit1[31].sprite.setPosition(4576, 5520);
	fruit1[32].sprite.setPosition(4668, 5544);
	fruit1[33].sprite.setPosition(4744, 5588);
	fruit1[34].sprite.setPosition(4812, 5692);
	fruit1[35].sprite.setPosition(4916, 5712);
	fruit1[36].sprite.setPosition(4940, 5652);
	fruit1[37].sprite.setPosition(5032, 5584);
	fruit1[38].sprite.setPosition(5164, 5548);
	fruit1[39].sprite.setPosition(5276, 5572);
	fruit1[40].sprite.setPosition(5344, 5672);
	fruit1[41].sprite.setPosition(5364, 5760);
	fruit1[42].sprite.setPosition(5364, 5896);
	fruit1[43].sprite.setPosition(5320, 6036);
	fruit1[44].sprite.setPosition(5240, 6204);
	fruit1[45].sprite.setPosition(5156, 6336);
	fruit1[46].sprite.setPosition(5080, 6416);
	fruit1[47].sprite.setPosition(4772, 6000);
	fruit1[48].sprite.setPosition(4852, 5964);
	fruit1[49].sprite.setPosition(4984, 5904);
	fruit1[50].sprite.setPosition(5068, 5864);
	fruit1[51].sprite.setPosition(5204, 5796);
	fruit1[52].sprite.setPosition(5420, 5696);
	fruit1[53].sprite.setPosition(5536, 5648);
	fruit1[54].sprite.setPosition(5588, 5604);
	fruit1[55].sprite.setPosition(5656, 5792);
	fruit1[56].sprite.setPosition(5716, 5688);
	fruit1[57].sprite.setPosition(5756, 5568);
	fruit1[58].sprite.setPosition(5832, 5436);
	fruit1[59].sprite.setPosition(5752, 5420);
	fruit1[60].sprite.setPosition(5604, 5416);
	fruit1[61].sprite.setPosition(5428, 5404);
	fruit1[62].sprite.setPosition(15016, 3996);
	fruit1[63].sprite.setPosition(15192, 3840);
	welll[0].sprite.setPosition(10104.5, 3685.06);
	welll[1].sprite.setPosition(6014.25, 8428.53);
	christmas[0].sprite.setPosition(7960, 9080);
	
	christmas[1].sprite.setPosition(8480, 9496);
	
	christmas[2].sprite.setPosition(8944, 8904);
	
	christmas[3].sprite.setPosition(9352, 9520);
	
	christmas[4].sprite.setPosition(10048, 8992);
	
	christmas[5].sprite.setPosition(10408, 9544);
	
	christmas[6].sprite.setPosition(10832, 8936);
	
	christmas[7].sprite.setPosition(11296, 9440);
	
	christmas[8].sprite.setPosition(11688, 8880);
	
	christmas[9].sprite.setPosition(12224, 9392);
	

	boxes[0].sprite.setPosition(17764.2, 1836.0	);
	boxes[1].sprite.setPosition(9894, 3678.5);
	boxes[2].sprite.setPosition(3750.98, 11000.2);
	boxes[3].sprite.setPosition(5803.75, 8421.97);

	cars[0].sprite.setPosition(18034.7+300, 1622.24);
	cars[1].sprite.setPosition(8134.97, 3293.64);
	cars[2].sprite.setPosition(3945.5, 11393);
	
	autumn1[0].sprite.setPosition(-103.788, 5388.64);
	autumn1[1].sprite.setPosition(96.2121, 5721.97);
	autumn1[2].sprite.setPosition(354.545, 6021.97);
	autumn1[3].sprite.setPosition(546.212, 6313.64);
	autumn1[4].sprite.setPosition(787.879, 6605.3);
	autumn1[5].sprite.setPosition(-178.788, 12090.9);
	autumn1[6].sprite.setPosition(145.455, 11793.9);
	autumn1[7].sprite.setPosition(430.303, 11472.7);
	autumn1[8].sprite.setPosition(751.515, 11178.8);
	autumn1[9].sprite.setPosition(1069.7, 10878.8);
	autumn1[10].sprite.setPosition(6532.8, 5389.44);
	autumn1[11].sprite.setPosition(6332.8, 5722.77);
	autumn1[12].sprite.setPosition(6074.47, 6022.77);
	autumn1[13].sprite.setPosition(5882.8, 6314.44);
	autumn1[14].sprite.setPosition(5641.14, 6606.1);
	
	autumn2[0].sprite.setPosition(1162.88, 6680.3);
	autumn2[1].sprite.setPosition(1337.88, 6946.97);
	autumn2[2].sprite.setPosition(1554.55, 7205.3);
	autumn2[3].sprite.setPosition(1771.21, 7455.3);
	autumn2[4].sprite.setPosition(1572.73, 10433.3);
	autumn2[5].sprite.setPosition(1854.55, 10203.0);
	autumn2[6].sprite.setPosition(2112.12, 9939.39);
	autumn2[7].sprite.setPosition(2354.55, 9651.52);
	autumn2[8].sprite.setPosition(5666.14, 6681.1);
	autumn2[9].sprite.setPosition(5491.14, 6947.77);
	autumn2[10].sprite.setPosition(5274.47, 7206.1);
	autumn2[11].sprite.setPosition(5057.81, 7456.1);

	fenc[0].sprite.setPosition(13320.6, 4394.29);
	fenc[1].sprite.setPosition(13422.6, 4394.29);
	fenc[2].sprite.setPosition(13523.6, 4395.29);
	fenc[3].sprite.setPosition(13624.5, 4393.63);
	fenc[4].sprite.setPosition(13726.5, 4393.63);
	fenc[5].sprite.setPosition(13827.5, 4394.63);
	fenc[6].sprite.setPosition(13932.0, 4394.39);
	fenc[7].sprite.setPosition(14033.1, 4393.39);
	fenc[8].sprite.setPosition(14135.1, 4393.39);
	fenc[9].sprite.setPosition(14236.1, 4394.39);
	fenc[10].sprite.setPosition(14337.0, 4392.73);
	fenc[11].sprite.setPosition(14439.0, 4392.73);
	fenc[12].sprite.setPosition(14540.0, 4393.73);
	fenc[13].sprite.setPosition(14642.6, 4394.66);
	fenc[14].sprite.setPosition(14744.6, 4394.66);
	fenc[15].sprite.setPosition(14845.6, 4395.66);
	fenc[16].sprite.setPosition(14946.5, 4394.0);
	fenc[17].sprite.setPosition(15048.5, 4394.0);
	fenc[18].sprite.setPosition(15149.5, 4395.0);
	fenc[19].sprite.setPosition(15254.0, 4394.76);
	fenc[20].sprite.setPosition(15356.0, 4394.76);
	fenc[21].sprite.setPosition(15457, 4395.76);
	fenc[22].sprite.setPosition(15557.9, 4394.1);
	fenc[23].sprite.setPosition(15659.9, 4394.1);
	fenc[24].sprite.setPosition(15760.9, 4395.1);
	fenc[25].sprite.setPosition(15863.5, 4396.03);
	fenc[26].sprite.setPosition(15965.5, 4396.03);
	fenc[27].sprite.setPosition(16066.5, 4397.03);
	fenc[28].sprite.setPosition(16167.4, 4395.37);
	fenc[29].sprite.setPosition(16269.4, 4395.37);
	fenc[30].sprite.setPosition(16370.4, 4396.37);
	fenc[31].sprite.setPosition(16471.7, 4396.62);
	fenc[32].sprite.setPosition(16573.7, 4396.62);
	fenc[33].sprite.setPosition(16674.7, 4397.62);
	fenc[34].sprite.setPosition(16775.6, 4395.96);
	fenc[35].sprite.setPosition(16877.6, 4395.96);
	fenc[36].sprite.setPosition(16978.6, 4396.96);
	fenc[37].sprite.setPosition(17081.2, 4397.89);
	fenc[38].sprite.setPosition(17183.2, 4397.89);
	fenc[39].sprite.setPosition(17284.2, 4398.89);
	fenc[40].sprite.setPosition(17385.1, 4397.23);
	fenc[41].sprite.setPosition(17487.1, 4397.23);
	fenc[42].sprite.setPosition(17588.1, 4398.23);
	fenc[43].sprite.setPosition(17692.6, 4397.99);
	fenc[44].sprite.setPosition(17794.6, 4397.99);
	fenc[45].sprite.setPosition(17897.8, 4396.08);
	fenc[46].sprite.setPosition(17998.7, 4394.42);
	fenc[47].sprite.setPosition(18100.7, 4394.42);
	fenc[48].sprite.setPosition(18201.7, 4395.42);
	fenc[49].sprite.setPosition(18304.3, 4396.35);
	fenc[50].sprite.setPosition(18406.3, 4396.35);
	fenc[51].sprite.setPosition(18507.3, 4397.35);
	fenc[52].sprite.setPosition(18608.2, 4395.69);
	fenc[53].sprite.setPosition(18710.2, 4395.69);
	fenc[54].sprite.setPosition(18811.2, 4396.69);
	fenc[55].sprite.setPosition(18915.7, 4396.45);
	fenc[56].sprite.setPosition(19017.7, 4396.45);
	fenc[57].sprite.setPosition(19118.7, 4397.45);
	fenc[58].sprite.setPosition(19219.6, 4395.79);
	fenc[59].sprite.setPosition(14952.0, 4015.69);
	fenc[60].sprite.setPosition(15054.0, 4015.69);
	fenc[61].sprite.setPosition(15155.0, 4016.69);
	fenc[62].sprite.setPosition(15259.5, 4016.45);
	fenc[63].sprite.setPosition(15361.5, 4016.45);
	fenc[64].sprite.setPosition(15462.5, 4017.45);
	fenc[65].sprite.setPosition(15563.4, 4015.79);
	fenc[66].sprite.setPosition(15665.4, 4015.79);
	fenc[67].sprite.setPosition(15766.4, 4016.79);
	fenc[68].sprite.setPosition(15869.0, 4017.72);
	fenc[69].sprite.setPosition(15971.0, 4017.72);
	fenc[70].sprite.setPosition(16072.0, 4018.72);
	fenc[71].sprite.setPosition(16172.9, 4017.06);
	fenc[72].sprite.setPosition(16274.9, 4017.06);
	fenc[73].sprite.setPosition(16375.9, 4018.06);
	fenc[74].sprite.setPosition(16477.2, 4018.31);
	fenc[75].sprite.setPosition(16579.2, 4018.31);
	fenc[76].sprite.setPosition(16680.2, 4019.31);
	fenc[77].sprite.setPosition(16781.0, 4017.65);
	fenc[78].sprite.setPosition(16883.0, 4017.65);
	fenc[79].sprite.setPosition(16984.0, 4018.65);
	fenc[80].sprite.setPosition(13573.0, 2036.6);
	fenc[81].sprite.setPosition(13673.9, 2034.93);
	fenc[82].sprite.setPosition(13775.9, 2034.93);
	fenc[83].sprite.setPosition(13876.9, 2035.93);
	fenc[84].sprite.setPosition(13981.4, 2035.7);
	fenc[85].sprite.setPosition(14488.4, 2034.03);
	fenc[86].sprite.setPosition(14589.4, 2035.03);
	fenc[87].sprite.setPosition(14692.0, 2035.97);
	fenc[88].sprite.setPosition(14794.0, 2035.97);
	fenc[89].sprite.setPosition(14895.0, 2036.97);
	vertical_fence[0].sprite.setPosition(13358.1, 451.702);
	vertical_fence[1].sprite.setPosition(13358.1, 522.702);
	vertical_fence[2].sprite.setPosition(13358.1, 596.702);
	vertical_fence[3].sprite.setPosition(13356.9, 680.132);
	vertical_fence[4].sprite.setPosition(13356.9, 751.132);
	vertical_fence[5].sprite.setPosition(13356.9, 825.132);
	vertical_fence[6].sprite.setPosition(13356.7, 897.672);
	vertical_fence[7].sprite.setPosition(13356.7, 968.672);
	vertical_fence[8].sprite.setPosition(13356.7, 1042.67);
	vertical_fence[9].sprite.setPosition(13355.5, 1126.1);
	vertical_fence[10].sprite.setPosition(13355.5, 1197.1);
	vertical_fence[11].sprite.setPosition(13355.5, 1271.1);
	vertical_fence[12].sprite.setPosition(13356.0, 1348.02);
	vertical_fence[13].sprite.setPosition(13356, 1419.02);
	vertical_fence[14].sprite.setPosition(13356.0, 1493.02);
	vertical_fence[15].sprite.setPosition(13356.1, 1575.2);
	vertical_fence[16].sprite.setPosition(13355.9, 1647.74);
	vertical_fence[17].sprite.setPosition(13355.9, 1718.74);
	vertical_fence[18].sprite.setPosition(13355.9, 1792.74);
	vertical_fence[19].sprite.setPosition(13354.6, 1876.17);
	vertical_fence[20].sprite.setPosition(13354.6, 1947.17);
	vertical_fence[21].sprite.setPosition(13354.6, 2021.17);
	vertical_fence[22].sprite.setPosition(13355.1, 2098.09);
	vertical_fence[23].sprite.setPosition(13355.1, 2169.09);
	vertical_fence[24].sprite.setPosition(13355.1, 2243.09);
	vertical_fence[25].sprite.setPosition(13353.9, 2326.52);
	vertical_fence[26].sprite.setPosition(13351.6, 2929.31);
	vertical_fence[27].sprite.setPosition(13351.6, 3003.31);
	vertical_fence[28].sprite.setPosition(13351.4, 3075.85);
	vertical_fence[29].sprite.setPosition(13351.4, 3146.85);
	vertical_fence[30].sprite.setPosition(13351.4, 3220.85);
	vertical_fence[31].sprite.setPosition(13350.3, 3304.28);
	vertical_fence[32].sprite.setPosition(13350.3, 3375.28);
	vertical_fence[33].sprite.setPosition(13350.3, 3449.28);
	vertical_fence[34].sprite.setPosition(13350.8, 3526.2);
	vertical_fence[35].sprite.setPosition(13350.8, 3597.2);
	vertical_fence[36].sprite.setPosition(13350.8, 3671.2);
	vertical_fence[37].sprite.setPosition(13349.6, 3754.63);
	vertical_fence[38].sprite.setPosition(13349.6, 3825.63);
	vertical_fence[39].sprite.setPosition(13349.6, 3899.63);
	vertical_fence[40].sprite.setPosition(13349.4, 3972.17);
	vertical_fence[41].sprite.setPosition(13349.4, 4043.17);
	vertical_fence[42].sprite.setPosition(13349.4, 4117.17);
	vertical_fence[43].sprite.setPosition(13348.1, 4200.6);
	vertical_fence[44].sprite.setPosition(13348.1, 4271.6);
	vertical_fence[45].sprite.setPosition(13348.1, 4345.6);
	vertical_fence[46].sprite.setPosition(13604.1, 916.814);
	vertical_fence[47].sprite.setPosition(13604.0, 989.354);
	vertical_fence[48].sprite.setPosition(13604.0, 1060.35);
	vertical_fence[49].sprite.setPosition(13604.0, 1134.35);
	vertical_fence[50].sprite.setPosition(13602.8, 1217.78);
	vertical_fence[51].sprite.setPosition(13602.8, 1288.78);
	vertical_fence[52].sprite.setPosition(13602.8, 1362.78);
	vertical_fence[53].sprite.setPosition(13603.3, 1439.7);
	vertical_fence[54].sprite.setPosition(13603.3, 1510.7);
	vertical_fence[55].sprite.setPosition(13603.3, 1584.7);
	vertical_fence[56].sprite.setPosition(13603.4, 1666.88);
	vertical_fence[57].sprite.setPosition(13603.1, 1739.42);
	vertical_fence[58].sprite.setPosition(13603.1, 1810.42);
	vertical_fence[59].sprite.setPosition(13603.1, 1884.42);
	vertical_fence[60].sprite.setPosition(13601.9, 1967.85);
	vertical_fence[61].sprite.setPosition(15029.6, 923.134);
	vertical_fence[62].sprite.setPosition(15029.5, 995.674);
	vertical_fence[63].sprite.setPosition(15029.5, 1066.67);
	vertical_fence[64].sprite.setPosition(15029.5, 1140.67);
	vertical_fence[65].sprite.setPosition(15028.3, 1224.1);
	vertical_fence[66].sprite.setPosition(15028.3, 1295.1);
	vertical_fence[67].sprite.setPosition(15028.3, 1369.1);
	vertical_fence[68].sprite.setPosition(15028.8, 1446.02);
	vertical_fence[69].sprite.setPosition(15028.8, 1517.02);
	vertical_fence[70].sprite.setPosition(15028.8, 1591.02);
	vertical_fence[71].sprite.setPosition(15028.9, 1673.2);
	vertical_fence[72].sprite.setPosition(15028.6, 1745.74);
	vertical_fence[73].sprite.setPosition(15028.6, 1816.74);
	vertical_fence[74].sprite.setPosition(15028.6, 1890.74);
	vertical_fence[75].sprite.setPosition(15027.4, 1974.17);
	vertical_fence[76].sprite.setPosition(14990.2, 3100.12);
	vertical_fence[77].sprite.setPosition(14990.0, 3172.66);
	vertical_fence[78].sprite.setPosition(14990.0, 3243.66);
	vertical_fence[79].sprite.setPosition(14990.0, 3317.66);
	vertical_fence[80].sprite.setPosition(14988.8, 3401.09);
	vertical_fence[81].sprite.setPosition(14988.8, 3472.09);
	vertical_fence[82].sprite.setPosition(14988.8, 3546.09);
	vertical_fence[83].sprite.setPosition(14989.3, 3623.01);
	vertical_fence[84].sprite.setPosition(14989.3, 3694.01);
	vertical_fence[85].sprite.setPosition(14989.3, 3768.01);
	vertical_fence[86].sprite.setPosition(14988.1, 3851.44);
	vertical_fence[87].sprite.setPosition(14988.1, 3922.44);
	vertical_fence[88].sprite.setPosition(14988.1, 3996.44);
	vertical_fence[89].sprite.setPosition(17128.0, 3097.34);
	vertical_fence[90].sprite.setPosition(17127.8, 3169.88);
	vertical_fence[91].sprite.setPosition(17127.8, 3240.88);
	vertical_fence[92].sprite.setPosition(17127.8, 3314.88);
	vertical_fence[93].sprite.setPosition(17126.6, 3398.31);
	vertical_fence[94].sprite.setPosition(17126.6, 3469.31);
	vertical_fence[95].sprite.setPosition(17126.6, 3543.31);
	vertical_fence[96].sprite.setPosition(17127.1, 3620.23);
	vertical_fence[97].sprite.setPosition(17127.1, 3691.23);
	vertical_fence[98].sprite.setPosition(17127.1, 3765.23);
	vertical_fence[99].sprite.setPosition(17125.9, 3848.66);
	vertical_fence[100].sprite.setPosition(17125.9, 3919.66);
	vertical_fence[101].sprite.setPosition(17125.9, 3993.66);
	vertical_fence[102].sprite.setPosition(19361.5, 433.891);
	vertical_fence[103].sprite.setPosition(19361.5, 504.891);
	vertical_fence[104].sprite.setPosition(19361.5, 578.891);
	vertical_fence[105].sprite.setPosition(19360.3, 662.321);
	vertical_fence[106].sprite.setPosition(19360.3, 733.321);
	vertical_fence[107].sprite.setPosition(19360.3, 807.321);
	vertical_fence[108].sprite.setPosition(19360.1, 879.861);
	vertical_fence[109].sprite.setPosition(19360.1, 950.861);
	vertical_fence[110].sprite.setPosition(19360.1, 1024.86);
	vertical_fence[111].sprite.setPosition(19358.9, 1108.29);
	vertical_fence[112].sprite.setPosition(19358.9, 1179.29);
	vertical_fence[113].sprite.setPosition(19358.9, 1253.29);
	vertical_fence[114].sprite.setPosition(19359.4, 1330.21);
	vertical_fence[115].sprite.setPosition(19359.4, 1401.21);
	vertical_fence[116].sprite.setPosition(19359.4, 1475.21);
	vertical_fence[117].sprite.setPosition(19359.5, 1557.39);
	vertical_fence[118].sprite.setPosition(19359.3, 1629.93);
	vertical_fence[119].sprite.setPosition(19359.3, 1700.93);
	vertical_fence[120].sprite.setPosition(19359.3, 1774.93);
	vertical_fence[121].sprite.setPosition(19358.0, 1858.36);
	vertical_fence[122].sprite.setPosition(19358.0, 1929.36);
	vertical_fence[123].sprite.setPosition(19358.0, 2003.36);
	vertical_fence[124].sprite.setPosition(19358.5, 2080.28);
	vertical_fence[125].sprite.setPosition(19358.5, 2151.28);
	vertical_fence[126].sprite.setPosition(19358.5, 2225.28);
	vertical_fence[127].sprite.setPosition(19357.3, 2308.71);
	vertical_fence[128].sprite.setPosition(19357.3, 2379.71);
	vertical_fence[129].sprite.setPosition(19357.3, 2453.71);
	vertical_fence[130].sprite.setPosition(19357.2, 2526.25);
	vertical_fence[131].sprite.setPosition(19356.3, 2612.07);
	vertical_fence[132].sprite.setPosition(19356.3, 2683.07);
	vertical_fence[133].sprite.setPosition(19356.3, 2757.07);
	vertical_fence[134].sprite.setPosition(19355.0, 2840.5);
	vertical_fence[135].sprite.setPosition(19355.0, 2911.5);
	vertical_fence[136].sprite.setPosition(19355.0, 2985.5);
	vertical_fence[137].sprite.setPosition(19354.8, 3058.04);
	vertical_fence[138].sprite.setPosition(19354.8, 3129.04);
	vertical_fence[139].sprite.setPosition(19354.8, 3203.04);
	vertical_fence[140].sprite.setPosition(19353.7, 3286.47);
	vertical_fence[141].sprite.setPosition(19353.7, 3357.47);
	vertical_fence[142].sprite.setPosition(19353.7, 3431.47);
	vertical_fence[143].sprite.setPosition(19354.2, 3508.39);
	vertical_fence[144].sprite.setPosition(19354.2, 3579.39);
	vertical_fence[145].sprite.setPosition(19354.2, 3653.39);
	vertical_fence[146].sprite.setPosition(19353.0, 3736.82);
	vertical_fence[147].sprite.setPosition(19353.0, 3807.82);
	vertical_fence[148].sprite.setPosition(19353.0, 3881.82);
	vertical_fence[149].sprite.setPosition(19352.8, 3954.36);
	vertical_fence[150].sprite.setPosition(19352.8, 4025.36);
	vertical_fence[151].sprite.setPosition(19352.8, 4099.36);
	vertical_fence[152].sprite.setPosition(19351.5, 4182.79);
	vertical_fence[153].sprite.setPosition(19351.5, 4253.79);
	vertical_fence[154].sprite.setPosition(19351.5, 4327.79);
	fenc[90].sprite.setPosition(13326.5, 381.98);
	fenc[91].sprite.setPosition(13428.5, 381.98);
	fenc[92].sprite.setPosition(13529.5, 382.98);
	fenc[93].sprite.setPosition(13630.4, 381.32);
	fenc[94].sprite.setPosition(13732.4, 381.32);
	fenc[95].sprite.setPosition(13833.4, 382.32);
	fenc[96].sprite.setPosition(13937.9, 382.08);
	fenc[97].sprite.setPosition(14039.0, 381.08);
	fenc[98].sprite.setPosition(14141.0, 381.08);
	fenc[99].sprite.setPosition(14242.0, 382.08);
	fenc[100].sprite.setPosition(14342.9, 380.42);
	fenc[101].sprite.setPosition(14444.9, 380.42);
	fenc[102].sprite.setPosition(14545.9, 381.42);
	fenc[103].sprite.setPosition(14648.5, 382.35);
	fenc[104].sprite.setPosition(14750.5, 382.35);
	fenc[105].sprite.setPosition(14851.5, 383.35);
	fenc[106].sprite.setPosition(14952.4, 381.69);
	fenc[107].sprite.setPosition(15054.4, 381.69);
	fenc[108].sprite.setPosition(15155.4, 382.69);
	fenc[109].sprite.setPosition(15259.9, 382.45);
	fenc[110].sprite.setPosition(15361.9, 382.45);
	fenc[111].sprite.setPosition(15462.9, 383.45);
	fenc[112].sprite.setPosition(15563.8, 381.79);
	fenc[113].sprite.setPosition(15665.8, 381.79);
	fenc[114].sprite.setPosition(15766.8, 382.79);
	fenc[115].sprite.setPosition(15869.4, 383.72);
	fenc[116].sprite.setPosition(15971.4, 383.72);
	fenc[117].sprite.setPosition(16072.4, 384.72);
	fenc[118].sprite.setPosition(16173.3, 383.06);
	fenc[119].sprite.setPosition(16275.3, 383.06);
	fenc[120].sprite.setPosition(16376.3, 384.06);
	fenc[121].sprite.setPosition(16477.6, 384.31);
	fenc[122].sprite.setPosition(16579.6, 384.31);
	fenc[123].sprite.setPosition(16680.6, 385.31);
	fenc[124].sprite.setPosition(16781.5, 383.65);
	fenc[125].sprite.setPosition(16883.5, 383.65);
	fenc[126].sprite.setPosition(16984.5, 384.65);
	fenc[127].sprite.setPosition(17087.1, 385.58);
	fenc[128].sprite.setPosition(17189.1, 385.58);
	fenc[129].sprite.setPosition(17290.1, 386.58);
	fenc[130].sprite.setPosition(17391.0, 384.92);
	fenc[131].sprite.setPosition(17493.0, 384.92);
	fenc[132].sprite.setPosition(17594.0, 385.92);
	fenc[133].sprite.setPosition(17698.5, 385.68);
	fenc[134].sprite.setPosition(17800.5, 385.68);
	fenc[135].sprite.setPosition(17903.7, 383.77);
	fenc[136].sprite.setPosition(18004.6, 382.11);
	fenc[137].sprite.setPosition(18106.6, 382.11);
	fenc[138].sprite.setPosition(18207.6, 383.11);
	fenc[139].sprite.setPosition(18310.2, 384.04);
	fenc[140].sprite.setPosition(18412.2, 384.04);
	fenc[141].sprite.setPosition(18513.2, 385.04);
	fenc[142].sprite.setPosition(18614, 383.38);
	fenc[143].sprite.setPosition(18716.1, 383.38);
	fenc[144].sprite.setPosition(18817.1, 384.38);
	fenc[145].sprite.setPosition(18921.6, 384.14);
	fenc[146].sprite.setPosition(19023.6, 384.14);
	fenc[147].sprite.setPosition(19124.6, 385.14);
	fenc[148].sprite.setPosition(19225.5, 383.48);
	fenc[149].sprite.setPosition(13572.6, 846.595);
	fenc[150].sprite.setPosition(13673.5, 844.935);
	fenc[151].sprite.setPosition(13775.5, 844.935);
	fenc[152].sprite.setPosition(13876.5, 845.935);
	fenc[153].sprite.setPosition(13981.0, 845.695);
	fenc[154].sprite.setPosition(14082.1, 844.695);
	fenc[155].sprite.setPosition(14184.1, 844.695);
	fenc[156].sprite.setPosition(14285.1, 845.695);
	fenc[157].sprite.setPosition(14386.0, 844.035);
	fenc[158].sprite.setPosition(14488.0, 844.035);
	fenc[159].sprite.setPosition(14589.0, 845.035);
	fenc[160].sprite.setPosition(14691.6, 845.965);
	fenc[161].sprite.setPosition(14793.6, 845.965);
	fenc[162].sprite.setPosition(14894.6, 846.965);
	fenc[163].sprite.setPosition(13572.6, 846.595);
	fenc[164].sprite.setPosition(13673.5, 844.935);
	fenc[165].sprite.setPosition(13775.5, 844.935);
	fenc[166].sprite.setPosition(13876.5, 845.935);
	fenc[167].sprite.setPosition(13981.0, 845.695);
	fenc[168].sprite.setPosition(14082.1, 844.695);
	fenc[169].sprite.setPosition(14184.1, 844.695);
	fenc[170].sprite.setPosition(14285.1, 845.695);
	fenc[171].sprite.setPosition(14386.0, 844.035);
	fenc[172].sprite.setPosition(14488.0, 844.035);
	fenc[173].sprite.setPosition(14589.0, 845.035);
	fenc[174].sprite.setPosition(14691.6, 845.965);
	fenc[175].sprite.setPosition(14793.6, 845.965);
	fenc[176].sprite.setPosition(14894.6, 846.965);
	fenc[177].sprite.setPosition(14964.0, 3035.69);
	fenc[178].sprite.setPosition(15066.0, 3035.69);
	fenc[179].sprite.setPosition(15167.0, 3036.69);
	fenc[180].sprite.setPosition(15271.5, 3036.45);
	fenc[181].sprite.setPosition(15373.5, 3036.45);
	fenc[182].sprite.setPosition(15474.5, 3037.45);
	fenc[183].sprite.setPosition(15575.4, 3035.79);
	fenc[184].sprite.setPosition(15677.4, 3035.79);
	fenc[185].sprite.setPosition(15778.4, 3036.79);
	fenc[186].sprite.setPosition(15881.0, 3037.72);
	fenc[187].sprite.setPosition(16387.8, 3038.06);
	fenc[188].sprite.setPosition(16489.2, 3038.31);
	fenc[189].sprite.setPosition(16591.2, 3038.31);
	fenc[190].sprite.setPosition(16692.2, 3039.31);
	fenc[191].sprite.setPosition(16793.0, 3037.65);
	fenc[192].sprite.setPosition(16895.0, 3037.65);
	fenc[193].sprite.setPosition(16996.0, 3038.65);

	autumn3[0].sprite.setPosition(1904.55, 7646.97);
	autumn3[1].sprite.setPosition(2037.88, 7813.64);
	autumn3[2].sprite.setPosition(2162.88, 7988.64);
	autumn3[3].sprite.setPosition(2312.88, 8171.97);
	autumn3[4].sprite.setPosition(2487.88, 8355.3);
	autumn3[5].sprite.setPosition(2678.79, 8530.3);
	autumn3[6].sprite.setPosition(2863.64, 8733.33);
	autumn3[7].sprite.setPosition(2952.0, 9064.0);
	autumn3[8].sprite.setPosition(2757.94, 9248.61);
	autumn3[9].sprite.setPosition(2597.33, 9442.55);
	autumn3[10].sprite.setPosition(3965.38, 8734.13);
	autumn3[11].sprite.setPosition(4150.23, 8531.1);
	autumn3[12].sprite.setPosition(4341.14, 8356.1);
	autumn3[13].sprite.setPosition(4516.14, 8172.77);
	autumn3[14].sprite.setPosition(4666.14, 7989.44);
	autumn3[15].sprite.setPosition(4791.14, 7814.44);
	autumn3[16].sprite.setPosition(4924.47, 7647.77);

	burned.sprite.setPosition(6284.0, 1440.0);
	burned.intialize(Burned_tree2);
	burned.hitbox.setSize(Vector2f(burned.sprite.getGlobalBounds().width-300, burned.sprite.getGlobalBounds().height-100));
	burned.sprite.setScale(1.61, 1.62);
	burned.hitbox.setScale(1.61, 1.62);

	broken[0].sprite.setPosition(18029.7, 4555.28);
	broken[1].sprite.setPosition(6033.54, 3041.03);
	//broken[1].sprite.setRotation(16.9785);
	broken1.sprite.setPosition(8503.76, 1258.84);
	//broken1.sprite.setRotation(20.3125);
	broken2.sprite.setPosition(6704.33, 2264.82);
	broken3[0].sprite.setPosition(8640.06, 2573.52);
	broken3[1].sprite.setPosition(4588.0, 11936.5);
	broken3[2].sprite.setPosition(15610.0, 3866.0);

	moss1.sprite.setPosition(3752.0, 2592.0);
	moss2.sprite.setPosition(850.5, 3722.5);
	moss3.sprite.setPosition(896.0, 1272.0);
	moss1.intialize(Mossy_tree);
	moss1.hitbox.setSize(Vector2f(moss1.sprite.getGlobalBounds().width-200, moss1.sprite.getGlobalBounds().height-200));
	moss2.intialize(Mossy_tree_1);
	moss2.hitbox.setSize(Vector2f(moss2.sprite.getGlobalBounds().width+100, moss2.sprite.getGlobalBounds().height+100));
	moss3.intialize(Mossy_tree_2);
	moss3.hitbox.setSize(Vector2f(moss3.sprite.getGlobalBounds().width-100, moss3.sprite.getGlobalBounds().height));
	moss1.sprite.setScale(1.69, 1.89);
	moss2.sprite.setScale(2.74375, 2.81875);
	moss3.sprite.setScale(2.22, 2.52);

	broken[0].intialize(broken_tree_6);
	broken[1].intialize(broken_tree_6);
	broken1.intialize(broken_tree_3);
	broken2.intialize(broken_tree);
	broken3[0].intialize(broken_tree_2);
	broken3[1].intialize(broken_tree_2);
	broken3[2].intialize(broken_tree_2);
	broken[0].hitbox.setSize(Vector2f(broken[0].sprite.getGlobalBounds().width, broken[0].sprite.getGlobalBounds().height-400)); 
	broken[1].hitbox.setSize(Vector2f(broken[1].sprite.getGlobalBounds().width, broken[1].sprite.getGlobalBounds().height-400)); 
	broken1.hitbox.setSize(Vector2f(broken1.sprite.getGlobalBounds().width, broken1.sprite.getGlobalBounds().height-200)); 
	broken2.hitbox.setSize(Vector2f(broken2.sprite.getGlobalBounds().width, broken2.sprite.getGlobalBounds().height)); 
	broken3[0].hitbox.setSize(Vector2f(broken3[0].sprite.getGlobalBounds().width, broken3[0].sprite.getGlobalBounds().height)); 
	broken3[1].hitbox.setSize(Vector2f(broken3[1].sprite.getGlobalBounds().width+100, broken3[1].sprite.getGlobalBounds().height)); 
	broken3[2].hitbox.setSize(Vector2f(broken3[2].sprite.getGlobalBounds().width-100, broken3[2].sprite.getGlobalBounds().height-100)); 
	broken[0].sprite.setScale(1.83, 1.458575);
	broken[1].sprite.setScale(1.83, 1.458575);
	broken1.sprite.setScale(1.922485, 1.7662675);
	broken2.sprite.setScale(1.90121, 1.871515);
	broken3[0].sprite.setScale(1.548, 1.62828);
	broken3[1].sprite.setScale(2.173, 1.8);
	broken[1].sprite.setRotation(16.9785);
	broken1.sprite.setRotation(20.3125);

	house1.sprite.setPosition(15157.3, 1646.94);
	house1.intialize(House_3);
	house1.sprite.setScale(1.87272,1.5975);
	house1.hitbox.setSize(Vector2f(house1.sprite.getGlobalBounds().width, house1.sprite.getGlobalBounds().height));

	house2.sprite.setPosition(7336.83, 1917.67);
	house2.intialize(House_2);
	house2.sprite.setScale(1.4325,1.394);
	house2.hitbox.setSize(Vector2f(house2.sprite.getGlobalBounds().width, house2.sprite.getGlobalBounds().height));

	house3.sprite.setPosition(1830.0, 2326.0);
	house3.intialize(House_1);
	house3.sprite.setScale(2.075,2.068);
	house3.hitbox.setSize(Vector2f(house3.sprite.getGlobalBounds().width, house3.sprite.getGlobalBounds().height));
	house4.sprite.setPosition(2232.0, 11458);
	house4.intialize(House);
	house4.sprite.setScale(1.635,1.5699);
	house4.hitbox.setSize(Vector2f(house4.sprite.getGlobalBounds().width, house4.sprite.getGlobalBounds().height));


	camp.intialize(Camp_fire_1_texture);
	camp.sprite.setPosition(8444.0, 2902.0);
	camp.hitbox.setSize(Vector2f(camp.sprite.getGlobalBounds().width-40, camp.sprite.getGlobalBounds().height+50));
	camp.sprite.setScale(5.25,5.21875 );
	camp.animation_init(32, 64, 6);
	camp1.intialize(Camp_fire_2_texture);
	camp1.sprite.setPosition(3589.61, 11203.4);
	camp1.hitbox.setSize(Vector2f(camp1.sprite.getGlobalBounds().width, camp1.sprite.getGlobalBounds().height+100));
	camp1.sprite.setScale(5.921875,5.140625 );
	camp1.animation_init(32, 32, 6);
	flag.intialize(Flag_texture);
	flag.sprite.setPosition(8274.0, 2948.0);
	flag.hitbox.setSize(Vector2f(flag.sprite.getGlobalBounds().width-80, flag.sprite.getGlobalBounds().height+200));
	flag.sprite.setScale(5.125,6.53125 );
	flag.animation_init(32, 64, 6);

	tnt2.sprite.setPosition(14018.7, 1555.0);
	tnt2.intialize(tent_1);
	tnt2.sprite.setScale(1.45,1.283 );
	tnt2.hitbox.setSize(Vector2f(tnt2.sprite.getGlobalBounds().width , tnt2.sprite.getGlobalBounds().height ));

	tnt3[0].sprite.setPosition(3852.5, 3160.5);
	tnt3[0].intialize(Tent_2);
	tnt3[0].sprite.setScale(1.5229175, 1.691);
	tnt3[0].hitbox.setSize(Vector2f(tnt3[0].sprite.getGlobalBounds().width , tnt3[0].sprite.getGlobalBounds().height ));
	tnt3[1].sprite.setPosition(2108.0, 6863.0);
	tnt3[1].intialize(Tent_2);
	tnt3[1].sprite.setScale(1.28, 1.19895);
	tnt3[1].hitbox.setSize(Vector2f(tnt3[1].sprite.getGlobalBounds().width , tnt3[1].sprite.getGlobalBounds().height ));

	tnt4.sprite.setPosition(17162.8, 1632.92);
	tnt4.intialize(Tent_3);
	tnt4.sprite.setScale(1.668865, 1.5897);
	tnt4.hitbox.setSize(Vector2f(tnt4.sprite.getGlobalBounds().width , tnt4.sprite.getGlobalBounds().height ));

	lamp[0].sprite.setPosition(13614.0, 1969.0);
	lamp[1].sprite.setPosition(14958.0, 861.0);
	lamp[2].sprite.setPosition(15462.0, 3101.0);
	lamp[3].sprite.setPosition(17026.0, 3121.0);
	for (int i(0); i < 4; i++)
	{
		lamp[i].intialize(light);
	}
		lamp[0].sprite.setScale(1, 1.352);
		lamp[1].sprite.setScale(1, 1.336);
		lamp[2].sprite.setScale(1.24, 1.464);
		lamp[3].sprite.setScale(1.2, 1.528);

		// Ensure lamp hitboxes are sized and have correct origin after scaling
		for (int i = 0; i < 4; i++)
		{
			lamp[i].hitbox.setSize(Vector2f(lamp[i].sprite.getGlobalBounds().width, lamp[i].sprite.getGlobalBounds().height-40));
			//lamp[i].hitbox.setOrigin(0, lamp[i].hitbox.getSize().y);
		}

		fallen_lamp[0].sprite.setPosition(1349.24, 2053.79);
		fallen_lamp[1].sprite.setPosition(3881.0, 3855.24);
		fallen_lamp[0].intialize(fallen_light);
		fallen_lamp[1].intialize(fallen_light);
		fallen_lamp[0].sprite.setScale(1.505, 1.6039);
		fallen_lamp[1].sprite.setScale(1.727, 1.4344);
		fallen_lamp[1].hitbox.setSize(Vector2f(fallen_lamp[1].sprite.getGlobalBounds().width-30 , fallen_lamp[1].sprite.getGlobalBounds().height ));
		fallen_lamp[0].hitbox.setSize(Vector2f(fallen_lamp[0].sprite.getGlobalBounds().width-30 , fallen_lamp[0].sprite.getGlobalBounds().height ));

		broken_lamp[0].sprite.setPosition(8654.33, 1823.61);
		broken_lamp[1].sprite.setPosition(6717.73, 3211.76);
		broken_lamp[0].intialize(broken_light);
		broken_lamp[1].intialize(broken_light);
		broken_lamp[1].hitbox.setSize(Vector2f(broken_lamp[1].sprite.getGlobalBounds().width , broken_lamp[1].sprite.getGlobalBounds().height ));
		broken_lamp[0].hitbox.setSize(Vector2f(broken_lamp[0].sprite.getGlobalBounds().width , broken_lamp[0].sprite.getGlobalBounds().height ));

		lakee[0].sprite.setPosition(17352.0, 3816.0);
		lakee[1].sprite.setPosition(16277.4, 11789.4);
		lakee[0].intialize(lake);
		lakee[1].intialize(lake);
		lakee[0].sprite.setScale(1.30729, 1.359375);
		lakee[1].sprite.setScale(1.30729, 1.359375);
		lakee[0].hitbox.setSize(Vector2f(lakee[0].sprite.getGlobalBounds().width-300 , lakee[0].sprite.getGlobalBounds().height -200));
		lakee[1].hitbox.setSize(Vector2f(lakee[1].sprite.getGlobalBounds().width-300 , lakee[1].sprite.getGlobalBounds().height -200));

		anvell.sprite.setPosition(17280.4, 1501.19);
		anvell.intialize(anvel);
		anvell.sprite.setScale(1.327, 1.32705);

	for (int i = 0; i < 17; i++)
	{
		autumn3[i].intialize(Autumn_tree_2);
	}
	sakura.intialize(Sakura_texture);
	sakura.sprite.setPosition(14773.0, 10753.5);
	sakura.sprite.setScale(7.098, 6.388);
	//sakura.sprite.setTextureRect(sf::IntRect(0, 0, 250, 300));
	sakura.animation_init(250,300,6);
	sakura.interaction_init("hanboos emta ? ;)");
	sakura.hitbox.setSize(Vector2f(sakura.sprite.getGlobalBounds().width -300, sakura.sprite.getGlobalBounds().height -400));

	for (int i = 0; i < 194; i++)
	{
		fenc[i].intialize(fence);
		fenc[i].hitbox.setSize(Vector2f(fenc[i].hitbox.getSize().x+80, fenc[i].hitbox.getSize().y+50));
		fenc[i].hitbox.setPosition(fenc[i].hitbox.getPosition().x-100, fenc[i].hitbox.getPosition().y+30 );
	}
	for (int i = 0; i < 155; i++)
	{
		vertical_fence[i].intialize(parallel_fence);
		vertical_fence[i].hitbox.setSize(Vector2f(vertical_fence[i].hitbox.getSize().x+20, vertical_fence[i].hitbox.getSize().y+50));
		vertical_fence[i].hitbox.setPosition(vertical_fence[i].hitbox.getPosition().x-130, vertical_fence[i].hitbox.getPosition().y+30 );
	}
	for (int i = 0; i < 64; i++)
	{
		fruit1[i].intialize(fruit_tree_1);
	}
	for (int i = 0; i < 13; i++)
	{
		fruit[i].intialize(fruit_tree);
		//if(i<11)
		//fruit[i].hitbox.setPosition(fruit[i].hitbox.getPosition().x + 150, fruit[i].hitbox.getPosition().y - 150);
		//fruit[i].sprite.setPosition(fruit[i].sprite.getPosition()+Vector2f(0,800));
	}
	fruit[10].hitbox.setSize(fruit[10].hitbox.getSize() - Vector2f(100, 0));
	fruit[11].hitbox.setSize(fruit[11].hitbox.getSize() - Vector2f(150, 100));
	fruit[12].hitbox.setSize(fruit[12].hitbox.getSize() - Vector2f(150,50));

	fruit[0].sprite.setScale(1.36, 1.47);
	fruit[1].sprite.setScale(1.36, 1.47);
	fruit[2].sprite.setScale(1.36, 1.47);
	fruit[3].sprite.setScale(1.36, 1.47);
	fruit[4].sprite.setScale(1.36, 1.47);
	fruit[5].sprite.setScale(1.36, 1.47);
	fruit[6].sprite.setScale(1.36, 1.47);
	fruit[7].sprite.setScale(1.36, 1.47);
	fruit[8].sprite.setScale(1.36, 1.47);
	fruit[9].sprite.setScale(1.36, 1.47);
	fruit[10].sprite.setScale(1.355, 1.345);
	fruit[11].sprite.setScale(1.785, 1.79);
	fruit[12].sprite.setScale(1.82, 1.77);
	fruit[0].hitbox.setScale(1.36, 1.47);
	fruit[1].hitbox.setScale(1.36, 1.47);
	fruit[2].hitbox.setScale(1.36, 1.47);
	fruit[3].hitbox.setScale(1.36, 1.47);
	fruit[4].hitbox.setScale(1.36, 1.47);
	fruit[5].hitbox.setScale(1.36, 1.47);
	fruit[6].hitbox.setScale(1.36, 1.47);
	fruit[7].hitbox.setScale(1.36, 1.47);
	fruit[8].hitbox.setScale(1.36, 1.47);
	fruit[9].hitbox.setScale(1.36, 1.47);
	fruit[10].hitbox.setScale(1.355, 1.345);
	fruit[11].hitbox.setScale(1.785, 1.79);
	fruit[12].hitbox.setScale(1.82, 1.77);

	for (int i = 0; i < 10; i++)
	{
		christmas[i].intialize(christmas_tree);
		christmas[i].sprite.setScale(1.14, 1.28);
		christmas[i].hitbox.setScale(1.14, 1.28);
	}



	for (int i = 0; i < 2; i++)
	{
		welll[i].intialize(well);
		welll[i].hitbox.setScale(1.33, 1.22);
		welll[i].sprite.setScale(1.33, 1.22);
		welll[i].interaction_init("Gooo2 \nGooo2\nGooo2");
		welll[i].interaction_box.setScale(1.33, 1.22);
		welll[i].hitbox.setSize(Vector2f(welll[i].sprite.getGlobalBounds().width-200 , welll[i].sprite.getGlobalBounds().height-200 ));
		welll[i].text.text.setCharacterSize(80);
	}
	for (int i = 0; i < 3; i++)
	{
		cars[i].intialize(car);
		cars[i].hitbox.setSize(Vector2f(cars[i].sprite.getGlobalBounds().width , cars[i].sprite.getGlobalBounds().height ));
	}
	cars[0].sprite.setScale(-1.32705, 1.327049);
	cars[0].hitbox.setScale(-1.32705, 1.327049);
	for(int i=0;i<4;i++)
	{
		boxes[i].intialize(box);
		boxes[i].hitbox.setSize(Vector2f(boxes[i].sprite.getGlobalBounds().width/2, boxes[i].sprite.getGlobalBounds().height));
	}
	boxes[0].sprite.setScale(1.32705, 1.32705);
	boxes[0].hitbox.setScale(1.32705, 1.32705);
	for (int i = 0; i < 15; i++)
	{
		autumn1[i].intialize(Autumn_tree);
	}
	for (int i = 0; i < 12; i++)
	{
		autumn2[i].intialize(Autumn_tree_1);
		autumn2[i].hitbox.setSize(Vector2f(autumn2[i].sprite.getGlobalBounds().width / 2, autumn2[i].sprite.getGlobalBounds().height/2));
	}
}

void game_update() {
	// Center camera on fox but clamp inside background bounds
	sf::Vector2u bgSize = Vector2u(20000,12000);
	sf::Vector2f camSize = camera.getSize();

	sf::Vector2f foxCenter(
		Fox.getGlobalBounds().left + Fox.getGlobalBounds().width / 2.0f,
		Fox.getGlobalBounds().top + Fox.getGlobalBounds().height / 2.0f
	);

	float camX = std::max(camSize.x / 2.0f, std::min((float)bgSize.x - camSize.x / 2.0f, foxCenter.x));
	float camY = std::max(camSize.y / 2.0f, std::min((float)bgSize.y - camSize.y / 2.0f, foxCenter.y));

	camera.setCenter(camX, camY);

	Fox_hitbox.setPosition(Fox.getPosition().x-240 , Fox.getPosition().y-980 );
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

		// Clamp fox position to stay inside background so it never leaves the map/view
		{
			sf::Vector2u bgSize = Vector2u(20000,12000);
			sf::FloatRect foxBounds = Fox.getGlobalBounds();
			float halfW = foxBounds.width / 2.f;
			float halfH = foxBounds.height / 2.f;
			sf::Vector2f pos = Fox.getPosition();

			pos.x = std::max(halfW, std::min((float)bgSize.x - halfW, pos.x));
			pos.y = std::max(halfH, std::min((float)bgSize.y - halfH, pos.y));

			Fox.setPosition(pos);
		}

	}
	else {
		// No movement keys pressed
		fox_status = Idle;
		Fox_speed = Fox_base_speed; // restore base speed
	}

	// After movement handling, play/stop grass sound based on current fox_status
	if (fox_status == Walking || fox_status == Running) {
		if (grass.getStatus() != sf::Sound::Playing) {
			grass.play();
		}
	} else {
		if (grass.getStatus() == sf::Sound::Playing) {
			grass.stop();
		}
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
	Hare.update(0);
	Hare1.update(200);
	Deer.update(0);
	Deer1.update(300);
	Boar.update(0,200,200);
	//Boar.interaction_box.setPosition(3874, 3180  ); 
	Black_grouse.update(0);
	Black_grouse1.update(100);
	Black_grouse2.update(200);
	Black_grouse3.update(300);
	treee1.update();
	treee1.hitbox.setPosition(treee1.sprite.getPosition().x + 180, treee1.sprite.getPosition().y - 290);

	treee2.update();
	treee2.hitbox.setPosition(treee2.sprite.getPosition().x + 430, treee2.sprite.getPosition().y - 200);
	treee1.collision();
	treee2.collision();

	for (int i = 0; i < 73; i++)
	{
		treee[i].hitbox.setPosition(treee[i].sprite.getPosition().x + 200, treee[i].sprite.getPosition().y - 90);
		treee[i].collision();

		if (i < 9)
		{
			treee3[i].update(); 
			if(i<4)
				treee3[i].hitbox.setPosition(treee3[i].sprite.getPosition().x+30, treee3[i].sprite.getPosition().y-170);
			else
				treee3[i].hitbox.setPosition(treee3[i].sprite.getPosition().x+70, treee3[i].sprite.getPosition().y-300);

			treee3[i].collision();
		}
		if (i < 13)
		{
			fruit[i].update();
			fruit[i].collision();
		}if (i < 64)
		{
			fruit1[i].update();
			fruit1[i].collision();
		}
		if (i < 11)
			fruit[i].hitbox.setPosition(fruit[i].hitbox.getPosition().x + 150, fruit[i].hitbox.getPosition().y - 150);
		if (i < 2)
		{
			welll[i].update();
			welll[i].hitbox.setPosition(welll[i].sprite.getPosition().x +45, welll[i].sprite.getPosition().y - 150);
			welll[i].collision();
			welll[i].interaction();
		}
		if (i < 10) {
			christmas[i].update();
			christmas[i].collision();
			christmas[i].hitbox.setPosition(christmas[i].sprite.getPosition().x + 250, christmas[i].sprite.getPosition().y - 90);
		}
		if (i < 4)
		{
			boxes[i].update();
			boxes[i].hitbox.setPosition(boxes[i].sprite.getPosition().x+50 , boxes[i].sprite.getPosition().y - 130);
			boxes[i].collision();
		}
		if (i < 3)
		{
			cars[i].update();
			cars[i].hitbox.setPosition(cars[i].sprite.getPosition().x , cars[i].sprite.getPosition().y - 110);
			cars[i].collision();
		}
		if (i < 15)
		{
			autumn1[i].update();
			autumn1[i].collision();
		}
	}
	for (int i = 0; i < 194; i++)
	{
		//fenc[i].update();
		fenc[i].hitbox.setPosition(Vector2f(fenc[i].sprite.getPosition().x + 30, fenc[i].sprite.getPosition().y - 70));

		fenc[i].collision();
	}
	for (int i = 0; i < 155; i++)
	{
		//vertical_fence[i].update();
		vertical_fence[i].hitbox.setPosition(Vector2f(vertical_fence[i].sprite.getPosition().x + 30, vertical_fence[i].sprite.getPosition().y - 70));

		vertical_fence[i].collision();
	}
	sakura.update();
	sakura.hitbox.setPosition(Vector2f(sakura.sprite.getPosition().x +45, sakura.sprite.getPosition().y - 1490));
	sakura.collision();
	sakura.animation(250, 300, 6);
	sakura.interaction();
	sakura.back.setPosition(Fox.getPosition().x+200 , sakura.sprite.getPosition().y-200);
	sakura.text.text.setPosition(Fox.getPosition().x+400 , sakura.text.text.getPosition().y-200);
	for (int i = 0; i < 12; i++)
	{
		autumn2[i].update();
		autumn2[i].collision();
	}
	for (int i = 0; i < 17; i++)
	{
		autumn3[i].update();
		autumn3[i].collision();
	}
	broken[0].update();
	broken[0].hitbox.setPosition(broken[0].sprite.getPosition().x + 380, broken[0].sprite.getPosition().y - 440);
	broken[0].collision();
	broken[1].update();
	broken[1].hitbox.setPosition(broken[1].sprite.getPosition().x + 380, broken[1].sprite.getPosition().y - 190);
	broken[1].collision();
	broken1.update();
	broken1.hitbox.setPosition(broken1.sprite.getPosition().x + 300, broken1.sprite.getPosition().y - 150);
	broken1.collision();
	broken2.update();
	broken2.hitbox.setPosition(broken2.sprite.getPosition().x + 100, broken2.sprite.getPosition().y - 190);
	broken2.collision();
	broken3[0].update();
	broken3[0].hitbox.setPosition(broken3[0].sprite.getPosition().x + 70, broken3[0].sprite.getPosition().y - 290);
	broken3[0].collision();
	broken3[1].update();
	broken3[1].hitbox.setPosition(broken3[1].sprite.getPosition().x + 150, broken3[1].sprite.getPosition().y - 290);
	broken3[1].collision();
	broken3[2].update();
	broken3[2].hitbox.setPosition(broken3[2].sprite.getPosition().x + 45, broken3[2].sprite.getPosition().y - 100);
	broken3[2].collision();
	fruit[10].hitbox.setPosition(fruit[10].sprite.getPosition().x + 380, fruit[10].sprite.getPosition().y - 190);
	fruit[11].hitbox.setPosition(fruit[11].sprite.getPosition().x + 550, fruit[11].sprite.getPosition().y - 100);
	fruit[12].hitbox.setPosition(fruit[12].sprite.getPosition().x + 550, fruit[12].sprite.getPosition().y - 100);
	//fruit[11].hitbox.setSize(fruit[11].hitbox.getSize() - Vector2f(100,0));
	//fruit[12].hitbox.setSize(fruit[12].hitbox.getSize() - Vector2f(100,0));
	house1.update();
	house1.hitbox.setPosition(house1.sprite.getPosition().x - 30, house1.sprite.getPosition().y - 850);
	house1.collision();
	house2.update();
	house2.hitbox.setPosition(house2.sprite.getPosition().x - 30, house2.sprite.getPosition().y - 850);
	house2.collision();

	house3.update();
	house3.hitbox.setPosition(house3.sprite.getPosition().x - 30, house3.sprite.getPosition().y - 1050);
	house3.collision();
	house4.update();
	house4.hitbox.setPosition(house4.sprite.getPosition().x - 30, house4.sprite.getPosition().y - 850);
	house4.collision();

	moss1.update();
	moss1.hitbox.setPosition(moss1.sprite.getPosition().x +340, moss1.sprite.getPosition().y - 650);
	moss1.collision();
	moss2.update();
	moss2.hitbox.setPosition(moss2.sprite.getPosition().x +320, moss2.sprite.getPosition().y - 450);
	moss2.collision();
	moss3.update();
	moss3.hitbox.setPosition(moss3.sprite.getPosition().x +300, moss3.sprite.getPosition().y - 400);
	moss3.collision();

	camp.update();
	camp.hitbox.setPosition(camp.sprite.getPosition().x +20, camp.sprite.getPosition().y - 100);
	camp.collision();
	camp.animation(32,64,6);
	camp1.update();
	camp1.hitbox.setPosition(camp1.sprite.getPosition().x +50, camp1.sprite.getPosition().y - 100);
	camp1.collision();
	camp1.animation(32, 32, 6);
	flag.update();
	flag.hitbox.setPosition(flag.sprite.getPosition().x +40, flag.sprite.getPosition().y - 250);
	flag.collision();
	flag.animation(32, 64, 6);

	tnt2.update();
	tnt2.hitbox.setPosition(tnt2.sprite.getPosition().x , tnt2.sprite.getPosition().y - 350);
	tnt2.collision();
	tnt3[0].update();
	tnt3[0].hitbox.setPosition(tnt3[0].sprite.getPosition().x - 15, tnt3[0].sprite.getPosition().y - 500);
	tnt3[0].collision();
	tnt3[1].update();
	tnt3[1].hitbox.setPosition(tnt3[1].sprite.getPosition().x - 10, tnt3[1].sprite.getPosition().y - 300);
	tnt3[1].collision();
	tnt4.update();
	tnt4.hitbox.setPosition(tnt4.sprite.getPosition().x - 15, tnt4.sprite.getPosition().y - 500);
	tnt4.collision();

	burned.update();
	burned.hitbox.setPosition(burned.sprite.getPosition().x + 230, burned.sprite.getPosition().y - 240);
	burned.collision();

	for (int i = 0; i < 4; i++)
	{
		lamp[i].update();
		lamp[i].hitbox.setPosition(lamp[i].sprite.getPosition().x , lamp[i].sprite.getPosition().y - 150);
		lamp[i].collision();
		if (i < 2)
		{
			fallen_lamp[i].update();
			fallen_lamp[i].hitbox.setPosition(fallen_lamp[i].sprite.getPosition().x , fallen_lamp[i].sprite.getPosition().y - 250);
			fallen_lamp[i].collision();
			broken_lamp[i].update();
			broken_lamp[i].hitbox.setPosition(broken_lamp[i].sprite.getPosition().x , broken_lamp[i].sprite.getPosition().y - 100);
			broken_lamp[i].collision();
			lakee[i].update();
			lakee[i].hitbox.setPosition(lakee[i].sprite.getPosition().x + 150, lakee[i].sprite.getPosition().y - 1000);

			lakee[i].collision();
		}
	}
	anvell.update();
	anvell.collision();
}
void game_draw() {
	window.setView(camera);
	window.draw(Game_Background_Sprite[0]);
	window.draw(Game_Background_Sprite[1]);
	window.draw(Game_Background_Sprite[2]);
	window.draw(Game_Background_Sprite[3]);
	for (int i = 2; i >= 0; i--)
	{
		cars[i].draw();
	}
	anvell.draw();
	window.draw(Fox_hitbox);
	window.draw(Fox);
	for (int i = 72; i >= 0; i--)
	{
		treee[i].draw();
		if (i < 9)
		{
			treee3[i].draw();
		}
		if (i < 10)
		{
			fruit[i].draw();
		}
		if (i < 2)
		{
			welll[i].draw();
		}
		if (i < 10) {
			christmas[i].draw();
		}
		if (i < 4)
		{
			boxes[i].draw();
		}
		
		if (i < 15)
		{
			autumn1[i].draw();
		}
	}
	fruit1[0].draw();
	fruit1[1].draw();
	fruit1[2].draw();
	fruit1[3].draw();
	fruit1[4].draw();
	fruit1[5].draw();
	fruit1[6].draw();
	fruit1[7].draw();
	fruit1[8].draw();
	fruit1[9].draw();
	fruit1[10].draw();
	
	
	fruit1[39].draw();
	fruit1[40].draw();
	fruit1[61].draw();
	fruit1[60].draw();
	fruit1[59].draw();
	fruit1[58].draw();
	fruit1[57].draw();
	fruit1[54].draw();
	fruit1[53].draw();
	fruit1[52].draw();
	fruit1[56].draw();
	fruit1[55].draw();
	fruit1[41].draw();
	fruit1[51].draw();
	fruit1[50].draw();

	//fruit1[20].draw();
	fruit1[32].draw();
	fruit1[33].draw();
	fruit1[38].draw();
	fruit1[37].draw();
	fruit1[36].draw();
	fruit1[34].draw();
	fruit1[35].draw();

	fruit1[49].draw();
	fruit1[48].draw();
	fruit1[47].draw();
	fruit1[42].draw();
	fruit1[43].draw();
	fruit1[44].draw();
	fruit1[45].draw();
	fruit1[62].draw();
	fruit1[63].draw();
	fruit1[31].draw();
	fruit1[30].draw();
	fruit1[29].draw();
	fruit1[28].draw();
	fruit1[27].draw();
	fruit1[26].draw();
	fruit1[25].draw();
	fruit1[24].draw();
	fruit1[23].draw();
	fruit1[22].draw();
	fruit1[21].draw();
	fruit1[46].draw();
	fruit1[20].draw();

	fruit1[13].draw();
	fruit1[12].draw();
	fruit1[16].draw();
	fruit1[17].draw();
	fruit1[15].draw();
	fruit1[18].draw();
	fruit1[14].draw();
	fruit1[19].draw();
	fruit1[11].draw();
	burned.draw();
	for (int i = 90; i <= 193; i++)
	{
		fenc[i].draw();
	}
	for (int i = 1; i < 4; i++)
	{
		lamp[i].draw();
	}
	for (int i = 0; i < 155; i++)
	{
		vertical_fence[i].draw();
	}
	for (int i = 0; i <=89; i++)
	{
		fenc[i].draw();
	}
	lamp[0].draw();
	for (int i = 0; i < 12; i++)
	{
		autumn2[i].draw();
	}
	fruit[11].draw();
	fruit[10].draw();
	fruit[12].draw();

	for (int i = 0; i < 17; i++)
	{
		autumn3[i].draw();
	}
	Hare.draw();
	
	Deer.draw();
	Black_grouse.draw();
	Black_grouse1.draw();
	Black_grouse2.draw();
	Black_grouse3.draw();

	sakura.draw();
	treee1.draw();
	treee2.draw();

	broken[0].draw();
	broken[1].draw();
	broken1.draw();
	broken2.draw();
	broken3[0].draw();
	broken3[1].draw();
	broken3[2].draw();

	moss1.draw();
	moss2.draw();
	moss3.draw();
	house1.draw();
	house2.draw();
	house3.draw();
	house4.draw();
	camp.draw();
	camp1.draw();
	flag.draw();
	tnt2.draw();
	tnt3[0].draw();
	tnt3[1].draw();
	tnt4.draw();
	for (int i(0); i < 2; i++)
	{
		fallen_lamp[i].draw();
		broken_lamp[i].draw();
		lakee[i].draw();
	}
	Hare1.draw();
	Boar.draw();
	Deer1.draw();

}
