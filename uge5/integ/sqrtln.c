#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>

double func (double x) {
	double f = (log(x) / sqrt(x));
	return f;
}

int main(void) {
	double start = 0, end = 1;
	double epsrel = 1e-6, epsabs = 1e-6;
	double n = 1000;
	double result, error;

	gsl_integration_workspace * w = gsl_integration_workspace_alloc(n);

	gsl_function F;
	F.function = &func;

// Next up adaptive integration using sing.
	gsl_integration_qags(&F, start, end, epsabs, epsrel, n, w, &result, &error); 

	printf("Result = %.12f\n", result);
	printf("Estimated error = %.12f\n", error);

	gsl_integration_workspace_free(w);
return 0;
}
