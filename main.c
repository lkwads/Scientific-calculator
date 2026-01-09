#include <stdio.h>
#include <stdlib.h>






//declaration of fonction
void print_logo();
float add(float x, float y);
float soust(float x, float y);
float multi(float x, float y);
double v_abs(double x);
float  Ln_x(float x);
double puissance(double x, int n);
float racine(float x, int order);
int factoriel(int x);
float division(float x, float y);
float inverse(float x);
float Exp_x(double x);
float cos_x(float x);
float sin_x(float x);
float tan_x(float x);





int main(){

	//variable declrations 
	float x, y;
	int opera, order ;
	double res ;
	char *symbole ,*string;
	char *string1, *string2 ;
	int error = 0, is_it = 0;

	do{
		printf("x = ");
		scanf("%f", &x);
		printf("y = ");
		scanf("%f", &y);
		print_logo();
		printf("choise opration: ");
		scanf("%d", &opera);


		switch (opera)
		{
		case 0:
			printf("exiting ... \n");
			break;
		case 1:
			res = multi(x , y);
			symbole = " * ";
			string = "x*y = ";
			break;
		case 2:
			res = add(x, y);
			string = "x+y = ";
			break ;
		case 3:
			res = soust(x,y);
			string = "x-y = ";
			break;
		case 4:
			res = factoriel(x);
			string = "x! = ";
			break;
		case 5:
			if(x<0){
				printf("negative numbers are not accepted \n");
				error = 1;
			}else{
				printf("what is order of this sqrt : ");
				scanf("%d", &order);
				res = racine(x, order);
				string = "√x = ";
			}
			break ;
		case 6:
			res = v_abs(x);
			string = "|x| = ";
			break;
		case 7 :
			if(y == 0){
				printf("[-] division by zero is not possible\n");
				error = 1;
			}else{
				res = division(x,y);
				string = "x/y = ";
			}
			break ;
		case 8:
			if(y < 1){
				if(y<0)
					res = 1/puissance(x , abs(y));
				else if(y == 0)
					res = 1 ;
				else
					printf("[-] not found right but you can calculating sqrt\n");
			}else 
				res = puissance(x,y);

			string = "x^y = ";
			break;
		case 9:
			if(x == 0){
				printf("negative numbers are not accepted \n");
				error = 1;
			}else
				res = inverse(x);
			string = "1/x = ";
			break;
		case 10:
			res = cos_x(x);
			string = "cos(x) = ";
			break;
		case 11:
			res = sin_x(x);
			string = "sin(x) = ";
			break;
		case 12 :
			res = tan_x(x);
			string = "tan(x) = ";
			break;
		case 13:
			res = Exp_x(x);
			string = "exp(x) = ";
			break;
		case 14:
			if(x<=0){
				printf("[-] this fonction is not defined in this domaine \n");
				error = 1;
			}else
				res = Ln_x(x);
				string = "ln(x) = ";
			break;
		default:
			printf("[-] this operation is not found !\n");
			break;
		}

		
		if(error == 0 && opera != 0){
			printf("%s %f\n", string, res);
		}
	} while(opera != 0);
	return 0;
}


float Ln_x(float x){
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



float Exp_x(double x) {

    const double inv_ln2 = 1.4426950408889634; // 1/ln(2)
    const double ln2 = 0.6931471805599453;

    // z = x / ln(2)
    float y = x * inv_ln2;

    // split z = k + r pour calcule 2^k et utilise polynome pour aproximation de 2^r
    int k = (int)y;
    float r = y - k;

    // polynomial approximation for 2^r
    float p = 1.0 + r * ln2 + 0.5 * (r * ln2) * (r * ln2);

    // build 2^k using exponent bits find 2^k with set k+127 in exponent place and set 0 in manitssa and bit of sign
    unsigned  bits = ((unsigned)(k + 127)) << 23;
    float two_k = *(float*)&bits;

	// return 2^k *2^r
    return two_k * p;
}




float cos_x(float x){

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



float sin_x(float x){


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



float tan_x(float x){

	// tan(x) = sin(x) / cos(x)
	return sin_x(x)/cos_x(x) ;
	
}




float add(float x , float y){
	return (x+y);
}



float division(float x, float y){
	return x/y ;
}


float soust(float x, float y){
	return (x-y);
}



float multi(float x, float y){
	return (x*y);
}



double v_abs(double x){
    return (x < 0) ? -x : x ;
}




double puissance(double x, int n){
	double re = 1.0 ;

	for(int i=1; i<=n; ++i){
		re *= x; 
	}
	return re;
}



// calcule f(x)
float f(float x, float y, int oredr){
    float z=1;
    for(int i = 1; i<=oredr ; i++){
        z *= x;
    }
    return z - y;
}



// derivie de la fonction 
float de_f(float x, int order){
    float z =1 ;
    for(int i=1; i<order; i++){
        z *= x;
    }
    return order*z;
}



// Function cacule racine avec la relation de  Newton-Raphson method
//this fonction you can choise order of root not just root 2
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


int factoriel(int x){
	// we strat from x and we finish in 1 this is factoriel 
	int res = 1;
	for(int i=x; i>1 ; i--){
		res *= i ;
	}
	return res ;
}



float inverse(float x){
	return 1/x;
}


void print_logo(){

	printf(

    "==============================================\n"
    "   	     SCIENTIFIC CALCULATOR        \n"
    "==============================================\n"
    " 	Select an operation by entering\n"
    " 	the corresponding number:\n\n"

    "  	  0  - Exit program\n\n"

    " 	Basic Operations:\n"
    "	  1  - Multiplication (*)\n"
    "	  2  - Addition (+)\n"
    "  	  3  - Subtraction (-)\n"
    "  	  7  - Division (/)\n\n"

    "	 Advanced Math:\n"
    "	  4  - Factorial (x!)\n"
    "	  5  - Square  (√x)\n"
    "	  6  - Absolute value |x|\n"
    "	  8  - Power (x^y)\n"
    "	  9  - Reciprocal (1/x)\n\n"

    "	 Trigonometric Functions:\n"
    "	 10  - Cosine cos(x)\n"
    "	 11  - Sine sin(x)\n"
    "	 12  - Tangent tan(x)\n\n"

    "	 Exponential & Logarithmic:\n"
    "	 13  - Exponential exp(x)\n"
    "	 14  - Natural logarithm ln(x)\n\n"

    "==================================================\n"
	"                                   by lkwads\n"

);

}



// by lkwads 
// all resource in the file resource you can learn more