// ConsoleApplication3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

/******************************************************************************

							Online C Compiler.
				Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define taille 100
int choix;//le choix effectué par le joueur pour découvrir ou placer un drapeau

int randomGeneratorBomb()

{
	int randomnumber;
	randomnumber = rand() % 4;
	return(randomnumber);
}

void createTable(char t[taille])
{
	for (int i = 0; i < taille; i++)
	{
		if (randomGeneratorBomb() == 1)
		{
			t[i] = '*';
		}
		else
		{
			t[i] = 'X';
		}
	}
}

void createBombMask(char tmask[taille]) {
	for (int i = 0; i < taille; i++)
	{
		tmask[i] = '.';

	}
}

void afficherTable(char tableau[taille])
{
	printf(" 0  1  2  3  4  5  6  7  8  9 \n");
	printf("------------------------------\n");
	for (int i = 0; i < taille; i++)
	{
		printf(" %c ", tableau[i]);
		if (((i + 1) % 10) == 0)
		{
			printf("\n");
		}

	}
}

void bombautour(char table[taille])
{
	for (int i = 0; i < taille; ++i)
	{
		int count = 0;
		if (table[i] == 'X')
		{

			// compter le nombre de bombe adjacente
			if (table[i] == '*')
			{
				count = ++count;
			}

			if (i != 0)
			{
				if (table[i - 1] == '*')
				{
					count = ++count;
				}
				if (table[i - 10] == '*')
				{
					count = ++count;
				}
			}

			if (i != 0)
			{
				if (table[i - 9] == '*')
				{
					count = ++count;
				}
				if (table[i - 11] == '*')
				{
					count = ++count;
				}
			}


			if (i != taille - 1)
			{
				if (table[i + 1] == '*')
				{
					count = ++count;
				}
				if (table[i + 10] == '*')
				{
					count = ++count;
				}
			}

			if (i != taille - 1)
			{
				if (table[i + 9] == '*')
				{
					count = ++count;
				}
				if (table[i + 11] == '*')
				{
					count = ++count;
				}
			}

			// converion count en char ASCI	I
			table[i] = (char)(count + 48);
		}

	}
}
//int ChoiceCase(int i, int j) 
//{
//	int choiseCase;
//	choiseCase = j * 10 + i;
//	return choiseCase;
//}

void decouvrirCase(char tmask[taille], char table[taille], int choiseCase)
{

	int i = choiseCase;


		if (table[i + 10] == '0' && table[i + 10] != '*')
		{
			tmask[i + 10] = '0';
			table[i + 10] = ' ';
			decouvrirCase(tmask, table, i + 10);//haut
		}

		if (table[i + 10] != ' ' && table[i + 10] != '0') {
			tmask[i + 10] = table[i + 10];
		}

		if (table[i - 10] == '0' && table[i - 10] != '*')
		{
			tmask[i - 10] = '0';
			table[i - 10] = ' ';
			decouvrirCase(tmask, table, i - 10);//bas
		}

		if (table[i - 10] != ' ' && table[i - 10] != '0') {
			tmask[i - 10] = table[i - 1];
		}

		 if (table[i - 1] == '0' && table[i - 1] != '*')
		{
			tmask[i - 1] = '0';
			table[i - 1] = ' ';
			decouvrirCase(tmask, table, i - 1);//gauche
		}

		if (table[i - 1] != ' ' && table[i - 1] != '0') {
			tmask[i - 1] = table[i - 1];
		}

		if (table[i - 11] == '0' && table[i - 11] != '*')
		{
			tmask[i - 11] = '0';
			table[i - 11] = ' ';
			decouvrirCase(tmask, table, i - 11);//en haut a gauche
		}

		if (table[i - 11] != ' ' && table[i - 11] != '0') {
			tmask[i - 11] = table[i - 11];
		}

		if (table[i + 9] == '0' && table[i + 9] != '*')
		{
			tmask[i + 9] = '0';
			table[i + 9] = ' ';
			decouvrirCase(tmask, table, i + 9);//en bas a gauche
		}

		if (table[i + 9] != ' ' && table[i + 9] != '0') {
			tmask[i + 9] = table[i + 9];
		}
	
		if (table[i + 1] == '0' && table[i + 1] != '*')
		{
			tmask[i + 1] = '0';
			table[i + 1] = ' ';
			decouvrirCase(tmask, table, i + 1);//droite
		}

		if (table[i + 1] != ' ' && table[i + 1] != '0') {
			tmask[i + 1] = table[i + 1];
		}

		if (table[i + 11] == '0' && table[i + 11] != '*')
		{
			tmask[i + 11] = '0';
			table[i + 11] = ' ';
			decouvrirCase(tmask, table, i + 11);//en bas a droite
		}

		if (table[i + 11] != ' ' && table[i + 11] != '0') {
			tmask[i + 11] = table[i + 11];
		}

		if (table[i - 9] == '0' && table[i -9] != '*')
		{
			tmask[i - 9] = '0';
			table[i - 9] = ' ';
			decouvrirCase(tmask, table, i - 9);//en haut a droite
		}

		if (table[i - 9] != ' ' && table[i - 9] != '0') {
			tmask[i - 9] = table[i - 9];
		}
}




void Jouer(char tmask[taille], char table[taille], int choiseCase, int choix)
{
	switch (choix)
	{
	case 1:
		tmask[choiseCase] = table[choiseCase];
		if (table[choiseCase] == '0') {
			decouvrirCase(tmask, table, choiseCase);
		}

		break;
	case 2:
		if (tmask[choiseCase] == '.') {
			tmask[choiseCase] = 'D';
			break;
		}
		if (tmask[choiseCase] == 'D') {
			tmask[choiseCase] = '.';
			break;
		}
	}
}

int main()
{
	printf("   Bienvenue au demineur ! \n\n\n");
	char table[taille];
	char tmask[taille];
	createTable(table);
	createBombMask(tmask);
	afficherTable(tmask);
	bombautour(table);


	

	int start = 0;
	int choiseCase = 0;
	int randomnumber = 0;
	while (start == 0) {
		int errorCase = 0;
		while (errorCase == 0)
		{
			int x;
			int y;
			printf("quelle ligne :");
			scanf_s("%d", &x);
			printf("quelle colonne :");
			scanf_s("%d", &y);
			choiseCase = y * 10 + x;
			printf("Vous avez choisi la case %d.\n", choiseCase);
			printf("\tQue voulez-vous faire ?\n");
			printf("\t\t1. Decouvrir une case \n");
			printf("\t\t2. Posez un Drapeau (D)\n");
			do
			{
				printf("\t\t\tVotre choix : ");
				scanf_s("%d", &choix);
			} while (choix < 0 || choix>2);

			if (choiseCase > taille)
			{
				printf("Nombre incorrect essaye encore !\n\n");

			}
			else if (choiseCase < 0) {
				printf("Nombre incorrect essaye encore !\n\n");

			}
			else {
				errorCase = 1;
			}

		}
		Jouer(tmask, table, choiseCase, choix);

		afficherTable(tmask);

		if (table[choiseCase] == '*')
		{
			printf("\n Tu as trouve une bombe, perdu :c");
			break;
		}
		else {
			printf("\n \n");
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
