#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "grille.h"
#define CYCLE 1000000L

void grille(int div, int XFenetre, int YFenetre, int (tab1)[], int t) {

    int i, j, k;

 	char ecranfin1[] = "images/Diapositive2-1.PNG";
 	char ecranfin2[] = "images/Diapositive2-2.PNG";
 	char ecranfin3[] = "images/Diapositive2-3.PNG";
 	char stars[] = "images/stars.png";

    couleur blanc = CouleurParComposante(255, 255, 255);
    couleur rouge = CouleurParComposante(255, 179, 179);
    couleur noir = CouleurParComposante(0, 0, 0);
	couleur gris = CouleurParComposante(204, 204, 204);

    char str[20], temps[30];
    unsigned long Microsecondes(), suivant1, suivant2;
    int sauvegarde[2][2], e, num[2], sauvtab, l[2], compteur=0, finjeu=0;
    int* tableau = NULL;
	int* tabdiscriminant = NULL;
    tableau=(int*)malloc(t*sizeof(int));
    tabdiscriminant=(int*)malloc(t*sizeof(int));

    for(k=0; k<t; k++){ /* si tableau[k]=0 alors la carte k est dévoilable, sinon elle est figée */
      	tableau[k]=0;
    }

    for(k=0; k<t; k++){ /* remplissage d'un tableau de 1 à k soit [1;k], pour interdire le retournement de 2 fois la même carte */
      	tabdiscriminant[k]=k;
    }
    /* tabdiscriminant[k]=0 -> face cachée, tabdiscriminant[k]=-1 -> face figée */
    
    suivant2 = Microsecondes() + CYCLE;
    
    while(finjeu!=1){

		for(e=0; e<2;) {

			while(SourisCliquee()!=1 && ToucheEnAttente()!=1){ /* timer */
				if(Microsecondes()>suivant2){
					ChoisirCouleurDessin(rouge);
   					RemplirRectangle(5,5,60,40);
    				ChoisirCouleurDessin(noir);
    				DessinerRectangle(5,5,60,40);

					compteur++;
					sprintf(temps,"%d", compteur);
					EcrireTexte(10,35,temps,2);
					suivant2 = Microsecondes() + CYCLE;
    			}
			}

			if(ToucheEnAttente()==1){
				triche(div,XFenetre,YFenetre,e,&*tab1,&*tableau);		/*mode de triche*/
			}

			for(k=0, i=XFenetre/div; i<XFenetre; i=i+2*(XFenetre/div)){
				for(j=YFenetre/9; j<YFenetre; j=j+2*(YFenetre/9), k++){
			        if(_X > i && _Y > j && _X < i+(XFenetre/div) && _Y < j+(YFenetre/9)){
			            if(tableau[k] == 0 && tabdiscriminant[k] >= 0){
			               	if(e == 1 && tabdiscriminant[k] == sauvtab){ /* vérifie si la 2e carte retournée n'est pas la même que la première */
			                }
				            else {
						        sauvegarde[e][0] = i;
						        sauvegarde[e][1] = j;
				 	            sauvtab = tabdiscriminant[k];
				 	            tableau[k] = -1;
					            num[e] = tab1[k];
					            l[e] = k;
					            sprintf(str, "images/image%d.png", tab1[k]);
					            ChargerImage(str, i+5, j+5, 0, 0, XFenetre/div, YFenetre/9);
						        e++;
				            }
				        }
				    }
				}
			}
		}
		    

		suivant1 = Microsecondes() + CYCLE;

		if(num[0] == num[1]){
			tableau[l[0]]=-1;
			tableau[l[1]]=-1;
		}
		else {
			while(suivant1 > Microsecondes()){
				if(Microsecondes() > suivant2){ /* continuité du timer au cas où il y a une seconde d'attente de comparaison */
					ChoisirCouleurDessin(rouge);
   					RemplirRectangle(5,5,60,40);
    				ChoisirCouleurDessin(noir);
    				DessinerRectangle(5,5,60,40);

					compteur++;
					sprintf(temps,"%d", compteur);
					EcrireTexte(10,35,temps,2);
					suivant2 = Microsecondes() + CYCLE;
				}
				if(SourisCliquee()==1){
				    /* ici, on ignore les coordonnées du clic au cas où l'utilisateur clique pendant la comparaison des 2 images */
				}
				if(ToucheEnAttente()==1){
				    /* ici, on ignore la touche au cas où l'utilisateur essaye d'activer le mode de triche pendant la comparaison des 2 images */
				}
			}
			ChoisirCouleurDessin(noir);  
			RemplirRectangle(sauvegarde[0][0],sauvegarde[0][1],XFenetre/div,YFenetre/9);
			RemplirRectangle(sauvegarde[1][0],sauvegarde[1][1],XFenetre/div,YFenetre/9);
			ChoisirCouleurDessin(blanc);
			DessinerRectangle(sauvegarde[0][0],sauvegarde[0][1],XFenetre/div,YFenetre/9);
			DessinerRectangle(sauvegarde[1][0],sauvegarde[1][1],XFenetre/div,YFenetre/9);
			tableau[l[0]]=0;
			tableau[l[1]]=0;
		}
		for(i=0,k=0; k<t; k++){      
			if(tableau[k] == -1){
				i++;
				if(i==t){
				    EffacerEcran(noir);
				    ChargerImageFond(stars);
				    if(XFenetre == 900 && YFenetre == 900){
				    	ChargerImage(ecranfin1,0,0,0,0,XFenetre,YFenetre);
				    }
				    if(XFenetre == 1300 && YFenetre == 900){
				    	ChargerImage(ecranfin2,0,0,0,0,XFenetre,YFenetre);
				    }
				    if(XFenetre == 1700 && YFenetre == 900){
				    	ChargerImage(ecranfin3,0,0,0,0,XFenetre,YFenetre);
				    }
				    sprintf(temps,"Votre temps : %d secondes", compteur);
					ChoisirCouleurDessin(rouge);
   					RemplirRectangle(5,5,350,40);
    				ChoisirCouleurDessin(noir);
    				DessinerRectangle(5,5,350,40);
    				EcrireTexte(10,35,temps,2);

    				ChoisirCouleurDessin(gris);
	   				RemplirRectangle(360,5,100,40);
	    			ChoisirCouleurDessin(noir);
	    			DessinerRectangle(360,5,100,40);
	    			EcrireTexte(365,35,"Quitter",2);

					while(finjeu!=1){
						if(SourisCliquee()==1){
							if(_X > 360 && _X < 460 && _Y > 5 && _Y < 40){
								finjeu=1;
	    					}
						}
					}
				}
			}
		}
	}
}

