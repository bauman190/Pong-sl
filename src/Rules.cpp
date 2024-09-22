#include "Rules.h"
#include "Button.h"
#include "ScreenOptions.h"
#include "sl.h"

extern Screen currentScreen;

static Button back;

extern int screenHeight;
extern int screenWidth;

void drawRules()
{
	slText(screenWidth * 0.5, screenHeight * 0.90, "Rules");
	slSetTextAlign(SL_ALIGN_LEFT);
	slSetFontSize(30);
	slText(0, screenHeight * 0.6, "First to score 5 Wins");
	slText(0, screenHeight * 0.5, "Player 1: Up: W  , Down: S");
	slText(0, screenHeight * 0.4, "Player 2: Up: UP Key  , Down: Down Key");
	slText(0, screenHeight * 0.25, "Pause : P");

	slSetFontSize(50);
	slSetTextAlign(SL_ALIGN_CENTER);
	slText(back.button.x, back.button.y, "Back");


	if (onButton(back))
	{
		slRectangleFill(back.button.x, back.button.y + back.button.height / 2, back.button.width, back.button.height);
		slSetForeColor(0, 0, 0, 1);
		slText( back.button.x, back.button.y, "Back");
		slSetForeColor(1, 1, 1, 1);
	}
	
}

void inputRules()
{
	if (clickButton(back))
	{
		currentScreen = menu;
	}
}

void inItRules()
{
	back.button.width = slGetTextWidth("Back");
	back.button.height = slGetTextHeight("Back");
	back.button.x = back.button.width / 2;
	back.button.y = back.button.height / 2;
}