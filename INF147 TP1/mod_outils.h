/*****************************************************************************************
Auteurs :	Barry Lawson
			Philippe Marineau
			Jean-Philippe Portant
			Teano Rocha
Date : Octobre 2022

Outils pouvant etre utilises a differents endroits dans le programme

On y retrouve la macro fonction suivante :
	- SWAP : Permute deux valeurs
*****************************************************************************************/

#ifndef __MOD_OUTILS__
#define __MOD_OUTILS__

/*****************************************************************************************
*                                   MACRO-FONCTIONS                                      *
*****************************************************************************************/


// Macro-fonction qui permute deux valeurs
#define SWAP(X, Y)	*X = *X ^ *Y;\
					*Y = *X ^ *Y;\
					*X = *X ^ *Y;

#endif
