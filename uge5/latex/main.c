#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>

double err_fkt(double x);

int main(int argc, char *argv[]) {
	double input[3];
	for(int i = 1; i < argc; i++) {input[i-1]=atof(argv[i]);}
	double a = input[0];
	double b = input[1];
	double dx = input[2];

	printf("x\terrfunc\n");
	double value;
	for(double x = a; x<b; x+=dx){
	value = err_fkt(x);
	printf("%g\t%g\n", x, value);
}
	return 0;
}
