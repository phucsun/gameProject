#ifndef _FUNCTION__H
#define _FUNCTION__H

#include <iostream>
#include <math.h>
#include "defs.h"

void SlopeCalculation (int x1, int y1, int x2, int y2, float *dx, float *dy)
{
	int steps = max(abs(x1 - x2), abs(y1 - y2));
    if (steps == 0)
	{
		*dx = *dy = 0;
		return;
	}
    *dx = (x1 - x2);
	*dx /= steps;
    *dy = (y1 - y2);
	*dy /= steps;
}

#endif // _FUNCTION__H
