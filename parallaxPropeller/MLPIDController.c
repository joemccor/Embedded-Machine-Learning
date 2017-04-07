#include "simpletools.h"
#include "pid.h"
#include "positionAcquisition.h"
#include "ann.h"

int main()
{
	tableState table = tableInit();
	position pos = positionInit();
	tableState delta = {0, 0};
	PIDConstants PID = {0, 0, 0};

	while(1)
	{
		getPositionUpdate(&pos);
		pid(PID, pos.err, pos.lerr)
		tiltTableBy(&table, &delta);
	}  
}
