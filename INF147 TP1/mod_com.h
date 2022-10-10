/*****************************************************************************************
Auteurs :	Barry Lawson
			Philippe Marineau
			Jean-Philippe Portant
			Teano Rocha
Date : Octobre 2022

Ce module permet de d�couper les commandes pour l'analyse.

On y retrouve les sous-programmes suivants :
	 - COM_get_opcode : Extrait le code d'op�ration d'une commande.
	 - COM_get_operande_1 : Extrait le premier op�rande d'une commande.
	 - COM_get_operande_2 : Extrait le deuxi�me op�rande d'une commande.
	 - test_COM_get_opcode : Test unitaire pour la fonction COM_get_opcode.
	 - test_COM_get_operande_1 : Test unitaire pour la fonction COM_get_operande_1.
	 - test_COM_get_operande_2 : Test unitaire pour la fonction COM_get_operande_2.
*****************************************************************************************/

#ifndef __MOD_COM__
#define __MOD_COM__

#include <stdio.h>

#define OPCODE_BIT_DEBUT			1
#define OPCODE_BIT_FIN				3
#define OPERANDE_1_BIT_DEBUT		4
#define OPERANDE_1_BIT_FIN			13
#define OPERANDE_2_BIT_DEBUT		14
#define OPERANDE_2_BIT_FIN			23

/*
 COM_GET_OPCODE

	Extrait le code d'operation d'une commande.

 PARAM�TRES :

	une_commande: Une commande lue par la CNC.

 VALEUR DE RETOUR :

	opcode: Le code d'operation de la commande.
*/
unsigned int COM_get_opcode(unsigned int une_commande);

/*
 COM_GET_OPERANDE_1

	Extrait le premier operande d'une commande.

 PARAM�TRES :

	une_commande: Une commande lue par la CNC.

 VALEUR DE RETOUR :

	operande_1: Le premier operande de la commande.
*/
unsigned int COM_get_operande_1(unsigned int une_commande);

/*
 COM_GET_OPERANDE_1

	Extrait le deuxieme operande d'une commande.

 PARAM�TRES :

	une_commande: Une commande lue par la CNC.

 VALEUR DE RETOUR :

	operande_1: Le deuxieme operande de la commande.
*/
unsigned int COM_get_operande_2(unsigned int une_commande);

/*
 TEST_COM_GET_OPCODE

	Suite de tests unitaires pour COM_get_opcode.

 PARAM�TRES :

	Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void test_COM_get_opcode();

/*
 TEST_COM_GET_OPERANDE_1

	Suite de tests unitaires pour COM_get_operande_1

 PARAM�TRES :

	Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void test_COM_get_operande_1();

/*
 TEST_COM_GET_OPERANDE_2

	Suite de tests unitaires pour COM_get_operande_2

 PARAM�TRES :

	Aucuns.

 VALEUR DE RETOUR :

	Aucune.
*/
void test_COM_get_operande_2();

#endif