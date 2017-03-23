#include<stdio.h>
#include<complex.h>
#include<tgmath.h>
#ifdef __clang__
#define complex _Complex double
#endif
#include"komplex.h"
#include <stdlib.h>
#define RND (double)rand()/RAND_MAX

#define KOMPLEX(z) komplex_new(creal(z),cimag(z));

int main()
{
	komplex a = { RND, RND };
	komplex b = { RND, RND };
	komplex z, w;
	complex A = a.re + a.im * I;
	complex B = b.re + b.im * I;

	printf("\ntesting komplex_set...\n");
	komplex_print("a=", a);
	printf("setting z <-- a\n");
	komplex_set(&z, a.re, a.im);
	komplex_print("z=", z);
	if (komplex_equal(z, a))
		printf("test passed\n\n");								else
		printf("test falied\n\n");

													printf("testing komplex_add...\n");
	komplex_print("a=", a);
	komplex_print("b=", b);
	z = komplex_add(a, b);
	w = KOMPLEX(A + B);										komplex_print("a+b should   =", w);
	komplex_print("a+b actually =", z);
	if (komplex_equal(w, z))
		printf("test passed\n\n");								else
		printf("test falied\n\n");

	printf("testing komplex_div...\n");
	komplex_print("a=", a);
	komplex_print("b=", b);
	z = komplex_div(a, b);
	w = KOMPLEX(A / B);
	komplex_print("a/b should   =", w);
	komplex_print("a/b actually =", z);
	if (komplex_equal(w, z))
		printf("test passed\n\n");
	else
		printf("test falied\n\n");

	printf("testing komplex_conjugate...\n");
													komplex_print("a=", a);
	z = komplex_conjugate(a);									w = komplex_new(a.re, -a.im);
	komplex_print("a* should   =", w);
	komplex_print("a* actually =", z);
	if (komplex_equal(w, z))
		printf("test passed\n\n");
	else
		printf("test falied\n\n");
	
	printf("testing komplex_exp...\n");
	komplex_print("a=", a);
	z = komplex_exp(a);
	w = KOMPLEX(exp(A));
	komplex_print("exp(a) should   =", w);
	komplex_print("exp(a) actually =", z);
	if (komplex_equal(w, z))
		printf("test passed\n\n");
	else
		printf("test falied\n\n");

	return 0;
}
