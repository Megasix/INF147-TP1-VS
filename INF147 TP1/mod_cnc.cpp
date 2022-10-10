#include "mod_cnc.h"

commande CNC_prochaine_commande(void)
{

	// Compteur statique qui sert à parcourir le flux de commandes
	static int i = 0;

	// Le flux de commandes simulé
	commande tab_commandes[] = { 0b00000000001000100110011001000010,
		                         0b00000000000000000000000000000000,
								 0b00000000001000100110001100100010,
								 0b00000000001110110110001100100010,
		                         0b00000000001110110110011001000010,
								 0b00000000000000000000000000000001,
								 0b00000000001011101110001100100010,
								 0b00000000000000000000000000000000,
								 0b00000000001011101110011001000010,
								 0b00000000000000000000000000000001,
								 0b00000000001000100110011111010010,
								 0b00000000000000000000000000000000,
								 0b00000000001000100110101011110010,
								 0b00000000000000000000000000000001,
								 0b00000000001000100110100101100010,
								 0b00000000000000000000000000000000,
								 0b00000000001110110110100101100010,
								 0b00000000000000000000000000000001,
								 0b00000000001000100110111110100010,
								 0b00000000000000000000000000000000,
								 0b00000000001000100110110010000010,
								 0b00000000001011101110110010000010,
								 0b00000000001011101110111110100010,
								 0b00000000001110110110111110100010,
								 0b00000000001110110110110010000010,
								 0b00000000000000000000000000000001,
								 0b00000000001000100111010010110010,
								 0b00000000000000000000000000000000,
								 0b00000000001011101111000110010010,
								 0b00000000001011101111010010110010,
								 0b00000000001110110111000110010010,
							     0b00000000000000000000000000000011,
								 0b00000000000000000000000000000001,
								 0b00000000000000000000000000000101 };

	// Retourner un signal d'arrêt si le flux de commandes est épuisé
	if (i < sizeof(tab_commandes) / sizeof(commande))
	{
		return tab_commandes[i++];
	}
	else
	{
		return CLOSE;
	}

}

void test_CNC_prochaine_commande(void)
{
	// L'indice de l'opération courante
	int indice_operation;

	// La commande courante dans le flux de commandes
	commande commande_courante;

	// Les codes d'opérations en chaînes de caractères
	static const char* code_operation_str[] = { "LZON",
											    "LZOFF",
											    "DPLC",
											    "DONE",
										        "ERR"  };

	// Numéro de la commande courante 
	int no_commande = 1;

	// Analyser chacune des commandes retournées par la CNC
	while ((commande_courante = CNC_prochaine_commande()) != CLOSE)
	{

		// Découper la commande
		opcode code_operation = COM_get_opcode(commande_courante);
		operande operande_1 = COM_get_operande_1(commande_courante);
		operande operande_2 = COM_get_operande_2(commande_courante);

		// Convertir l'opération en chaîne de caractères pour affichage
		switch (code_operation)
		{
			case LZON:
				indice_operation = INDICE_LZON;
				break;
			case LZOFF:
				indice_operation = INDICE_LZOFF;
				break;
			case DPLC:
				indice_operation = INDICE_DPLC;
				break;
			case DONE:
				indice_operation = INDICE_DONE;
				break;
			default:
				indice_operation = INDICE_ERROR;
		}
	
		// Afficher les paramètres de la commande
		printf("%-4i%s\t%u\t%u\n",
			   no_commande++,
			   code_operation_str[indice_operation],
			   operande_1,
			   operande_2);
	}
		 
}
