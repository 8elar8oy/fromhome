
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
void initScore(sf::Text& Text1, int count, sf::Font& font, const sf::Vector2f textStartPos) {
	font.loadFromFile("ds-digib.ttf");
	Text1.setString(std::to_string(count));
	Text1.setFont(font);
	Text1.setCharacterSize(charSize);
	Text1.setPosition(textStartPos);


}
void initText(sf::Text& Text1, std::string str, sf::Font& font, const sf::Vector2f textStartPos) {
	font.loadFromFile("ds-digib.ttf");
	Text1.setString(str);
	Text1.setFont(font);
	Text1.setCharacterSize(charSize);
	Text1.setPosition(textStartPos);


}
void updateScore(Ball& ball, Text& healthText) {
	if (ball.shape.getPosition().y >= (WINDOW_HEIGHT - 2 * BALL_RADIUS)) {

		health = health - 1;
		healthText.setString(std::to_string(health));
		ball.shape.setPosition(BALL_START_POS);
		ball.speedx = 0;
		ball.speedy = 0;

	}
}
//обновление позиции обьектов
void updateGame(Bat& bat, Ball& ball, sf::Text& healthText/*,Block block*/) {

	controlBat(bat);
	moveBall(ball);
	checkLives(health);
	updateScore(ball, healthText);
	//updateBlock(block);

}

void checkCollisions(Ball& ball, Bat& bat, sf::Text& HealthText) {
	ballReboundEdges(ball, HealthText);
	batReboundEdges(bat);
	ballReboundBat(ball, bat);

}
//отрисовка обьектов
void drawGame(sf::RenderWindow& window, Bat& bat, Ball& ball, sf::Text& scoreText, sf::Text& healthText, sf::Text Text1, sf::Text Text2,Block& block) {
	window.clear(sf::Color::Cyan);
	window.draw(bat.shape);
	window.draw(ball.shape);
	window.draw(scoreText);
	window.draw(healthText);
	window.draw(Text1);
	window.draw(Text2);
	drawBlock(window, block);
	
	window.display();
}