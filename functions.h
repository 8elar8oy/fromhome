#pragma once
#include "SFML/Graphics.hpp"
#include "Bat.h"
#include "Ball.h"
#include "Text.h"
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
void initText(Text& Text1,int count,Font& font, const int charSize, const Vector2f textStartPos) {
		/*const int charSize = 64;*/
	Text1.setString(std::to_string(count));
	Text1.setFont(font);
	Text1.setCharacterSize(charSize);
	Text1.setPosition(textStartPos);	
	font.loadFromFile("ds-digib.ttf");

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
void drawGame(sf::RenderWindow& window, Bat bat, Ball ball,TextText score,TextText lives ) {
	window.clear(sf::Color::Cyan);
	window.draw(bat.shape);
	window.draw(ball.shape);
	window.draw(score.text);
	window.draw(lives.text);
	window.display();
}