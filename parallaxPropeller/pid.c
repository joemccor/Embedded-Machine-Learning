#include "pid.h"
#include "simpletools.h"
#include "mstimer.h"

PIDINTERFACE* pidController;

char pidCount;

void initPID()
{
	pidController[pidCount] = (PIDINTERFACE){
    .err = 0.0,
    .lastError=0.0,
    .time = 0,
    .lastTime = 0,
    .delta = 0.0,
    .constants = (PIDCONSTANTS){.P=0.5, .I=0.0, .D=0.0}
  };
	pidCount++;
}

void running_pid()
{
	int counter = 0;
	mstime_start();
	while(1){
		pid( &(pidController[counter]) );
		counter = (counter+1) % pidCount;
		pause(1);
	}
}

float pAction(PIDCONSTANTS* c, float err)
{
	return c->P * err;
}

float iAction(PIDCONSTANTS* c, float uerr, int uTime)
{
	return c->I * (uerr * uTime);
}

float dAction(PIDCONSTANTS* c, float uerr, int uTime)
{
	return c->D * (uerr / uTime);
}

void pid(PIDINTERFACE* pid)
{
	//time
	pid->time = mstime_get();
	int tDiff = pid->time - pid->lastTime;
	pid->lastTime = pid->time;

	//error
	float errDiff = (pid->err - pid->lastError);
	pid->lastError = pid->err;

	//PID controller
	PIDCONSTANTS* constants = &(pid->constants);
	float proportional = pAction(constants, pid->err);
	float integral = iAction(constants, errDiff, tDiff);
	float differential = dAction(constants, errDiff, tDiff);
	pid->delta = ( proportional + integral + differential );
}