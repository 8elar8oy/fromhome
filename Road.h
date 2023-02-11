#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
using namespace sf;
struct Surface {
	Texture texture;
	Sprite sprite;
	float offsetX;
};
void SurfaceInit(Surface& Surface, Vector2f SurfacePos, std::string filename, float offset) {
	Surface.texture.loadFromFile(filename);
	Surface.sprite.setTexture(Surface.texture);
	Surface.sprite.setPosition(SurfacePos);
	Surface.offsetX = offset;

}
void SurfaceDraw(RenderWindow& window, Surface& Surface1, Surface& Surface2) {
	window.draw(Surface1.sprite);
	window.draw(Surface2.sprite);
}
void SurfaceUpdate(Surface& Surface1, Surface& Surface2) {
	Surface1.sprite.move(0.f, ROAD_LAYER_SPEED);
	Surface2.sprite.move(0.f, ROAD_LAYER_SPEED);

	if (Surface1.sprite.getPosition().y >= WINDOW_HEIGHT)
	{
		Surface1.sprite.setPosition(Surface1.offsetX, -WINDOW_HEIGHT);
	}
	if (Surface2.sprite.getPosition().y >= WINDOW_HEIGHT)
	{
		Surface2.sprite.setPosition(Surface2.offsetX, -WINDOW_HEIGHT);
	}
}