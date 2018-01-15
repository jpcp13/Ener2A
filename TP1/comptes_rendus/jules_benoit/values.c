#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>  /*Appel des bibliotheques necessaire a la bonne execution du programme */
double y,x,a,b,h,i; /*Definir les variables */
double g(double); /*Definir la fonction*/
void write_values(double a, double b, double h); /*void appel la fonction write_values sans en afficher sa valeur */


double g(double x) {
	/*Nous  definissons la fonction permettant de calculer les valeurs du tableau*/
	
	return x*x*x-(3*x)+1;
}

/*Appel de la fonction pour integrer résultats dans un tableau en considerant les valeurs rentrees par l’utilisateur.
Resultats integre dans un fichier texte et s’ouvrira à la fin du programme grace a :"FILE *f = fopen("values.txt","w")" */

void write_values(double a, double b, double h) {
	double x,y;
	x=a;
	FILE *f = fopen("values.txt","w");
	for(i=a; i<=b; i=i+h){
		y=g(x);
		fprintf (f, "x=%lg,f(x)=%lg\n",x,y);
		x=x+h;
	}
}


int main () {

/*On rentre les paramètres necessaire pour calculer x et f(x) entre a et b, le tout avec un pas de h.
a sert à determiner le x de la fonction
b sert à determiner à quel x le programme s’arrete
write_values(a,b,h) calcule la fonction grace à a et b */

	printf("borne inferieur de l'intervalle :\n");
	scanf("%lg",&a);
	printf("borne superieur de l'intervalle :\n");	
	scanf("%lg",&b);
	printf("pas :\n");
	scanf("%lg",&h);	

	write_values(a,b,h);	
	
	return EXIT_SUCCESS;
}


