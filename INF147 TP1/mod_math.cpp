#include "mod_math.h"
#include "math.h"


double MATH_puissance(double x, int n)
{
	double xn = 1;

	for (int i = n; i > 0; i--)
	{
		xn = xn * x;
	}

	return xn;
}

//valeur_absolue de barry, FONCTIONNEL
double MATH_valeur_absolue(double x) {
	double abs_x = x >= 0 ? x : -x;
	return abs_x;
}

double MATH_racine_carree(double x)
{
	double racine_carree = x;
	double r_precedent = 0;

	while (MATH_valeur_absolue(racine_carree - r_precedent) > MATH_EPSILON)
	{
		r_precedent = racine_carree;
		racine_carree = 0.5 * (r_precedent + (x / r_precedent));
	}

	return racine_carree;
}

double MATH_sin(double x)
{
	int k = 0;
	
	double sin_x = (MATH_puissance(-1, k) * MATH_puissance(x, 2 * k + 1)) / (MATH_factorielle(2 * k + 1));
	double prochain_terme = (MATH_puissance(-1, k +1) * MATH_puissance(x, 2 * k + 2)) / (MATH_factorielle(2 * k + 2));

	while (prochain_terme > MATH_EPSILON)
	{
		k++;
		double sin_x = (MATH_puissance(-1, k) * MATH_puissance(x, 2 * k + 1)) / (MATH_factorielle(2 * k + 1));
		double prochain_terme = (MATH_puissance(-1, k + 1) * MATH_puissance(x, 2 * k + 2)) / (MATH_factorielle(2 * k + 2));
	}

	return sin_x;
}

void test_MATH_puissance(void)
{
	const double valeur_attendue_1 = 1.000;
	const double valeur_attendue_2 = 1.000;
	const double valeur_attendue_3 = 1.000;
	const double valeur_attendue_4 = 4.000;
	const double valeur_attendue_5 = 4747561509943.000;

	double valeur_obtenue_1 = MATH_puissance(1.0,0);
	double valeur_obtenue_2 = MATH_puissance(1.0,1);
	double valeur_obtenue_3 = MATH_puissance(1.0,2);
	double valeur_obtenue_4 = MATH_puissance(2.0,2);
	double valeur_obtenue_5 = MATH_puissance(7.0,15);

	printf("\n\tTest no.1 - MATH_pusisance(1.0,0\n\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendue_1);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_1);

	printf("\n\tTest no.2 - MATH_pusisance(1.0,1\n\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendue_2);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_2);

	printf("\n\tTest no.3 - MATH_pusisance(1.0,2\n\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendue_3);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_3);

	printf("\n\tTest no.4 - MATH_pusisance(2.0,2\n\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendue_4);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_4);

	printf("\n\tTest no.5 - MATH_pusisance(7.0,15\n\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendue_5);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_5);
}

void test_MATH_racine_carree(void)
{
	const double valeur_attendue_1 = 1.414;
	const double valeur_attendue_2 = 2.000;

	double valeur_obtenue_1 = MATH_racine_carree(2.0);
	double valeur_obtenue_2 = MATH_racine_carree(4.0);

	printf("\n\tTest no.1 - MATH_racine_carree(2.0\n\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendue_1);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_1);

	printf("\n\tTest no.2 - MATH_racine_carree(4.0\n\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendue_2);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_2);

}

void test_MATH_sin(void)
{

	const double valeur_attendue_1 = 0.000;
	const double valeur_attendue_2 = 0.707;
	const double valeur_attendue_3 = 1.000;
	const double valeur_attendue_4 = 0.707;

	double valeur_obtenue_1 = MATH_sin(0.0);
	double valeur_obtenue_2 = MATH_sin(PI /4);
	double valeur_obtenue_3 = MATH_sin(PI /2);
	double valeur_obtenue_4 = MATH_sin(3* PI /4);

	double x1 = 0.0;
	double x2 = PI / 4;
	double x3 = PI / 2;
	double x4 = 3 * PI / 4;

	printf("\n\tTest no.1 - MATH_sin(0.0\n\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendue_1);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_1);

	printf("\n\tTest no.2 - MATH_sin(0.0\n\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendue_2);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_2);

	printf("\n\tTest no.3 - MATH_sin(0.0\n\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendue_3);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_3);

	printf("\n\tTest no.4 - MATH_sin(0.0\n\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendue_4);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_4);

}
