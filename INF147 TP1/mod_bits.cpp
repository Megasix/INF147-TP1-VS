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

#include "mod_bits.h"

/*****************************************************************************************
*                                 FONCTIONS PUBLIQUES                                    *
*****************************************************************************************/

// Retourne l'etat d'un bit a une position donnee
unsigned int BITS_obtenir(unsigned int valeur, unsigned int position)
{
	unsigned int valeur_bit = 0;	// La valeur du bit a retourner
	// Lecture du bit a la position donnee
	if(position >= POSITION_MIN)
		valeur_bit = (valeur >> (position - 1) & MASQUE_BIT_1);
	return valeur_bit;
}

// Bascule un bit a une position donne
void BITS_basculer(unsigned int* valeur, unsigned int position)
{
	// On bascule le bit a la position donne
	if(position >= POSITION_MIN)
		*valeur ^= (MASQUE_BIT_1 << (position - 1));	
}

// Extrait les bits situe entre deux positions fournies d'une valeur donnee
unsigned int BITS_extraire(unsigned int valeur, unsigned int bit_depart
	                      , unsigned int bit_fin)
{
	unsigned int segment_bits = 0;	// La valeur du segments de bits selectionne
	for (unsigned int position = bit_depart; position <= bit_fin; position++)
	{
		//On vérifie chaque bit entre les 2 positions et les extrait dans segments_bits
		if (BITS_obtenir(valeur, position))	
			BITS_basculer(&segment_bits, position - (bit_depart - 1));
	}
	return segment_bits;
}

// Suite de tests unitaires pour BITS_obtenir.
void test_BITS_obtenir(void)
{

	printf("\nTEST_BITS_OBTENIR\n");

	const unsigned int une_valeur = 2863311530;

	printf("\n\tTest no.1 - Afficher les bits de 2,863,311,530 en petit boutien\n\n");
	printf("\t\tReponse attendue : 1010 1010 1010 1010 1010 1010 1010 1010\n");
	printf("\t\tReponse obtenue  : ");

	int compteur = 1;

	for (int i = UINT_NB_BITS; i >= 1; i--)
	{

		printf("%i", BITS_obtenir(une_valeur, i));

		if (compteur % 4 == 0)
		{
			printf(" ");
		}

		compteur++;

	}

	printf("\n");

}

// Suite de tests unitaires pour BITS_basculer.
void test_BITS_basculer(void)
{

	printf("\nTEST_BITS_BASCULER\n");

	const unsigned int valeur_attendue_1 = 4294967295;
	unsigned int valeur_obtenue_1 = 2863311530;

	for (int i = 1; i <= UINT_NB_BITS - 1; i = i + 2)
	{
		BITS_basculer(&valeur_obtenue_1, i);
	}

	printf("\n\tTest no.1 - Basculer les bits pairs de 2863311530\n\n");
	printf("\t\tReponse attendue : %u\n", valeur_attendue_1);
	printf("\t\tReponse obtenue  : %u\n", valeur_obtenue_1);

}

// Suite de tests unitaires pour BITS_extraire.
void test_BITS_extraire(void)
{

	printf("\nTEST_BITS_EXTRAIRE\n");

	const unsigned int une_valeur = 2863311530;

	unsigned int valeur_attendue_1 = 10;
	unsigned int valeur_obtenue_1 = BITS_extraire(une_valeur, 1, 4);

	printf("\n\tTest no.1 - Afficher les bits 1 -> 4 de 2,863,311,530\n\n");
	printf("\t\tReponse attendue : %u\n", valeur_attendue_1);
	printf("\t\tReponse obtenue  : %u\n", valeur_obtenue_1);

	unsigned int valeur_attendue_2 = 5;
	unsigned int valeur_obtenue_2 = BITS_extraire(une_valeur, 2, 5);

	printf("\n\tTest no.2 - Afficher les bits 2 -> 5 de 2,863,311,530\n\n");
	printf("\t\tReponse attendue : %u\n", valeur_attendue_2);
	printf("\t\tReponse obtenue  : %u\n", valeur_obtenue_2);

}