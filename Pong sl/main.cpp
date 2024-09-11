#include "sl.h"
#include "Ball.h"


float screenHeight = 540;
float screenWidth = 960;

void main()
{
	Ball ball;
	inItBall(ball);
	slWindow(screenWidth, screenHeight, "Pong", false);

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
		ballMovment(ball);
		slSetForeColor(0.5, 0.9, 0.5, 0.7);
		slRectangleFill(ball.hitBox.x, ball.hitBox.y,ball.hitBox.width, ball.hitBox.height);
		slSetForeColor(1, 1, 1,1);
		slCircleFill(ball.pos.x, ball.pos.y, ball.radius, 20);
		slRender();
	}
	slClose();
}