#include "nvector.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

nvector* nvector_alloc(int n){
	nvector* v = malloc(sizeof(nvector));
	(*v).size = n;
	(*v).data = malloc(n*sizeof(double));
	if (v==NULL) {
	fprintf(stderr, "Error in function: nvector_alloc\n");
	return -1;
}
	return v;
}

void nvector_free(nvector* v){
	free((*v).data);
	free(v);
	v = NULL;
}

void nvector_set(nvector* v, int i, double value){
	if(i > -1 && i < (*v).size) (*v).data[i] = value;
	else printf("Unsupported assignment in nvector_set. Check vector size.");
}

double nvector_get(nvector* v, int i){
	if (i > -1 && i < v->size)
{
	double k = v->data[i];
	return k;
}
else
{
	fprintf(stderr, "Unsupported request in nvector_get. Check vector size.\n");
	return -1;
	}
}

double nvector_dot_product(nvector* v, nvector* w){
	double dot_prod = 0.00;
	if(v->size == w->size){
	printf("Dot product not defined for these vectors!\n");
}
	else{
	for(int i=0; i<(*v).size; i++){
	dot_prod = dot_prod + (*w).data[i]*(*v).data[i];
}
}
return dot_prod;
}

