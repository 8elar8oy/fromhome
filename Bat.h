#pragma once
#include "settings.h"
struct Bat {
	sf::RectangleShape shape;
	float speedx;
};
//создание Ракетки
void initBat(Bat& bat)
{
	bat.shape.setSize(BAT_SIZE);
	bat.shape.setFillColor(BAT_COLOR);
	bat.shape.setPosition(BAT_START_POS);
	bat.speedx = 0.f;

}
void batReboundEdges(Bat& bat) {
	float batx = bat.shape.getPosition().x;
	float baty = bat.shape.getPosition().y;
	if (batx <= 0) bat.shape.setPosition(0.f, baty);
	if (batx >= WINDOW_WIDTH - LENGTH_BAT) bat.shape.setPosition(WINDOW_WIDTH - LENGTH_BAT, baty);
}
void controlBat(Bat& bat) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) bat.speedx = -BAT_SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) bat.speedx = BAT_SPEED;
	bat.shape.move(bat.speedx, 0.f);
	bat.speedx = 0.f;
}
void batUpdate(Bat& bat)
{
	batReboundEdges(bat);
	controlBat(bat);
}