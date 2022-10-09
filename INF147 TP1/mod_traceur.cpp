#include "mod_traceur.h"

void TRACEUR_initialiser_fenetre(void)
{
	initwindow(DIM_LARGEUR, DIM_HAUTEUR);
}

void TRACEUR_ligne(int x_1, int y_1, int x_2, int y_2)
{
	// Chemin de l'outil (WHITE)
	setcolor(WHITE);
	line(x_1, y_1, x_2, y_2);

	// Limite superieure du faisceau laser (LIGHTCYAN)
	setcolor(LIGHTCYAN);

//	line(x_1, y_1, x_2, y_2);

	// Limite inferieur du faisceau laser (LIGHTCYAN)
	setcolor(LIGHTCYAN);
	
//	line(x_1, y_1, x_2, y_2);

	// Un cercle de rayon r qui represente le point de depart (LIGHTCYAN)
	setcolor(LIGHTCYAN);
	circle(x_1, y_1, RAYON);

	// Un cercle de rayon r qui represente le point de fin (LIGHTCYAN)
	setcolor(LIGHTCYAN);
	circle(x_2, y_2, RAYON);
}
