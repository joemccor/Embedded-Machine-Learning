/*
ball.h

Header file for ball data and updating/calculation functions
*/

#ifndef BALL_H__
#define BALL_H__

#include "simpletools.h"

typedef struct{
	volatile int x; 		   // x position of ball in camera FOV 			[pixels]
	volatile int y;			// y position of ball in camera FOV     		[pixels]
	volatile int lastX;		// x position of ball in camera FOV 			[pixels]
	volatile int lastY;		// y position of ball in camera FOV     		[pixels]
	volatile int xTarget;	// x-target position of ball in camera FOV		[pixels]
	volatile int yTarget;	// y-target position of ball in camera FOV		[pixels]
	volatile int xVel;		// x-velocity of ball in camera FOV				[pixels]
	volatile int yVel;		// y-velocity of ball in camera FOV				[pixels]
	volatile int xError;	// x-error in ball position in camera FOV		[pixels]
	volatile int yError;	// y-error in ball position in camera FOV		[pixels]
	volatile int xAccelNeeded;
	volatile int yAccelNeeded;
} BALLDATA;

BALLDATA initBall();

void updateBallX(BALLDATA* bd, int newX);

void updateBallY(BALLDATA* bd, int newY);

void updateBallXTarget(BALLDATA* bd, int newX);

void updateBallYTarget(BALLDATA* bd, int newY);

void calculateBallVelocity(BALLDATA* bd);

void calculateBallPositionError(BALLDATA* bd);

void calculateNeededAccel(BALLDATA* bd, int settlingTime);

#endif /* BALL_H__*/