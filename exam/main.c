#include<stdio.h>
#include<math.h>
#include<gsl/gsl_vector.h>
#include<gsl/gsl_errno.h>
#include<gsl/gsl_multiroots.h>
#define ALG gsl_multiroot_fsolver_hybrids
 
// Problem 3 - root finding of natural logarithm

//make exponentialfunction that will be solves by gsl in main
int exp_function(const gsl_vector *vec, void * params, gsl_vector *f){
	double t=gsl_vector_get(vec,0);
	double x = *(double*)params;
	double fkt = exp(t)-x;
	gsl_vector_set(f,0,fkt); //this function sets the value of the i-th element of the vector f to fkt 
return GSL_SUCCESS;
}
			     
int main(int argc, char* argv[]){
//defining constants to use throughout the exercise
	const int dim =1; // set the dimension of the problem
	double x;
	double xend=atof(argv[2]); // atof() converts a character string to a double-precision floating-point value
	const double dx=atof(argv[3]); // argv = argument vector and is a array of argument
	int iter=0,status;
	const double acc = 1e-3; 
for(x=atof(argv[1]); x<xend; x+=dx){
	gsl_multiroot_function Exp_fkt;
	Exp_fkt.f = exp_function; // function to solve
	Exp_fkt.n = dim; // define dimension   
	Exp_fkt.params = (void*)&x; 											 
	gsl_multiroot_fsolver * state = gsl_multiroot_fsolver_alloc(ALG, dim);
	gsl_vector *t= gsl_vector_alloc(dim); // creates a vector of lenght dim
	gsl_vector_set(t,0,2); // here we make our starting guess' on a solution
	gsl_multiroot_fsolver_set(state, &Exp_fkt, t);
							 
	iter=0;
	status=0;
do{
       	iter++;
	int flag=gsl_multiroot_fsolver_iterate (state);
if(flag!=0) // A flag is a variable that is supposed to signalize something
break; // if it's not solved correctly, then it will break
	status = gsl_multiroot_test_residual (state->f, acc);}
while(status==GSL_CONTINUE && iter <99); //maximum iterations
	printf("%8f, %8f, %8f\n", x, gsl_vector_get(state->x,0),log(x));
	gsl_vector_free(t); // This function frees a previously allocated vector t
	gsl_multiroot_fsolver_free (state); //frees all memory that has to do with state
}
return 0;
}
