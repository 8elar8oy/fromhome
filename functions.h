

#pragma once
#include "SFML/Graphics.hpp"
#include "Bat.h"
#include "Ball.h"
#include "Text.h"
#include "windows.h"
#include "Blocks.h"


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
void updateGame(Bat& bat, Ball& ball, sf::Text& healthText) {

	controlBat(bat);
	moveBall(ball);
	checkLives(health);
	updateScore(ball, healthText);

}

void checkCollisions(Ball& ball, Bat& bat, sf::Text& HealthText) {
	ballReboundEdges(ball, HealthText);
	batReboundEdges(bat);
	ballReboundBat(ball, bat);

}
//отрисовка обьектов
void drawGame(sf::RenderWindow& window, Bat& bat, Ball& ball, sf::Text& scoreText, sf::Text& healthText, sf::Text Text1, sf::Text Text2, BlockRow& blockrow,Block& block) {
	window.clear(sf::Color::Cyan);
	window.draw(bat.shape);
	window.draw(ball.shape);
	window.draw(scoreText);
	window.draw(healthText);
	window.draw(Text1);
	window.draw(Text2);
	drawBlock(window, blockrow);
	window.display();
}