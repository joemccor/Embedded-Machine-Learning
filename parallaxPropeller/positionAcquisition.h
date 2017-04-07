/*
positionAcquisition.h

Header file for the position acquisition functions
*/

#ifndef POSITIONACQUISITION_H
#define POSITIONACQUISITION_H
#if defined(__cplusplus)
extern "C" {
#endif

#include "simpletools.h"

typedef struct{
	int x;    	// x position      [pixels]
	int y;    	// y position      [pixels]
	int xerr; 	// error in x      [pixels]
	int yerr; 	// error in y      [pixels]
	int lxerr;	// last error in x [pixels]
	int lyerr;	// last error in y [pixels]
} positionData;

positionData getTargetUpdate();
void hello();

#if defined(__cplusplus)
}
#endif
#endif