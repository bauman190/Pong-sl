#include "raylib.h"
#include "ScreenOptions.h"
#include "Button.h"

extern Screen currentScreen;

extern bool gameRuning;

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

	BeginDrawing();
	ClearBackground(BLACK);

	DrawText("Pong", GetScreenWidth() / 2 - MeasureText("Pong", 100) / 2, GetScreenHeight() * 0.20, 100, WHITE);

	DrawText("Play", play.button.x, play.button.y, play.button.height, WHITE);
	DrawText("Rules", Rules.button.x, Rules.button.y, Rules.button.height, WHITE);
	DrawText("Exit", exit.button.x, exit.button.y, exit.button.height, WHITE);
	if (onButton(play))
	{
		DrawRectangle(play.button.x, play.button.y, play.button.width, play.button.height, WHITE);
		DrawText("Play", play.button.x, play.button.y, play.button.height, BLACK);
	}
	else if (onButton(exit))
	{
		DrawRectangle(exit.button.x, exit.button.y, exit.button.width, exit.button.height, WHITE);
		DrawText("Exit", exit.button.x, exit.button.y, exit.button.height, BLACK);
	}
	else if (onButton(Rules))
	{
		DrawRectangle(Rules.button.x, Rules.button.y, Rules.button.width, Rules.button.height, WHITE);
		DrawText("Rules", Rules.button.x, Rules.button.y, Rules.button.height, BLACK);
	}
	
	DrawText("By: Juan Bautista Castignani",0 , GetScreenHeight() * 0.95, 25, WHITE);
	EndDrawing();

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