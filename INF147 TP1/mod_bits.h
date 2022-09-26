#ifndef __MOD_BITS__
#define __MOD_BITS__

#include <stdio.h>

#define UINT_NB_BITS 32		// Le nombre de bits dans un entier non signé
#define BIT_ACTIF    1		// Un bit allumé
#define BIT_INACTIF  0		// Un bit éteint

/*
 BITS_OBTENIR

	Retourne l'etat d'un bit a une position donnee.

 PARAMÈTRES :

	 Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
unsigned int BITS_obtenir(unsigned int valeur, int position);

/*
 BITS_BASCULER

	Suite de tests unitaires pour BITS_basculer.

 PARAMÈTRES :

	 Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void BITS_basculer(unsigned int* valeur, int position);

/*
 BITS_EXTRAIRE

	Suite de tests unitaires pour BITS_extraire.

 PARAMÈTRES :

	 Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
unsigned int BITS_extraire(unsigned int valeur, int position_1, int position_2);

/*
 TEST_BITS_OBTENIR

	Suite de tests unitaires pour BITS_obtenir.

 PARAMÈTRES :

	 Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void test_BITS_obtenir(void);

/*
 TEST_BITS_BASCULER

	Suite de tests unitaires pour BITS_basculer.

 PARAMÈTRES :

	 Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void test_BITS_basculer(void);

/*
 TEST_BITS_EXTRAIRE

	Suite de tests unitaires pour BITS_extraire.

 PARAMÈTRES :

	 Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void test_BITS_extraire(void);

#endif