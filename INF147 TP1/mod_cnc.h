#ifndef __MOD_CNC__
#define __MOD_CNC__

#include <stdio.h>
#include "mod_com.h"

#define LZON 0		// Ouverture du laser
#define LZOFF 1		// Fermeture du laser
#define DPLC 2	    // D�placement lin�aire
#define DONE 3      // Lecture termin�e
#define ERR 4		// Erreur de lecture 
#define CLOSE 5		// Fermer la CNC

// Positions des cha�nes de caract�res dans le tableau de
// codes d'op�rations dans test_CNC_prochaine_commande.
#define INDICE_LZON 0
#define INDICE_LZOFF 1
#define INDICE_DPLC 2
#define INDICE_DONE 3
#define INDICE_ERROR 4

// Type qui repr�sente une commande
typedef unsigned int commande;

// Type qui represente un code d'operation
typedef unsigned int opcode;

// type qui represente une operande
typedef unsigned int operande;

/*
CNC_PROCHAINE_COMMANDE

	Retourne la prochaine commande d'un flux de commandes simul�.

PARAM�TRES :

	Aucuns.

VALEUR DE RETOUR :

	- Une commande (type : commande).
*/
commande CNC_prochaine_commande(void);

/*
TEST_CNC_PROCHAINE_COMMANDE

	Test visuel pour CNC_prochaine_commande.

PARAM�TRES :

	Aucuns.

VALEUR DE RETOUR :

	Aucune.
*/
void test_CNC_prochaine_commande(void);

#endif