#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h> 

double f(double x) {   
	return x*x*x-(3*x)+1;
}


void secante(double x1, double x0, double eps) {  /* fonction secante sans afficher la valeur */
	
	double x2, erreur;
	int it = 0;
	
	FILE *g = fopen("values_secante.txt","w");  

/*Creation de la boucle do, pour le calcul de l’equation 0=(x-x0) + f(x1)
Ensuite tant que x1-x0 > eps, nous continuons les itérations. */

	do {
		x2 = ( ( x0 * f(x1) ) - ( x1 * f(x0) ) ) / ( f(x1) - f(x0) );
		erreur = fabs(x1-x0);				  
		x0 = x1;
		x1 = x2;
		it = it + 1;	
	}
	while (erreur > eps);
	
	fprintf(g, "endradrement = [%.10f,  %.10f]\n", x1, x0);
	fprintf(g, "nombre d'iteration = %d\n", it);
	printf("nombre d'iteration = %d\n", it);
}


int main (int argc,char *argv[]) {   /* Nous rangeons les resultats sous un tableau */

	double x1,x0,eps;

	sscanf(argv[1], "%lg", &x0);
	sscanf(argv[2], "%lg", &x1);
	sscanf(argv[3], "%lg", &eps);

	secante(x1,x0,eps);
	
	return EXIT_SUCCESS;
}
