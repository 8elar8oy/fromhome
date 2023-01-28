#include "settings.h"
#include "functions.h"
#include "bat.h"
#include "ball.h"
#include "Text.h"
#include "Blocks.h"
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
	
	BlockField blockfield;
	InitBlockField(blockfield);
	initBat(bat);
	initBall(ball);
	initScore(healthText, health, font, HEALTHTEXT_START_POS);
	initText(Text1, str1, font, TEXT1_START_POS);
	initScore(scoreText, score, font, SCORETEXT_START_POS);
	initText(Text2, str2, font, TEXT2_START_POS);

	while (window.isOpen())
	{
		checkEvents(window);
		updateGame(bat, ball, blockfield, healthText);
		checkCollisions(ball, bat,blockfield, healthText,scoreText);
		drawGame(window, bat, ball, blockfield, scoreText, healthText, Text1, Text2);
	}
	return 0;
}