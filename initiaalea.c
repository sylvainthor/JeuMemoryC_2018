#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "initiaalea.h"
#define CYCLE 1000000L

void initiaalea(int (tab1)[], int t){

  	int random, i, j, k;
        srand(time(NULL));

  	for(i=0; i<t;){
      	random = rand() % t/2+1;
      	    for(k=0,j=0; j<t; j++){
         		  if(tab1[j] == random){
              k++;
          	}
      	}
      	if(k==0 || k==1){
          	tab1[i] = random;
          	i++;
      	}
    }
}