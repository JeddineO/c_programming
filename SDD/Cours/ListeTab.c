#include<stdio.h>
#include<stdlib.h>
// Declaration des constantes
#define NbElem 25
// Definition de la structure d'une liste a l'aide d'un tableau
typedef struct 
{
    int Tab[NbElem]; // le tableau des elements
    int IdElem; // indice du dernier element
}MaTab;
// Prototype
int InitTab(MaTab *);
int TabVide(MaTab *);
int TabSature(MaTab *);
int InsererTab(MaTab *, int );
// Programme principale
void main()
{
    MaTab t;
    printf("%d",InitTab(&t));
}
// Initialiser le tableau
int InitTab(MaTab *MonTableau)
{
    if (!MonTableau) return ((int)-1); // test si la zone memoire existe
    MonTableau->IdElem = -1; // le tableau est vide
    return ((int)1);
}
// S'avoir si le tableau est vide
int TabVide(MaTab *MonTableau)
{
    if (!MonTableau) return ((int)-1); // test si la zone memoire existe
    return ((int)(MonTableau->IdElem == -1));
}
// S'avoir si le tableau est sature
int TabSature(MaTab *MonTableau)
{
    if (!MonTableau) return ((int)-1); // test si la zone memoire existe
    return ((int)(MonTableau->IdElem == (NbElem-1)));
}
// Inserer un element au tableau
int InsererTab(MaTab *MonTableau, int Elem)
{
    if (!MonTableau) return ((int)-1); // test si la zone memoire existe
    if (TabSature(MonTableau)) return ((int)0); // test si le tableau est sature
    MonTableau->Tab[++MonTableau->IdElem] = Elem; // Insertion a la derniere case du tableau
    return ((int)1);
}