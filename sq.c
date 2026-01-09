#include <stdio.h>
#include <stdlib.h>



// calcule f(x)
float f(float x, float y, int oredr){
    float z=1;
    for(int i = 1; i<=oredr ; i++){
        z *= x;
    }
    return z - y;
}

//calcule f'(x)
float de_f(float x, int order){
    float z =1 ;
    for(int i=1; i<order; i++){
        z *= x;
    }
    return order*z;
}



// Function cacule square with  Newton-Raphson method
//this fonction you can choise order of square not just sqrt root
float racine(float x, int order)
{
    const float difference = 0.00001;

        //intisalisation of xn for Newton-Raphson methode 
    float  x_n = x/order;

        // loop stop when xn^2 - N < 0.00001 to take aproximation evry smaller ro real result
    while(abs(f(x_n, x, order)) >= difference){

                // xn+1 = xn - f(xn)/f'(xn)
        x_n = x_n - f(x_n,x, order)/de_f(x_n, order) ;
    }
    return x_n;
}


