#pragma once
#include "settings.h"
#include "windows.h"
#include "BlockField.h"
struct Ball {
	sf::CircleShape shape;
	float speedx = 0;
	float speedy = 0;
};
//создание мяча
void initBall(Ball& ball)
{
	srand(time(nullptr));
	ball.shape.setRadius(BALL_RADIUS);
	ball.shape.setFillColor(BALL_COLOR);
	ball.shape.setPosition(BALL_START_POS);
}
//движение мячика
void moveBall(Ball& ball)
{
	ball.shape.move(ball.speedx, ball.speedy);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		ball.speedy = arr_speed[index];
		index = rand() % 2;
		ball.speedx = arr_speed[index];
	}
}
void ballReboundEdges(Ball& ball, sf::Text& healthText) {
	ball.shape.move(ball.speedx, ball.speedy);
	if (ball.shape.getPosition().x <= 0) ball.speedx = -ball.speedx;
	if (ball.shape.getPosition().x >= (WINDOW_WIDTH - 2 * BALL_RADIUS)) ball.speedx = -ball.speedx;
	if ((ball.shape.getPosition().y <= 0) || (ball.shape.getPosition().y >= (WINDOW_HEIGHT - 2 * BALL_RADIUS))) ball.speedy = -ball.speedy;
}
//касание мяча ракеткой
bool pointInRect(Bat& bat, sf::Vector2f& point) {
	return (point.x >= bat.shape.getPosition().x && point.x <= bat.shape.getPosition().x + LENGTH_BAT ) &&
		(point.y >= bat.shape.getPosition().y && point.y <= bat.shape.getPosition().y + WIDTH_BAT);
}
bool pointInBlock(Block& block, sf::Vector2f& point) {
	return (point.x >= block.shape.getPosition().x && point.x <= block.shape.getPosition().x + LENGTH_BLOCK) &&
		(point.y >= block.shape.getPosition().y && point.y <= block.shape.getPosition().y + WIDTH_BLOCK);
}
//мячик отбивается от ракетки
void ballReboundObjects(Ball& ball, Bat& bat, BlockField& blockfield, Text& ScoreText) {

	sf::Vector2f midTop{
		ball.shape.getPosition().x + BALL_RADIUS,
		ball.shape.getPosition().y
	};
	sf::Vector2f midBottom{
		ball.shape.getPosition().x + BALL_RADIUS,
		ball.shape.getPosition().y + 2 * BALL_RADIUS
	};
	sf::Vector2f midLeft{
		ball.shape.getPosition().x,
		ball.shape.getPosition().y + BALL_RADIUS
	};
	sf::Vector2f midRight{
		ball.shape.getPosition().x + 2 * BALL_RADIUS,
		ball.shape.getPosition().y + BALL_RADIUS
	};
	if (pointInRect(bat, midBottom))
		ball.speedy = -ball.speedy;
	if (pointInRect(bat, midTop))
		ball.speedy = -ball.speedy;
	if (pointInRect(bat, midLeft))
		ball.speedx = -ball.speedx;
	if (pointInRect(bat, midRight))
		ball.speedx = -ball.speedx;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{

			if (pointInBlock(blockfield.field[i][j], midBottom)) {
				ball.speedy = -ball.speedy;
				score = score + 10;
				ScoreText.setString(std::to_string(score));
				blockfield.field[i][j].shape.setPosition(0.f, 1000.f);
				break;
			}
			if (pointInBlock(blockfield.field[i][j], midTop)) {
				ball.speedy = -ball.speedy;
				score = score + 10;
				ScoreText.setString(std::to_string(score));
				blockfield.field[i][j].shape.setPosition(0.f, 1000.f);
				break;
			}
			if (pointInBlock(blockfield.field[i][j], midLeft)) {
				ball.speedx = -ball.speedx;
				score = score + 10;
				ScoreText.setString(std::to_string(score));
				blockfield.field[i][j].shape.setPosition(0.f, 1000.f);
				break;
			}
			if (pointInBlock(blockfield.field[i][j], midRight)) {
				ball.speedx = -ball.speedx;
				score = score + 10;
				ScoreText.setString(std::to_string(score));
				blockfield.field[i][j].shape.setPosition(0.f, 1000.f);
				break;
			}
		}
	}
}
void drawBall(RenderWindow& window, Ball& ball) {
	window.draw(ball.shape);
}