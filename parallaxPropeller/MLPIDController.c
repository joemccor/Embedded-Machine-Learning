/*
	Tilty-Table
	By Joseph McCormick
		
	Cog assignments:
		1. Main     - Initilization
		2. COMM     - Continuous communication with PC for ball position updates and system reporting
		2. PID      - Continuously calculate response of PID controller
		3. TABLE    - Continuously manage servos based on current tablestate
		4. ANN      - Continuously perform evaluation and updating of PID controller
*/
#include "simpletools.h"

#include "ball.h"
#include "pid.h"
#include "tiltControl.h"
#include "communication.h"

int main()
{
  int settlingTime = 10;
	//cog pointers
	printf("init cog pointers\n");
	int* ball_cog, pid_cog, table_cog, comm_cog;

	//initialize a ball
	printf("init ball state\n");
	BALLDATA ball = initBall();
  calculateBallPositionError(&ball);

	//initialized the PID controllers and run them
	printf("init PIDs\n");
	PIDINTERFACE pids[2];
	pidController = pids;
	initPID();
	initPID();
	pid_cog = cog_run(running_pid, 64);

	//initialize the table state and run the table manager
	printf("init table\n");
	TABLESTATE* table = initTable();
	table_cog = cog_run(running_Table, 64);

	//Communication
	printf("switching communication service\n");
	simpleterm_close();

	combBall = &ball;
	comPID = &(pids[0].constants);

	pitch = &(debug->pitch);
	roll = &(debug->roll);
	
	err = &(pids[1].delta);
	delt = &(pids[0].delta);
	
	comm_cog = cog_run(comm, 64);
 
 pause(10);
		calculateBallPositionError(&ball);

		//update PID controllers
		//x, roll
		pids[0].err = (float)ball.xError;
		//y, pitch
		pids[1].err = (float)ball.yError;
		pids[1].constants = pids[0].constants;
 
 pause(10); 
 		int lastxVel = 0;
 		int lastyVel = 0;

 		int xAccel = 0;
 		int yAccel = 0;
   int tsquared = (settlingTime*settlingTime);
	while(1)
	{
		//update communications and ball error
		calculateBallPositionError(&ball);
		calculateNeededAccel(&ball, pids[0].time - pids[0].lastTime);
    
		xAccel = (lastxVel - ball.xVel);
		yAccel = (lastyVel - ball.yVel);


		//update PID controllers
		//x, roll
    pids[0].err = (float)(ball.xAccelNeeded - xAccel);
		//y, pitch
    pids[1].err = (float)(ball.yAccelNeeded - yAccel);
		pids[1].constants = pids[0].constants;
  
		//update table tilt
		table->pitch = (int)(pids[0].delta);//x
		table->roll = (int)(pids[1].delta);//y
		pause(1);
	}
}