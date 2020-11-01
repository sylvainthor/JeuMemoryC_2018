#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "main.h"
#include "menu.h"
#include "initiaalea.h"
#include "initiagrille.h"
#include "grille.h"
#define CYCLE 1000000L

int main(void){

	int t, div, XFenetre, YFenetre;
	int* tab1 = NULL;

	menu(&t, &div, &XFenetre, &YFenetre);

	tab1=(int*)malloc(t*sizeof(int));

  	/* initialisation grille t cases soit t/2 doublons */

	initiaalea(&*tab1,t);
    initiagrille(div,XFenetre,YFenetre);
    grille(div,XFenetre,YFenetre,&*tab1,t);
    exit(1);

  	return EXIT_SUCCESS;
}