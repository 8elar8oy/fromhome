#include <SFML/Graphics.hpp>
#include "settings.h"
#include "functions.h"
#include "Road.h"
#include "Player.h"
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);
	window.setPosition(Vector2i{ (1920 - (int)WINDOW_WIDTH) / 2, 0 });
	Surface road, road1, sand, sand1, grass, grass1;
	SurfaceInit(grass, Vector2f{ 0.f, 0.f }, "grass1.jpg", 0.f);
	SurfaceInit(grass1, Vector2f{ 0.f, -WINDOW_HEIGHT }, "grass1.jpg", 0.f);
	SurfaceInit(sand, Vector2f{ 50.f, 0.f }, "sand1.jpg", 50.f);
	SurfaceInit(sand1, Vector2f{ 50.f, -WINDOW_HEIGHT }, "sand1.jpg", 50.f);
	SurfaceInit(road, Vector2f{ 100.f,0.f }, "road1.jpg", 100.f);
	SurfaceInit(road1, Vector2f{ 100.f, -WINDOW_HEIGHT }, "road1.jpg", 100.f);
	Player player;
	playerInit(player, PLAYER_START_POS, "carpng.png");
	Box box,box1,box2;
	srand(time(nullptr));
	int i = rand() % 4;
	int j = rand() % 4;
	int l = rand() % 4;
	while ((j == i) || (j==l) || (i==l)) {
		i = rand() % 4;
		j = rand() % 4;
		l = rand() % 4;
	}
	BoxInit(box,pos_arr[i],texture_arr[i]);
	BoxInit(box1, pos_arr1[j], texture_arr[j]);
	BoxInit(box2, pos_arr2[l], texture_arr[l]);
	while (window.isOpen())
	{
		checkEvents(window);
		updateGame(road, sand, grass, road1, sand1, grass1, player,box,box1,box2);

		/*checkCollisions();*/
		drawGame(window, road, road1, sand, sand1, grass, grass1, player,box,box1,box2);
	}
	return 0;
}