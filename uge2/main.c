#include<stdio.h>
#include<limits.h>
#include<float.h>

int main()
{

	int bits = sizeof(void*)*8;
	printf("\nThis is a %i bit system with FLT_EVAL_METHOD = %i,\n",bits,FLT_EVAL_METHOD);

	switch(FLT_EVAL_METHOD)
	{
	case 0 : printf("evaluates everything to range.\n\n"); break;
	case 1 : printf("evaluates float as double.\n\n"); break;
	case 2 : printf("evaluates float and double as long double.\n\n"); break;
	default: printf("indeterminate\n\n");
	}

	float fe = 1.0f;
	while(1+fe != 1) {fe/=2;} fe*=2;
	printf("float  epsilon = %g\n",fe);
	printf("FLT_EPSILON    = %g\n\n",FLT_EPSILON);

	double de = 1;
	while(1+de!=1) {de/=2;} de*=2;
	printf("double epsilon = %g\n",de);
	printf("DBL_EPSILON    = %g\n\n",DBL_EPSILON);

	long double le = 1.0L;
	while(1+le!=1) {le/=2;} le*=2;
	printf("long   epsilon = %Lg\n",le);
	printf("LDBL_EPSILON   = %Lg\n",LDBL_EPSILON);

	return 0;
}
