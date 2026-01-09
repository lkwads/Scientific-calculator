#include <stdio.h>
#include <stdlib.h>


float pow(float x, int n){
        double re = 1.0 ;

        for(int i=1; i<=n; ++i){
                re *= x; 
        }
        return re;
}
