#include "sceneGameplay.h"
#include "Player.h"
#include "Ball.h"
#include <string>
#include "ScreenOptions.h"
#include "Pause.h"
#include "Win.h"
#include <iostream>

extern int screenHeight;
extern int screenWidth;

inGameScene scene;
static int scoreToWin = 5;
extern WhoWins whoWins;

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
	if (slGetKey(SL_KEY_ESCAPE))
	{
		scene = Pause;
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

void drawGamePlay(Ball ball, Paddle player1, Paddle player2, int scoreP1, int scoreP2, WhoWins whoWins)
{
	std::string intTostring1;
	std::string intTostring2;
	const char* textScoreP1;
	const char* textScoreP2;

	switch (scene)
	{
	case Game:
		slSetForeColor(1, 1, 1, 1);
		slRectangleFill(player2.paddle.x, player2.paddle.y, player2.paddle.width, player2.paddle.height);
		slRectangleFill(player1.paddle.x, player1.paddle.y, player1.paddle.width, player1.paddle.height);

		intTostring1 = std::to_string(scoreP1);
		textScoreP1 = intTostring1.c_str();
		intTostring2 = std::to_string(scoreP2);
		textScoreP2 = intTostring2.c_str();
		slSetFontSize(50);
		slText(screenWidth * 0.40, screenHeight * 0.5, textScoreP1);
		slText(screenWidth * 0.60, screenHeight * 0.5, textScoreP2);

		slCircleFill(ball.pos.x, ball.pos.y, ball.radius, 20);
		break;
	case Pause:
		drawPause();
		break;
	case Win:
		drawWin(whoWins);
		break;
	default:
		break;
	}
}

void avoidSimultaneousCollision(Ball& ball, Paddle player1, Paddle player2)
{
	if (recRecColition(ball, player1) && ball.pos.y < ball.radius)
	{
		ball.pos.x = player1.paddle.x + player1.paddle.width / 2 + ball.radius;
		ball.pos.y = ball.radius;
		ball.hitBox.x = ball.pos.x;
		ball.hitBox.y = ball.pos.y;
	}
	else if (recRecColition(ball, player1) && ball.pos.y + ball.radius > screenHeight)
	{
		ball.pos.x = player1.paddle.x + player1.paddle.width / 2 + ball.radius;
		ball.pos.y = screenHeight - ball.radius;
		ball.hitBox.x = ball.pos.x;
		ball.hitBox.y = ball.pos.y;
	}
	else if (recRecColition(ball, player2) && ball.pos.y < ball.radius)
	{
		ball.pos.x = player2.paddle.x - player2.paddle.width / 2 - ball.radius;
		ball.pos.y = ball.radius;
		ball.hitBox.x = ball.pos.x;
		ball.hitBox.y = ball.pos.y;
	}
	else if (recRecColition(ball, player2) && ball.pos.y + ball.radius > screenHeight)
	{
		ball.pos.x = player2.paddle.x - player2.paddle.width / 2 - ball.radius;
		ball.pos.y = screenHeight - ball.radius;
		ball.hitBox.x = ball.pos.x;
		ball.hitBox.y = ball.pos.y;
	}
}

void updateGameplay(Ball& ball, Paddle& player1, Paddle& player2, int& scoreP1, int& scoreP2, WhoWins& whoWins)
{
	if (scoreP1 >= scoreToWin || scoreP2 >= scoreToWin)
	{
		if (scoreP1 >= scoreToWin)
		{
			whoWins = Player1;
		}
		else
		{
			whoWins = Player2;
		}
		scene = Win;

	}
	switch (scene)
	{
	case Game:
		gamePlayInput(player1, player2);
		ballWallColitions(ball, player1, player2, scoreP1, scoreP2);
		ballPaddleColitions(ball, player1, player2);
		avoidSimultaneousCollision(ball, player1, player2);
		ballMovment(ball);

		break;
	case Pause:
		inputPause();
		break;
	case Win:
		inputWin();
		resetGamePlay(ball, player1, player2, scoreP1, scoreP2);
		break;
	default:
		break;
	}
}

void resetGamePlay(Ball& ball, Paddle& player1, Paddle& player2, int& scoreP1, int& scoreP2)
{
	resetBall(ball);
	resetPaddles(player1, player2);
	scoreP1 = 0;
	scoreP2 = 0;
}