#include "sl.h"
#include "Ball.h"
#include "Player.h"
#include "ScreenOptions.h"
#include "sceneMenu.h"
#include "sceneGameplay.h"
#include "Rules.h"
#include "Pause.h"
#include "Win.h"

int screenHeight = 540;
int screenWidth = 960;

Screen currentScreen = menu;

bool gameRuning = true;

WhoWins whoWins = None;

void runGame()
{
	Ball ball;
	Paddle player1;
	Paddle player2;
	int scoreP1 = 0;
	int scoreP2 = 0;

	slWindow(screenWidth, screenHeight, "Pong", false);
	inItPlayers(player1, player2);
	inItBall(ball);
	slSetFont(slLoadFont("res/Minecraft.ttf"), 50);
	slSetTextAlign(SL_ALIGN_CENTER);
	inItMenu();
	inItRules();
	inItPauseMenu();
	inItWin();
	
	while (!slShouldClose() && gameRuning)
	{
		switch (currentScreen)
		{
		case menu:
			checkImputMenu();
			drawMenu();
			resetGamePlay(ball, player1, player2, scoreP1, scoreP2);
			whoWins = None;
			break;
		case gameplay:
			updateGameplay(ball, player1, player2, scoreP1, scoreP2 , whoWins);
			drawGamePlay(ball, player1, player2, scoreP1, scoreP2, whoWins);
			break;
		case rules:
			inputRules();
			drawRules();
			break;
		default:
			break;
		}
		
		slRender();
	}
	slClose();
}
