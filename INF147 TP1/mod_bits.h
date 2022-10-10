/*****************************************************************************************
Auteurs :	Barry Lawson
			Philippe Marineau
			Jean-Philippe Portant
			Teano Rocha
Date : Octobre 2022

Permet de manipuler les données au niveau des bits avec les opérateurs binaires vus en
classe

On y retrouve les sous-programmes suivants :
	- BITS_obtenir : Retourne l'etat d'un bit a une position donnee
	- BITS_basculer : Bascule un bit a une position donne
	- BITS_extraire : Extrait les bits situe entre deux positions fournies d'une valeur
					  donnee
	- test_BITS_obtenir : Suite de tests unitaires pour BITS_obtenir.
	- test_BITS_basculer : Suite de tests unitaires pour BITS_basculer.
	- test_BITS_extraire : Suite de tests unitaires pour BITS_extraire.
*****************************************************************************************/

#ifndef __MOD_BITS__
#define __MOD_BITS__

#include <stdio.h>

/*****************************************************************************************
*                                      CONSTANTES                                        *
*****************************************************************************************/

#define UINT_NB_BITS	32		// Le nombre de bits dans un entier non signé
#define BIT_ACTIF		1		// Un bit allumé
#define BIT_INACTIF		0		// Un bit éteint
#define POSITION_MIN	1		// L'indice du premier bit
#define MASQUE_BIT_1	0b1		// Un masque avec le premier bit actif

/*****************************************************************************************
*                                 FONCTIONS PUBLIQUES                                    *
*****************************************************************************************/

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
unsigned int BITS_extraire(unsigned int valeur, unsigned int bit_depart
						  , unsigned int bit_fin);

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