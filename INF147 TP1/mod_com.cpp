#include "mod_com.h"

#include "mod_bits.h"


unsigned int COM_get_opcode(unsigned int une_commande)
{
	unsigned int opcode = BITS_extraire(une_commande, OPCODE_BIT_DEBUT, OPCODE_BIT_FIN);
	return opcode;
}

unsigned int COM_get_operande_1(unsigned int une_commande)
{
	unsigned int operande_1 = BITS_extraire(une_commande, OPERANDE_1_BIT_DEBUT, OPERANDE_1_BIT_FIN);
	return operande_1;
}

unsigned int COM_get_operande_2(unsigned int une_commande)
{
	unsigned int operande_2 = BITS_extraire(une_commande, OPERANDE_2_BIT_DEBUT, OPERANDE_2_BIT_FIN);
	return operande_2;
}

void test_COM_get_opcode()
{
	printf("\nTEST_COM_GET_OPCODE\n");

	const unsigned int une_commande = 2310760003;
	const unsigned int valeur_attendue = 3;
	unsigned int valeur_obtenue;

	valeur_obtenue = COM_get_opcode(une_commande);

	printf("\n\tTest no.1 - COM_get_opcode(%u)\n", une_commande);
	printf("\t\tReponse attendue : %u\n", valeur_attendue);
	printf("\t\tReponse obtenue  : %u\n", valeur_obtenue);
}

void test_COM_get_operande_1()
{
	printf("\nTEST_COM_GET_OPERANDE_1\n");

	const unsigned int une_commande = 2310760003;
	const unsigned int valeur_attendue = 200;
	unsigned int valeur_obtenue;

	valeur_obtenue = COM_get_operande_1(une_commande);

	printf("\n\tTest no.1 - COM_get_operande_1(%u)\n", une_commande);
	printf("\t\tReponse attendue : %u\n", valeur_attendue);
	printf("\t\tReponse obtenue  : %u\n", valeur_obtenue);
}

void test_COM_get_operande_2()
{
	printf("\nTEST_COM_GET_OPERANDE_2\n");

	const unsigned int une_commande = 2310760003;
	const unsigned int valeur_attendue = 475;
	unsigned int valeur_obtenue;

	valeur_obtenue = COM_get_operande_2(une_commande);

	printf("\n\tTest no.1 - COM_get_opcode_2(%u)\n", une_commande);
	printf("\t\tReponse attendue : %u\n", valeur_attendue);
	printf("\t\tReponse obtenue  : %u\n", valeur_obtenue);
}