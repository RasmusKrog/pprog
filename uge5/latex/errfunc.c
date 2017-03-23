#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>

double f (double x, void *params){
	  double f = 2.0/sqrt(M_PI)*exp(-x*x);
	    return f;
}

double err_fkt(double x) {
	int limit = 100;
	double epsabs = 1e-6, epsrel = 1e-6, result, abserr;
	gsl_function F;
	F.function = &f;
	F.params = NULL;

	gsl_integration_workspace *w = gsl_integration_workspace_alloc(limit);
	gsl_integration_qags (&F, 0, x, epsabs, epsrel, limit, w, &result, &abserr);
	return result;
}
