/*****************************************************************************************
Auteurs :	Barry Lawson
			Philippe Marineau
			Jean-Philippe Portant
			Teano Rocha
Date : Octobre 2022

Ce module permet de découper les commandes pour l'analyse.

On y retrouve les sous-programmes suivants :
	- TRACEUR_initialiser_fenetre : Cette fonction initialise la fenêtre dans laquelle le
									tracé sera effectué
	- TRACEUR_ligne : Cette fonction se charge du tracé des lignes en fonction des
				      coordonnées entrée.
*****************************************************************************************/

#ifndef __MOD_TRACEUR__
#define __MOD_TRACEUR__

#include "graphics.h"
#pragma comment(lib, "graphics")

// Dimension du graphique en pixels
#define DIM_HAUTEUR 750	
#define DIM_LARGEUR 750

// Tolérance en pixels pour le graphique
#define TRACEUR_EPSILON 1

//Rayon de cercle aux extrémités des lignes tracées
#define RAYON 10

//valeur associée à une ligne verticale
#define LIGNE_VERTICAL 1

//valeur associée à une ligne horizontale
#define LIGNE_HORIZONTAL 2

//valeur associée à une ligne oblique
#define LIGNE_OBLIQUE 3

/*
 TRACEUR_INITIALISER_FENETRE

	Initialise la fenêtre du tracé avec les dimensions spécifiées par les constantes DIM_HAUTEUR et DIM_LARGEUR.

 PARAMÈTRES :

	Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void TRACEUR_initialiser_fenetre(void);

/*
* TRACEUR_LIGNE
 
	Trace une ligne entre deux points donnés avec les contours de l'outil

 PARAMETRES :

	x_1: La position x du premier point
	y_1: La position y du premier point
	x_2: La position x du deuxieme point
	y_2: La position y du deuxieme point
  
 VALEUR DE RETOUR :

	Aucune
*/
void TRACEUR_ligne(int x_1, int y_1, int x_2, int y_2);

#endif
