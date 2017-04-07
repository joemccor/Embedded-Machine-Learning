typedef struct{
	int P; // Proportionality action constant  [arbitrary]
	int I; // Integration action constant      [arbitrary]
	int D; // Derivative action constant       [arbitrary]
} PIDConstants;

int pAction(PIDConstants c, int err)
{
	return c.P * (err);
}

int iAction(PIDConstants c, int uerr, int uTime)
{
	return c.I * (uerr * uTime);
}

int dAction(PIDConstants c, int uerr, int uTime)
{
	return c.D * (uerr / uTime);
}

int pid(PIDConstants c, int err, int lerr, int t0, int t1)
{
	int tDiff = (t0 - t1);
	int errDiff = (err - lerr);
	return ( pAction(c, errDiff) + iAction(c, errDiff, tDiff) + dAction(c, errDiff, tDiff) );
}