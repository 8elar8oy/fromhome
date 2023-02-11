#pragma once
#include "SFML/Graphics.hpp"
#include "windows.h"
#include "Road.h"
#include "Player.h"
#include "obstacle.h"

using namespace sf;
void checkEvents(RenderWindow& window) {
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
	}
}

void updateGame(Surface& Grass1, Surface& Grass2, Surface& Sand1, Surface& Sand2, Surface& Road1, Surface& Road2, Player& player,Box& box,Box& box1,Box& box2) {
	playerUpdate(player);
	SurfaceUpdate(Grass1, Grass2);
	SurfaceUpdate(Sand1, Sand2);
	SurfaceUpdate(Road1, Road2);
	srand(time(nullptr));
	int i = rand() % 4;
	int j = rand() % 4;
	int l = rand() % 4;
	while ((j == i) || (j == l) || (i == l)) {
		i = rand() % 4;
		j = rand() % 4;
		l = rand() % 4;
	}
	BoxUpdate(box,i);
	BoxUpdate(box1,j);
	BoxUpdate(box2, l);


}
void checkCollisions() {


}
void drawGame(RenderWindow& window, Surface& road, Surface& road1, Surface& sand, Surface& sand1, Surface& grass, Surface& grass1, Player& player,Box& box,Box& box1,Box& box2) {
	window.clear();
	SurfaceDraw(window, grass, grass1);
	SurfaceDraw(window, sand, sand1);
	SurfaceDraw(window, road, road1);
	playerDraw(window, player);
	BoxDraw(window, box);
	BoxDraw(window, box1);
	BoxDraw(window, box2);
	window.display();
}
