#include <stdio.h>
#include <math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multimin.h>

double rosenbrock(const gsl_vector *v, void *params) {
	double x = gsl_vector_get(v, 0);
	double y = gsl_vector_get(v, 1);
	return pow((1 - x), 2) + 100 * pow((y - (x * x)), 2);
}

int main() {
	int status;
	int iter = 0;
	double dim = 2, eps = 1e-3;
	double step = 0.1;
	const gsl_multimin_fminimizer_type *T = gsl_multimin_fminimizer_nmsimplex2;
	gsl_vector *ss, *x;

// Initialising method
	gsl_multimin_function F;
	F.f = rosenbrock;
	F.n = dim;

	gsl_multimin_fminimizer *s = gsl_multimin_fminimizer_alloc(T, dim);

// Creating Starting point with additional step size
	x = gsl_vector_alloc(dim);
	gsl_vector_set(x, 0, 2);
	gsl_vector_set(x, 1, 2);
	ss = gsl_vector_alloc(dim);
	gsl_vector_set_all(ss, step);
	
	gsl_multimin_fminimizer_set(s, &F, x, ss);

	do {
		iter++;
		status = gsl_multimin_fminimizer_iterate(s);

		if (status != 0)
											break;	
	
		status = gsl_multimin_test_size(s->size, eps);
		if (status == GSL_SUCCESS)
		
		printf("Convergence, minimum found at: \n");
		printf("%5d %.5f %.5f %8g %8g\n", iter,
		
	gsl_vector_get(s->x, 0), gsl_vector_get(s->x, 1),
	s->fval, s->size);
} 

	while (status == GSL_CONTINUE && iter < 100);

	gsl_vector_free(x);
	gsl_vector_free(ss);
	gsl_multimin_fminimizer_free(s);

return status;
}
