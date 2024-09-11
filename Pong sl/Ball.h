#pragma once
#include "sl.h"
#include "Vector2.h"
#include "Rectangle.h"

struct Ball
{
	Vector2 pos;
	Vector2 speed;
	float radius;
	bool goingUp;
	Rectangle hitBox;
	float initialSpeed;
};


void ballMovment(Ball& ball);

void inItBall(Ball& ball);

void resetBall(Ball& ball);

void randBall(Ball& ball);

