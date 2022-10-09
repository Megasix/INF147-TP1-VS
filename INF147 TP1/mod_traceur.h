#ifndef __MOD_TRACEUR__
#define __MOD_TRACEUR__

#include "graphics.h"
#pragma comment(lib, "graphics")

// Dimension du graphique en pixels
#define DIM_HAUTEUR 750	
#define DIM_LARGEUR 750

// Tol�rance en pixels pour le graphique
#define TRACEUR_EPSILON 1

#define R_FAISCEAU 10

/*
 TRACEUR_INITIALISER_FENETRE

	Initialise la fen�tre du trac� avec les dimensions sp�cifi�es par les constantes DIM_HAUTEUR et DIM_LARGEUR.

 PARAM�TRES :

	 Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void TRACEUR_initialiser_fenetre();

void TRACEUR_ligne(int x_1, int y_1, int x_2, int y_2);
/* � remplir */

#endif
