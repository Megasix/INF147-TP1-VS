#include "mod_math.h"

#define EPSILON 0.0001
#define PI 3.14159265

//fonction puissance de Teano
double MATH_puissance(double x, int n) {
    double xn = 1;

    for (int i = n; i > 0; i--) {
        xn = xn * x;
    }

    return xn;
}

double MATH_valeur_absolue(double x) {
    double abs_x = x >= 0 ? x : -x;
    return abs_x;
}

unsigned int MATH_factorielle(unsigned int n) {
    unsigned int fact_n = 1;
    for (int i = 2; i <= n; i++)
        fact_n *= i;
    return fact_n;
}

double MATH_cos(double x) {

    int k = 0;
    double cos_x = (MATH_puissance(-1, k) * MATH_puissance(x, 2 * k)) / (MATH_factorielle(2 * k));;
    double terme_suivant =
            (MATH_puissance(-1, k + 1) * MATH_puissance(x, 2 * (k + 1))) / (MATH_factorielle(2 * (k + 1)));

    while (MATH_valeur_absolue(terme_suivant) > EPSILON) {
        k++;
        cos_x += (MATH_puissance(-1, k) * MATH_puissance(x, 2 * k)) / (MATH_factorielle(2 * k));
        terme_suivant = (MATH_puissance(-1, k + 1) * MATH_puissance(x, 2 * (k + 1))) / (MATH_factorielle(2 * (k + 1)));
    }

    return cos_x;
}

//fonction sin de Teano
double MATH_sin(double x)
{
    int k = 0;

    double sin_x = (MATH_puissance(-1, k) * MATH_puissance(x, 2 * k + 1)) / (MATH_factorielle(2 * k + 1));
    double prochain_terme = (MATH_puissance(-1, k + 1) * MATH_puissance(x, 2 * (k + 1) + 1)) / (MATH_factorielle(2 * (k + 1) + 1));

    while (MATH_valeur_absolue(prochain_terme) > EPSILON)
    {
        k++;
        sin_x += (MATH_puissance(-1, k) * MATH_puissance(x, 2 * k + 1)) / (MATH_factorielle(2 * k + 1));
        prochain_terme = (MATH_puissance(-1, k + 1) * MATH_puissance(x, 2 * (k + 1) + 1)) / (MATH_factorielle(2 * (k + 1) + 1));
    }

    return sin_x;
}

//fonction atan de Philippe
double MATH_atan(double x)
{
    double atan_x = 0;
    double prochain_terme = 0;
    int k = 0;

    do
    {
        atan_x += (MATH_puissance(-1, k) * MATH_puissance(x, 2 * k + 1)) / (2 * k + 1);
        k++;
        prochain_terme = MATH_puissance(-1, k) * MATH_puissance(x, 2 * k + 1) / (2 * k + 1);
    } while (MATH_valeur_absolue(prochain_terme) > EPSILON);

    return atan_x;
}

void test_MATH_valeur_absolue() {
    printf("\nTEST_MATH_VALEUR_ABSOLUE\n");

    double x1 = -1;

    printf("\n\tTest no.1 - MATH_valeur_absolue(-1)\n\n");
    printf("\t\tReponse attendue : 1.000\n");
    printf("\t\tReponse obtenue  : %.3f\n", MATH_valeur_absolue(x1));

    double x2 = 0;

    printf("\n\tTest no.2 - MATH_valeur_absolue(0)\n\n");
    printf("\t\tReponse attendue : 0.000\n");
    printf("\t\tReponse obtenue  : %.3f\n", MATH_valeur_absolue(x2));

    double x3 = 1;

    printf("\n\tTest no.3 - MATH_valeur_absolue(1)\n\n");
    printf("\t\tReponse attendue : 1.000\n");
    printf("\t\tReponse obtenue  : %.3f\n", MATH_valeur_absolue(x3));
}

void test_MATH_factorielle() {
    printf("\nTEST_MATH_FACTORIELLE\n");

    unsigned int n1 = 0;

    printf("\n\tTest no.1 - MATH_factorielle(0)\n\n");
    printf("\t\tReponse attendue : 1\n");
    printf("\t\tReponse obtenue  : %d\n", MATH_factorielle(n1));

    unsigned int n2 = 1;

    printf("\n\tTest no.2 - MATH_factorielle(1)\n\n");
    printf("\t\tReponse attendue : 1\n");
    printf("\t\tReponse obtenue  : %d\n", MATH_factorielle(n2));

    unsigned int n3 = 3;

    printf("\n\tTest no.3 - MATH_factorielle(3)\n\n");
    printf("\t\tReponse attendue : 6\n");
    printf("\t\tReponse obtenue  : %d\n", MATH_factorielle(n3));
}

void test_MATH_cos() {
    printf("\nTEST_MATH_COS\n");

    double x1 = 0;

    printf("\n\tTest no.1 - MATH_cos(0)\n\n");
    printf("\t\tReponse attendue : 1.000\n");
    printf("\t\tReponse obtenue  : %.3f\n", MATH_cos(x1));

    double x2 = PI / 4;

    printf("\n\tTest no.2 - MATH_cos(PI/4)\n\n");
    printf("\t\tReponse attendue : 0.707\n");
    printf("\t\tReponse obtenue  : %.3f\n", MATH_cos(x2));

    double x3 = PI / 2;

    printf("\n\tTest no.3 - MATH_cos(PI/2)\n\n");
    printf("\t\tReponse attendue : 0.000\n");
    printf("\t\tReponse obtenue  : %.3f\n", MATH_cos(x3));

    double x4 = 3 * PI / 4;

    printf("\n\tTest no.1 - MATH_cos(3*PI/4)\n\n");
    printf("\t\tReponse attendue : -0.707\n");
    printf("\t\tReponse obtenue  : %.3f\n", MATH_cos(x4));
}