#include "settings.h"
#include "functions.h"
#include "Bat.h"
#include "Ball.h"
#include "settings.h"
#include "functions.h"
#include "Bat.h"
#include "Ball.h"
#include "Text.h"
#include "Blocks.h"
#include "BlockRow.h"
#include "BlockField.h"
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
	Block block;
	BlockRow blockrow;
	BlockField blockfield;
	
	
	InitBlockField(blockfield);
	initBat(bat);
	initBall(ball);
	initScore(healthText, health, font, HealthTextStartPos);
	initText(Text1, str1, font, Text1StartPos);
	initScore(scoreText, score, font, ScoreTextStartPos);
	initText(Text2, str2, font, Text2StartPos);

	while (window.isOpen())
	{
		checkEvents(window);
		updateGame(bat, ball, blockfield, healthText);
		checkCollisions(ball, bat, healthText);
		drawGame(window, bat, ball, blockfield, scoreText, healthText, Text1, Text2);




	}

	return 0;
}