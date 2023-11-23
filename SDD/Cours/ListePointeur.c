#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
// Definition de la structure d'une liste a l'aide d'un pointeur
typedef struct Liste
{
    int info; // contenu d'une cellule
    struct Liste *suivant; // pointeur vers la cellule suivante
}Cellule;
// Prototype
Cellule *CreerCellule(int);
int TailleListe(Cellule *);
int AfficherListe(Cellule *);
Cellule *ViderListe(Cellule *);
// Programme principale
void main()
{
    
}
// Creer une cellule
Cellule *CreerCellule(int valinfo)
{
    Cellule *NE;
    NE = (Cellule *)malloc(sizeof(Cellule));
    if (!NE)
    {
        printf("\nErreur d'allocation");
        exit(0);
    }
    NE->info = valinfo;
    NE->suivant = NULL;
    return ((Cellule *)NE);    
}
// La Taille de la liste
int TailleListe(Cellule *liste)
{
    int compteur = 0;
    Cellule *courant;
    if (!liste) return ((int)-1); // test si la liste existe
    courant = liste;
    while (courant) // parcourir la liste tant que courant != NULL
    {   
        compteur ++; // incrementer le compteur
        courant = courant->suivant; // Passer a la cellule suivante
    }
    return ((int)compteur);
}
// Afficher la liste
int AfficherListe(Cellule *liste)
{
    Cellule *courant;
    if (!liste) return ((int)-1); // test si la liste existe
    courant = liste;
    printf("\nLes elements de la liste : ");
    while (courant) // tant qu'il ya des elements dans la liste
    {
        printf("%d\t",courant->info);
        courant = courant->suivant;
    }
    return ((int)1);
}
// Vider la liste
Cellule *ViderListe(Cellule *liste)
{
    Cellule *courant;
    while (liste) // tant qu'il ya des elements dans la liste
    {
        courant = liste; // positionner la tete de la liste
        liste = liste->suivant; // deplacer la tete de la liste
        free(courant); // liberer la zone memoire
    }
    return ((Cellule *)liste);
}
Cellule *InsererListe(int Elem, int Pos, Cellule *liste)
{
    int i = 1;
    Cellule *courant, *NewElem;
    if (!liste) 
    {
        printf("\nErreur : liste n'existe pas!");
        exit(0);
    }
    if ((TailleListe(liste) < Pos-1) && (Pos < 1))
    {
        printf("\nPosition invalide!");
        return ((Cellule *)liste);
    }
    NewElem = CreerCellule(Elem);
    if (Pos == 1)
    {
        NewElem->suivant = liste;
        return ((Cellule *)NewElem);
    }
    courant = liste;
    while (i < Pos)
    {
        courant = courant->suivant;
    }
    
}