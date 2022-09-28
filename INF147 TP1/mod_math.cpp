#include "mod_math.h"


#define E		0.0001
#define PI		3.14159265


double MATH_puissance(double x, int n)
{
	double xn = 1;

	if (n > 0)
	{
		xn = x;
		for (int i = 1; i < n; i++)
		{
			xn *= x;
		}
	}
	else if (n < 0)
	{
		// Non implemente
	}

	return xn;
}

double MATH_valeur_absolue(double x)
{
	double abs_x = x;

	if (x < 0)
		abs_x = -x;

	return abs_x;
}

double MATH_racine_carree(double x)
{
	double racine_carree = x;
	double r_precedent = 0;

	while (MATH_valeur_absolue(racine_carree - r_precedent) > E)
	{
		r_precedent = racine_carree;
		racine_carree = (r_precedent + (x / r_precedent)) / 2;
	}

	return racine_carree;
}

unsigned int MATH_factorielle(unsigned int n)
{
	unsigned int fact_x = 1;

	for (unsigned int i = 2; i <= n ; i++)
	{
		fact_x *= i;
	}

	return fact_x;
}

double MATH_sin(double x)
{
	double sin_x = 0;



	return sin_x;
}

double MATH_cos(double x)
{
	double cos_x = 0;

	return cos_x;
}

double MATH_atan(double x)
{
	double atan_x = 0;

	return atan_x;
}

void test_MATH_puissance()
{
	printf("\nTEST_MATH_PUISSANCE\n");

	const double x_1 = 1.0;
	const unsigned int n_1 = 0;
	const double valeur_attendu_1 = 1.0;
	double valeur_obtenue_1 = MATH_puissance(x_1, n_1);

	printf("\n\tTest no.1 - MATH_puissance(%.1f, %u)\n", x_1, n_1);
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_1);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_1);

	const double x_2 = 1.0;
	const unsigned int n_2 = 1;
	const double valeur_attendu_2 = 1.0;
	double valeur_obtenue_2 = MATH_puissance(x_2, n_2);

	printf("\n\tTest no.2 - MATH_puissance(%.1f, %u)\n", x_2, n_2);
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_2);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_2);

	const double x_3 = 1.0;
	const unsigned int n_3 = 2;
	const double valeur_attendu_3 = 1.0;
	double valeur_obtenue_3 = MATH_puissance(x_3, n_3);

	printf("\n\tTest no.3 - MATH_puissance(%.1f, %u)\n", x_3, n_3);
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_3);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_3);

	const double x_4 = 2.0;
	const unsigned int n_4 = 2;
	const double valeur_attendu_4 = 4.0;
	double valeur_obtenue_4 = MATH_puissance(x_4, n_4);

	printf("\n\tTest no.3 - MATH_puissance(%.1f, %u)\n", x_4, n_4);
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_4);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_4);

	const double x_5 = 7.0;
	const unsigned int n_5 = 15;
	const double valeur_attendu_5 = 4747561509943.0;
	double valeur_obtenue_5 = MATH_puissance(x_5, n_5);

	printf("\n\tTest no.5 - MATH_puissance(%.1f, %u)\n", x_5, n_5);
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_5);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_5);
}

void test_MATH_valeur_absolue()
{
	printf("\nTEST_MATH_VALEUR_ABSOLUE\n");

	const double x_1 = -1.0;
	const double valeur_attendu_1 = 1.0;
	double valeur_obtenue_1 = MATH_valeur_absolue(x_1);

	printf("\n\tTest no.1 - MATH_valeur_absolue(%.1f)\n", x_1);
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_1);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_1);

	const double x_2 = 0.0;
	const double valeur_attendu_2 = 0.0;
	double valeur_obtenue_2 = MATH_valeur_absolue(x_2);

	printf("\n\tTest no.2 - MATH_valeur_absolue(%.1f)\n", x_2);
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_2);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_2);

	const double x_3 = 1.0;
	const double valeur_attendu_3 = 1.0;
	double valeur_obtenue_3 = MATH_valeur_absolue(x_3);

	printf("\n\tTest no.3 - MATH_valeur_absolue(%.1f)\n", x_3);
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_3);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_3);
}

void test_MATH_racine_carree()
{
	printf("\nTEST_MATH_RACINE_CARREE\n");

	const double x_1 = 2.0;
	const double valeur_attendu_1 = 1.414;
	double valeur_obtenue_1 = MATH_racine_carree(x_1);

	printf("\n\tTest no.1 - MATH_racine_carree(%.1f)\n", x_1);
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_1);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_1);

	const double x_2 = 4;
	const double valeur_attendu_2 = 2;
	double valeur_obtenue_2 = MATH_racine_carree(x_2);

	printf("\n\tTest no.2 - MATH_racine_carree(%.1f)\n", x_2);
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_2);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_2);
}

