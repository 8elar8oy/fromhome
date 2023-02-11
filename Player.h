#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
using namespace sf;
struct Player {
	Texture texture;
	Sprite sprite;
	float speedx;

};
void playerInit(Player& player, Vector2f& player_pos, std::string filename) {
	player.texture.loadFromFile(filename);
	player.sprite.setTexture(player.texture);
	player.sprite.setPosition(player_pos);
}
void playerUpdate(Player& player) {
	float playerx = player.sprite.getPosition().x;
	float playery = player.sprite.getPosition().y;
	if (playerx <= 100) player.sprite.setPosition(100.f, playery);
	if (playerx >= WINDOW_WIDTH - 300) player.sprite.setPosition(WINDOW_WIDTH - 300, playery);
	if (Keyboard::isKeyPressed(Keyboard::Left)) player.speedx = -CAR_SPEED;
	if (Keyboard::isKeyPressed(Keyboard::Right)) player.speedx = CAR_SPEED;
	player.sprite.move(player.speedx, 0.f);
	player.speedx = 0.f;

}
void playerDraw(RenderWindow& window, Player& player) {
	window.draw(player.sprite);
}

