
#pragma once
#include "settings.h"
using namespace sf;
struct Block {
	RectangleShape shape;

};
void initBlock(Block& block, sf::Color BLOCK_COLOR, sf::Vector2f BLOCK_START_POS) {
	block.shape.setSize(BLOCK_SIZE);
	block.shape.setFillColor(BLOCK_COLOR);
	block.shape.setPosition(BLOCK_START_POS);
}
void updateBlock(Block& block) {
	
}
void drawBlock(Block& block) {
	
}
