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
	//le type de tracer (vertical, horizontal, oblique)
	int type_tracer = 0;

	if (x_2 < x_1)
	{
		SWAP(&x_1, &x_2);
		SWAP(&y_1, &y_2);
	}
	
	//le delta x et y qui servira dans le calcul d'angle des lignes obliques
	int delta_x = x_2 - x_1;
	int delta_y = (y_2 - y_1);

	if (delta_x == 0)	//ligne vertical
	{
		type_tracer = LIGNE_VERTICAL;
	}
	else if (delta_y == 0)	//ligne horizontal
	{
		type_tracer = LIGNE_HORIZONTAL;
	}
	else			//ligne oblique
	{
		type_tracer = LIGNE_OBLIQUE;
	}

	setcolor(WHITE);
	line(x_1, y_1, x_2, y_2);
	setcolor(LIGHTCYAN);
	circle(x_1, y_1, RAYON);
	circle(x_2, y_2, RAYON);

	switch (type_tracer)
	{
	case 1 :			
		line(x_1 + RAYON, y_1, x_2 + RAYON, y_2);
		line(x_1 - RAYON, y_1, x_2 - RAYON, y_2);
		break;
	case 2 :			
		line(x_1, y_1 + RAYON, x_2, y_2 + RAYON);
		line(x_1, y_1 - RAYON, x_2, y_2 - RAYON);
		break;
	case 3 :			
		int dx = (int)(MATH_sin(MATH_atan(delta_y / delta_x)) * RAYON);
		int dy = (int)(MATH_cos(MATH_atan(delta_y / delta_x)) * RAYON);

		if (delta_y < 0)	//si vrai : la ligne est oblique montante
		{
			line(x_1 + dx, y_1 - dy, x_2 + dx, y_2 - dy);
			line(x_1 - dx, y_1 + dy, x_2 - dx, y_2 + dy);
		}
		else			//sinon la ligne est oblique descendante
		{
			line(x_1 + dx, y_1 + dy, x_2 + dx, y_2 + dy);
			line(x_1 - dx, y_1 - dy, x_2 - dx, y_2 - dy);
		}
		break;
	}
		


}
