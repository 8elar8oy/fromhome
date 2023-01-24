#pragma once
#include "settings.h"
#include "Blocks.h"

using namespace sf;
struct BlockRow {
	Block arr[20];
	int size;

};

void InitBlockRow(BlockRow& blockRow, int size, Vector2f& position, float stepX) {
	blockRow.size = size;
	for (int i = 0; i < blockRow.size; i++)
	{
				sf::Color color{ (sf::Uint8)(240),0,0 };
				sf::Vector2f blockPos{ position.x + i * stepX,position.y};
				initBlock(blockRow.arr[i], color, blockPos);
	}

}
void blockRowUpdate(BlockRow& blockrow) {
	for (int i = 0; i < blockrow.size; i++)
	{
			updateBlock(blockrow.arr[i]);
	}
}
void BlockRowDraw(RenderWindow& window, BlockRow& blockrow) {
	for (int i = 0; i < blockrow.size; i++)
	{
		window.draw(blockrow.arr[i].shape);
	
	}
}