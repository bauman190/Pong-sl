#include "sl.h"
#include "Ball.h"
#include "Player.h"

int screenHeight = 540;
int screenWidth = 960;



void gamePlayInput(Paddle& player1, Paddle& player2)
{
	if (slGetKey('W'))
	{
		moveUp(player1);
	}
	if (slGetKey('S'))
	{
		moveDown(player1);
	}
	if (slGetKey(SL_KEY_UP))
	{
		moveUp(player2);
	}
	if (slGetKey(SL_KEY_DOWN))
	{
		moveDown(player2);
	}

}


void ballWallColitions(Ball& ball)
{
	if (ball.pos.x >= screenWidth - ball.radius || ball.pos.x <= ball.radius)
	{
		if (ball.pos.x >= screenWidth - ball.radius)
		{
			//scoreIncreas(scorePlayer1);
			ball.pos.x = screenWidth - ball.radius;
		}
		else
		{
			//scoreIncreas(scorePlayer2);
			ball.pos.x = ball.radius;
		}
		//player1.paddle.y = GetScreenHeight() / 2 - player1.paddle.height / 2;
		//player2.paddle.y = GetScreenHeight() / 2 - player2.paddle.height / 2;
		//resetBall(ball);
		ball.speed.x *= -1.0f;
	}

	if (ball.pos.y >= screenHeight - ball.radius)
	{
		ball.pos.y = screenHeight - ball.radius;
		ball.speed.y *= -1.0f;
		//ball.goingUp = true;
	}

	if (ball.pos.y <= ball.radius)
	{
		ball.pos.y = ball.radius;
		ball.speed.y *= -1.0f;
		//ball.goingUp = false;
	}
}


bool recRecColition(Ball ball, Paddle player) 
{

	if (ball.hitBox.x + ball.hitBox.width / 2 >= player.paddle.x - player.paddle.width / 2 &&
		ball.hitBox.x - ball.hitBox.width / 2 <= player.paddle.x + player.paddle.width / 2 &&
		ball.hitBox.y + ball.hitBox.height / 2 >= player.paddle.y - player.paddle.height / 2 &&
		ball.hitBox.y - ball.hitBox.height / 2 <= player.paddle.y + player.paddle.height / 2)
	{
		return true;
	}
	return false;

}

void ballPaddleColitions(Ball& ball, Paddle player1, Paddle player2)
{

	if (recRecColition(ball, player1))
	{
		ball.speed.x *= -1.0f;
	}

	if (recRecColition(ball, player2))
	{
		ball.speed.x *= -1.0f;
	}
}

void runGame()
{
	Ball ball;
	Paddle player1;
	Paddle player2;
	inItBall(ball);
	slWindow(screenWidth, screenHeight, "Pong", false);
	inItPlayers(player1, player2);

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
		gamePlayInput(player1, player2);
		ballWallColitions(ball);
		ballMovment(ball);

		ballPaddleColitions(ball, player1, player2);
		
		slSetForeColor(0.5, 0.9, 0.5, 0.7);
		slRectangleFill(ball.hitBox.x, ball.hitBox.y, ball.hitBox.width, ball.hitBox.height);
		slSetForeColor(1, 1, 1, 1);
		slRectangleFill(player2.paddle.x, player2.paddle.y, player2.paddle.width, player2.paddle.height);
		slRectangleFill(player1.paddle.x, player1.paddle.y, player1.paddle.width, player1.paddle.height);
		slCircleFill(ball.pos.x, ball.pos.y, ball.radius, 20);
		slRender();
	}
	slClose();
}
