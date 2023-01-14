#pragma once
#include "SFML/Graphics.hpp"

const float WINDOW_WIDTH = 1600.f;
const float WINDOW_HEIGHT = 800.f;
const std::string WINDOW_TITLE = "SFML Simple Arcanoid P33122";
//���
const float BALL_RADIUS = 10.f;
const sf::Color BALL_COLOR{ sf::Color::White };
const sf::Vector2f BALL_START_POS{ (WINDOW_WIDTH - 2 * BALL_RADIUS) / 2,(WINDOW_HEIGHT - 2 * BALL_RADIUS) / 2 };
float arr_speed[]{ -5.f,5.f };
int index = rand() % 2;

//�������
const sf::Color BAT_COLOR{ sf::Color::White };
const float BAT_SPEED = 20.f;
const float LENGTH_BAT = 120;
const float WIDTH_BAT = 20;
const float BAY_OFFSET = 50;
const float BAT_START_POSX = (WINDOW_WIDTH - LENGTH_BAT) / 2;
const float BAT_START_POSY = WINDOW_HEIGHT - WIDTH_BAT - BAY_OFFSET;
const sf::Vector2f BAT_SIZE{ LENGTH_BAT, WIDTH_BAT };
const sf::Vector2f BAT_START_POS{ BAT_START_POSX,BAT_START_POSY };

//�����
const sf::Color BLOCKS_COLOR[4] = { sf::Color::Red,sf::Color::Black, sf::Color::Blue,sf::Color::Green };
//�����
const int charSize = 64;
int health = 0;
int score = 0;
std:: string str1 = "�����";
std::string str2 = "����";
const sf::Vector2f Text1StartPos{ WINDOW_WIDTH - charSize,charSize };
const sf::Vector2f Text2StartPos{ WINDOW_WIDTH - charSize * 2,charSize};
const sf::Vector2f HealthTextStartPos{ WINDOW_WIDTH - charSize,charSize*2 };
const sf::Vector2f ScoreTextStartPos{ WINDOW_WIDTH - charSize*2,charSize*2};