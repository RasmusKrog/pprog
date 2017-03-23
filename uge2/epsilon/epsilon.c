#include<stdio.h>
#include<limits.h>
#include<float.h>


double epsilon_doublewhile() {
	double dx = 1.;
	while (1+dx != 1)
	{dx /=2;}
	dx *=2;
	printf("while: epsilon = %g, dbl_epsilon = %g\n", dx, DBL_EPSILON);
return dx;
}

int main(){

/* Delopgave 1 */
	int iwhile=0;
	while (iwhile+1>iwhile){iwhile++;}
		printf("INT_MAX: %i\n",INT_MAX);
		printf("While: %i\n",iwhile);

	int ifor=0;
	for (ifor; ifor+1 > ifor ; ifor++) {}
		printf("For: %i\n",ifor);

	int idowhile=0;
	do {idowhile++;} while(idowhile+1 > idowhile);
		printf("Do While: %i\n",idowhile);

/* Delopgave 2 */
	int iwhilemin=0;
	while (iwhilemin-1<iwhilemin){iwhilemin--;}
		printf("INT_MIN: %i\n",INT_MIN);
		printf("While_min: %i\n",iwhilemin);

	int iformin=0;
	for (iformin; iformin-1 < iformin ; iformin--) {}
		printf("For_min: %i\n",iformin);

	int idowhilemin=0;
	do {idowhilemin--;} while(idowhilemin-1 < idowhilemin);
		printf("Do While_min: %i\n",idowhilemin);

/* Delopgave 3 */
	float x=1;
	while (x+1 != 1) {x/=2;}
	x*=2;
	printf("Eps_FLT = %lg\n",x);

	double x_a=1;
	while (x_a+1 != 1) {x_a/=2;}
	x_a*=2;
	printf("Eps_DBL = %lg\n",x_a);

	long double x_longd=1;
	while (x_longd+1 != 1) {x_longd/=2;}
	x_longd*=2;
	printf("Eps_LDBL = %Lg\n",x_longd);

/* inkludering af check.c */

	double e_dw = epsilon_doublewhile();

	double a = 1.00;
	double b = a;
	int eq1 = equal(a, b, 0.001, e_dw);
	printf("eq1 = %d\n", eq1);
	int eq2 = equal(1, 2, 0.005, 0.01);
	printf("eq2 = %d\n", eq2);

return 0;
}
