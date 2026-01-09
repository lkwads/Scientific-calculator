#include <stdio.h>
#include <stdlib.h>


float log(float x){
// for take exponent and mantisa from bx 
	unsigned int bx = * (unsigned int *) (&x);
	// shift mantisa for take just exponent right now bit of sign and expoenet in ex variable 
	unsigned int ex = bx >> 23;

	// ex valeur - 127 to find t t is used for cacule t*ln(2)
	signed int t = (signed int)ex-(signed int)127;
	unsigned int s = (t < 0) ? (-t) : t; 

	// this 1065353216 is 1 in float and this (bx & 8388607) take mantisa partie from bx  and right now bx = mantissa valeu + 1 so bx = epsilone
	bx = 1065353216 | (bx & 8388607);
	x = * (float *) (&bx);
	// this repsente ln(epsilone ) with 1<= epsilone <= 2 and this 0.6931471806*abs(t) for cacule ln(2)*t and restunr result
	return -1.49278+(2.11263+(-0.729104+0.10969*x)*x)*x+0.6931471806*t;
}
