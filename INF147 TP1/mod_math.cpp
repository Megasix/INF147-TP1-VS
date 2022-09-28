#include "mod_math.h"

double MATH_puissance(double x, int n) 
{
	double xn = 1.;
	int i = 1;
	if (n != 0)
	{
		while (i <= n) {
			xn *= x;
			i++;
		}
		return xn;
	}
	else
	{
		return 1.;
	}
}

double MATH_valeur_absolue(double x) 
{
	double abs_x = (x<0) ? x*-1 : x;
	return abs_x;
}

double MATH_racine_carree(double x) 
{
	double racine_carree = x;
	double racine_carree_prec = 0;

	while (MATH_valeur_absolue(racine_carree - racine_carree_prec) > MATH_EPSILON)
	{
		racine_carree_prec = racine_carree;
		racine_carree = .5 * (racine_carree_prec + (x / racine_carree_prec));
	}
	return racine_carree;
}

unsigned int MATH_factorielle(int n) 
{
	unsigned int fact_n = 1;
	for (int i = 2; i <= n; i++)
	{
		fact_n = fact_n * i;
	}
	return fact_n;
}

double MATH_sin(double x) 
{
	int k = 0;
	double sin_x = 0;
	double sin_x_temp;
	double num1;
	double num2;
	double denum;
	do
	{
		/*num1 = MATH_puissance(-1, k);
		num2 = MATH_puissance(x, 2 * k + 1);
		denum = MATH_factorielle(2 * k + 1);
		sin_x_temp = num1 * num2;
		sin_x_temp = sin_x_temp / denum;
		sin_x = sin_x + sin_x_temp;*/
		sin_x_temp = (MATH_puissance(-1, k) * MATH_puissance(x, 2 * k + 1)) / MATH_factorielle(2 * k + 1);
		sin_x = sin_x + sin_x_temp;
		k++;
	} while (MATH_valeur_absolue(sin_x_temp) > 0.0001);

	return sin_x;
}

void test_MATH_sin(void) 
{
	double x = (3*PI)/4;
	printf("%0.3lf", MATH_sin(x));
	printf("\n\n");
}

void test_MATH_factorielle(void) 
{
	int x = 5;
	printf("%i", MATH_factorielle(x));
	printf("\n\n");
}

void test_MATH_racine_carree(void)  
{
	double x = 4.0;
	printf("%0.3lf", MATH_racine_carree(x));
	printf("\n\n");
}
void test_MATH_valeur_absolue(void) 
{
	double x = 0.0;
	printf("%0.3lf", MATH_valeur_absolue(x));
	printf("\n\n");
}

void test_MATH_puissance(void)
{
	
	printf("TEST_MATH_PUISSANCE\n\n");

	// Test no.1
	double x = 1.0;
	int n = 0;

	printf("\n\tTest no.1 - MATH_puissance(%0.1lf, %i)\n\n", x , n);
	printf("\t\tReponse attendue : 1.000\n");
	printf("\t\tReponse obtenue  : ");

	printf("%0.3lf", MATH_puissance(x, n));
	printf("\n\n");

	// Test no.2
	x = 1.0;
	n = 1;

	printf("\n\tTest no.2 - MATH_puissance(%0.1lf, %i)\n\n", x, n);
	printf("\t\tReponse attendue : 1.000\n");
	printf("\t\tReponse obtenue  : ");

	printf("%0.3lf", MATH_puissance(x, n));
	printf("\n\n");

	// Test no.3
	x = 1.0;
	n = 2;

	printf("\n\tTest no.3 - MATH_puissance(%0.1lf, %i)\n\n", x, n);
	printf("\t\tReponse attendue : 1.000\n");
	printf("\t\tReponse obtenue  : ");

	printf("%0.3lf", MATH_puissance(x, n));
	printf("\n\n");

	// Test no.4
	x = 2.0;
	n = 2;

	printf("\n\tTest no.4 - MATH_puissance(%0.1lf, %i)\n\n", x, n);
	printf("\t\tReponse attendue : 4.000\n");
	printf("\t\tReponse obtenue  : ");

	printf("%0.3lf", MATH_puissance(x, n));

	printf("\n\n");

	// Test no.5
	x = 7.0;
	n = 15;

	printf("\n\tTest no.5 - MATH_puissance(%0.1lf, %i)\n\n", x, n);
	printf("\t\tReponse attendue : 4,747,561,509,943.000\n");
	printf("\t\tReponse obtenue  : ");

	printf("%0.3lf", MATH_puissance(x, n));

	printf("\n\n");
}