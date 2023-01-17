#pragma once
#include "windows.h"
#include "settings.h"
using namespace sf;
void checkLives(int& health) {
	if (health == 0) {
		exit(0);
	}
}