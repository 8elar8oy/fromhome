#pragma once
#include "SFML/Graphics.hpp"
#include "bat.h"
#include "ball.h"
#include "Text.h"
#include "windows.h"
#include "Blocks.h"
#include "BlockField.h"
using namespace sf;
void checkEvents(RenderWindow& window) {
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
	}
}

void updateGame(Bat& bat, Ball& ball, BlockField blockfield,Text& healthText) {
	controlBat(bat);
	moveBall(ball);
	
	blockFieldUpdate(blockfield);
	checkLives(health);
	updateHealth(ball, healthText);
	
}
void checkCollisions(Ball& ball, Bat& bat,BlockField& blockfield, Text& HealthText, Text& ScoreText) {
	ballReboundEdges(ball, HealthText);
	batReboundEdges(bat);
	ballReboundObjects(ball, bat,blockfield,ScoreText);
	
}
void drawGame(RenderWindow& window, Bat& bat, Ball& ball, BlockField& blockfield, Text& scoreText, Text& healthText, Text Text1, Text Text2) {
	window.clear(sf::Color::Cyan);
	drawBlockField(window, blockfield);
	drawBat(window, bat);
	drawBall(window, ball);
	drawScore(window, scoreText);
	drawLives(window, healthText);
	drawText1(window, Text1);
	drawText2(window, Text2);
	window.display();
}