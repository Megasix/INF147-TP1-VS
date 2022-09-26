#ifndef __MOD_MATH__
#define __MOD_MATH__

#include <stdio.h>

/*
 MATH_PUISSANCE

	Eleve une valeur x a une puissance n

 PARAM�TRES :

	x: Une base dont ont veut calculer une puissance
	n: La puissance d�siree

 VALEUR DE RETOUR :

	xn: La n-ieme puissance de x
*/
double MATH_puissance(double x, int n);

/*
 MATH_VALEUR_ABSOLUE

	Extrait la valeur absolue d'une valeur donnee

 PARAM�TRES :

	x: Une valeur de base

 VALEUR DE RETOUR :

	abs_x: La valeur absolue de x
*/
double MATH_valeur_absolue(double x);

/*
 MATH_RACINE_CARREE

	Extrait la racine carree d'un rationnel

 PARAM�TRES :

	x: Une valeur de base

 VALEUR DE RETOUR :

	racine_carree: La racine carree de x
*/
double MATH_racine_carree(double x);

/*
 MATH_FACTORIELLE

	Calcule la factorielle d'un entier donnee

 PARAM�TRES :

	n: Une valeur de base

 VALEUR DE RETOUR :

	fact_n: La factorielle carree de n
*/
unsigned int MATH_factorielle(unsigned int n);

/*
 MATH_SIN

	Calcule le sinus d'un angle donne en radians

 PARAM�TRES :

	x: Un angle quelconque

 VALEUR DE RETOUR :

	sin_x: Le sinus de l'angle donne
*/
double MATH_sin(double x);

/*
 MATH_COS

	Calcul le cosinus d'un angle donne en radian

 PARAM�TRES :

	x: Un angle quelconque

 VALEUR DE RETOUR :

	cos_x: Le cosinus de l'angle donne
*/
double MATH_cos(double x);

/*
 MATH_ATAN

	Calcule l'arc tangente d'un rationnel donne

 PARAM�TRES :

	x: Un rationnel quelconque

 VALEUR DE RETOUR :

	atan_x: L'arc tangente du rationnel donne
*/
double MATH_atan(double x);

/*
 TEST_MATH_PUISSANCE

	Suite de tests unitaires pour MATH_puissance.

 PARAM�TRES :

	Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void test_MATH_puissance();

/*
 TEST_MATH_VALEUR_ABSOLUE

	Suite de tests unitaires pour MATH_valeur_absolue.

 PARAM�TRES :

	Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void test_MATH_valeur_absolue();

/*
 TEST_MATH_RACINE_CARRE

	Suite de tests unitaires pour MATH_racine_carre.

 PARAM�TRES :

	Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void test_MATH_racine_carree();

/*
 TEST_MATH_FACTORIELLE

	Suite de tests unitaires pour MATH_factorielle.

 PARAM�TRES :

	Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void test_MATH_factorielle();

/*
 TEST_MATH_SIN

	Suite de tests unitaires pour MATH_sin.

 PARAM�TRES :

	Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void test_MATH_sin();

/*
 TEST_MATH_COS

	Suite de tests unitaires pour MATH_cos.

 PARAM�TRES :

	Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void test_MATH_cos();

/*
 TEST_MATH_ATAN

	Suite de tests unitaires pour MATH_atan.

 PARAM�TRES :

	Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void test_MATH_atan();

#endif