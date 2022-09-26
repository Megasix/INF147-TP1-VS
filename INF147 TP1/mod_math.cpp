#include "mod_math.h"

double MATH_valeur_absolue (double x){
    double abs_x = x>=0 ? x : -x;
    return abs_x;
}

unsigned int MATH_factorielle (unsigned int n){
    unsigned int fact_n = 1;
    for (int i = 2; i <= n; i++)
        fact_n *= i;
    return fact_n;
}

double MATH_cosinus (double x){
    double cos_x =0;
    return cos_x;
}

void test_MATH_valeur_absolue(){
    printf("\nTEST_MATH_VALEUR_ABSOLUE\n");

    double x1 = -1;

    printf("\n\tTest no.1 - MATH_valeur_absolue(-1)\n\n");
    printf("\t\tReponse attendue : 1.000\n");
    printf("\t\tReponse obtenue  : %.3f\n",MATH_valeur_absolue(x1));

    double x2 = 0;

    printf("\n\tTest no.2 - MATH_valeur_absolue(0)\n\n");
    printf("\t\tReponse attendue : 0.000\n");
    printf("\t\tReponse obtenue  : %.3f\n",MATH_valeur_absolue(x2));

    double  x3 = 1;

    printf("\n\tTest no.3 - MATH_valeur_absolue(1)\n\n");
    printf("\t\tReponse attendue : 1.000\n");
    printf("\t\tReponse obtenue  : %.3f\n",MATH_valeur_absolue(x3));
}

void test_MATH_factorielle(){
    printf("\nTEST_MATH_FACTORIELLE\n");

    unsigned int n1 = 0;

    printf("\n\tTest no.1 - MATH_factorielle(0)\n\n");
    printf("\t\tReponse attendue : 1\n");
    printf("\t\tReponse obtenue  : %d\n",MATH_factorielle(n1));

    unsigned int n2 = 1;

    printf("\n\tTest no.2 - MATH_factorielle(1)\n\n");
    printf("\t\tReponse attendue : 1\n");
    printf("\t\tReponse obtenue  : %d\n", MATH_factorielle(n2));

    unsigned int n3 = 3;

    printf("\n\tTest no.3 - MATH_factorielle(3)\n\n");
    printf("\t\tReponse attendue : 6\n");
    printf("\t\tReponse obtenue  : %d\n", MATH_factorielle(n3));
}