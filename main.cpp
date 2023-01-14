#include "settings.h"
#include "functions.h"
#include "Bat.h"
#include "Ball.h"

using namespace sf;
int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(60);
	Bat bat;
	Ball ball;
	Text scoreText;
	Text healthText;
	Text Text1;
	Text Text2;
	Font font;
	initBat(bat);
	initBall(ball);
	initScore(healthText,health,font, HealthTextStartPos);
	initText(Text1, str1, font, Text1StartPos);
	initScore(scoreText, score,font, ScoreTextStartPos);
	initText(Text2, str2, font, Text2StartPos);
	while (window.isOpen())
	{
		checkEvents(window);
		updateGame(bat, ball);
		checkCollisions(ball, bat);
		drawGame(window, bat, ball,scoreText,healthText,Text1,Text2);
	}

	return 0;
}