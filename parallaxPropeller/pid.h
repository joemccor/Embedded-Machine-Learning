/*
pid.h

Header file for pid controller
*/

#ifndef PID_H__
#define PID_H__

/*you header file can have declarations here*/

#include "simpletools.h"
#include "mstimer.h"

typedef struct{
	volatile float P; // Proportionality action constant  [arbitrary]
	volatile float I; // Integration action constant      [arbitrary]
	volatile float D; // Derivative action constant       [arbitrary]
} PIDCONSTANTS;

typedef struct{
	volatile float err;
	volatile float delta;

	float lastError;
	int time;
	int lastTime;
	PIDCONSTANTS constants;
} PIDINTERFACE;

PIDINTERFACE* pidController;

char pidCount;

void initPIDs(char count);

void running_pid();

float pAction(PIDCONSTANTS* c, float err);

float iAction(PIDCONSTANTS* c, float uerr, int uTime);

float dAction(PIDCONSTANTS* c, float uerr, int uTime);

void pid(PIDINTERFACE* pid);

#endif /* PID_H__*/