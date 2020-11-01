#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "menu.h"
#define CYCLE 1000000L

void menu(int* t, int* div, int* XFenetre, int* YFenetre) {
  couleur bleuclair = CouleurParComposante(179, 204, 255);
  couleur rouge = CouleurParComposante(255, 179, 179);
  couleur gris = CouleurParComposante(204, 204, 204);
  couleur noir = CouleurParComposante(0, 0, 0);
  couleur blanc = CouleurParComposante(255, 255, 255);

  char fond[] = "images/fond.jpeg";
  char commentjouer[] = "images/Diapositive1.PNG";
  char stars[] = "images/stars.png";
  int tmp1=0, tmp2=0, tmp3=0;

  InitialiserGraphique();
  ChoisirEcran(0);

  CreerFenetre(0,0,900,900);
  EffacerEcran(bleuclair);
  ChargerImageFond(fond); /* indiquer chemin image */

  ChoisirCouleurDessin(rouge); /* bloc rectangle "jouer" */
  RemplirRectangle(900/2-155,900/2-200,300,100);
  ChoisirCouleurDessin(noir);
  DessinerRectangle(900/2-155,900/2-200,300,100);

  ChoisirCouleurDessin(bleuclair);  /* bloc rectangle "comment jouer" */
  RemplirRectangle(900/2-155,900/2-60,300,100);
  ChoisirCouleurDessin(noir);
  DessinerRectangle(900/2-155,900/2-60,300,100);

  ChoisirCouleurDessin(gris); /* bloc rectangle "quitter" */
  RemplirRectangle(900/2-155,900/2+80,300,100);
  ChoisirCouleurDessin(noir);
  DessinerRectangle(900/2-155,900/2+80,300,100);

  EcrireTexte(900/2-50,900/2-140,"Jouer",2);
  EcrireTexte(900/2-90,900/2,"Comment jouer ?",2);
  EcrireTexte(900/2-55,900/2+140,"Quitter",2);

  while(tmp1 != 1){
    tmp1=0, tmp2=0, tmp3=0;
    while((SourisCliquee()!=1)) { 
    }

    /* rectangle invisible (zone cliquable) pour cliquer sur le rectangle "jouer" */
    if (_X>900/2-155 && _Y>900/2-200 && _X<900/2+145 && _Y<900/2-100) {

      EffacerEcran(CouleurParNom("white"));
      ChargerImageFond(fond);

      ChoisirCouleurDessin(noir);     /* taille */
      RemplirRectangle(900/2-90,900/2-385,150,50);
      ChoisirCouleurDessin(blanc);
      DessinerRectangle(900/2-90,900/2-385,150,50);
      EcrireTexte(900/2-55,200/2,"Taille",2);

      ChoisirCouleurDessin(rouge);    /* 4x4 */
      RemplirRectangle(900/2-155,900/2-250,300,100);
      ChoisirCouleurDessin(noir);
      DessinerRectangle(900/2-155,900/2-250,300,100);
      EcrireTexte(900/2-40,900/2-190,"4 x 4",2);

      ChoisirCouleurDessin(bleuclair);  /* 4x6 */
      RemplirRectangle(900/2-155,900/2-60,300,100);
      ChoisirCouleurDessin(noir);
      DessinerRectangle(900/2-155,900/2-60,300,100);
      EcrireTexte(900/2-40,900/2,"4 x 6",2);

      ChoisirCouleurDessin(gris);     /* 4x8 */
      RemplirRectangle(900/2-155,900/2+130,300,100);
      ChoisirCouleurDessin(noir);
      DessinerRectangle(900/2-155,900/2+130,300,100);
      EcrireTexte(900/2-40,900/2+190,"4 x 8",2);

      while(tmp2 != 1){
        while((SourisCliquee()!=1)) { 
        }

        /* au cas où le joueur clique sur 4x4 */
        if(_X>900/2-155 && _Y>900/2-250){
          if(_X<900/2+145 && _Y<900/2-150){
            tmp1=1;
            tmp2=1;
            *t=16;
            *div=9;
            *XFenetre=900;
            *YFenetre=900;
          }
        }

        /* au cas où le joueur clique sur 4x6 */
        if(_X>900/2-155 && _Y>900/2-60){
          if(_X<900/2+145 && _Y<900/2+40){
            tmp1=1;
            tmp2=1;
            *t=24;
            *div=13;            
            *XFenetre=1300;
            *YFenetre=900;
          }
        }

        /* au cas où le joueur clique sur 4x8 */
        if(_X>900/2-155 && _Y>900/2+130){
          if(_X<900/2+145 && _Y<900/2+230){
            tmp1=1;
            tmp2=1;
            *t=32;
            *div=17;            
            *XFenetre=1700;
            *YFenetre=900;
          }
        } 
      }
    }
    /* rectangle invisible (zone cliquable) pour cliquer sur le rectangle "comment jouer" */
    else {
      if (_X>900/2-155 && _Y>900/2-60 && _X<900/2+145 && _Y<900/2+40){

        EffacerEcran(noir);
        ChargerImageFond(stars);
        ChargerImage(commentjouer,0,0,0,0,900,900);

        ChoisirCouleurDessin(gris);
        RemplirRectangle(360,5,80,40);
        ChoisirCouleurDessin(noir);
        DessinerRectangle(360,5,80,40);
        EcrireTexte(365,35,"Retour",2);

        while(tmp3!=1){
          if(SourisCliquee()==1){
            if(_X > 360 && _X < 460 && _Y > 5 && _Y < 45){
              tmp3=1;
            }
          }
        }
        /* on réaffiche le menu quand le joueur clique sur "retour" */
        EffacerEcran(bleuclair);
        ChargerImageFond(fond); /* indiquer chemin image */

        ChoisirCouleurDessin(rouge); /* bloc rectangle "jouer" */
        RemplirRectangle(900/2-155,900/2-200,300,100);
        ChoisirCouleurDessin(noir);
        DessinerRectangle(900/2-155,900/2-200,300,100);

        ChoisirCouleurDessin(bleuclair);  /* bloc rectangle "comment jouer" */
        RemplirRectangle(900/2-155,900/2-60,300,100);
        ChoisirCouleurDessin(noir);
        DessinerRectangle(900/2-155,900/2-60,300,100);

        ChoisirCouleurDessin(gris); /* bloc rectangle "quitter" */
        RemplirRectangle(900/2-155,900/2+80,300,100);
        ChoisirCouleurDessin(noir);
        DessinerRectangle(900/2-155,900/2+80,300,100);

        EcrireTexte(900/2-50,900/2-140,"Jouer",2);
        EcrireTexte(900/2-90,900/2,"Comment jouer ?",2);
        EcrireTexte(900/2-55,900/2+140,"Quitter",2);
      }
      /* rectangle invisible (zone cliquable) pour cliquer sur le rectangle "quitter" */
      else {
        if (_X>900/2-155 && _Y>900/2+80 && _X<900/2+145 && _Y<900/2+180) {
          exit(1);
        }
      }
    }
  }
}
