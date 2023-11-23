#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int info;
    struct list *suivant;
}Cellule;

Cellule *CreerCellule(int val)
{
    Cellule *CL = (Cellule *)malloc(sizeof(Cellule));
    if (!CL) 
    {
        printf("\nErreur d'allocation de la memoire!");
        exit(0);
    }
    CL->info = val;
    CL->suivant = NULL;
    return ((Cellule *)CL);
}
Cellule *InsererListeCroissate(Cellule *liste, Cellule *NewElem)
{
    Cellule *courant;
    // Cas de liste vide
    if (!liste) return ((Cellule *)NewElem);
    // Cas d'insertion en tete
    if (NewElem->info < liste->info)
    {
        NewElem->suivant = liste;
        // liste = NewElem;
        return ((Cellule *)NewElem);
    }
    courant = liste;
    while (courant->suivant)
    {   // Cas insertion en milieu
        if(NewElem->info < courant->suivant->info)
        {
            NewElem->suivant = courant->suivant;
            courant->suivant = NewElem;
            return ((Cellule *)liste);
        }
        courant = courant->suivant;
    }
    // Cas d'insertion en queue
    courant->suivant = NewElem;
    return ((Cellule *)liste);
}
void AfficherListe(Cellule *liste)
{
    Cellule *courant;
    if (!liste) 
    {
        printf("\nErreur Liste n'existe pas!");
        exit(0);
    }
    printf("\nAffichage : ");
    courant = liste;
    while (courant)
    {
        printf("%d\t",courant->info);
        courant = courant->suivant;
    }
}

int main()
{
    Cellule *liste = NULL;
    liste = InsererListeCroissate(liste, CreerCellule(12));
    liste = InsererListeCroissate(liste, CreerCellule(14));
    liste = InsererListeCroissate(liste, CreerCellule(10));
    liste = InsererListeCroissate(liste, CreerCellule(11));
    AfficherListe(liste);
}