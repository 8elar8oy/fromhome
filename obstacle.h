#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
struct Box {
	Texture texture;
	Sprite sprite;
};
void BoxInit(Box& box, Vector2f boxPos, std::string filename) {
	box.texture.loadFromFile(filename);
	box.sprite.setTexture(box.texture);
	box.sprite.setPosition(boxPos);
	
}
void BoxDraw(RenderWindow& window, Box& box) {
	window.draw(box.sprite);
	
}
void BoxUpdate(Box& box,int i) {
	box.sprite.move(0.f, ROAD_LAYER_SPEED);
	
	
	if (box.sprite.getPosition().y >= WINDOW_HEIGHT)
	{
		srand(time(nullptr));
		//int i = rand() % 4;
		box.sprite.setPosition(pos_arr[i]);
	}
	
}
