#include <stdio.h>
#include <stdlib.h>

float sin(float x){
   const double PI = 3.141592653589793;

    // divise x/2pi and convert it to int and multiple 2*pi (13/2pi = 3.6 and 3.6 =3 int 3*2pi and we find the x with 2*pi*k + x )
    x = x - (int)(x / (2*PI)) * (2*PI);

	//this to get x in[-pi , pi] , taylor methode work perfect in 0 
    if (x > PI) 
		x -= 2*PI;

    if (x < -PI) 
		x += 2*PI;

    double x2 = x * x;

	//taylor young methode for sin
	double sin_x = x - x2*x/factoriel(3) + x2*x2*x/factoriel(5) -x2*x2*x2*x/factoriel(7) ;

	return sin_x ;
}
