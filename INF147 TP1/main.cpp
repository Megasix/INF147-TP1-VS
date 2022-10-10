/****************************************************************************************

Auteurs :
	Barry Lawson
	Philippe Marineau
	Jean-Philippe Portant
	Teano Rocha
	
	Voici notre solution au probleme du premier Travail Pratique (TP) du cours
	INF-147. Nous devions implementer un systeme d'interpretation de signaux
	transmis à une CNC via WiFi. L'enjeu du TP à été de mettre en commun notre
	connaissance du format binaire afin de pouvoir dechifrer les donnees contenues
	dans une ligne de commande et, notre connaissances des mathematiques qui nous
	a servie a notamment afficher une previsualisation du tracer de la decoupeuse
	laser.

*****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/****************************************************************************************
*                               DEFINTION DES CONSTANTES                                *
****************************************************************************************/

// Mode pour les tests unitaires
#define TESTS 0

// Librairies utilisées par l'application an mode normal
#if !TESTS
	#include "mod_traceur.h"
	#include "mod_cnc.h"
#endif

// (Dés)activation des tests pour les différents modules
#define TESTS_BITS    0
#define TESTS_COM     0
#define TESTS_MATH    0
#define TESTS_CNC     0
#define TESTS_TRACEUR 0

// Librairies utilisées par l'application en mode test
#if TESTS && TESTS_BITS
	#include "mod_bits.h"
#endif

#if TESTS && TESTS_COM
	#include "mod_com.h"
#endif

#if TESTS && TESTS_MATH
	#include "mod_math.h"
#endif

#if TESTS && TESTS_CNC
	#include "mod_cnc.h"
#endif

#if TESTS && TESTS_TRACEUR
	#include "mod_traceur.h"
#endif

// (Dés)activation de l'exemple de l'Annexe A
#define TUTORIEL_GRAPHICS 0

/****************************************************************************************
*                           DEFINTION DU PROGRAMME PRINCIPAL                            *
****************************************************************************************/

/*
MAIN

	Nous faisons le liens entre les commandes recue et leur actions associées dans le main

Parametres :
	- Aucun

Retour :
	- Aucun
*/

#if !TESTS

	int main()
	{
		// nous initialisons la fenetre (windows) a une certaine taille specifie dans /mod_traceur.h
		TRACEUR_initialiser_fenetre();
		
		
		int x = 0;		// position de la tete de la CNC en abscisses
		int y = 0; 		// position de la tete de la CNC en ordonnees
		bool etat_laser = 0;	// etat de fonctionnement de la tete laser de la CNC 0=OFF, 1=ON
		
		// declaration de commande_courante, cette variable nous serviras notamment a verifier si l'on a recu une commande "CLOSE"
		commande commande_courante;
		// declaration de code_operation, cette variable nous indique quelle action nous devons effectuer
		opcode code_operation;	
		// declaration de operande_1, cette variable correspond a la premiere operande de la commande recue
		operande operande_1;
		// declaration de operande_2, cette variable correspond a la deuxieme operande de la commande recue
		operande operande_2;							

		// tant que la commande_courante n'est pas une instruction CLOSE, on continue
		while ((commande_courante = CNC_prochaine_commande()) != CLOSE)		
		{
			// assignation des valeur aux variables correspondantes
			code_operation = COM_get_opcode(commande_courante);		
			operande_1 = COM_get_operande_1(commande_courante);
			operande_2 = COM_get_operande_2(commande_courante);

			switch (code_operation)						
			{
			// si code_operation est egal a INDICE_LZON on active le lazer
			case INDICE_LZON:						
				etat_laser = 1;
				break;
			// si code_operation est egal a INDICE_LZOFF on desactive le lazer
			case INDICE_LZOFF:						
				etat_laser = 0;
				break;
			// si code_operation est egal a INDICE_DPLC on deplace la tete du lazer aux coordonnee x et y
			case INDICE_DPLC:	
				// si etat_laser est ON (1), on affiche le trace dans la fenetre
				if (etat_laser)
				{
					TRACEUR_ligne(x, y, operande_1, operande_2);	
				}
				x = operande_1;
				y = operande_2;
				break;
			// si code_operation est egal a INDICE_DONE on deplace la tete du lazer a la position initiale (x=0, y=0) et on desactive le lazer.
			case INDICE_DONE:						
				etat_laser = 0;
				x = 0;
				y = 0;
				break;
			}
		}

		system("pause");
		return EXIT_SUCCESS;
	}

#else
#include "mod_outils.h"
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
