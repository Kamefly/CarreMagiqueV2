#include <stdio.h>
#include <stdlib.h>

#define TAILLE 25

typedef struct tPosition
{
	int nX;
	int nY;

} tPosition;

enum Bool {false, true};

void initTab(int nTab[TAILLE][TAILLE]);
int caseVide(int nTab[TAILLE][TAILLE], tPosition jeton);
void avancerDroite(int nTab[TAILLE][TAILLE], tPosition jeton);
void avancerGauche(int nTab[TAILLE][TAILLE], tPosition jeton);
void corriger(int nTab[TAILLE][TAILLE], tPosition jeton);
void placer(int nTab[TAILLE][TAILLE], tPosition jeton, int nCpt);
void avancer (tPosition jeton, int nTab[TAILLE][TAILLE], int nCpt);
void afficher(int nTab[TAILLE][TAILLE]);

int main(){
	tPosition jeton;
	int nTab[TAILLE][TAILLE];
	jeton.nX = 3;
	jeton.nY = 2;
	initTab(nTab);
	nTab[jeton.nX][jeton.nY] = 1;

	for (int nCpt = 2; nCpt < TAILLE; ++nCpt)
	 {
        avancer(tPosition jeton,nTab, nCpt);
	 }

	afficher(nTab);
	return 0;
}

void avancer (tPosition jeton, int nTab[TAILLE][TAILLE], int nCpt){
	avancerDroite(nTab, jeton);

	if (caseVide(nTab, jeton) == true)
		placer(nTab, jeton, nCpt);
	else
    {
        avancerGauche(nTab, jeton);
		placer(nTab, jeton, nCpt);
    }
}

void initTab(int nTab[TAILLE][TAILLE]){

	for (int nCpt = 0; nCpt < 5; ++nCpt)
	{
		nTab[nCpt][1] = 0;
		nTab[nCpt][2] = 0;
		nTab[nCpt][3] = 0;
		nTab[nCpt][4] = 0;
		nTab[nCpt][5] = 0;
	}
}

int caseVide(int nTab[TAILLE][TAILLE], tPosition jeton){

	if (nTab[jeton.nX-1][jeton.nY-1] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void avancerDroite(int nTab[TAILLE][TAILLE], tPosition jeton){
	jeton.nX = jeton.nX+1;
	jeton.nY = jeton.nY-1;
	corriger(nTab,jeton);
}

void avancerGauche(int nTab[TAILLE][TAILLE], tPosition jeton){
	jeton.nX = jeton.nX-1;
	jeton.nY = jeton.nY-1;
	corriger(nTab,jeton);
}

void corriger(int nTab[TAILLE][TAILLE], tPosition jeton){
	if (jeton.nX == 6)
	{
		jeton.nX = 1;
	}
	if (jeton.nY == 0)
	{
		jeton.nY = 5;
	}
	if (jeton.nX == 0)
	{
		jeton.nX = 5;
	}
}

void placer(int nTab[TAILLE][TAILLE], tPosition jeton, int nCpt){
	nTab[jeton.nX][jeton.nY] = nCpt;
}

void afficher(int nTab[TAILLE][TAILLE]){

	for (int nCpt = 1; nCpt < 5; ++nCpt)
    {
		printf("%d\n", nTab[nCpt][1]);
		printf("%d\n", nTab[nCpt][2]);
		printf("%d\n", nTab[nCpt][3]);
		printf("%d\n", nTab[nCpt][4]);
		printf("%d\n", nTab[nCpt][5]);
	}
}
