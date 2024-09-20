#include "sl.h"
#include "Ball.h"
#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

int screenHeight = 540;
int screenWidth = 960;

//Preguntarle al profe lo del dibujado de texto

void gamePlayInput(Paddle& player1, Paddle& player2)
{
	if (slGetKey('W') && player1.paddle.y + player1.paddle.height / 2 < screenHeight)
	{
		moveUp(player1);
	}
	if (slGetKey('S') && player1.paddle.y - player1.paddle.height / 2 > 0)
	{
		moveDown(player1);
	}
	if (slGetKey(SL_KEY_UP) && player2.paddle.y + player2.paddle.height / 2 < screenHeight)
	{
		moveUp(player2);
	}
	if (slGetKey(SL_KEY_DOWN) && player2.paddle.y - player2.paddle.height / 2 > 0)
	{
		moveDown(player2);
	}

}


void ballWallColitions(Ball& ball, Paddle& player1, Paddle& player2)
{
	if (ball.pos.x >= screenWidth - ball.radius || ball.pos.x <= ball.radius)
	{
		if (ball.pos.x >= screenWidth - ball.radius)
		{
			//scoreIncreas(scorePlayer1);
			resetBall(ball);
		}
		else
		{
			//scoreIncreas(scorePlayer2);
			resetBall(ball);
		}
		player1.paddle.y = screenHeight / 2;
		player2.paddle.y = screenHeight / 2;
		//resetBall(ball);
		
	}

	if (ball.pos.y >= screenHeight - ball.radius)
	{
		ball.pos.y = screenHeight - ball.radius;
		ball.speed.y *= -1.0f;
	}

	if (ball.pos.y <= ball.radius)
	{
		ball.pos.y = ball.radius;
		ball.speed.y *= -1.0f;
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
		if (ball.speed.y < 0 && ball.pos.y > player1.paddle.y)
		{
			ball.pos.x = player1.paddle.x + player1.paddle.width / 2 + ball.radius;
			ball.speed.y *= -1.0f;
		}
		else if (ball.speed.y > 0 && ball.pos.y < player1.paddle.y)
		{
			ball.pos.x = player1.paddle.x + player1.paddle.width / 2 + ball.radius;
			ball.speed.y *= -1.0f;
		}
		ball.speed.x *= -1.0f;
	}
	

	if (recRecColition(ball, player2))
	{
		if (ball.speed.y < 0 && ball.pos.y > player2.paddle.y)
		{
			ball.pos.x = player2.paddle.x - player2.paddle.width / 2 - ball.radius;
			ball.speed.y *= -1.0f;
		}
		else if (ball.speed.y > 0 && ball.pos.y < player2.paddle.y)
		{
			ball.pos.x = player2.paddle.x - player2.paddle.width / 2 - ball.radius;
			ball.speed.y *= -1.0f;
		}
		ball.speed.x *= -1.0f;
	}
}

void runGame()
{
	Ball ball;
	Paddle player1;
	Paddle player2;
	int scoreP1 = 0;
	int scoreP2 = 0;
	string score = to_string(scoreP1);
	const char* textScore = score.c_str();
	slWindow(screenWidth, screenHeight, "Pong", false);
	inItPlayers(player1, player2);
	inItBall(ball);
	//slSetFont(slLoadFont("Minecraft.ttf"), 14);
	//slSetTextAlign(SL_ALIGN_CENTER);
	
	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
		gamePlayInput(player1, player2);
		ballWallColitions(ball, player1, player2);
		ballMovment(ball);

		ballPaddleColitions(ball, player1, player2);
		
		slSetForeColor(0.5, 0.9, 0.5, 0.7);
		slRectangleFill(ball.hitBox.x, ball.hitBox.y, ball.hitBox.width, ball.hitBox.height);
		slSetForeColor(1, 1, 1, 1);
		slRectangleFill(player2.paddle.x, player2.paddle.y, player2.paddle.width, player2.paddle.height);
		slRectangleFill(player1.paddle.x, player1.paddle.y, player1.paddle.width, player1.paddle.height);

		//slSetFontSize(14);
		slText(200, 200,textScore);

		slCircleFill(ball.pos.x, ball.pos.y, ball.radius, 20);
		slRender();
	}
	slClose();
}
