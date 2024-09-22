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
