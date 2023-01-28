#pragma once
#include "windows.h"
#include "settings.h"
using namespace sf;
void checkLives(int& health) {
	if (health == 0) {
		exit(0);
	}
}
void initScore(Text& text, int count, Font& font, const Vector2f textStartPos) {
	font.loadFromFile("ds-digib.ttf");
	text.setString(std::to_string(count));
	text.setFont(font);
	text.setFillColor(Color::Black);
	text.setCharacterSize(CHAR_SIZE);
	text.setPosition(textStartPos);
}

void updateHealth(Ball& ball, Text& healthText) {
	if (ball.shape.getPosition().y >= (WINDOW_HEIGHT - 2 * BALL_RADIUS)) {
		health = health - 1;
		healthText.setString(std::to_string(health));
		ball.shape.setPosition(BALL_START_POS);
		ball.speedx = 0;
		ball.speedy = 0;
	}
}
void initText(Text& text, std::string str, Font& font, const Vector2f textStartPos) {
	font.loadFromFile("ds-digib.ttf");
	text.setString(str);
	text.setFont(font);
	text.setFillColor(Color::Black);
	text.setCharacterSize(CHAR_SIZE);
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
