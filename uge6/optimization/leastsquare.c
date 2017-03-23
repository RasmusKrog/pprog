#include <stdio.h>
#include <math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multimin.h>
#include <assert.h>

struct exp_data {int n; double *t, *y, *e;};

double deviation(const gsl_vector *x, void *params) {
	double A = gsl_vector_get(x, 0); // initial amount
	double T = gsl_vector_get(x, 1); // lifetime
	double B = gsl_vector_get(x, 2); // background noise

	struct exp_data *p = (struct exp_data*) params;

	int n = p->n;
	double *t = p->t;
	double *y = p->y;
	double *e = p->e;

	double sum = 0;

for (int i = 0; i < n; i++) {
	double f = A * exp(-t[i] / T) + B;
	sum += pow(f - y[i], 2) / pow(e[i], 2);
	}
return sum;
}

int main() {
	int status;
	int iter = 0;
	const int dim = 3;
	const double eps = 1e-3, step = 1;
	const gsl_multimin_fminimizer_type *T = gsl_multimin_fminimizer_nmsimplex2;

// Loading data given from exercise sheet
	double t[]= {0.47,1.41,2.36,3.30,4.24,5.18,6.13,7.07,8.01,8.95};
	double y[]= {5.49,4.08,3.54,2.61,2.09,1.91,1.55,1.47,1.45,1.25};
	double e[]= {0.26,0.12,0.27,0.10,0.15,0.11,0.13,0.07,0.15,0.09};

	int n = sizeof(t) / sizeof(t[0]);
	assert(n == sizeof(y) / sizeof(y[0]) && n == sizeof(e) / sizeof(e[0]));

	printf("# t\ty\te");
	for(int i = 0; i < n; i++) {
	printf("%g\t%g\t%g\n", t[i], y[i], e[i]);
}
	printf("\n\n");

	struct exp_data params; // specify a method parameter that takes a variable number of arguments
	params.n=n;
	params.t=t;
	params.y=y;
	params.e=e;

	gsl_multimin_function F;
	F.f = deviation;
	F.n = dim;
	F.params = (void*) &params;

	gsl_vector *x = gsl_vector_alloc(dim);
	gsl_vector_set(x, 0, 3);
	gsl_vector_set(x, 1, 2);
	gsl_vector_set(x, 2, 0);

	gsl_vector *ss = gsl_vector_alloc(dim);
	gsl_vector_set_all(ss, step);

// Initialise process
	gsl_multimin_fminimizer *s = gsl_multimin_fminimizer_alloc(T, dim);
	gsl_multimin_fminimizer_set(s, &F, x, ss);

	do {
		iter++;
		status = gsl_multimin_fminimizer_iterate(s);

	if (status != 0)
		break;

	status = gsl_multimin_test_size(s->size, eps);

	if (status == GSL_SUCCESS)
		fprintf(stderr, "Convergence, minimum found at: \n");
		fprintf(stderr, "%5d %.5f %.5f %.5f %8g %8g\n", iter,
	gsl_vector_get(s->x, 0), gsl_vector_get(s->x, 1), gsl_vector_get(s->x, 2),
	s->fval, s->size);
}

while (status == GSL_CONTINUE && iter < 100);
	
	double A = gsl_vector_get(s->x, 0);
	double Tr = gsl_vector_get(s->x, 1);
	double B = gsl_vector_get(s->x, 2);

	printf("# t, A*exp(-t/T)+B\n");
	double dt = (t[n-1] - t[0]) / 50;
	for (double ti = t[0]; ti < t[n-1] + dt; ti +=dt) {
	printf("%g\t%g\n", ti, A*exp(-ti/Tr)+B);
}

	gsl_vector_free(x);
	gsl_vector_free(ss);
	gsl_multimin_fminimizer_free(s);

return status;
}
