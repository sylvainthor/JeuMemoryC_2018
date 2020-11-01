#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "initiagrille.h"
#define CYCLE 1000000L

void initiagrille(int div, int XFenetre, int YFenetre) {

	int i, j;
    char fond[] = "images/fond.jpeg";

    /* images et grille */

    couleur blanc = CouleurParComposante(255, 255, 255);
    couleur rouge = CouleurParComposante(255, 179, 179);
    couleur noir = CouleurParComposante(0, 0, 0);

    FermerGraphique();
	InitialiserGraphique();
	ChoisirEcran(0);
	CreerFenetre(0,0,XFenetre,YFenetre); /* adaptation de la taille de l'écran en fonction de la grille */
    EffacerEcran(noir);
    ChargerImageFond(fond); 

    /* création de la grille */

    for(i=XFenetre/div; i<XFenetre; i=i+2*(XFenetre/div)){
        for(j=YFenetre/9; j<YFenetre; j=j+2*(YFenetre/9)){
            ChoisirCouleurDessin(noir);  
            RemplirRectangle(i,j,XFenetre/div,YFenetre/9);
            ChoisirCouleurDessin(blanc);
            DessinerRectangle(i,j,XFenetre/div,YFenetre/9);
        }
    }

    /* création mini rectangle en haut à gauche pour le timer */

    ChoisirCouleurDessin(rouge);
   	RemplirRectangle(5,5,60,40);
    ChoisirCouleurDessin(noir);
    DessinerRectangle(5,5,60,40);
}