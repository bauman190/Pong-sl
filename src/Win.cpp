#include "Win.h"
#include "Button.h"
#include "ScreenOptions.h"
#include "sl.h"

extern int screenWidth;
extern int screenHeight;

static Button playAgain;
static Button mainMenu;

extern inGameScene scene;
extern Screen currentScreen;
extern WhoWins whoWins;


void drawWin(WhoWins whoWins)
{

    if (whoWins == Player1)
    {
        slText( screenWidth / 2, screenHeight * 0.75, "Player 1 Wins");
    }
    else if (whoWins == Player2)
    {
		slText(screenWidth / 2, screenHeight * 0.75, "Player 2 Wins");
    }

	slText(playAgain.button.x, playAgain.button.y, "Play Again");
	slText(mainMenu.button.x, mainMenu.button.y, "Main Menu");

	if (onButton(playAgain))
	{
		slRectangleFill(playAgain.button.x, playAgain.button.y + playAgain.button.height / 2, playAgain.button.width, playAgain.button.height);
		slSetForeColor(0, 0, 0, 1);
		slText(playAgain.button.x, playAgain.button.y, "Play Again");
		slSetForeColor(1, 1, 1, 1);
	}
	else if (onButton(mainMenu))
	{
		slRectangleFill(mainMenu.button.x, mainMenu.button.y + mainMenu.button.height / 2, mainMenu.button.width, mainMenu.button.height);
		slSetForeColor(0, 0, 0, 1);
		slText(mainMenu.button.x, mainMenu.button.y, "Main Menu");
		slSetForeColor(1, 1, 1, 1);
	}
}

void inputWin()
{
	if (clickButton(playAgain))
	{
		scene = Game;
	}
	if (clickButton(mainMenu))
	{
		currentScreen = menu;
		scene = Game;
	}
}

void inItWin()
{
	playAgain.button.x = screenWidth / 2;
	playAgain.button.y = screenHeight / 2;
	playAgain.button.width = slGetTextWidth("Play Again");
	playAgain.button.height = slGetTextHeight("Play Again");

	mainMenu.button.x = slGetTextWidth("Main Menu") / 2;
	mainMenu.button.y = slGetTextHeight("Main Menu");
	mainMenu.button.width = slGetTextWidth("Main Menu");
	mainMenu.button.height = slGetTextHeight("Main Menu");
}