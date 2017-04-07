//positionAcquisition
typedef struct{
	int x;    // x position      [pixels]
	int y;    // y position      [pixels]
	int xerr; // error in x      [pixels]
	int yerr; // error in y      [pixels]
	int lxerr;// last error in x [pixels]
	int lyerr;// last error in y [pixels]
} positionData;

positionData getTargetUpdate(){
	positionData t = {0, 0, 0, 0, 0, 0};
	//read serial communications and parse into t
		//info is received in format: [{currentX}, {currentY}, {desiredX}, {desiredY}]
	//compute xerr, yerr, lxerr,lyerr
	return t;
}

void hello(){
	getTargetUpdate();
}