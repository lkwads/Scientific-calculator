#include <stdio.h>
#include <stdlib.h>

// Declaration of functions
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

	// Variable declarations
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
		printf("Choice of operation: ");
		scanf("%d", &opera);

		switch (opera)
		{
		case 0:
			printf("Exiting ... \n");
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
				printf("Negative numbers are not accepted \n");
				error = 1;
			}else{
				printf("What is the order of this sqrt? ");
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
				printf("[-] Division by zero is not possible\n");
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
					printf("[-] Not found correct value, but you can calculate sqrt\n");
			}else 
				res = puissance(x,y);

			string = "x^y = ";
			break;
		case 9:
			if(x == 0){
				printf("Negative numbers are not accepted \n");
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
				printf("[-] This function is not defined in this domain \n");
				error = 1;
			}else
				res = Ln_x(x);
				string = "ln(x) = ";
			break;
		default:
			printf("[-] This operation is not found!\n");
			break;
		}

		
		if(error == 0 && opera != 0){
			printf("%s %f\n", string, res);
		}
	} while(opera != 0);
	return 0;
}

float Ln_x(float x){
	// Take exponent and mantissa from bx
	unsigned int bx = * (unsigned int *) (&x);
	// Shift mantissa to extract only exponent bits into ex variable
	unsigned int ex = bx >> 23;

	// Subtract 127 from exponent to find t, which is used to calculate t*ln(2)
	signed int t = (signed int)ex-(signed int)127;
	unsigned int s = (t < 0) ? (-t) : t; 

	// 1065353216 represents 1 in float, and (bx & 8388607) extracts the mantissa
	// Now bx = mantissa value + 1, so bx = epsilon
	bx = 1065353216 | (bx & 8388607);
	x = * (float *) (&bx);
	// This represents ln(epsilon) with 1 <= epsilon <= 2, and 0.6931471806*abs(t) calculates ln(2)*t, then returns result
	return -1.49278+(2.11263+(-0.729104+0.10969*x)*x)*x+0.6931471806*t;
}

float Exp_x(double x) {

    const double inv_ln2 = 1.4426950408889634; // 1/ln(2)
    const double ln2 = 0.6931471805599453;

    // z = x / ln(2)
    float y = x * inv_ln2;

    // Split z = k + r to calculate 2^k and use polynomial for approximation of 2^r
    int k = (int)y;
    float r = y - k;

    // Polynomial approximation for 2^r
    float p = 1.0 + r * ln2 + 0.5 * (r * ln2) * (r * ln2);

    // Build 2^k using exponent bits, set k+127 in exponent and 0 in mantissa and sign bit
    unsigned  bits = ((unsigned)(k + 127)) << 23;
    float two_k = *(float*)&bits;

	// Return 2^k * 2^r
    return two_k * p;
}

float cos_x(float x){

    const double PI = 3.141592653589793;

    // Reduce x modulo 2*pi and convert to [-pi, pi]
    x = x - (int)(x / (2*PI)) * (2*PI);
    if (x > PI)  x -= 2*PI;
    if (x < -PI) x += 2*PI;

	double x2 = x * x;

	// Taylor-Young method for cosine
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

    // Reduce x modulo 2*pi and convert to [-pi, pi]
    x = x - (int)(x / (2*PI)) * (2*PI);
    if (x > PI) 
		x -= 2*PI;
    if (x < -PI) 
		x += 2*PI;

	double x2 = x * x;

	// Taylor-Young method for sine
	double sin_x = x - x2*x/factoriel(3) + x2*x2*x/factoriel(5) -x2*x2*x2*x/factoriel(7) ;

	return sin_x ;
}

float tan_x(float x){
	// tan(x) = sin(x)/cos(x)
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

// Calculate f(x)
float f(float x, float y, int order){
    float z=1;
    for(int i = 1; i<=order ; i++){
        z *= x;
    }
    return z - y;
}

// Derivative of the function
float de_f(float x, int order){
    float z =1 ;
    for(int i=1; i<order; i++){
        z *= x;
    }
    return order*z;
}

// Calculate root using Newton-Raphson method
// You can choose the order of the root, not just square root
float racine(float x, int order)
{
    const float difference = 0.00001;

	// Initialization of x_n for Newton-Raphson method
    float  x_n = x/order;

	// Loop stops when xn^order - N < 0.00001 to approximate the real result
    while(abs(f(x_n, x, order)) >= difference){
		
		// xn+1 = xn - f(xn)/f'(xn)
        x_n = x_n - f(x_n,x, order)/de_f(x_n, order) ;
    }
    return x_n;
}

int factoriel(int x){
	// Calculate factorial from x down to 1
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

// by mohamed soussi
// All resources are in the resource file. You can learn more.
