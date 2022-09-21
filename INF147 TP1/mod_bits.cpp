#include "mod_bits.h"

/* À remplir */

int BITS_obtenir(unsigned int valeur, int position)
{
	if(position >= 1)
		return (valeur & (1U << (position -  1))) != 0;
	return 0;
}

void BITS_basculer(unsigned int* valeur, int position)
{
	if(position >= 1)
		*valeur ^= (1U << (position - 1));
}

unsigned int BITS_extraire(unsigned int valeur, int position_1, int position_2)
{
	unsigned int ret = 0;
	for (unsigned int pos = position_1; pos <= position_2; pos++)
	{
		ret += BITS_obtenir(valeur, pos) << (pos - position_1);
	}
	return ret;
}

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