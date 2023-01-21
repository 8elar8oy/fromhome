#pragma once
#include "settings.h"
using namespace sf;
struct Block {
	RectangleShape shape;
	Color color;
	Vector2f position;
	
};
struct BlockRow {
	Block arr[10];
	int size;

};

void BlockInit(BlockRow& blockRow,int size,Color& color, Vector2f& position,float stepX) {
	blockRow.size = size;
	for (int i = 0; i < blockRow.size; i++)
	{
		sf::Color color{ (sf::Uint8)(25 * i),100,100 };
		sf::Vector2f blockPos{ position.x + i * stepX,position.y };
		initBlock(blockRow.arr[i],color,blockPos);
	}
	
}
void initBlock(Block& block,Color& color, Vector2f& position) {
	
	block.color = color;
	block.position = position;
	block.shape.setSize(BLOCK_SIZE);
	block.shape.setFillColor(block.color);
	block.shape.setPosition(block.position);

}

void updateBlock(Block& block) {

}
void drawBlock(RenderWindow& window, Block& block) {
	
	window.draw(block.shape);
}
	