#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h> 


double f(double x) {     /*Definition de la fonction */
	return x*x*x - 3*x + 1;
}

double df(double x) {  /*Definition de la dérivé de la fonction precedente*/

	return 3*x*x - 3;
}
/*Integration des resultats sous forme de tableau */
int main (int argc,char *argv[]) {
	double x0, x1, eps, erreur;
	int it;
	
	sscanf(argv[1], "%lg", &x0);
	sscanf(argv[2], "%lg", &eps);	
	
	it = 0;

/*Nous créons une boucle do. Cette boucle permet de calculer x1=x0-.
Et erreur=x0-x1 et tant que erreur > eps, on continue les iterations */

	do {
	   	printf("x0 = %lg\n", x0);
		x1 = x0 - f(x0) / df(x0);
		erreur = fabs(x0-x1);				  
		x0 = x1;
		it = it + 1;	
	}
	while (erreur > eps);	

	printf("it = %d\n", it);

	return EXIT_SUCCESS;
}
