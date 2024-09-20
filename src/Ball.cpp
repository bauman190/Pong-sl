#include "Ball.h"
#include "sl.h"
#include <iostream>

extern int screenHeight;
extern int screenWidth;

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
    ball.hitBox.x = ball.pos.x;
    ball.hitBox.y = ball.pos.y;
    ball.hitBox.width = ball.radius * 2;
    ball.hitBox.height = ball.radius * 2;
    ball.speedUp = 1.1f;
    ball.maxSpeed = 350.0f;

    randBall(ball);
}


void resetBall(Ball& ball)
{
    ball.pos.x = screenWidth * 0.5;
    ball.pos.y = screenHeight * 0.5;
    ball.speed.x = ball.initialSpeed;
    ball.speed.y = ball.initialSpeed;
    ball.hitBox.x = ball.pos.x - ball.radius;
    ball.hitBox.y = ball.pos.y - ball.radius;
    ball.hitBox.width = ball.radius * 2;
    ball.hitBox.height = ball.radius * 2;

    randBall(ball);
}


int randValue()
{
    return rand() % 2;
}

void randBall(Ball& ball)
{
    srand(time(NULL));
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

void ballSpeedUP(Ball& ball)
{  
    ball.speed.x *= ball.speedUp;
    ball.speed.y *= ball.speedUp;   
    if (+ball.speed.x > ball.maxSpeed)
    {
         ball.speed.x = ball.maxSpeed;
         ball.speed.y = ball.maxSpeed;
    }
}