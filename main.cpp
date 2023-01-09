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
	
	initBat(bat);
	initBall(ball);
	
	
	while (window.isOpen())
	{
		
		checkEvents(window);
		updateGame(bat,ball);
		checkCollisions(ball,bat);
		drawGame(window, bat, ball);
		
	}

	return 0;
}