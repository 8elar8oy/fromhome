#pragma once
#include "SFML/Graphics.hpp"
#include "Bat.h"
#include "Ball.h"
#include "windows.h"

//основная функция
void checkEvents(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}
//создание мяча
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
//движение мячика
void moveBall(Ball& ball)
{
	
	ball.shape.move(ball.speedx, ball.speedy);
}
//создание ракетки
void initBat(Bat& bat)
{
	bat.shape.setSize(BAT_SIZE);
	bat.shape.setFillColor(BAT_COLOR);
	bat.shape.setPosition(BAT_START_POS);
	bat.speedx = 0.f;	
	
}
void ballReboundEdges(Ball& ball) {
	ball.shape.move(ball.speedx, ball.speedy);
	if (ball.shape.getPosition().x <= 0) ball.speedx = -ball.speedx;
	if (ball.shape.getPosition().x >= (WINDOW_WIDTH - 2 * BALL_RADIUS)) ball.speedx = -ball.speedx;
	if ((ball.shape.getPosition().y <= 0) || (ball.shape.getPosition().y >= (WINDOW_HEIGHT - 2 * BALL_RADIUS))) ball.speedy = -ball.speedy;
	
	

}
//управление ракеткой
void controlBat(Bat& bat) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) bat.speedx = -BAT_SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) bat.speedx = BAT_SPEED;
	bat.shape.move(bat.speedx, 0.f);
	bat.speedx = 0.f;
}
//ракетка отбивается от краев экрана
void batReboundEdges(Bat& bat) {
	float batx = bat.shape.getPosition().x;
	float baty = bat.shape.getPosition().y;
	if (batx <= 0) bat.shape.setPosition(0.f, baty);
	if (batx >= WINDOW_WIDTH - LENGTH_BAT) bat.shape.setPosition(WINDOW_WIDTH - LENGTH_BAT, baty);
}
//обновление позиции обьектов
void updateGame(Bat& bat,Ball& ball) {

	controlBat(bat);
	moveBall(ball);
	
}
bool pointInRect(const Bat& bat, sf::Vector2f& point) {
	return ((point.x >= bat.shape.getPosition().x && point.x <= bat.shape.getPosition().x + LENGTH_BAT) &&
		(point.y >= bat.shape.getPosition().y && point.y <= bat.shape.getPosition().y + WIDTH_BAT));
		
}
void checkCollisions(Ball& ball,Bat& bat) {
	ballReboundEdges(ball);
	batReboundEdges(bat);
	/*sf::Vector2f midLeft{ ball.shape.getPosition().x, ball.shape.getPosition().y + BALL_RADIUS };
	sf::Vector2f midTop{ ball.shape.getPosition().x + BALL_RADIUS, ball.shape.getPosition().y };
	sf::Vector2f midRight{ ball.shape.getPosition().x + 2 * BALL_RADIUS, ball.shape.getPosition().y + BALL_RADIUS };*/
	sf::Vector2f midBottom{ ball.shape.getPosition().x + BALL_RADIUS, ball.shape.getPosition().y + 2 * BALL_RADIUS };
	if (pointInRect(bat, midBottom))
		ball.speedy = -ball.speedy;
	
}
//отрисовка обьектов
void drawGame(sf::RenderWindow& window, Bat bat,Ball ball) {
	window.clear(sf::Color::Cyan);
	window.draw(bat.shape);
	window.draw(ball.shape);
	window.display();
}
