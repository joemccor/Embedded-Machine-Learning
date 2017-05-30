/*
communication.h

Header file for communication functions
*/

#ifndef COMM_H__
#define COMM_H__

#include "simpletools.h"
#include "pid.h"
#include "ball.h"

PIDCONSTANTS* comPID;
BALLDATA* combBall;

float *err;
float *delt;

int *pitch;
int *roll;

void comm();

#endif /* COMM_H__*/