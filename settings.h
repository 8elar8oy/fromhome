#pragma once
#include "SFML/Graphics.hpp"
//окно
const float WINDOW_WIDTH = 1600.f;
const float WINDOW_HEIGHT = 800.f;
const std::string WINDOW_TITLE = "SFML Simple Arcanoid P33122";
//мяч
const float BALL_RADIUS = 10.f;
const sf::Color BALL_COLOR{ sf::Color::White };
const sf::Vector2f BALL_START_POS{ (WINDOW_WIDTH - 2 * BALL_RADIUS) / 2,(WINDOW_HEIGHT - 2 * BALL_RADIUS) / 2 };
float arr_speed[]{ -5.f,5.f };
int index = rand() % 2;

//ракетка
const sf::Color BAT_COLOR{ sf::Color::White };
const float BAT_SPEED = 20.f;
const float LENGTH_BAT = 120;
const float WIDTH_BAT = 20;
const float BAY_OFFSET = 50;
const float BAT_START_POSX = (WINDOW_WIDTH - LENGTH_BAT) / 2;
const float BAT_START_POSY = WINDOW_HEIGHT - WIDTH_BAT - BAY_OFFSET;
const sf::Vector2f BAT_SIZE{ LENGTH_BAT, WIDTH_BAT };
const sf::Vector2f BAT_START_POS{ BAT_START_POSX,BAT_START_POSY };
//блоки
const float LENGTH_BLOCK = 80;
const float WIDTH_BLOCK = 40;
const sf::Vector2f BLOCK_SIZE{ LENGTH_BLOCK,WIDTH_BLOCK };
const float BLOCK_START_POSX = 5;
const float BLOCK_START_POSY = 5;
sf::Vector2f BLOCK_START_POS{ BLOCK_START_POSX,BLOCK_START_POSY };
sf::Color BLOCKS_COLOR[4]{ sf::Color::Red,sf::Color::Yellow, sf::Color::Green,sf::Color::Blue };
float stepX = LENGTH_BLOCK;
float stepY = WIDTH_BLOCK;
const int COLUMNS = 20; 
const int ROWS = 8;
//текст
const int CHAR_SIZE = 48;
int health = 3;
int score = 0;
std::string str1 = "LIFES";
std::string str2 = "SCORE";
const sf::Vector2f TEXT1_START_POS{ WINDOW_WIDTH - CHAR_SIZE * 4, 20 };
const sf::Vector2f TEXT2_START_POS{ WINDOW_WIDTH - CHAR_SIZE * 8, 20 };
const sf::Vector2f HEALTHTEXT_START_POS{ WINDOW_WIDTH - (CHAR_SIZE * 4),60 };
const sf::Vector2f SCORETEXT_START_POS{ WINDOW_WIDTH - (CHAR_SIZE * 8),60 };