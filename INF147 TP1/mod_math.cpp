/*********************************************************************
Par : Tous
Date : Octobre 2022
Ce module contient les fonctions qui sont utilisé pour créer le graphique dans mod_traceur
On y retrouve les sous-programmes suivants :
- MATH_puissance : Eleve une valeur x a une puissance n donnee.
- MATH_valeur_absolue : Extrait la valeur absolue d'une valeur donnée.
- MATH_racine_carree : Extrait la racine carrée d'un rationnel.
- MATH_factorielle : Calcule la factorielle d'un entier donné.
- MATH_sin : Calcule le sinus d'un angle donné en radians.
- MATH_cos : Calcule le cosinus d'un angle donné en radians.
- MATH_atan : Calcule l'arc tangente d'un rationnel donné.
- test_MATH_puissance : Suite de tests unitaires pour la fonction MATH_puissance.
- test_MATH_valeur_absolue : Suite de tests unitaires pour la fonction MATH_valeur_absolue.
- test_MATH_racine_carree : Suite de tests unitaires pour la fonction MATH_racine_carree.
- test_MATH_factorielle : Suite de tests unitaires pour la fonction MATH_factorielle.
- test_MATH_sin : Suite de tests unitaires pour la fonction MATH_sin.
- test_MATH_cos : Suite de tests unitaires pour la fonction MATH_cos.
- test_MATH_atan : Suite de tests unitaires pour la fonction MATH_atan.
*********************************************************************/
#include "mod_math.h"

// Eleve une valeur x a une puissance n donnee.
double MATH_puissance(double x, int n)
{
	double xn = 1; // Variable x facteur n

	// On veut seulement calculer la puissance si le facteur est plus grand que 0, sinon on retourne 1
	if (n > 0)
	{
		xn = x;
		// On multiplie la valeur de x "n" fois
		for (int i = 1; i < n; i++) 
		{
			xn *= x;
		}
	}

	return xn;
}

// Extrait la valeur absolue d'une valeur donnée.
double MATH_valeur_absolue(double x)
{
	// Si la valeur est plus petite que zero, on applique un double negatif pour avoir la valeur positive, sinon on garde x
	double abs_x = (x < 0) ? -x : x;

	return abs_x;
}

// Extrait la racine carrée d'un rationnel.
double MATH_racine_carree(double x)
{
	double racine_carree = x; // La racine carree courante
	double racine_precedent = 0; // La racine carree precedente 

	while (MATH_valeur_absolue(racine_carree - racine_precedent) > MATH_EPSILON)
	{
		racine_precedent = racine_carree; // Assignation de la racine courante dans la racine precedente 
		racine_carree = (racine_precedent + (x / racine_precedent)) / 2; // algorithme de Babylone
	}

	return racine_carree;
}

// Calcule la factorielle d'un entier donné.
unsigned int MATH_factorielle(unsigned int n)
{
	unsigned int fact_n = 1; // Initialisation de la factorielle de n

	for (unsigned int i = 2; i <= n ; i++)  
	{
		fact_n *= i; // Multiplication de la factorielle courante par le nombre incremente "i"
	}

	return fact_n;
}

// Calcule le sinus d'un angle donné en radians.
double MATH_sin(double x)
{
	double sin_x = 0; // Initialisation du sinus de x
	double prochain_terme = 0; // Initialisation du prochain terme pour la boucle
	int k = 0; // Initialisation du compteur pour la boucle

	// Boucle qui reproduit l'approximation polynômiale donnée par la série de Taylor
	do
	{
		sin_x += (MATH_puissance(-1, k) * MATH_puissance(x, 2 * k + 1)) / MATH_factorielle(2 * k + 1 );
		k++;
		prochain_terme = MATH_puissance(-1, k) * MATH_puissance(x, 2 * k + 1) / MATH_factorielle(2 * k + 1);
	} while (MATH_valeur_absolue(prochain_terme) > MATH_EPSILON); // Vérification que le prochain terme est plus grand que 1/10^4

	return sin_x;
}

