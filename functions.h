#pragma once
#include "SFML/Graphics.hpp"
#include "bat.h"
#include "ball.h"
#include "Text.h"
#include "windows.h"
#include "Blocks.h"
#include "BlockRow.h"
#include "BlockField.h"
using namespace sf;
//основная функция
void checkEvents(RenderWindow& window) {
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
	}
	//создание ракетки
}
//обновление позиции обьектов
void updateGame(Bat& bat, Ball& ball, BlockField blockfield, Text& healthText) {
	controlBat(bat);
	moveBall(ball);
	blockFieldUpdate(blockfield);
	checkLives(health);
	updateScore(ball, healthText);
}
void checkCollisions(Ball& ball, Bat& bat, Text& HealthText) {
	ballReboundEdges(ball, HealthText);
	batReboundEdges(bat);
	ballReboundBat(ball, bat);

}
//отрисовка обьектов
void drawGame(RenderWindow& window, Bat& bat, Ball& ball, BlockField& blockfield, Text& scoreText, Text& healthText, Text Text1,Text Text2) {
	window.clear(sf::Color::Cyan);
	BlockFieldDraw(window, blockfield);
	DrawBat(window, bat);
	window.draw(ball.shape);
	drawScore(window, scoreText);
	drawLives(window, healthText);
	drawText1(window, Text1);
	drawText2(window, Text2);
	window.display();
}