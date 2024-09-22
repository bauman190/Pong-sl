#include "Pause.h"
#include "Button.h"
#include "ScreenOptions.h"
#include "sl.h"
#include "sceneGameplay.h"

extern int screenWidth;
extern int screenHeight;


static Button resume;
static Button mainMenu;

extern inGameScene scene;
extern Screen currentScreen;



void inputPause()
{
	if (clickButton(resume))
	{
		scene = Game;
	}
	if (clickButton(mainMenu))
	{
		currentScreen = menu; 
		scene = Game;
	}
}

void drawPause()
{
	slSetTextAlign(SL_ALIGN_CENTER);
	slText(screenWidth * 0.5, screenHeight * 0.90, "Pause");
	slText(resume.button.x, resume.button.y, "Resume");
	slText(mainMenu.button.x, mainMenu.button.y, "Main Menu");
	if (onButton(resume))
	{
		slRectangleFill(resume.button.x, resume.button.y + resume.button.height / 2, resume.button.width, resume.button.height);
		slSetForeColor(0, 0, 0, 1);
		slText(resume.button.x, resume.button.y, "Resume");
		slSetForeColor(1, 1, 1, 1);
	}
	else if (onButton(mainMenu))
	{
		slRectangleFill(mainMenu.button.x, mainMenu.button.y + resume.button.height / 2, mainMenu.button.width, mainMenu.button.height);
		slSetForeColor(0, 0, 0, 1);
		slText(mainMenu.button.x, mainMenu.button.y, "Main Menu");
		slSetForeColor(1, 1, 1, 1);
	}
}

void inItPauseMenu()
{
	resume.button.x = screenWidth * 0.5;
	resume.button.y = screenHeight * 0.5;
	resume.button.width = slGetTextWidth("Resume");
	resume.button.height = slGetTextHeight("Resume");

	mainMenu.button.x = slGetTextWidth("Main Menu") / 2;
	mainMenu.button.y = slGetTextHeight("Main Menu");
	mainMenu.button.width = slGetTextWidth("Main Menu");
	mainMenu.button.height = slGetTextHeight("Main Menu");

}