void test_MATH_factorielle()
{
	printf("\nTEST_MATH_FACTORIELLE\n");

	const unsigned int n_1 = 0;
	const unsigned int valeur_attendu_1 = 1;
	unsigned int valeur_obtenue_1;

	valeur_obtenue_1 = MATH_factorielle(n_1);

	printf("\n\tTest no.1 - MATH_factorielle(%u)\n", n_1);
	printf("\t\tReponse attendue : %u\n", valeur_attendu_1);
	printf("\t\tReponse obtenue  : %u\n", valeur_obtenue_1);

	const unsigned int n_2 = 1;
	const unsigned int valeur_attendu_2 = 2;
	unsigned int valeur_obtenue_2;

	valeur_obtenue_2 = MATH_factorielle(n_2);

	printf("\n\tTest no.2 - MATH_factorielle(%u)\n", n_2);
	printf("\t\tReponse attendue : %u\n", valeur_attendu_2);
	printf("\t\tReponse obtenue  : %u\n", valeur_obtenue_2);

	const unsigned int n_3 = 3;
	const unsigned int valeur_attendu_3 = 6;
	unsigned int valeur_obtenue_3;

	valeur_obtenue_3 = MATH_factorielle(n_3);

	printf("\n\tTest no.3 - MATH_factorielle(%u)\n", n_3);
	printf("\t\tReponse attendue : %u\n", valeur_attendu_3);
	printf("\t\tReponse obtenue  : %u\n", valeur_obtenue_3);
}

void test_MATH_sin()
{
	printf("\nTEST_MATH_SIN\n");

	const double x_1 = 0.0;
	const double valeur_attendu_1 = 0.0;
	double valeur_obtenue_1 = MATH_sin(x_1);

	printf("\n\tTest no.1 - MATH_sin(%.1f)\n", x_1);
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_1);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_1);

	const double x_2 = PI/4;
	const double valeur_attendu_2 = 0.707;
	double valeur_obtenue_2 = MATH_sin(x_2);

	printf("\n\tTest no.2 - MATH_sin(PI / 4)\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_2);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_2);

	const double x_3 = PI/2;
	const double valeur_attendu_3 = 1.0;
	double valeur_obtenue_3 = MATH_sin(x_3);

	printf("\n\tTest no.3 - MATH_sin(PI / 2)\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_3);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_3);

	const double x_4 = 3 * PI / 4;
	const double valeur_attendu_4 = 0.707;
	double valeur_obtenue_4 = MATH_sin(x_4);

	printf("\n\tTest no.3 - MATH_sin(3 * PI / 4)\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_4);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_4);
}

void test_MATH_cos()
{
	printf("\nTEST_MATH_COS\n");

	const double x_1 = 0.0;
	const double valeur_attendu_1 = 1.0;
	double valeur_obtenue_1 = MATH_cos(x_1);

	printf("\n\tTest no.1 - MATH_cos(%.1f)\n", x_1);
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_1);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_1);

	const double x_2 = PI/4;
	const double valeur_attendu_2 = 0.707;
	double valeur_obtenue_2 = MATH_cos(x_2);

	printf("\n\tTest no.2 - MATH_cos(PI / 4)\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_2);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_2);

	const double x_3 = PI/2;
	const double valeur_attendu_3 = 0.0;
	double valeur_obtenue_3 = MATH_cos(x_3);

	printf("\n\tTest no.3 - MATH_cos(PI / 2)\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_3);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_3);

	const double x_4 = 3*PI/4;
	const double valeur_attendu_4 = 0.707;
	double valeur_obtenue_4 = MATH_cos(x_4);

	printf("\n\tTest no.3 - MATH_cos(3 * PI / 4)\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_4);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_4);
}

void test_MATH_atan()
{
	printf("\nTEST_MATH_ATAN\n");

	const double x_1 = 0.0;
	const double valeur_attendu_1 = 0.0;
	double valeur_obtenue_1 = MATH_atan(x_1);

	printf("\n\tTest no.1 - MATH_atan(%.1f)\n", x_1);
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_1);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_1);

	const double x_2 = 1.0;
	const double valeur_attendu_2 = 0.785;
	double valeur_obtenue_2 = MATH_atan(x_2);

	printf("\n\tTest no.2 - MATH_atan(%.1f)\n", x_2);
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_2);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_2);
}
