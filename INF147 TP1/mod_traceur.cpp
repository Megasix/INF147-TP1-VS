#include "mod_traceur.h"
#include "mod_outils.h"
#include "graphics.h"
#include "mod_math.h"

void TRACEUR_initialiser_fenetre(void)
{
	initwindow(DIM_LARGEUR, DIM_HAUTEUR);
}


void TRACEUR_ligne(int x_1, int y_1, int x_2, int y_2)
{
	const int rayon = 10;
	int type_tracer = 0;

	if (x_2 < x_1)
	{
		SWAP(x_1, x_2);
		SWAP(y_1, y_2);
	}

	int delta_x = x_2 - x_1;
	int delta_y = y_2 - y_1;

	if ((delta_x == 0) && (delta_y ==! 0)) //ligne horizontal
	{
		type_tracer = 1;
	}
	else if ((delta_x ==! 0) && (delta_y == 0)) //ligne vertical
	{
		type_tracer = 2;
	}
	else //ligne oblique
	{
		type_tracer = 3;
	}

	switch (type_tracer)
	{
	case 1 :
		setcolor(WHITE);
		line(x_1, y_1, x_2, y_2);
		setcolor(LIGHTCYAN);
		line(x_1, y_1 + rayon, x_2, y_2 + rayon);
		line(x_1, y_1 - rayon, x_2, y_2 - rayon);
		circle(x_1, y_1, rayon);
		circle(x_2, y_2, rayon);
		break;
	case 2 :
		setcolor(WHITE);
		line(x_1, y_1, x_2, y_2);
		setcolor(LIGHTCYAN);
		line(x_1 + rayon, y_1, x_2 + rayon, y_2);
		line(x_1 - rayon, y_1, x_2 - rayon, y_2);
		circle(x_1, y_1, rayon);
		circle(x_2, y_2, rayon);
		break;
	case 3 :
		int dx = 0;
		int dy = 0;

		setcolor(WHITE);
		line(x_1, y_1, x_2, y_2);
		setcolor(LIGHTCYAN);
		circle(x_1, y_1, rayon);
		circle(x_2, y_2, rayon);

		if (delta_y < 0) //si vrai : ligne oblique montant
		{
			dx = cos(MATH_atan(delta_y / delta_x)) * rayon;
			dy = sin(MATH_atan(delta_y / delta_x)) * rayon;
		
			line(x_1 + dx, y_1 - dy, x_2 + dx, y_2 - dy);
			line(x_1 - dx, y_1 + dy, x_2 - dx, y_2 + dy);
		}
		else //sinon c'est descendant
		{
			dx = cos(MATH_atan(delta_y / delta_x)) * rayon;
			dy = sin(MATH_atan(delta_y / delta_x)) * rayon;

			line(x_1 + dx, y_1 + dy, x_2 + dx, y_2 + dy);
			line(x_1 - dx, y_1 - dy, x_2 - dx, y_2 - dy);
		}
		break;
	}
		

/* À remplir */
