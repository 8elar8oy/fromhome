#pragma once
#pragma once
#include "settings.h"
#include "Blocks.h"
#include "BlockRow.h"
using namespace sf;
struct BlockField {
	Block field[8][20];


};
void InitBlockField(BlockField& blockField, int columns,int rows, Vector2f& position, float stepX) {
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			
			sf::Color color{ BLOCKS_COLOR[i/2] };
		
		
			sf::Vector2f blockPos{ position.x + i * stepX,position.y };
			initBlock(blockField.field[i][j], BLOCKS_COLOR[i/2], blockPos);
		}
		
	}

}
void blockFieldUpdate(BlockField& blockfield, int columns, int rows) {
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			updateBlock(blockfield.field[i][j]);

			
		}

	}
}
void BlockFieldDraw(RenderWindow& window, BlockField& blockfield, int columns, int rows) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			
			window.draw(blockfield.field[i][j].shape);

		}

	}
	
}