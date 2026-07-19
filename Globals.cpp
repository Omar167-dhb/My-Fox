
// Forward declarations
void menu_intialization();
void menu_Input(sf::Event& event, sf::Vector2i mouse_pos);
void menu_Update();
void menu_draw();
void game_input_once();
void game_update();
void game_draw();
void intializing_textures();

enum game_state
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
int window_w = 1920;
int window_h = 1080;
//the window
sf::RenderWindow window = { sf::VideoMode::getDesktopMode(), " My Fox ^^)" };
//Variables until arrange it
sf::RectangleShape Fox_hitbox;
sf::Texture Main_Menu_Background, Game_Background;
sf::Sprite Main_Menu_Background_Sprite, Game_Background_Sprite;
sf::Font font;
std::vector<sf::Text> Main_Menu_texts(5);
std::vector<sf::Text> Settings_texts(3);
std::vector<sf::Text> Settings_texts1(3);
std::vector<sf::Text> Pause_text(3);
std::vector<sf::Text> Inc_Dec(6);
bool isfullscreen = true;
game_state state = Main_menu;
game_state last_state = Main_menu;
sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
int Main_Menu_counter_key = 0, Main_Menu_counter_mouse = 0, Inc_counter = 0, Pause_counter_key = 0, Pause_counter_mouse = 0;
sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
sf::Event event;

int Main_volume = 100, Music_volume = 100, Sound_volume = 100;
int music_temp = 100, sound_temp = 100;
sf::Texture Fox_walking, Fox_running, Fox_idle;
sf::Sprite Fox;
int Fox_Idle_counter(0), Fox_Walking_counter(0), Fox_Running_counter(0);
Fox_state fox_status = Idle;
last_direction fox_direction = Right;
sf::Clock clock1;

// Track previous animation state to reset timers/counters on transition
Fox_state previous_fox_status = Idle;
sf::View camera;
double Delta_time;
float Fox_walking_timer = 0, Fox_running_timer = 0, Fox_idle_timer = 0;


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

int Fox_base_speed = 200;
int Fox_speed = 200;

void intializing()
{
	camera.setSize(desktop.width, desktop.height);
	window.create(desktop, " My Fox ^^)", sf::Style::Fullscreen);
	menu_intialization();
	intializing_textures();
}
void Input(sf::Event& event, sf::Vector2i mouse_pos)
{
	menu_Input(event, mouse_pos);
	game_input_once();
}
void update()
{
	menu_Update();
	game_update();
}
void draw()
{
	window.clear();
	menu_draw();
	game_draw();
	window.display();
}