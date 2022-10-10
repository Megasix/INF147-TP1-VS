/*********************************************************************
Par : Tous
Date : Octobre 2022
Ce module permet de découper les commandes pour l'analyse.
On y retrouve les sous-programmes suivants :
 - COM_get_opcode : Extrait le code d'opération d'une commande.
 - COM_get_operande_1 : Extrait le premier opérande d'une commande.
 - COM_get_operande_2 : Extrait le deuxième opérande d'une commande.
 - test_COM_get_opcode : Test unitaire pour la fonction COM_get_opcode.
 - test_COM_get_operande_1 : Test unitaire pour la fonction COM_get_operande_1.
 - test_COM_get_operande_2 : Test unitaire pour la fonction COM_get_operande_2.
*********************************************************************/
#include "mod_com.h"

#include "mod_bits.h"

// Extrait le code d'opération d'une commande.
unsigned int COM_get_opcode(unsigned int une_commande)
{
	// On va chercher l'opcode de la commande à l'aide de la fonction BITS_extraire
	unsigned int opcode = BITS_extraire(une_commande, OPCODE_BIT_DEBUT, OPCODE_BIT_FIN);
	return opcode;
}

// Extrait le premier opérande d'une commande.
unsigned int COM_get_operande_1(unsigned int une_commande)
{
	// On va chercher la premiere oprerande de la commande à l'aide de la fonction BITS_extraire
	unsigned int operande_1 = BITS_extraire(une_commande, OPERANDE_1_BIT_DEBUT, OPERANDE_1_BIT_FIN);
	return operande_1;
}

// Extrait le deuxième opérande d'une commande.
unsigned int COM_get_operande_2(unsigned int une_commande)
{
	// On va chercher la deuxieme oprerande de la commande à l'aide de la fonction BITS_extraire
	unsigned int operande_2 = BITS_extraire(une_commande, OPERANDE_2_BIT_DEBUT, OPERANDE_2_BIT_FIN);
	return operande_2;
}

// Test unitaire pour la fonction COM_get_opcode.
void test_COM_get_opcode()
{
	printf("\nTEST_COM_GET_OPCODE\n");

	const unsigned int une_commande = 2310760003; // La commande de l'énoncé
	const unsigned int valeur_attendue = 3; // La valeur atendue selon l'énoncé
	unsigned int valeur_obtenue; // La valeur qui sera obtenue selon la fonction COM_get_opcode

	// On met l'opcode dans la valeur obtenue
	valeur_obtenue = COM_get_opcode(une_commande);

	printf("\n\tTest no.1 - COM_get_opcode(%u)\n", une_commande);
	printf("\t\tReponse attendue : %u\n", valeur_attendue);
	printf("\t\tReponse obtenue  : %u\n", valeur_obtenue);
}

// Test unitaire pour la fonction COM_get_operande_1.
void test_COM_get_operande_1()
{
	printf("\nTEST_COM_GET_OPERANDE_1\n");

	const unsigned int une_commande = 2310760003; // La commande de l'énoncé
	const unsigned int valeur_attendue = 200; // La valeur atendue selon l'énoncé
	unsigned int valeur_obtenue; // La valeur qui sera obtenue selon la fonction COM_get_operande_1

	valeur_obtenue = COM_get_operande_1(une_commande);

	printf("\n\tTest no.1 - COM_get_operande_1(%u)\n", une_commande);
	printf("\t\tReponse attendue : %u\n", valeur_attendue);
	printf("\t\tReponse obtenue  : %u\n", valeur_obtenue);
}

// Test unitaire pour la fonction COM_get_operande_2.
void test_COM_get_operande_2()
{
	printf("\nTEST_COM_GET_OPERANDE_2\n");

	const unsigned int une_commande = 2310760003; // La commande de l'énoncé
	const unsigned int valeur_attendue = 475; // La valeur atendue selon l'énoncé
	unsigned int valeur_obtenue; // La valeur qui sera obtenue selon la fonction COM_get_operande_2

	valeur_obtenue = COM_get_operande_2(une_commande);

	printf("\n\tTest no.1 - COM_get_opcode_2(%u)\n", une_commande);
	printf("\t\tReponse attendue : %u\n", valeur_attendue);
	printf("\t\tReponse obtenue  : %u\n", valeur_obtenue);
}
