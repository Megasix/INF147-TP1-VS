#include "mod_math.h"

double MATH_puissance(double x, int n)
{
	double xn = 1;

	for (int i = n; i > 0; i--)
	{
		xn = xn * x;
	}

	return xn;
}

double MATH_racine_carree(double x)
{
	double racine_carree = x;
	double e = 1 / (MATH_puissance(10, 4));
	double r_precedent = 0;

	while (racine_carree - r_precedent > e)
	{
		r_precedent = racine_carree;
		racine_carree = 0.5 * (r_precedent + (x / r_precedent));
	}

	return racine_carree;
}
