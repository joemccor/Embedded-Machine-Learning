#include "simpletools.h"
#include "ball.h"

BALLDATA initBall()
{
	BALLDATA b = (BALLDATA){
		.x = 0,
		.y = 0,
		.lastX = 0,
		.lastY = 0,
		.xTarget = 0,
		.yTarget = 0,
		.xVel = 0,
		.yVel = 0,
		.xError = 0,
		.yError = 0
	};
	return b;
}

void updateBallX(BALLDATA* bd, int newX)
{
	bd->lastX = bd->x;
	bd->x = newX;
}

void updateBallY(BALLDATA* bd, int newY)
{
	bd->lastY = bd->y;
	bd->y = newY;
}

void updateBallXTarget(BALLDATA* bd, int newX)
{
	bd->xTarget = newX;
}

void updateBallYTarget(BALLDATA* bd, int newY)
{
	bd->yTarget = newY;
}

void calculateBallVelocity(BALLDATA* bd)
{
	bd->xVel = bd->lastX - bd->x;
	bd->yVel = bd->lastY - bd->y;
}

void calculateBallPositionError(BALLDATA* bd)
{
  calculateBallVelocity(bd);
	bd->xError = bd->xTarget - bd->x;
	bd->yError = bd->yTarget - bd->y;
}

void calculateNeededAccel(BALLDATA* bd, int settlingTime){
  int halfSettling = settlingTime/2;
	bd->xAccelNeeded = 2*(bd->xError - settlingTime*bd->xVel)/(halfSettling*halfSettling);
	bd->yAccelNeeded = 2*(bd->yError - settlingTime*bd->yVel)/(halfSettling*halfSettling);
}