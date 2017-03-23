#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>

double trialhamiltoniantrial(double x, void * params) {
	double alpha = *(double *) params;
	double f = ((- alpha * alpha * x * x)/2 + alpha/2 + (x * x)/2) * exp(- alpha * x * x);
	return f;
}

double trialtrial(double x, void * params) {
	double alpha = *(double *) params;
	double f = exp( - alpha * x * x);
	return f;
}

int main(void) {
	double epsabs = 1e-6, epsrel = 1e-6;
	double n = 1000, alpha_start = 0.1, alpha_max = 5.0, delta_alpha=0.1;
	double psiHpsi, pHperror;
	double psipsi, pperror;
	printf("a\tE(a)\n");
for (double alpha = alpha_start; alpha < alpha_max; alpha += delta_alpha) {
	gsl_integration_workspace * w = gsl_integration_workspace_alloc(n);
	gsl_integration_workspace * q = gsl_integration_workspace_alloc(n);

	gsl_function F;
	F.function = &trialhamiltoniantrial;

	gsl_function G;
	G.function = &trialtrial;

	F.params = &alpha;
	gsl_integration_qagi(&F, epsabs, epsrel, n, w, &psiHpsi, &pHperror);

	G.params = &alpha;
	gsl_integration_qagi(&G, epsabs, epsrel, n, q, &psipsi, &pperror);
	
	double E = psiHpsi / psipsi;
	printf("%g\t%g\n", alpha, E);

	gsl_integration_workspace_free(w);
	gsl_integration_workspace_free(q);
}
return 0;
}

