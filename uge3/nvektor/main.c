#include "nvector.h"
#include <stdio.h>
#include <stdlib.h>

#include<stdio.h>
#include<stdlib.h>
#include"nvector.h"

int main(){
	int q = 3;

	double k;
nvector* t = nvector_alloc(q);
nvector* p = nvector_alloc(4);

(*t).data[0] = 3;
(*t).data[1] = 2;
(*t).data[2] = 1;

printf("t = [%g, %g, %g]\n", (*t).data[0], (*t).data[1], (*t).data[2]);

nvector_set(t, 1, 1.23);

printf("Setting new value of t[1]\n");
printf("t = [%g, %g, %g]\n", (*t).data[0], (*t).data[1], (*t).data[2]);
k = nvector_get(t, 2);
printf("Using nvector_get to get the third element of the vector t\n");												      printf("v[2]=%g\n",k);
printf("Making a new vector, p\n");
nvector_set(p, 0, 1.23);
nvector_set(p, 1, 2.34);
nvector_set(p, 2, 3.45);
printf("p = [%g, %g, %g]\n", (*p).data[0], (*p).data[1], (*p).data[2]);												      printf("The dot product between p and t is\n");
printf("dot(t,p) = %g\n", nvector_dot_product(t,p));

nvector_free(t);
nvector_free(p);
return 0;
}

