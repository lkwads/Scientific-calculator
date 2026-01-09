#include <stdio.h>
#include <stdlib.h>


int fact(int x){

        int res = 1;
        for(int i=x; i>1 ; i--){
                res *= i ;
        }
        return res ;



}
