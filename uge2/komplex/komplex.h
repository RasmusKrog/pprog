#ifndef KOMPLEX_H
#define KOMPLEX_H

typedef struct {double re,im;} komplex;

komplex komplex_add      (komplex a, komplex b); /* returns a+b */
komplex komplex_sub      (komplex a, komplex b); /* returns a-b */
komplex komplex_new      (double x, double y);   /* returns x+i*y */
void    komplex_set      (komplex* z, double x, double y);   /* z = x+i*y */
komplex komplex_conjugate(komplex z);            /* returns complex conjugate */
int     komplex_equal    (komplex a, komplex b); /* returns 1 if equal, 0 otherwise */
void    komplex_print    (char* s, komplex z);
komplex komplex_mul      (komplex a, komplex b);
komplex komplex_div      (komplex a, komplex b);

#endif
