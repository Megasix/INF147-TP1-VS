/*****************************************************************************************
Auteurs :	Barry Lawson
			Philippe Marineau
			Jean-Philippe Portant
			Teano Rocha
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
*****************************************************************************************/

#ifndef __MOD_MATH__
#define __MOD_MATH__

#include <stdio.h>


#define MATH_EPSILON		0.0001
#define MATH_PI				3.14159265


/*
 MATH_PUISSANCE

	Eleve une valeur x a une puissance n

 PARAMÈTRES :

	x: Une base dont ont veut calculer une puissance
	n: La puissance désiree

 VALEUR DE RETOUR :

	xn: La n-ieme puissance de x
*/
double MATH_puissance(double x, int n);

/*
 MATH_VALEUR_ABSOLUE

	Extrait la valeur absolue d'une valeur donnee

 PARAMÈTRES :

	x: Une valeur de base

 VALEUR DE RETOUR :

	abs_x: La valeur absolue de x
*/
double MATH_valeur_absolue(double x);

/*
 MATH_RACINE_CARREE

	Extrait la racine carree d'un rationnel

 PARAMÈTRES :

	x: Une valeur de base

 VALEUR DE RETOUR :

	racine_carree: La racine carree de x
*/
double MATH_racine_carree(double x);

/*
 MATH_FACTORIELLE

	Calcule la factorielle d'un entier donnee

 PARAMÈTRES :

	n: Une valeur de base

 VALEUR DE RETOUR :

	fact_n: La factorielle carree de n
*/
unsigned int MATH_factorielle(unsigned int n);

/*
 MATH_SIN

	Calcule le sinus d'un angle donne en radians

 PARAMÈTRES :

	x: Un angle quelconque

 VALEUR DE RETOUR :

	sin_x: Le sinus de l'angle donne
*/
double MATH_sin(double x);

/*
 MATH_COS

	Calcul le cosinus d'un angle donne en radian

 PARAMÈTRES :

	x: Un angle quelconque

 VALEUR DE RETOUR :

	cos_x: Le cosinus de l'angle donne
*/
double MATH_cos(double x);

/*
 MATH_ATAN

	Calcule l'arc tangente d'un rationnel donne

 PARAMÈTRES :

	x: Un rationnel quelconque

 VALEUR DE RETOUR :

	atan_x: L'arc tangente du rationnel donne
*/
double MATH_atan(double x);

/*
 TEST_MATH_PUISSANCE

	Suite de tests unitaires pour MATH_puissance.

 PARAMÈTRES :

	Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void test_MATH_puissance();

/*
 TEST_MATH_VALEUR_ABSOLUE

	Suite de tests unitaires pour MATH_valeur_absolue.

 PARAMÈTRES :

	Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void test_MATH_valeur_absolue();

/*
 TEST_MATH_RACINE_CARRE

	Suite de tests unitaires pour MATH_racine_carre.

 PARAMÈTRES :

	Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void test_MATH_racine_carree();

/*
 TEST_MATH_FACTORIELLE

	Suite de tests unitaires pour MATH_factorielle.

 PARAMÈTRES :

	Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void test_MATH_factorielle();

/*
 TEST_MATH_SIN

	Suite de tests unitaires pour MATH_sin.

 PARAMÈTRES :

	Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void test_MATH_sin();

/*
 TEST_MATH_COS

	Suite de tests unitaires pour MATH_cos.

 PARAMÈTRES :

	Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void test_MATH_cos();

/*
 TEST_MATH_ATAN

	Suite de tests unitaires pour MATH_atan.

 PARAMÈTRES :

	Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void test_MATH_atan();

#endif