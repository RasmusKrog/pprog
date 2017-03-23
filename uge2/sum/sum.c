#include<stdio.h>
#include<limits.h>
#include<math.h>
#include<float.h>


int main(){

	int max=INT_MAX/3;
	int i=1;
	float sum_up_float = 0;
	float sum_down_float = 0;

while(i<=max)	{
	sum_up_float+= 1.0f/i;
	i++;
}

i=max;
while(i>0)	{
	sum_down_float+= 1.0f/i;
	i++;
}

	printf("Sum = %f %~n", sum_up_float);
	printf("Sum = %f", sum_down_float);
	return 0;
}