// Calcule le cosinus d'un angle donné en radians.
double MATH_cos(double x)
{
	double cos_x = 0; // Initialisation du cosinus de x
	double prochain_terme = 0;  // Initialisation du prochain terme pour la boucle
	int k = 0; // Initialisation du compteur pour la boucle

	// Boucle qui reproduit l'approximation polynômiale donnée par la série de Taylor
	do
	{
		cos_x += (MATH_puissance(-1, k) * MATH_puissance(x, 2 * k)) / MATH_factorielle(2 * k);
		k++;
		prochain_terme = MATH_puissance(-1, k) * MATH_puissance(x, 2 * k) / MATH_factorielle(2 * k);
	} while (MATH_valeur_absolue(prochain_terme) > MATH_EPSILON); // Vérification que le prochain terme est plus grand que 1/10^4

	return cos_x;
}

// Calcule l'arc tangente d'un rationnel donné.
double MATH_atan(double x)
{
	double atan_x = 0; // Initialisation de l'actangente de x
	double prochain_terme = 0; // Initialisation du prochain terme pour la boucle
	int k = 0; // Initialisation du compteur pour la boucle

	// Boucle qui reproduit l'approximation polynômiale donnée par la série de Taylor
	do
	{
		atan_x += (MATH_puissance(-1, k) * MATH_puissance(x, 2 * k + 1)) / (2 * k + 1);
		k++;
		prochain_terme = MATH_puissance(-1, k) * MATH_puissance(x, 2 * k + 1) / (2 * k + 1);
	} while (MATH_valeur_absolue(prochain_terme) > MATH_EPSILON); // Vérification que le prochain terme est plus grand que 1/10^4

	return atan_x;
}

// uite de tests unitaires pour la fonction MATH_puissance.
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

// Suite de tests unitaires pour la fonction MATH_valeur_absolue.
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

//Suite de tests unitaires pour la fonction MATH_racine_carree.
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

// Suite de tests unitaires pour la fonction MATH_factorielle.
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

// Suite de tests unitaires pour la fonction MATH_sin.
void test_MATH_sin()
{
	printf("\nTEST_MATH_SIN\n");

	const double x_1 = 0.0;
	const double valeur_attendu_1 = 0.0;
	double valeur_obtenue_1 = MATH_sin(x_1);

	printf("\n\tTest no.1 - MATH_sin(%.1f)\n", x_1);
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_1);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_1);

	const double x_2 = MATH_PI/4;
	const double valeur_attendu_2 = 0.707;
	double valeur_obtenue_2 = MATH_sin(x_2);

	printf("\n\tTest no.2 - MATH_sin(PI / 4)\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_2);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_2);

	const double x_3 = MATH_PI/2;
	const double valeur_attendu_3 = 1.0;
	double valeur_obtenue_3 = MATH_sin(x_3);

	printf("\n\tTest no.3 - MATH_sin(PI / 2)\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_3);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_3);

	const double x_4 = 3 * MATH_PI / 4;
	const double valeur_attendu_4 = 0.707;
	double valeur_obtenue_4 = MATH_sin(x_4);

	printf("\n\tTest no.3 - MATH_sin(3 * PI / 4)\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_4);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_4);
}

// Suite de tests unitaires pour la fonction MATH_cos.
void test_MATH_cos()
{
	printf("\nTEST_MATH_COS\n");

	const double x_1 = 0.0;
	const double valeur_attendu_1 = 1.0;
	double valeur_obtenue_1 = MATH_cos(x_1);

	printf("\n\tTest no.1 - MATH_cos(%.1f)\n", x_1);
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_1);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_1);

	const double x_2 = MATH_PI / 4;
	const double valeur_attendu_2 = 0.707;
	double valeur_obtenue_2 = MATH_cos(x_2);

	printf("\n\tTest no.2 - MATH_cos(PI / 4)\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_2);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_2);

	const double x_3 = MATH_PI / 2;
	const double valeur_attendu_3 = 0.0;
	double valeur_obtenue_3 = MATH_cos(x_3);

	printf("\n\tTest no.3 - MATH_cos(PI / 2)\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_3);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_3);

	const double x_4 = 3* MATH_PI / 4;
	const double valeur_attendu_4 = -0.707;
	double valeur_obtenue_4 = MATH_cos(x_4);

	printf("\n\tTest no.3 - MATH_cos(3 * PI / 4)\n");
	printf("\t\tReponse attendue : %.3f\n", valeur_attendu_4);
	printf("\t\tReponse obtenue  : %.3f\n", valeur_obtenue_4);
}

// Suite de tests unitaires pour la fonction MATH_atan.
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

