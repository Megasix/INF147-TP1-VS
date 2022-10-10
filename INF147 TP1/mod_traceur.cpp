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

	//Si le x_2 entrée est plus petit, on permute les coordonnées afin de facilité les calculs plus tard
	if (x_2 < x_1)
	{
		SWAP(&x_1, &x_2);
		SWAP(&y_1, &y_2);
	}
	
	//le delta x et y qui servira dans le calcul d'angle des lignes obliques
	int delta_x = x_2 - x_1;
	int delta_y = (y_2 - y_1);
	
	//on définie le type de ligne tracée
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
	
	//on trace les lignes supplémentaires en fonction du type de tracé
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
		
		//si vrai : la ligne est oblique montante
		if (delta_y < 0)	
		{
			line(x_1 + dx, y_1 - dy, x_2 + dx, y_2 - dy);
			line(x_1 - dx, y_1 + dy, x_2 - dx, y_2 + dy);
		}
		//sinon la ligne est oblique descendante
		else			
		{
			line(x_1 + dx, y_1 + dy, x_2 + dx, y_2 + dy);
			line(x_1 - dx, y_1 - dy, x_2 - dx, y_2 - dy);
		}
		break;
	}
}
