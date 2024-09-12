#include "Ball.h"
#include "sl.h"
#include <iostream>

extern int screenHeight;
extern int screenWidth;
;

void ballMovment(Ball& ball)
{
    ball.pos.x += ball.speed.x * slGetDeltaTime();
    ball.pos.y += ball.speed.y * slGetDeltaTime();
    ball.hitBox.x = ball.pos.x;
    ball.hitBox.y = ball.pos.y;
}

void inItBall(Ball& ball)
{
    ball.radius = 10;
    ball.initialSpeed = 200;
    ball.pos.x = screenWidth * 0.5;
    ball.pos.y = screenHeight * 0.5;
    ball.speed.x = ball.initialSpeed;
    ball.speed.y = ball.initialSpeed;
    ball.goingUp = true;
    ball.hitBox.x = ball.pos.x;
    ball.hitBox.y = ball.pos.y;
    ball.hitBox.width = ball.radius * 2;
    ball.hitBox.height = ball.radius * 2;

    randBall(ball);
}


void resetBall(Ball& ball)
{
    ball.pos.x = screenWidth * 0.5;
    ball.pos.y = screenHeight * 0.5;
    ball.speed.x = ball.initialSpeed;
    ball.speed.y = ball.initialSpeed;
    ball.goingUp = true;
    ball.hitBox.x = ball.pos.x - ball.radius;
    ball.hitBox.y = ball.pos.y - ball.radius;
    ball.hitBox.width = ball.radius * 2;
    ball.hitBox.height = ball.radius * 2;

    randBall(ball);
}


int randValue()
{
    srand(time(NULL));
    return rand() % 1;
}

void randBall(Ball& ball)
{
    int rand = randValue();
    if (rand == 0)
    {
        ball.speed.x *= -1.0f;
    }
    else
    {
        ball.speed.x *= 1.0f;
    }
    rand = randValue();

    if (rand == 0)
    {
        ball.speed.y *= -1.0f;
    }
    else
    {
        ball.speed.y *= 1.0f;
    }
}
