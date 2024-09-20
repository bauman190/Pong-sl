#include "Button.h"
#include "sl.h"


bool collitionPointRec(Button button, int pointX, int pointY);

bool clickButton(Button button)
{

	if (collitionPointRec(button, slGetMouseX(), slGetMouseY()) && slGetMouseButton(SL_MOUSE_BUTTON_1))
	{
		return true;
	}
	return false;
}

bool onButton(Button button)
{

	if (collitionPointRec(button, slGetMouseX(), slGetMouseY()))
	{
		return true;
	}
	return false;
}

bool collitionPointRec(Button button, int pointX, int pointY)
{
	if (button.button.x - button.button.width /2 < pointX && 
		button.button.x + button.button.width / 2 > pointX &&
		button.button.y - button.button.height / 2 < pointY &&
		button.button.y + button.button.height / 2 < pointY)
	{
		return true;
	}
	return false;
}
