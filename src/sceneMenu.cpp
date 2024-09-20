#include "ScreenOptions.h"
#include "Button.h"
#include "sl.h"

extern Screen currentScreen;

extern bool gameRuning;

extern int screenHeight;
extern int screenWidth;

static Button play;
static Button Rules;
static Button exit;

void checkImputMenu()
{
	if (clickButton(play))
	{
		currentScreen = gameplay;
	}
	if (clickButton(exit))
	{
		gameRuning = !gameRuning;
	}
	if (clickButton(Rules))
	{
		currentScreen = rules;
	}

}

void drawMenu() 
{

	slSetForeColor(1, 1, 1, 1);

	slText(screenWidth / 2, screenHeight * 0.20, "PONG");

	slText(play.button.x, play.button.y, "Play");
	slText( Rules.button.x, Rules.button.y, "Rules");
	slText( exit.button.x, exit.button.y, "Exit");
	if (onButton(play))
	{
		slRectangleFill(play.button.x, play.button.y, play.button.width, play.button.height);
		slSetForeColor(0, 0, 0, 1);
		slText(play.button.x, play.button.y, "Play");
		slSetForeColor(1, 1, 1, 1);
	}
	else if (onButton(exit))
	{
		slRectangleFill(exit.button.x, exit.button.y, exit.button.width, exit.button.height);
		slSetForeColor(0, 0, 0, 1);
		slText(exit.button.x, exit.button.y, "Exit");
		slSetForeColor(1, 1, 1, 1);
	}
	else if (onButton(Rules))
	{
		DrawRectangle(Rules.button.x, Rules.button.y, Rules.button.width, Rules.button.height, WHITE);
		DrawText("Rules", Rules.button.x, Rules.button.y, Rules.button.height, BLACK);
	}
	
	DrawText("By: Juan Bautista Castignani",0 , GetScreenHeight() * 0.95, 25, WHITE);
	

}

void inItMenu()
{
	
	play.button.x = GetScreenWidth() / 2  - MeasureText("Play", 50) / 2;
	play.button.y = GetScreenHeight() / 2;
	play.button.width = MeasureText("Play", 50);
	play.button.height = 50;


	Rules.button.x = GetScreenWidth() / 2 - MeasureText("Rules", 50) / 2;
	Rules.button.y = GetScreenHeight() * 0.625;
	Rules.button.width = MeasureText("Rules", 50);
	Rules.button.height = 50;

	exit.button.x = GetScreenWidth() / 2 - MeasureText("Exit", 50) / 2;
	exit.button.y = GetScreenHeight() * 0.75;
	exit.button.width = MeasureText("Exit", 50);
	exit.button.height = 50;



}