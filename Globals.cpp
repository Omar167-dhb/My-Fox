
class Typewriter {
private:
	std::string fullText;
	std::string displayedText;
	sf::Clock clock;
	float delay;
	int currentLength;

public:
	sf::Text text;
	Typewriter(sf::Font& font, float delayTime = 0.05f) {
		delay = delayTime;
		currentLength = 0;
		text.setFont(font);
		text.setCharacterSize(50);
		text.setFillColor(sf::Color::Black);
		//text.setPosition(50, 300);
	}

	// هنا تقدر تغير النص وقت ما تحب
	void setText(const std::string& str) {
		fullText = str;
		displayedText.clear();
		currentLength = 0;
		text.setString("");
		clock.restart();
	}

	void update() {
		if (clock.getElapsedTime().asSeconds() > delay && currentLength < fullText.size()) {
			currentLength++;
			displayedText = fullText.substr(0, currentLength);
			text.setString(displayedText);
			clock.restart();
		}
	}
	void reset() {
		currentLength = 0;
		displayedText.clear();
		text.setString("");
		clock.restart();
	}

	void draw(sf::RenderWindow& window) {
		window.draw(text);
	}

}; enum game_state
{
	Main_menu,
	Playing,
	Paused,
	Settings,
	How_to_play,
	credits,
};
enum last_direction
{
	Right,
	Left,
	Up,
	Down
};
enum Fox_state
{
	Idle,
	Walking,
	Running,
	
};
//the window
int window_w = 1920;
int window_h = 1080;
sf::RenderWindow window = { sf::VideoMode::getDesktopMode(), " My Fox ^^)" };

//font to use in the game
sf::Font font;
// NPC font
sf::Font font1;
// texts to use in the game menus

std::vector<sf::Text> Main_Menu_texts(5);
std::vector<sf::Text> Settings_texts(3);
std::vector<sf::Text> Settings_texts1(3);
std::vector<sf::Text> Pause_text(3);

// Exit for ESC button
sf::Text Exit_text{"EXIT",font,50};
// the + , - buttons in the settings menu
std::vector<sf::Text> Inc_Dec(6);
// How to play and credits texts
std::vector<sf::Text> credits_text(2);
std::vector<sf::Text> How_to_play_texts(6);
//boolean to check if the game is in fullscreen or not
bool isfullscreen = true;
// to handle window
game_state state = Main_menu;
game_state last_state = Main_menu;
// to handle the window size
sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
// counters to handle menus with mouse and keyboard
int Main_Menu_counter_key = 0, Main_Menu_counter_mouse = 0, Inc_counter = 0, Pause_counter_key = 0, Pause_counter_mouse = 0;
//mouse position to handle the mouse input
sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
//event to handle the input
sf::Event event;
// to handle the volume of the game
int Main_volume = 100, Music_volume = 100, Sound_volume = 100;
// to save the last volume of the game to use it in the settings menu
int music_temp = 100, sound_temp = 100;
// texture and sprite for the fox (MC)
sf::Texture Fox_walking, Fox_running, Fox_idle;
sf::Sprite Fox;
// hitbox for the fox to handle collisions
sf::RectangleShape Fox_hitbox;
// counters and timers for the fox's animation states
int Fox_Idle_counter(0), Fox_Walking_counter(0), Fox_Running_counter(0);
float Fox_walking_timer = 0, Fox_running_timer = 0, Fox_idle_timer = 0;
// current state and direction of the fox
Fox_state fox_status = Idle;
last_direction fox_direction = Right;
// clock to track delta time for movement and animation
sf::Clock clock1;
// Track previous animation state to reset timers/counters on transition
Fox_state previous_fox_status = Idle;
// camera and views for different game states
sf::View camera,main_menu_cam(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y)), Pause_cam(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
// delta time for frame-independent movement and animation
double Delta_time;
// textures and sprites for backgrounds
sf::Texture Main_Menu_Background, Game_Background[4];
sf::Sprite Main_Menu_Background_Sprite, Game_Background_Sprite[4];
sf::Texture secondary_background_texture;
sf::Sprite secondary_background_sprite;
// dimensions and frame counts for fox animations
int idle_total_width;
int idle_total_hight;
int idle_framecount = 4;
int Fox_yoffset[4] = { 96,64,32,0 };
int Fox_yoffset_run[4] = { 64,96,32,0 };
int walking_total_width;
int walking_total_hight;
int walking_framecount = 6;

int running_total_width;
int running_total_hight;
int running_framecount = 6;
// base speed and current speed of the fox
int Fox_base_speed = 200;
int Fox_speed = 200;
// textures & sprites of the animated animals in the game (NPCs)
sf::Texture Hare_texture, Deer_texture, Boar_texture, Black_grouse_texture;
sf::Sprite Hare_sprite[2], Deer_sprite[2], Boar_sprite, Black_grouse_sprite[4];
// textures & sprites of the animated objects in the game
sf::Texture Sakura_texture, Camp_fire_1_texture, Camp_fire_2_texture, Flag_texture;
//sf::Sprite Sakura_sprite, Camp_fire_1_sprite, Camp_fire_2_sprite, Flag_sprite;
// textures & sprites of the animated keys in the game menus
sf::Texture W_texture[2], A_texture[2], S_texture[2], D_texture[2], Shift_texture[2], E_texture[2], Esc_texture[2], P_texture[2];
sf::Sprite W_sprite, A_sprite, S_sprite, D_sprite, Shift_sprite, E_sprite, Esc_sprite, Esc_sprite1, P_sprite;

// counters for keyboard animations in the menus
int keyboard_count = 0;
// timers for keyboard animations in the menus
float Esc_sprite_timer = 0, Esc1_sprite_timer = 0, W_sprite_timer = 0, A_sprite_timer = 0, S_sprite_timer = 0, D_sprite_timer = 0, Shift_sprite_timer = 0, E_sprite_timer = 0, P_sprite_timer = 0;

// background texture and sprite for text display
sf::Texture text_background_texture;
sf::Sprite text_background_sprite;
//Texures for rest of the game objects
Texture anvel, fence, parallel_fence, box, lake, well, car, light, fallen_light, broken_light, House, House_1, House_2, House_3, tent, tent_1, Tent_2, Tent_3;
Texture tree, tree_1, tree_2, tree_3, broken_tree, broken_tree_1, broken_tree_2, broken_tree_3, broken_tree_4, broken_tree_5, broken_tree_6, Autumn_tree, Autumn_tree_1, Autumn_tree_2, christmas_tree, Mossy_tree, Mossy_tree_1, Mossy_tree_2, fruit_tree, fruit_tree_1, Burned_tree2;

SoundBuffer water, walk, menu, play, felos, meme,getout;
Sound grass, Goo2, Main, game, money, alawey,out;

// Forward declarations
void menu_intialization();
void menu_update(game_state& state);
void menu_Input(sf::Event& event, sf::Vector2i mouse_pos);
void menu_draw();
void set_Static_animition(Texture texture[], int& counter, Sprite& sprite, int framecount, float& timer);
void How_to_play_menu_update();
void game_input_once();
void game_update();
void game_draw();
void game_intialization();
void intializing_textures();
void sound_init();
void typewriterEffect(sf::RenderWindow& window, const std::string& fullText, sf::Font& font, float delay = 0.05f) {
	sf::Text text("", font, 30);
	text.setFillColor(sf::Color::White);
	text.setPosition(50, 300);

	sf::Clock clock;
	int currentLength = 0;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// نزود حرف كل فترة زمنية
		if (clock.getElapsedTime().asSeconds() > delay && currentLength < fullText.size()) {
			currentLength++;
			text.setString(fullText.substr(0, currentLength));
			clock.restart();
		}

		window.clear();
		window.draw(text);
		window.display();
	}
}
void sound_update();
void intializing()
{
	// Set the camera size to be larger than the desktop resolution for a wider view
	camera.setSize(desktop.width + 1000, desktop.height + 1000);
	//camera.setSize(20000, 12000);
	// Create the window in fullscreen mode with the desktop resolution
	window.create(desktop, " My Fox ^^)", sf::Style::Fullscreen);
	menu_intialization();
	intializing_textures();
	game_intialization();
	sound_init();
}

