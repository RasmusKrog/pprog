#include <stdio.h>
#include <math.h>

int main(){
		double x=5;
		double gx = tgamma(x);
		printf("gamma(%g)=%g\n",x,gx);
		return 0;
}
