/*
pid.h

Header file for pid controller
*/

#ifndef PID_H
#define PID_H
#if defined(__cplusplus)
extern "C" {
#endif

#include "simpletools.h"

typedef struct{
	int P; // Proportionality action constant  [arbitrary]
	int I; // Integration action constant      [arbitrary]
	int D; // Derivative action constant       [arbitrary]
} PIDConstants;

int pAction(PIDConstants c, int err);
int iAction(PIDConstants c, int uerr, int uTime);
int dAction(PIDConstants c, int uerr, int uTime);
int pid(PIDConstants c, int err, int lerr, int t0, int t1);

#if defined(__cplusplus)
}
#endif
#endif