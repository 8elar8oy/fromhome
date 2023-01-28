#pragma once
#include "windows.h"
#include "settings.h"
using namespace sf;
void checkLives(int& health) {
	if (health == 0) {
		exit(0);
	}
}
void initScore(sf::Text& Text1, int count, sf::Font& font, const sf::Vector2f textStartPos) {
	font.loadFromFile("ds-digib.ttf");
	Text1.setString(std::to_string(count));
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
void initText(sf::Text& text, std::string str, sf::Font& font, const sf::Vector2f textStartPos) {
	font.loadFromFile("ds-digib.ttf");
	text.setString(str);
	text.setFont(font);
	text.setCharacterSize(charSize);
	text.setPosition(textStartPos);
}
void drawScore(RenderWindow& window, Text& scoreText) {
	window.draw(scoreText);
}
void drawLives(RenderWindow& window, Text& healthText) {
	window.draw(healthText);
}
void drawText1(RenderWindow& window, Text& Text1) {
	window.draw(Text1);
}
void drawText2(RenderWindow& window, Text& Text2) {
	window.draw(Text2);
}
