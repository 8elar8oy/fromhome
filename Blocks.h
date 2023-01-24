#pragma once
#include "settings.h"
using namespace sf;
struct Block {
	RectangleShape shape;
	Color color;
	Vector2f position;
	
};



void initBlock(Block& block,Color& color, Vector2f& position) {
	
	block.color = color;
	block.position = position;
	block.shape.setSize(BLOCK_SIZE);
	block.shape.setFillColor(block.color);
	block.shape.setOutlineThickness(1);
	block.shape.setOutlineColor(Color::Black);
	block.shape.setPosition(block.position);

}

void updateBlock(Block& block) {

}
void drawBlock(RenderWindow& window, Block& block) {
	
	window.draw(block.shape);
}
	