void triche(int div, int XFenetre, int YFenetre, int e, int (tab1)[], int (tableau)[]){

	int i, j ,k;
	char str[20];
    KeySym touche;
    couleur blanc = CouleurParComposante(255, 255, 255);
	couleur noir = CouleurParComposante(0, 0, 0);

	touche = Touche();
	if(touche == XK_t){
	    for(k=0, i=XFenetre/div; i<XFenetre; i=i+2*(XFenetre/div)){
	        for(j=YFenetre/9; j<YFenetre; j=j+2*(YFenetre/9), k++){
	            sprintf(str, "images/image%d.png", tab1[k]);
	            ChargerImage(str, i+5, j+5, 0, 0, XFenetre/div, YFenetre/9);
	        }
	    }
	    while(ToucheEnAttente()!=1){
			if(SourisCliquee()==1){
				/* ici, on ignore les coordonnées du clic au cas où l'utilisateur clique pendant la comparaison des 2 images */
			}
	    }
	    touche = Touche();
	    if(touche == XK_t){
	        for(k=0,i=XFenetre/div; i<XFenetre; i=i+2*(XFenetre/div)){
	            for(j=YFenetre/9; j<YFenetre; j=j+2*(YFenetre/9), k++){
	             	if(tableau[k] == -1 && e == 0){
	               	}
		            else{
		             	if(tableau[k]==0){
		                    ChoisirCouleurDessin(noir);  
		                    RemplirRectangle(i,j,XFenetre/div,YFenetre/9);
		                    ChoisirCouleurDessin(blanc);
		                    DessinerRectangle(i,j,XFenetre/div,YFenetre/9);
		                }
	                }
	            }
	        }
	    }
	}
	_X = 0;
	_Y = 0;
}