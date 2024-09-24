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

	slText(screenWidth / 2, screenHeight * 0.80, "PONG");

	slText(play.button.x, play.button.y - play.button.height / 2, "Play");
	slText( Rules.button.x, Rules.button.y - Rules.button.height / 2, "Rules");
	slText( exit.button.x, exit.button.y - exit.button.height / 2, "Exit");
	if (onButton(play))
	{
		slRectangleFill(play.button.x, play.button.y, play.button.width, play.button.height);
		slSetForeColor(0, 0, 0, 1);
		slText(play.button.x, play.button.y - play.button.height / 2, "Play");
		slSetForeColor(1, 1, 1, 1);
	}
	else if (onButton(exit))
	{
		slRectangleFill(exit.button.x, exit.button.y, exit.button.width, exit.button.height);
		slSetForeColor(0, 0, 0, 1);
		slText(exit.button.x, exit.button.y - exit.button.height / 2, "Exit");
		slSetForeColor(1, 1, 1, 1);
	}
	else if (onButton(Rules))
	{
		slRectangleFill(Rules.button.x, Rules.button.y, Rules.button.width, Rules.button.height);
		slSetForeColor(0, 0, 0, 1);
		slText(Rules.button.x, Rules.button.y - Rules.button.height / 2, "Rules");
		slSetForeColor(1, 1, 1, 1);
	}
	slSetFontSize(20);
	slSetTextAlign(SL_ALIGN_LEFT);
	slText(0,screenHeight * 0.05, "By: Juan Bautista Castignani");
	slSetTextAlign(SL_ALIGN_CENTER);
	slSetFontSize(50);

}

void inItMenu()
{
	
	play.button.x = screenWidth / 2 ;
	play.button.y = screenHeight / 2;
	play.button.width = slGetTextWidth("Play");
	play.button.height = slGetTextHeight("Play");


	Rules.button.x = screenWidth / 2;
	Rules.button.y = screenHeight * 0.325;
	Rules.button.width = slGetTextWidth("Rules");
	Rules.button.height = slGetTextHeight("Rules");

	exit.button.x = screenWidth / 2 ;
	exit.button.y = screenHeight * 0.15;
	exit.button.width = slGetTextWidth("Exit");
	exit.button.height = slGetTextHeight("Exit");



}