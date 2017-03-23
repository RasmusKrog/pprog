#ifndef NVECTOR_H

typedef struct {int size; double* data;} nvector;		/* Definerer en struktur, som har to medlemmer. Første medlem er et integer,
								   								andet medlem er en pointer til et double*/

nvector* nvector_alloc		(int n);			// Allokerer hukommelse til en nvector-struktur, hvor arrayet data har størrelse n

void nvector_free		(nvector* v);			// Frigør den hukommelse, som er blevet allokeret med nvector_alloc

void nvector_set		(nvector* v, int i, double value);// Sætter det i'te element i vektoren v til at være <value>

double nvector_get		(nvector* v, int i);		// Returnerer værdien af det i'te element i en nvector strukturs data-array

double nvector_dot_product 	(nvector* v, nvector* w);	// Returnerer prikproduktet af de to vektorer

#define NVECTOR_H
#endif
