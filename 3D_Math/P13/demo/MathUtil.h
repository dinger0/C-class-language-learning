#ifndef MATHUTIL_H
#define MATHUTIL_H

#include <math.h>


const float kPi = 3.14159265f;
const float k2Pi = kPi * 2;
const float kPiOver2 = kPi / 2.0f;


inline void sinCos(float *returnSin, float *returnCos, float theta)
{
	*returnSin = sin(theta);
	*returnCos = cos(theta);
}


#endif
