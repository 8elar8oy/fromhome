#pragma once
#include "settings.h"
struct Ball {
	sf::CircleShape shape;
	float speedx;
	float speedy;

};
//создание м€ча
void initBall(Ball& ball)
{
	srand(time(nullptr));
	ball.shape.setRadius(BALL_RADIUS);
	ball.shape.setFillColor(BALL_COLOR);
	ball.shape.setPosition(BALL_START_POS);
	ball.speedy = arr_speed[index];
	index = rand() % 2;
	ball.speedx = arr_speed[index];



}
//движение м€чика
void moveBall(Ball& ball)
{

	ball.shape.move(ball.speedx, ball.speedy);
}
void ballReboundEdges(Ball& ball) {
	ball.shape.move(ball.speedx, ball.speedy);
	if (ball.shape.getPosition().x <= 0) ball.speedx = -ball.speedx;
	if (ball.shape.getPosition().x >= (WINDOW_WIDTH - 2 * BALL_RADIUS)) ball.speedx = -ball.speedx;
	if ((ball.shape.getPosition().y <= 0) || (ball.shape.getPosition().y >= (WINDOW_HEIGHT - 2 * BALL_RADIUS))) ball.speedy = -ball.speedy;
	if (ball.shape.getPosition().y >= (WINDOW_HEIGHT - 2 * BALL_RADIUS)) {
		exit(0);
	}
	
}
//касание м€ча ракеткой
bool pointInRect(const Bat& bat, sf::Vector2f& point) {
	return ((point.x >= bat.shape.getPosition().x && point.x <= bat.shape.getPosition().x + LENGTH_BAT) &&
		(point.y >= bat.shape.getPosition().y && point.y <= bat.shape.getPosition().y + WIDTH_BAT));

}
//м€чик отбиваетс€ от ракетки
void ballReboundBat(Ball& ball, Bat& bat) {
	sf::Vector2f midBottom{ ball.shape.getPosition().x + BALL_RADIUS, ball.shape.getPosition().y + 2 * BALL_RADIUS };
	if (pointInRect(bat, midBottom))
	ball.speedy = -ball.speedy;
}