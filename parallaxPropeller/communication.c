#include "simpleTools.h"
#include "communication.h"
#include "tiltControl.h"

PIDCONSTANTS* comPID;
BALLDATA* combBall;

int *pitch;
int *roll;

float *err;
float *delt;
void comm(){
	char c = 'c';
	float val = 0;

	simpleterm_open();

	while(1){
		printf("pitch:%d, roll:%d", (int)(*pitch)*10 , (int)(*roll)*10);

		scanf("%c:%f", &c, &val);
		switch( c ){
			case 'p':
				*pitch = val;
				break;
			case 'r':
				*roll = val;
				break;
			case 'P':
				comPID->P = val;
          printf("Change P");
				break;
			case 'I':
				comPID->I = val;
          printf("Change I");
				break;
			case 'D':
				comPID->D = val;
          printf("Change D");
				break;
			case 'x':
				updateBallX(combBall, (int)val);
          printf("ballX = %d", combBall->x);
				break;
			case 'y':
				updateBallY(combBall, (int)val);
          printf("ballY = %d", combBall->y);
				break;
			case 'X':
				updateBallXTarget(combBall, (int)val);
          printf("tarX = %d", combBall->xTarget);
				break;
			case 'Y':
				updateBallYTarget(combBall, (int)val);
          printf("tarY = %d", combBall->yTarget);
				break;
			case 'R':
				printf("P%f, I%f, D%f", comPID->P, comPID->I,comPID->D);
		}
	}
}
