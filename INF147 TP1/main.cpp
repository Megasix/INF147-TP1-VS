/****************************************************************************************

Auteur(e) :

	Ecrire description ici

*****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/****************************************************************************************
*                               DEFINTION DES CONSTANTES                                *
****************************************************************************************/

// Mode pour les tests unitaires
#define TESTS 1

// Librairies utilis�es par l'application an mode normal
#if !TESTS
	#include "mod_traceur.h"
	#include "mod_cnc.h"
#endif

// (D�s)activation des tests pour les diff�rents modules
#define TESTS_BITS    0
#define TESTS_COM     0
#define TESTS_MATH    0
#define TESTS_CNC     0
#define TESTS_TRACEUR 1

// Librairies utilis�es par l'application en mode test
#if TESTS && TESTS_BITS
	#include "mod_bits.h"
#endif

#if TESTS && TESTS_COM
	#include "mod_com.h"
#endif

#if TESTS && TESTS_MATH
	#include "mod_math.h"
#endif

#if TESTS && TESTS_TRACEUR
#include "mod_traceur.h"
#endif

// (D�s)activation de l'exemple de l'Annexe A
#define TUTORIEL_GRAPHICS 0

/****************************************************************************************
*                           DEFINTION DU PROGRAMME PRINCIPALE                           *
****************************************************************************************/

/*
MAIN

	Ecrire description ici

Parametres :
	- Aucun

Retour :
	- Aucun
*/

#if !TESTS

	int main()
	{

		/* � remplir */

		system("pause");
		return EXIT_SUCCESS;

	}

#else

	int main(void)
	{

		#if TESTS_BITS
			test_BITS_obtenir();
			test_BITS_basculer();
			//test_BITS_afficher();
			test_BITS_extraire();
		#endif

		#if TESTS_COM
			test_COM_get_opcode();
			test_COM_get_operande_1();
			test_COM_get_operande_2();
		#endif

		#if TESTS_MATH
			test_MATH_puissance();
			test_MATH_valeur_absolue();
			test_MATH_racine_carree();
			test_MATH_factorielle();
			test_MATH_sin();
			test_MATH_cos();
			test_MATH_atan();
        #endif		
	
		#if TESTS_CNC
			test_CNC_prochaine_commande();
		#endif

		#if TESTS_TRACEUR
			initwindow(250, 250);
			TRACEUR_ligne(125, 150, 125, 75);
			TRACEUR_ligne(50, 112, 200, 112);
			TRACEUR_ligne(50, 150, 200, 75);
			TRACEUR_ligne(50, 75, 200, 150);
		#endif

		#if TUTORIEL_GRAPHICS
			initwindow(250, 250);
			setcolor(WHITE);
			line(50, 50, 50, 100);
			line(50, 50, 100, 50);
			line(100, 50, 100, 100);
			line(50, 100, 100, 100);
			setcolor(RED);
			circle(125, 125, 25);
			setcolor(LIGHTCYAN);
			line(150, 150, 150, 200);
			line(150, 150, 200, 150);
			line(200, 150, 200, 200);
			line(150, 200, 200, 200);
		#endif

		system("pause");
		return EXIT_SUCCESS;

	}

#endif