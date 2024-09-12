#include "sl.h"
#include "Player.h"

extern int screenHeight;
extern int screenWidth;

void moveUp(Paddle& paddle)
{
	paddle.paddle.y += paddle.speed * slGetDeltaTime();
}
void moveDown(Paddle& paddle) 
{
	paddle.paddle.y -= paddle.speed * slGetDeltaTime();
}
void inItPlayers(Paddle& player1, Paddle& player2)
{
    player1.paddle.width = 20;
    player1.paddle.height = 120;
    player1.speed = 150;
    player1.paddle.x = screenWidth * 0.125 - player1.paddle.width;
    player1.paddle.y = screenHeight * 0.5;

    player2.paddle.width = 20;
    player2.paddle.height = 120;
    player2.speed = 150;
    player2.paddle.x = screenWidth * 0.875;
    player2.paddle.y = screenHeight * 0.5;
}
void resetPaddles(Paddle& player1, Paddle& player2)
{
    player1.paddle.x = screenWidth * 0.125 - player1.paddle.width;
    player1.paddle.y = screenHeight * 0.5;

    player2.paddle.x = screenWidth * 0.875;
    player2.paddle.y = screenHeight * 0.5;
}