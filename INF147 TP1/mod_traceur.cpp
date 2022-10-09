#include "mod_traceur.h"
#include "mod_math.h"

void TRACEUR_initialiser_fenetre(void)
{
	initwindow(DIM_LARGEUR, DIM_HAUTEUR);
}

void TRACEUR_ligne(int x_1, int y_1, int x_2, int y_2)
{
	int delta_x = x_2 - x_1;
	int delta_y = y_2 - y_1;
	double angle = 0;
	if(delta_x != 0)
		angle = MATH_atan((double)delta_y / delta_x) + MATH_PI / 2;
	int x_offset = MATH_cos(angle) * RAYON;
	int y_offset = MATH_sin(angle) * RAYON;

	// Chemin de l'outil (WHITE)
	setcolor(WHITE);
	line(x_1, y_1, x_2, y_2);

	// Limite superieure du faisceau laser (LIGHTCYAN)
	setcolor(LIGHTCYAN);
	line(x_1 + x_offset, y_1 + y_offset, x_2 + x_offset, y_2 + y_offset);

	// Limite inferieur du faisceau laser (LIGHTCYAN)
	setcolor(LIGHTCYAN);
	line(x_1 - x_offset, y_1 - y_offset, x_2 - x_offset, y_2 - y_offset);

	// Un cercle de rayon r qui represente le point de depart (LIGHTCYAN)
	setcolor(LIGHTCYAN);
	circle(x_1, y_1, RAYON);

	// Un cercle de rayon r qui represente le point de fin (LIGHTCYAN)
	setcolor(LIGHTCYAN);
	circle(x_2, y_2, RAYON);
}
