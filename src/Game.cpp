#include "sl.h"
#include "Ball.h"
#include "Player.h"
#include <string>
#include "ScreenOptions.h"
#include "sceneMenu.h"
#include "sceneGameplay.h"

using namespace std;

int screenHeight = 540;
int screenWidth = 960;

Screen currentScreen = menu;

bool gameRuning = true;


void runGame()
{
	Ball ball;
	Paddle player1;
	Paddle player2;
	int scoreP1 = 0;
	int scoreP2 = 0;
	string scoreP1Text;
	string scoreP2Text;
	const char* textScoreP1 = scoreP1Text.c_str();
	const char* textScoreP2 = scoreP2Text.c_str();

	slWindow(screenWidth, screenHeight, "Pong", false);
	inItPlayers(player1, player2);
	inItBall(ball);
	slSetFont(slLoadFont("res/Minecraft.ttf"), 50);
	slSetTextAlign(SL_ALIGN_CENTER);
	inItMenu();
	
	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE) && gameRuning)
	{
		switch (currentScreen)
		{
		case menu:
			checkImputMenu();
			drawMenu();
			break;
		case gameplay:
			updateGameplay(ball, player1, player2, scoreP1, scoreP2);
			drawGamePlay(ball, player1, player2, scoreP1, scoreP2);
			/*gamePlayInput(player1, player2);
			ballWallColitions(ball, player1, player2, scoreP1, scoreP2);
			ballMovment(ball);

			ballPaddleColitions(ball, player1, player2);

			slSetForeColor(0.5, 0.9, 0.5, 0.7);
			slRectangleFill(ball.hitBox.x, ball.hitBox.y, ball.hitBox.width, ball.hitBox.height);
			slSetForeColor(1, 1, 1, 1);
			slRectangleFill(player2.paddle.x, player2.paddle.y, player2.paddle.width, player2.paddle.height);
			slRectangleFill(player1.paddle.x, player1.paddle.y, player1.paddle.width, player1.paddle.height);

			scoreP1Text = to_string(scoreP1);
			textScoreP1 = scoreP1Text.c_str();
			scoreP2Text = to_string(scoreP2);
			textScoreP2 = scoreP2Text.c_str();
			slSetFontSize(50);
			slText(screenWidth * 0.40, screenHeight * 0.5, textScoreP1);
			slText(screenWidth * 0.60, screenHeight * 0.5, textScoreP2);

			slCircleFill(ball.pos.x, ball.pos.y, ball.radius, 20);*/
			break;
		case rules:
			break;
		default:
			break;
		}
		
		slRender();
	}
	slClose();
}
