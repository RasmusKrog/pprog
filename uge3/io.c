#include<stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	double x = 0;
	if(argc>1) x = atof(argv[1]);
	printf("command line argument = %g\n",x);

	fprintf(stdout,"hello\n");
	fprintf(stderr,"error\n");
	while(scanf("%lg",&x)!=EOF){
		printf("x = %lg\n",x);
	}
	
return 0;
}
