#ifndef __MOD_MATH__
#define __MOD_MATH__

#include <stdio.h>

#define UINT_NB_BITS 32		// Le nombre de bits dans un entier non signe
#define BIT_ACTIF    1		// Un bit allume
#define BIT_INACTIF  0		// Un bit eteint

void test_MATH_valeur_absolue();

void test_MATH_factorielle();

void test_MATH_cos();

double MATH_atan(double x);

double MATH_cos(double x);

double MATH_sin(double x);
#endif