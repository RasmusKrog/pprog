#include<math.h>
#include<stdio.h>

int equal(double a, double b, double tau, double epsilon){

	if( fabs( a - b ) < tau ){
		return 1;
	}

	if( fabs( a - b )/fabs( a ) + fabs( b ) < ( epsilon / 2.0 )){
		return 1;
	}

	else{
		return 0;
	}

}

