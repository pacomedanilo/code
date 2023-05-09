// ConsoleApplication3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

/******************************************************************************

							Online C Compiler.
				Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define taille 16
int choixCase;//le choix effectué par le joueur pour découvrir ou placer un drapeau





void afficherTable(char tableau[taille])
{

	for (int i = 0; i < taille; i++)
	{
		printf(" %d ", tableau[i]);
		if (((i + 1) %4) == 0)
		{
			printf("\n");
		}

	}
}



int main()
{
	int tableau[taille] = '0';
	afficherTable(tableau);



	int run = 0;
	int choixCase = 0;
	while (run == 0) {
		int errorCase = 0;
		while (errorCase == 0)
		{
			char signePlayer = 'X';
			printf("quelle case :");
			scanf_s("%d", &choixCase);
			printf("Vous avez choisi la case %d.\n", choixCase);
			tableau[choixCase] = signePlayer;

			if (choixCase > taille)
			{
				printf("Nombre incorrect essaye encore !\n\n");

			}
			else if (choixCase < 0) {
				printf("Nombre incorrect essaye encore !\n\n");

			}
			else {
				errorCase = 1;
			}
		afficherTable(tableau);
		}
	}
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