void update()
{
	switch (state)
	{
	case Main_menu:
		break;
	case Playing:
		
		game_update();
		break;
	case Paused:
		set_Static_animition(Esc_texture, keyboard_count, Esc_sprite, 2, Esc_sprite_timer);
		break;
	case Settings:
		sound_update();
		set_Static_animition(Esc_texture, keyboard_count, Esc_sprite, 2, Esc_sprite_timer);
		// Update the settings text to reflect current volume levels
		Settings_texts1[0].setString(to_string(Main_volume));
		Settings_texts1[1].setString(to_string(sound_temp));
		Settings_texts1[2].setString(to_string(music_temp));

		break;
	case How_to_play:
		How_to_play_menu_update();
		break;
	case credits:
		set_Static_animition(Esc_texture, keyboard_count, Esc_sprite, 2, Esc_sprite_timer);

		break;
	default:
		break;
	}
}
void draw(game_state state)
{

	switch (state)
	{
	case Main_menu:
		window.setView(main_menu_cam);
		window.draw(Main_Menu_Background_Sprite);
		for (const auto& x : Main_Menu_texts)
		{
			window.draw(x);
		}
		break;
	case Playing:
		game_draw();
		break;
	case Paused:
		window.draw(secondary_background_sprite);
		window.setView(Pause_cam);
		for (auto& x : Pause_text)
		{
			window.draw(x);
		}
		window.draw(Esc_sprite);
		window.draw(Exit_text);

		break;
	case Settings:
		window.setView(main_menu_cam);
		window.draw(secondary_background_sprite);
		for (int i = 0; i < 3; i++)
		{
			window.draw(Settings_texts[i]);
			window.draw(Settings_texts1[i]);
		}
		for (auto& x : Inc_Dec)
			window.draw(x);
		window.draw(Esc_sprite);
		window.draw(Exit_text);
		break;
	case How_to_play:
		window.setView(main_menu_cam);
		window.draw(secondary_background_sprite);
		for (auto& x : How_to_play_texts)
			window.draw(x);
		window.draw(Esc_sprite);
		window.draw(Exit_text);
		window.draw(W_sprite);
		window.draw(A_sprite);
		window.draw(S_sprite);
		window.draw(D_sprite);
		window.draw(Shift_sprite);
		window.draw(E_sprite);
		window.draw(P_sprite);
		window.draw(Esc_sprite1);
		break;
	case credits:
		window.setView(main_menu_cam);
		window.draw(secondary_background_sprite);
		for (auto& x : credits_text)
			window.draw(x);
		window.draw(Esc_sprite);
		window.draw(Exit_text);
		break;
	default:
		break;
	}

}   