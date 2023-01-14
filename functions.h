#pragma once
#include "SFML/Graphics.hpp"
#include "Bat.h"
#include "Ball.h"
#include "windows.h"

using namespace sf;
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
void initScore(Text& Text1, int count, Font& font, const sf::Vector2f textStartPos) {
	font.loadFromFile("ds-digib.ttf");
	Text1.setString(std::to_string(count));
	Text1.setFont(font);
	Text1.setCharacterSize(charSize);
	Text1.setPosition(textStartPos);
	

}
void initText(Text& Text1, std::string str, Font& font, const sf::Vector2f textStartPos) {
	font.loadFromFile("ds-digib.ttf");
	Text1.setString(str);
	Text1.setFont(font);
	Text1.setCharacterSize(charSize);
	Text1.setPosition(textStartPos);


}
void updateScore() {
}
void updateHealth() {
}





//обновление позиции обьектов
void updateGame(Bat& bat, Ball& ball) {

	controlBat(bat);
	moveBall(ball);

}

void checkCollisions(Ball& ball, Bat& bat) {
	ballReboundEdges(ball);
	batReboundEdges(bat);
	ballReboundBat(ball, bat);

}
//отрисовка обьектов
void drawGame(sf::RenderWindow& window, Bat bat, Ball ball, Text scoreText, Text healthText,Text Text1,Text Text2) {
	window.clear(sf::Color::Cyan);
	window.draw(bat.shape);
	window.draw(ball.shape);
	window.draw(scoreText);
	window.draw(healthText);
	window.display();
}