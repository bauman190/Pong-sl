#include "sceneGameplay.h"
#include "Player.h"
#include "Ball.h"
#include <string>

extern int screenHeight;
extern int screenWidth;


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

void scoreIncreas(int& score)
{
	score++;
}

void ballWallColitions(Ball& ball, Paddle& player1, Paddle& player2, int& scoreP1, int& scoreP2)
{
	if (ball.pos.x >= screenWidth - ball.radius || ball.pos.x <= ball.radius)
	{
		if (ball.pos.x >= screenWidth - ball.radius)
		{
			scoreIncreas(scoreP1);
		}
		else
		{
			scoreIncreas(scoreP2);
		}
		player1.paddle.y = screenHeight / 2;
		player2.paddle.y = screenHeight / 2;
		resetBall(ball);

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
		if (ball.pos.y > player1.paddle.y + player1.paddle.height / 2)
		{
			ball.pos.y = player1.paddle.y + player1.paddle.height / 2 + ball.radius;
		}
		else if (ball.pos.y < player1.paddle.y - player1.paddle.height / 2)
		{
			ball.pos.y = player1.paddle.y - player1.paddle.height / 2 - ball.radius;
		}
		else
		{
			ball.pos.x = player1.paddle.x + player1.paddle.width / 2 + ball.radius;
		}

		if (ball.speed.y < 0 && ball.pos.y > player1.paddle.y)
		{
			ball.speed.y *= -1.0f;
		}
		else if (ball.speed.y > 0 && ball.pos.y < player1.paddle.y)
		{
			ball.speed.y *= -1.0f;
		}
		ball.speed.x *= -1.0f;
		ballSpeedUP(ball);
	}


	if (recRecColition(ball, player2))
	{
		if (ball.pos.y > player2.paddle.y + player2.paddle.height / 2)
		{
			ball.pos.y = player2.paddle.y + player2.paddle.height / 2 + ball.radius;
		}
		else if (ball.pos.y < player2.paddle.y - player2.paddle.height / 2)
		{
			ball.pos.y = player2.paddle.y - player2.paddle.height / 2 - ball.radius;
		}
		else
		{
			ball.pos.x = player2.paddle.x - player2.paddle.width / 2 - ball.radius;
		}

		if (ball.speed.y < 0 && ball.pos.y > player2.paddle.y)
		{
			ball.speed.y *= -1.0f;
		}
		else if (ball.speed.y > 0 && ball.pos.y < player2.paddle.y)
		{
			ball.speed.y *= -1.0f;
		}
		ball.speed.x *= -1.0f;
		ballSpeedUP(ball);
	}

}

void drawGamePlay(Ball ball, Paddle player1, Paddle player2, int scoreP1, int scoreP2)
{
	std::string scoreP1Text;
	std::string scoreP2Text;
	const char* textScoreP1;
	const char* textScoreP2;

	slSetForeColor(0.5, 0.9, 0.5, 0.7);
	slRectangleFill(ball.hitBox.x, ball.hitBox.y, ball.hitBox.width, ball.hitBox.height);
	slSetForeColor(1, 1, 1, 1);
	slRectangleFill(player2.paddle.x, player2.paddle.y, player2.paddle.width, player2.paddle.height);
	slRectangleFill(player1.paddle.x, player1.paddle.y, player1.paddle.width, player1.paddle.height);

	scoreP1Text = std::to_string(scoreP1);
	textScoreP1 = scoreP1Text.c_str();
	scoreP2Text = std::to_string(scoreP2);
	textScoreP2 = scoreP2Text.c_str();
	slSetFontSize(50);
	slText(screenWidth * 0.40, screenHeight * 0.5, textScoreP1);
	slText(screenWidth * 0.60, screenHeight * 0.5, textScoreP2);

	slCircleFill(ball.pos.x, ball.pos.y, ball.radius, 20);
}

void updateGameplay(Ball& ball, Paddle& player1, Paddle& player2, int& scoreP1, int& scoreP2)
{
	gamePlayInput(player1, player2);
	ballWallColitions(ball, player1, player2, scoreP1, scoreP2);
	ballMovment(ball);

	ballPaddleColitions(ball, player1, player2);
}