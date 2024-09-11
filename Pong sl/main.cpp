#include "sl.h"

void main()
{

	slWindow(960, 540, "Pong", false);

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
		slSetForeColor(0.1, 0.9, 0.2, 0.4);
		slRectangleFill(200, 240, 100, 7);
		slRender();
	}
	slClose();
}