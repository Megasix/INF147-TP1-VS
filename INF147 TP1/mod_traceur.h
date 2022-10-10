#ifndef __MOD_TRACEUR__
#define __MOD_TRACEUR__

#include "graphics.h"
#pragma comment(lib, "graphics")

// Dimension du graphique en pixels
#define DIM_HAUTEUR 750	
#define DIM_LARGEUR 750

// Tolérance en pixels pour le graphique
#define TRACEUR_EPSILON 1

#define RAYON 10
#define LIGNE_VERTICAL 1
#define LIGNE_HORIZONTAL 2
#define LIGNE OBLIQUE 3


/*
 TRACEUR_INITIALISER_FENETRE

	Initialise la fenêtre du tracé avec les dimensions spécifiées par les constantes DIM_HAUTEUR et DIM_LARGEUR.

 PARAMÈTRES :

	 Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void TRACEUR_initialiser_fenetre(void);

/*
* TRACEUR_LIGNE
 
	Trace une ligne entre deux points donnés avec les contours de l'outil

 PARAMETRES :

   x_1: La position x du premier point
   y_1: La position y du premier point
   x_2: La position x du deuxieme point
   y_2: La position y du deuxieme point
  
 VALEUR DE RETOUR :

	Aucune
*/
void TRACEUR_ligne(int x_1, int y_1, int x_2, int y_2);

#endif
