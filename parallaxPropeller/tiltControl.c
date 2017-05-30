/*
	tilting table controller
	Controls the positions of servos
*/
#include "tiltControl.h"
#include "servo.h"
#include "math.h"

TABLESTATE tableDelta;
TABLESTATE *debug;

//pitch and roll tuning offset values
int pitch_offset = 900;
int roll_offset = 900;

TABLESTATE* initTable(int *thread){
	tableDelta = (TABLESTATE){.pitch=0, .roll=0};
	return &tableDelta;
}

void running_Table(){
	TABLESTATE current = (TABLESTATE){.pitch=0, .roll=0};
 debug = &current;
	while(1){
		applyTableStateDeltas(&current, &tableDelta);
		pause(1);
	}
}

void setTableState(TABLESTATE *t){
	int pitch = t->pitch;
	int roll = t->roll;

	if(abs(pitch) > 20)
		pitch = (abs(pitch)/pitch)*20;
	
	if(abs(roll) > 20)
		roll = (abs(roll)/roll)*20;
   t->pitch = pitch;
   t->roll = roll;
   
   
	pitch *= 10;
	roll *= 10;

		//don't allow table tilt greater than 0 degrees 
		servo_angle(SERVO_0, pitch_offset + pitch);
		servo_angle(SERVO_1, roll_offset - roll);

		servo_angle(SERVO_2, pitch_offset - pitch);
		servo_angle(SERVO_3, roll_offset + roll);


		/*servo_angle(SERVO_0, 900);
		servo_angle(SERVO_1, 900);

		servo_angle(SERVO_2, 900);
		servo_angle(SERVO_3, 900);
*/
}

void applyTableStateDeltas(TABLESTATE* currentTableState, TABLESTATE* delta){
	currentTableState->pitch += delta->pitch;
	currentTableState->roll += delta->roll;
	delta->pitch = 0;
	delta->roll = 0;
	setTableState(currentTableState);
}