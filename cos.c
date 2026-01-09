#include <stdio.h>
#include <stdlib.h>


float cos(float x){
    const double PI = 3.141592653589793;

    // divise x/2pi and convert it to int and multiple 2*pi (13/2pi = 3.6 and 3.6 =3 int 3*2pi and we find the x with 2*pi*k + x )
    x = x - (int)(x / (2*PI)) * (2*PI);

	//this to get x in[-pi , pi] , taylor methode work perfect in 0 
    if (x > PI)  x -= 2*PI;
    if (x < -PI) x += 2*PI;

    double x2 = x * x;


	//taylor-young methode for cos
    double cos_x =
        1
        - x2 / 2
        + x2 * x2 / 24
        - x2 * x2 * x2 / 720
        + x2 * x2 * x2 * x2 / 40320;

		return cos_x ;
}
