#ifndef __MOD_BITS__
#define __MOD_BITS__

#include <stdio.h>

#define UINT_NB_BITS 32		// Le nombre de bits dans un entier non signé
#define BIT_ACTIF    1		// Un bit allumé
#define BIT_INACTIF  0		// Un bit éteint

#define POSITION_MIN		1
#define MASQUE_BIT_1		0b1

/*
 BITS_OBTENIR

	Retourne l'etat d'un bit a une position donnee.

 PARAMÈTRES :

	valeur: Une valeur quelconque.
	position: La position du bit a consulter.

 VALEUR DE RETOUR :

	valeur_bit: La valeur du bit a la position donnee.
*/
unsigned int BITS_obtenir(unsigned int valeur, unsigned int position);

/*
 BITS_BASCULER

	Bascule un bit a une position donne

 PARAMÈTRES :

	valeur: Une reference vers une valeur quelconque.
	position: La position du bit a basculer.

 VALEUR DE RETOUR :

	Aucune.
*/
void BITS_basculer(unsigned int* valeur, unsigned int position);

/*
 BITS_EXTRAIRE

	Extrait les bits situe entre deux positions fournies d'une valeur donnee

 PARAMÈTRES :

	valeur: Une reference vers une valeur quelconque.
	bit_depart: La position du bit de depart.
	bit_fin: La position du bit de fin.

 VALEUR DE RETOUR :

	segment_bits: Segment de bits extrait.
*/
unsigned int BITS_extraire(unsigned int valeur, unsigned int bit_depart, unsigned int bit_fin);

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