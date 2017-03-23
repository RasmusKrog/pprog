#include<stdio.h>
#include<limits.h>
#include<float.h>

int main(){

/* Her bruges float funktionen */
int max = INT_MAX/3;

	float sum_up_float=0;
	float sum_down_float=0;

for (int i=1; i<max; i++){
    sum_up_float += 1.0f/i;
}

for (int i=max; i>0; i--){
    sum_down_float += 1.0f/i;
}
	printf("\nFor Floats\n");
	printf("Sum_up = %lg\n",sum_up_float);
	printf("Sum_down = %lg\n",sum_down_float);


/* Her bruges der double */
	double sum_up_double=0;
	double sum_down_double=0;

for (int i=1; i<=max; i++){
    sum_up_double += 1.0/i;
}

for (int i=max; i>=1; i--){
    sum_down_double += 1.0/i;
}

	printf("\nFor Doubles\n");
	printf("Sum_up = %lg\n",sum_up_double);
	printf("Sum_down = %lg\n",sum_down_double);

return 0;
}
