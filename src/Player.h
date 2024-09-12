#pragma once
#include "sl.h"
#include "Rectangle.h"


struct Paddle
{
	Rectangle paddle;
	float speed;
};

void moveUp(Paddle& paddle);
void moveDown(Paddle& paddle);
void inItPlayers(Paddle& player1, Paddle& player2);
void resetPaddles(Paddle& player1, Paddle& player2);