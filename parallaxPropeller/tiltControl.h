/*
tiltControl.h

Header file for tiltControl
*/

#include "simpletools.h"
#include "servo.h"

//servo connections
#define SERVO_0 14
#define SERVO_1 10
#define SERVO_2 16
#define SERVO_3 15


typedef struct{
	volatile int pitch;
	volatile int roll;
} TABLESTATE;

TABLESTATE tableDelta;
TABLESTATE *debug;


//pitch and roll tuning offset values
int pitch_offset;
int roll_offset;

TABLESTATE* initTable();
void updateTable(TABLESTATE* t);
void running_Table();
void setTableState(TABLESTATE *t);
void applyTableStateDeltas(TABLESTATE* currentTableState, TABLESTATE *deltas);