#pragma once
#include "settings.h"
#include "Blocks.h"

using namespace sf;
struct BlockField {
	Block field[8][20];
};
void InitBlockField(BlockField& blockField) {
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			sf::Color color{ BLOCKS_COLOR[i / 2] };
			sf::Vector2f blockPos{ BLOCK_START_POS.x + j * stepX,BLOCK_START_POS.y + i * stepY };
			initBlock(blockField.field[i][j], BLOCKS_COLOR[i / 2], blockPos);
		}
	}
}
void blockFieldUpdate(BlockField& blockfield) {
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			updateBlock(blockfield.field[i][j]);
		}
	}
}
void drawBlockField(RenderWindow& window, BlockField& blockfield) {
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			window.draw(blockfield.field[i][j].shape);
		}
	}
}

