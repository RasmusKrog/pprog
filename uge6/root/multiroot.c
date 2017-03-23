#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
#include <gsl/gsl_errno.h> 
#include <gsl/gsl_odeiv2.h>
#include <assert.h>

double Fe(double e, double r);

int master(const gsl_vector* x, void* params, gsl_vector* f) { // The function we want to find the root of in problem 2 is defined
	  
	double e = gsl_vector_get (x,0);
	double rmax = *(double*)params;
	gsl_vector_set(f,0,Fe(e,rmax)); 

return GSL_SUCCESS; 
}

int rosenbrock (const gsl_vector* x_ros, void* params, gsl_vector* f) { 
	double x = gsl_vector_get (x_ros,0);
	double y = gsl_vector_get (x_ros,1); 
	double dx = 2*(x-1) - 4*x*100*(y-x*x); 
	double dy = 200*(y-x*x); 

	gsl_vector_set (f,0,dx); 	
	gsl_vector_set (f,1,dy);

return GSL_SUCCESS;	
}

int main(void) {
	const int dim = 2;

	gsl_multiroot_function rosen;
	rosen.f = rosenbrock; 
	rosen.n = dim;	
	rosen.params = NULL; 

	const gsl_multiroot_fsolver_type* T = gsl_multiroot_fsolver_hybrids; 
	gsl_multiroot_fsolver* s = gsl_multiroot_fsolver_alloc(T,dim); 

	gsl_vector* x_ros = gsl_vector_alloc(dim);
	gsl_vector_set (x_ros, 0, 0.9); 
	gsl_vector_set (x_ros, 1, 0.9);

	gsl_multiroot_fsolver_set(s,&rosen,x_ros);

	int iter=0,status;
	const double acc=1e-3;

	do{
		iter++;
		int flag = gsl_multiroot_fsolver_iterate(s);
		if(flag!=0)break; 
		status = gsl_multiroot_test_residual (s->f,acc);
	} while(status==GSL_CONTINUE && iter<99);
		
	 	printf("The root of the gradient of the Rosenbrock function is given by the x,y coordinates in the following:\n iter = %2i, x = %g, y = %g, gradx = %g, grady = %g\n",iter,gsl_vector_get(s->x,0),gsl_vector_get(s->x,1),gsl_vector_get(s->f,0),gsl_vector_get(s->f,1));
	 	printf("\n\n");
	  	gsl_vector_free(x_ros);
		gsl_multiroot_fsolver_free (s);

		const int dim_fe = 1; 
		const double rmax = 8.00;

		gsl_multiroot_function fe;
		fe.f = master; //the function we want to find the root of
		fe.n = dim_fe; 
		fe.params = (void*)&rmax;

		const gsl_multiroot_fsolver_type* T_fe = gsl_multiroot_fsolver_hybrids;
		gsl_multiroot_fsolver* sfe = gsl_multiroot_fsolver_alloc(T_fe,dim_fe);

		gsl_vector* x = gsl_vector_alloc(dim_fe);
		gsl_vector_set (x, 0, -0.55); //start guess for root value
		gsl_multiroot_fsolver_set(sfe,&fe,x);

	int iter_fe = 0,status_fe;

do{
	iter_fe++;
	int flag_fe = gsl_multiroot_fsolver_iterate(sfe);
	if(flag_fe!=0)break; 
	status_fe= gsl_multiroot_test_residual (sfe->f,acc);
	} while(status_fe==GSL_CONTINUE && iter_fe<99);

	printf("The root of M(e) = 0 is given by e = %g for rmax = %g\n",gsl_vector_get(sfe->x,0),rmax);
  	printf("\n\n");

	double e = gsl_vector_get(sfe->x,0);

	for(double r=0; r<rmax; r+=0.1){ //create r-values for plotting
	printf("r: %g Udregnet Fe(r): %g Eksakt Fe(r): %g\n",r,Fe(e,r),r*exp(-r));

}

	gsl_vector_free(x);
  	gsl_multiroot_fsolver_free(sfe);
return 0;
}
