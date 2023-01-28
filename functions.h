#pragma once
#include "SFML/Graphics.hpp"
#include "Bat.h"
#include "Ball.h"
#include "Text.h"
#include "windows.h"
#include "Blocks.h"
#include "BlockRow.h"
#include "BlockField.h"
//основная функция
void checkEvents(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
	//создание ракетки
}
//обновление позиции обьектов
void updateGame(Bat& bat, Ball& ball, BlockField blockfield, sf::Text& healthText) {
	controlBat(bat);
	moveBall(ball);
	blockFieldUpdate(blockfield);
	checkLives(health);
	updateScore(ball, healthText);
}
void checkCollisions(Ball& ball, Bat& bat, sf::Text& HealthText) {
	ballReboundEdges(ball, HealthText);
	batReboundEdges(bat);
	ballReboundBat(ball, bat);

}
//отрисовка обьектов
void drawGame(sf::RenderWindow& window, Bat& bat, Ball& ball, BlockField& blockfield, sf::Text& scoreText, sf::Text& healthText, sf::Text Text1, sf::Text Text2) {
	window.clear(sf::Color::Cyan);
	BlockFieldDraw(window, blockfield);
	drawBat(window,bat);
	window.draw(ball.shape);
	drawScore(window, scoreText);
	drawLives(window, healthText);
	drawText1(window, Text1);
	drawText2( window, Text2);
	window.display();
}