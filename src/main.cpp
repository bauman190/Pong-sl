#include "sl.h"
#include "Ball.h"
#include "Player.h"


float screenHeight = 540;
float screenWidth = 960;

void main()
{
	Ball ball;
	Paddle player1;
	Paddle player2;
	inItBall(ball);
	slWindow(screenWidth, screenHeight, "Pong", false);
	inItPlayers(player1, player2);

	char w = 119;
	char s = 115;

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
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
		ballMovment(ball);
		slSetForeColor(0.5, 0.9, 0.5, 0.7);
		slRectangleFill(ball.hitBox.x, ball.hitBox.y,ball.hitBox.width, ball.hitBox.height);
		slSetForeColor(1, 1, 1,1);
		slRectangleFill(player2.paddle.x, player2.paddle.y, player2.paddle.width, player2.paddle.height);
		slRectangleFill(player1.paddle.x, player1.paddle.y, player1.paddle.width, player1.paddle.height);
		slCircleFill(ball.pos.x, ball.pos.y, ball.radius, 20);
		slRender();
	}
	slClose();
}