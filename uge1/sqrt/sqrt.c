#include<stdio.h>
#include<math.h>
#include<complex.h>

int main() {

	double x = -2.0; 
	double complex z = csqrt(x);
		printf("Square root of %lf is %lf %lf\n", x, creal(z), cimag(z));
	return(0);

}
