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
		hitbox.setSize(sf::Vector2f(sprite.getGlobalBounds().width-100, sprite.getGlobalBounds().height-100));
		
		sprite.setTexture(texure);
		//sprite.setTextureRect(sf::IntRect(0, height, 128/4, 128/4));
		sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
		hitbox.setSize(sf::Vector2f(sprite.getGlobalBounds().width+50 , sprite.getLocalBounds().height-100 ));
		hitbox.setFillColor(sf::Color::Transparent);
		hitbox.setOrigin(hitbox.getSize().x / 2, hitbox.getSize().y / 2);
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
			// Handle collision response here
			// For example, you could stop the fox from moving or push it back
			Fox.move(-Fox_speed * Delta_time, 0); // Example: push back to the left
		}
	}
	void interaction_init(string str)
	{
		interaction_box.setSize(sf::Vector2f(45, 30));
		interaction_box.setFillColor(sf::Color::Transparent);
		interaction_box.setOrigin(interaction_box.getSize().x / 2, interaction_box.getSize().y / 2);
		interaction_box.setSize(sf::Vector2f(150, 100));
		//interaction_box.setFillColor(sf::Color::Cyan);
		interaction_box.setOrigin(interaction_box.getSize().x / 2, interaction_box.getSize().y / 2);
		text.setText(str);
		this->interact_button.set_texture(E_texture);
		back.setTexture(back_text);
		back.setOrigin(back.getGlobalBounds().width / 2, back.getGlobalBounds().height / 2);
		back.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width, sprite.getPosition().y);
		text.text.setOrigin(text.text.getGlobalBounds().width / 2, text.text.getGlobalBounds().height / 2);
		text.text.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width, sprite.getPosition().y);
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
	}
};
Decor treee[73],treee1,treee2,treee3[9], fruit[12],fruit1[64], welll[2], christmas[10], boxes[4], cars[3], autumn1[15], autumn2[12], broken[2], autumn3[17], broken1, broken2, broken3[2], moss1, moss2, moss3, house1, house2, house3, house4,camp,camp1,flag,tnt2,tnt3[2],tnt4,lamp[4], fallen_lamp[2], broken_lamp[2],lake[2], anvel, sakura,fenc[180],vertical_fence[155];
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
		hitbox.setSize(sf::Vector2f(sprite.getGlobalBounds().width-100, sprite.getGlobalBounds().height-100));
		interaction_box.setSize(sf::Vector2f(45, 30));
		interaction_box.setFillColor(sf::Color::Transparent);
		interaction_box.setOrigin(interaction_box.getSize().x / 2, interaction_box.getSize().y / 2);
		yoffset = height;
		sprite.setTexture(texure);
		sprite.setTextureRect(sf::IntRect(0, height, 128/4, 128/4));
		sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
		hitbox.setSize(sf::Vector2f(sprite.getGlobalBounds().width+50 , sprite.getLocalBounds().height-100 ));
		hitbox.setFillColor(sf::Color::Transparent);
		hitbox.setOrigin(hitbox.getSize().x / 2, hitbox.getSize().y / 2);
		interaction_box.setSize(sf::Vector2f(150, 100));
		//interaction_box.setFillColor(sf::Color::Cyan);
		interaction_box.setOrigin(interaction_box.getSize().x / 2, interaction_box.getSize().y / 2);
		this->interact_button.set_texture(E_texture);
		text.setText(str);
		back.setTexture(back_text);
		back.setOrigin(back.getGlobalBounds().width / 2, back.getGlobalBounds().height / 2);
		back.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width, sprite.getPosition().y);
		text.text.setOrigin(text.text.getGlobalBounds().width / 2, text.text.getGlobalBounds().height / 2);
		text.text.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width, sprite.getPosition().y);
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
			txt =!txt;
		}
		
	}
	void update(int high,  int framewidth=100, int frameheight=100, int framecount = 4)
	{	
		set_NPC_animition(timer, counter, sprite, framecount, framewidth, frameheight, high);
		hitbox.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width / 2-30, sprite.getPosition().y + sprite.getGlobalBounds().height / 2-30);
		this->interact_button.bot_sprite.setPosition(sprite.getPosition().x+20, sprite.getPosition().y + 50);
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
		window.draw(sprite);
		window.draw(hitbox);
		window.draw(interaction_box);
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
struct object
{
	Texture texture; Sprite sprite;
	RectangleShape hitbox;
	bool animate = false;
	float timer = 0; int  counter = 0;
	object( Vector2f position, bool animated = false) {
		animate = animated;
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
	void intialize(Texture& t,int height, Vector2f position)
	{
		texture = t;
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0, height, 32, 32));
		sprite.setPosition(position);
		hitbox.setSize(sf::Vector2f(sprite.getGlobalBounds().width - 100, sprite.getGlobalBounds().height - 100));
		hitbox.setFillColor(sf::Color::Transparent);
		hitbox.setOrigin(hitbox.getSize().x / 2, hitbox.getSize().y / 2);
		
	}
	void update()
	{
		if (animate)
		{
			set_NPC_animition(timer, counter, sprite, 6, 32, 32, 0);
		}
		hitbox.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width / 2, sprite.getPosition().y + sprite.getGlobalBounds().height / 2);
		collision();
	}
};
void game_intialization() {

	Hare.intialize(0, "Prepare yourself for the bad news\n\nbut the Game is near to its end", Hare_texture);
	Hare.sprite.setPosition(2353.83, 6796.67);
	Hare.sprite.setScale(1.455, 1.67333);
	Hare.interaction_box.setScale(1.455, 1.67333);
	Hare1.intialize(50, "Hello there,'\ncould U do me a favor?\ncould U give me a few million EGP or Dollars\nAs U like ><)", Hare_texture);
	Hare1.sprite.setPosition(2477.5, 6986);
	Hare1.sprite.setScale(1.45833, 1.495);
	Hare1.interaction_box.setScale(1.45833, 1.495);

	Deer.intialize(0, "Hey Alaa\nNice to meet U\nI hope U enjoy the Game ^^)", Deer_texture);
	Deer.sprite.setPosition(14262.5, 1510);
	Deer.sprite.setScale(1.65, 1.425);
	Deer.interaction_box.setScale(1.65, 1.425);
	Deer1.intialize(75, "Can U get me some \n\n\n\"3laawey 7abib galby ana 5ademkom Lesghayar\"\n\n\n pls? ", Deer_texture);
	Deer1.text.text.setCharacterSize(45);
	Deer1.sprite.setPosition(14092.5, 1595);
	Deer1.sprite.setScale(1.5, 1.4);
	Deer1.interaction_box.setScale(1.5, 1.4);
	Boar.intialize(0, "Get the fuck out of here!\n\n\n(imagin him like any won U dont like\nor harm U\n\n(I don't like him neither\n\'I know it looks like me but I'll deny\')", Boar_texture);
	Boar.sprite.setPosition(3874, 3180);
	Black_grouse.intialize(0, "I love U", Black_grouse_texture);
	Black_grouse.sprite.setPosition(15631.8,3198.48);
	Black_grouse.sprite.setScale(1.54545, 1.42424);
	Black_grouse.interaction_box.setScale(1.54545, 1.42424);

	Black_grouse1.intialize(25, "ich liebe dich", Black_grouse_texture);
	Black_grouse1.sprite.setPosition(15662.1, 3610.61);
	Black_grouse1.sprite.setScale(1.69697, 1.60606);
	Black_grouse1.interaction_box.setScale(1.69697, 1.60606);
	Black_grouse2.intialize(50, "Ti amo", Black_grouse_texture);
	Black_grouse2.sprite.setPosition(16465.2, 3346.97);
	Black_grouse2.sprite.setScale(1.54545, 1.51515);
	Black_grouse2.interaction_box.setScale(1.54545, 1.51515);

	Black_grouse3.intialize(75, "Je t'aime", Black_grouse_texture);
	Black_grouse3.sprite.setPosition(16615.2, 3692.24);
	Black_grouse3.sprite.setScale(1.51515, 1.57576);
	Black_grouse3.interaction_box.setScale(1.51515, 1.57576);

	for (int i = 0; i < 72; i++)
	{
		treee[i].intialize(tree);
		//treee[i].sprite.setScale(1.5, 1.5);
		//treee[i].hitbox.setScale(1.5, 1.5);
	}
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
	treee[12].hitbox.setScale(1.04899, 1.04899);
	treee[12].sprite.setScale(1.04899, 1.04899);
	treee[13].sprite.setPosition(7704.38, 5181.31);
	treee[13].hitbox.setScale(1.04899, 1.04899);
	treee[13].sprite.setScale(1.04899, 1.04899);
	treee[14].sprite.setPosition(8086.78, 5181.38);
	treee[14].hitbox.setScale(1.04899, 1.04899);
	treee[14].sprite.setScale(1.04899, 1.04899);
	treee[15].sprite.setPosition(8481.21, 5181.4);
	treee[15].hitbox.setScale(1.04899, 1.04899);
	treee[15].sprite.setScale(1.04899, 1.04899);
	treee[16].sprite.setPosition(8883.64, 5185.48);
	treee[16].hitbox.setScale(1.04899, 1.04899);
	treee[16].sprite.setScale(1.04899, 1.04899);
	treee[17].sprite.setPosition(9284.07, 5181.53);
	treee[17].hitbox.setScale(1.04899, 1.04899);
	treee[17].sprite.setScale(1.04899, 1.04899);
	treee[18].sprite.setPosition(9670.45, 5181.55);
	treee[18].hitbox.setScale(1.04899, 1.04899);
	treee[18].sprite.setScale(1.04899, 1.04899);
	treee[19].sprite.setPosition(10076.9, 5181.62);
	treee[19].hitbox.setScale(1.04899, 1.04899);
	treee[19].sprite.setScale(1.04899, 1.04899);
	treee[20].sprite.setPosition(10483.3, 5181.65);
	treee[20].hitbox.setScale(1.04899, 1.04899);
	treee[20].sprite.setScale(1.04899, 1.04899);
	treee[21].sprite.setPosition(10885.7, 5185.72);
	treee[21].hitbox.setScale(1.04899, 1.04899);
	treee[21].sprite.setScale(1.04899, 1.04899);
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
	treee[32].hitbox.setScale(1.04899, 1.04899);
	treee[32].sprite.setScale(1.04899, 1.04899);
	treee[33].sprite.setPosition(7713.39, 8007.49);
	treee[33].hitbox.setScale(1.04899, 1.04899);
	treee[33].sprite.setScale(1.04899, 1.04899);
	treee[34].sprite.setPosition(8095.79, 8007.56);
	treee[34].hitbox.setScale(1.04899, 1.04899);
	treee[34].sprite.setScale(1.04899, 1.04899);
	treee[35].sprite.setPosition(8490.22, 8007.58);
	treee[35].hitbox.setScale(1.04899, 1.04899);
	treee[35].sprite.setScale(1.04899, 1.04899);
	treee[36].sprite.setPosition(8892.65, 8011.66);
	treee[36].hitbox.setScale(1.04899, 1.04899);
	treee[36].sprite.setScale(1.04899, 1.04899);
	treee[37].sprite.setPosition(9293.08, 8007.71);
	treee[37].hitbox.setScale(1.04899, 1.04899);
	treee[37].sprite.setScale(1.04899, 1.04899);
	treee[38].sprite.setPosition(9679.46, 8007.73);
	treee[38].hitbox.setScale(1.04899, 1.04899);
	treee[38].sprite.setScale(1.04899, 1.04899);
	treee[39].sprite.setPosition(10085.9, 8007.8);
	treee[39].hitbox.setScale(1.04899, 1.04899);
	treee[39].sprite.setScale(1.04899, 1.04899);
	treee[40].sprite.setPosition(10492.3, 8007.83);
	treee[40].hitbox.setScale(1.04899, 1.04899);
	treee[40].sprite.setScale(1.04899, 1.04899);
	treee[41].sprite.setPosition(10894.7, 8011.9);
	treee[41].hitbox.setScale(1.04899, 1.04899);
	treee[41].sprite.setScale(1.04899, 1.04899);
	treee[42].sprite.setPosition(11309.2, 8009.94);
	treee[42].hitbox.setScale(1.04899, 1.04899);
	treee[42].sprite.setScale(1.04899, 1.04899);
	treee[43].sprite.setPosition(11707.6, 8015.95);
	treee[43].hitbox.setScale(1.04899, 1.04899);
	treee[43].sprite.setScale(1.04899, 1.04899);
	treee[44].sprite.setPosition(12118.1, 8016.0);
	treee[44].hitbox.setScale(1.04899, 1.04899);
	treee[44].sprite.setScale(1.04899, 1.04899);
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
	treee[56].sprite.setScale(1.04899, 1.04899);
	treee[56].hitbox.setScale(1.04899, 1.04899);
	treee[57].sprite.setPosition(13306.4, 5265.31);
	treee[57].hitbox.setScale(1.04899, 1.04899);
	treee[57].sprite.setScale(1.04899, 1.04899);
	treee[58].sprite.setPosition(13688.8, 5265.38);
	treee[58].hitbox.setScale(1.04899, 1.04899);
	treee[58].sprite.setScale(1.04899, 1.04899);
	treee[59].sprite.setPosition(14083.2, 5265.4);
	treee[59].hitbox.setScale(1.04899, 1.04899);
	treee[59].sprite.setScale(1.04899, 1.04899);
	treee[60].sprite.setPosition(14485.6, 5269.48);
	treee[60].hitbox.setScale(1.04899, 1.04899);
	treee[60].sprite.setScale(1.04899, 1.04899);
	treee[61].sprite.setPosition(14886.1, 5265.53);
	treee[61].hitbox.setScale(1.04899, 1.04899);
	treee[61].sprite.setScale(1.04899, 1.04899);
	treee[62].sprite.setPosition(15272.5, 5265.55);
	treee[62].hitbox.setScale(1.04899, 1.04899);
	treee[62].sprite.setScale(1.04899, 1.04899);
	treee[63].sprite.setPosition(15678.9, 5265.62);
	treee[63].hitbox.setScale(1.04899, 1.04899);
	treee[63].sprite.setScale(1.04899, 1.04899);
	treee[64].sprite.setPosition(16085.3, 5265.65);
	treee[64].hitbox.setScale(1.04899, 1.04899);
	treee[64].sprite.setScale(1.04899, 1.04899);
	treee[65].sprite.setPosition(16487.7, 5269.72);
	treee[65].hitbox.setScale(1.04899, 1.04899);
	treee[65].sprite.setScale(1.04899, 1.04899);
	treee[66].sprite.setPosition(16902.2, 5267.76);
	treee[66].hitbox.setScale(1.04899, 1.04899);
	treee[66].sprite.setScale(1.04899, 1.04899);
	treee[67].sprite.setPosition(17300.6, 5273.77);
	treee[67].hitbox.setScale(1.04899, 1.04899);
	treee[67].sprite.setScale(1.04899, 1.04899);
	treee[68].sprite.setPosition(17711.1, 5273.82);
	treee[68].hitbox.setScale(1.04899, 1.04899);
	treee[68].sprite.setScale(1.04899, 1.04899);
	treee[69].sprite.setPosition(18118.0, 5289.28);
	treee[69].hitbox.setScale(1.04899, 1.04899);
	treee[69].sprite.setScale(1.04899, 1.04899);
	treee[70].sprite.setPosition(18512.4, 5297.31);
	treee[70].hitbox.setScale(1.04899, 1.04899);
	treee[70].sprite.setScale(1.04899, 1.04899);
	treee[71].sprite.setPosition(18926.8, 5293.38);
	treee[71].hitbox.setScale(1.04899, 1.04899);
	treee[71].sprite.setScale(1.04899, 1.04899);
	treee[72].sprite.setPosition(19348.2, 5297.4);
	treee[72].hitbox.setScale(1.04899, 1.04899);
	treee[72].sprite.setScale(1.04899, 1.04899);
	treee1.intialize(tree_1);
	treee1.sprite.setPosition(13400.0, 4200.0);
	treee1.sprite.setScale(2.26,2.2);
	treee1.hitbox.setScale(2.26, 2.2);
	treee2.intialize(tree_2);
	treee2.sprite.setPosition(13536.0, 1968.0);
	treee2.sprite.setScale(1.3,1.35);
	treee2.hitbox.setScale(1.3, 1.35);
	for (int i = 0; i < 9; i++)
	{
		treee3[i].intialize(tree_3);
	}
	treee3[0].sprite.setPosition(14708.0, 1186.0);
	treee3[0].sprite.setScale(0.55, 0.57);
	treee3[0].hitbox.setScale(0.55, 0.57);

	treee3[1].sprite.setPosition(16700.0, 3342.0);
	treee3[1].sprite.setScale(0.55, 0.57);
	treee3[1].hitbox.setScale(0.55, 0.57);
	treee3[2].sprite.setPosition(16760.0, 3582);
	treee3[2].sprite.setScale(0.55, 0.57);
	treee3[2].hitbox.setScale(0.55, 0.57);
	treee3[3].sprite.setPosition(16758, 3852.0);
	treee3[3].sprite.setScale(0.55, 0.57);
	treee3[3].hitbox.setScale(0.55, 0.57);

	treee3[4].sprite.setPosition(17442, 4252);

	treee3[5].sprite.setPosition(18718.0, 1872);

	treee3[6].sprite.setPosition(17822, 992.0);

	treee3[7].sprite.setPosition(1516.06, 11256.1);

	treee3[8].sprite.setPosition(1367.58, 11874.2);


}
void game_input_once() {
	// This function is no longer used - pause input is handled in Main.cpp inside the event loop
	// and NPC interaction input is called directly from Main.cpp after the event loop
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
	Hare.update(0);
	Hare.interaction_box.setPosition(Hare.sprite.getPosition().x -20 + Hare.sprite.getGlobalBounds().width / 2, Hare.sprite.getPosition().y + Hare.sprite.getGlobalBounds().height / 2+30);
	Hare1.update(200);
	Hare1.interaction_box.setPosition(Hare1.sprite.getPosition().x -20 + Hare1.sprite.getGlobalBounds().width / 2, Hare1.sprite.getPosition().y + Hare1.sprite.getGlobalBounds().height / 2+30);
	Deer.update(0);
	Deer.interaction_box.setPosition(Deer.sprite.getPosition().x -20 + Deer.sprite.getGlobalBounds().width / 2, Deer.sprite.getPosition().y + Deer.sprite.getGlobalBounds().height / 2+30);
	Deer1.update(300);
	Deer1.interaction_box.setPosition(Deer1.sprite.getPosition().x -20 + Deer1.sprite.getGlobalBounds().width / 2, Deer1.sprite.getPosition().y + Deer1.sprite.getGlobalBounds().height / 2+30);
	Boar.update(0,200,200);
	Boar.interaction_box.setPosition(Boar.sprite.getPosition().x -20 + Boar.sprite.getGlobalBounds().width / 2, Boar.sprite.getPosition().y + Boar.sprite.getGlobalBounds().height / 2+30);
	//Boar.interaction_box.setPosition(3874, 3180  );قولتلي 
	Black_grouse.update(0);
	Black_grouse.interaction_box.setPosition(Black_grouse.sprite.getPosition().x -20 + Black_grouse.sprite.getGlobalBounds().width / 2, Black_grouse.sprite.getPosition().y + Black_grouse.sprite.getGlobalBounds().height / 2);
	Black_grouse1.update(100);
	Black_grouse1.interaction_box.setPosition(Black_grouse1.sprite.getPosition().x -20 + Black_grouse1.sprite.getGlobalBounds().width / 2, Black_grouse1.sprite.getPosition().y + Black_grouse1.sprite.getGlobalBounds().height / 2);
	Black_grouse2.update(200);
	Black_grouse2.interaction_box.setPosition(Black_grouse2.sprite.getPosition().x -20 + Black_grouse2.sprite.getGlobalBounds().width / 2, Black_grouse2.sprite.getPosition().y + Black_grouse2.sprite.getGlobalBounds().height / 2);
	Black_grouse3.update(300);
	Black_grouse3.interaction_box.setPosition(Black_grouse3.sprite.getPosition().x -20 + Black_grouse3.sprite.getGlobalBounds().width / 2, Black_grouse3.sprite.getPosition().y + Black_grouse3.sprite.getGlobalBounds().height / 2);

}
void game_draw() {
	window.setView(camera);
	window.draw(Game_Background_Sprite);
	window.draw(Fox);
	window.draw(Fox_hitbox);
	Hare1.draw();
	Hare.draw();
	Deer1.draw();
	Deer.draw();
	Boar.draw();
	Black_grouse.draw();
	Black_grouse1.draw();
	Black_grouse2.draw();
	Black_grouse3.draw();

	
}