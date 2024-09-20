#pragma once
#include "sl.h"
#include "Vector2.h"
#include "Rectangle.h"

struct Ball
{
	Vector2 pos;
	Vector2 speed;
	float speedUp;
	float radius;
	Rectangle hitBox;
	float initialSpeed;
	float maxSpeed;
};


void ballMovment(Ball& ball);

void inItBall(Ball& ball);

void resetBall(Ball& ball);

void randBall(Ball& ball);

void ballSpeedUP(Ball& ball);
