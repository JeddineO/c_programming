#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int info;
    struct list *suivant;
}Cellule;

Cellule *CreerCellule(int val)
{
    Cellule *CL;
    CL = (Cellule *)malloc(sizeof(Cellule)); // Allocation de la memoire
    if (!CL) 
    {   // Erreur d'allocation de la memoire
        printf("\nErreur d'allocation de la memoire!");
        exit(0); // Quitter le programme
    }
    CL->info = val; // Affecter la valeur
    CL->suivant = NULL; // Initialiser le pointeur suivant par NULL
    return ((Cellule *)CL); // retourne CL
}
Cellule *InsererListeOrdonnee(Cellule *liste, Cellule *cell)
{
    Cellule *courant;
    // tester si la liste existe
    if (!liste) return ((Cellule *)cell); 
    // insertion en tete
    if (cell->info < liste->info)
    {
        cell->suivant = liste;
        return ((Cellule *)cell);
    }
    courant = liste; // pointer courant en tete
    while (courant->suivant) // tant que courant a un suivant
    {
        if (cell->info < courant->suivant->info )
        {   // Insertion en milieu
            cell->suivant = courant->suivant;
            courant->suivant = cell;
            return ((Cellule *)liste);
        }
        courant = courant->suivant;
    }
    // Insertion en queue
    courant->suivant = cell;
    cell->suivant = NULL;
    return ((Cellule *)liste);
}

Cellule *ConcatenationOrdonneeListes(Cellule *liste1, Cellule *liste2)
{
    Cellule *liste = NULL, *courant1, *courant2, *CL;
    courant1 = liste1;
    courant2 = liste2;
    while (courant1 && courant2)
    {
        // Inserer un element de la liste 1
        CL = courant1;
        courant1 = courant1->suivant;
        CL->suivant = NULL;
        liste = InsererListeOrdonnee(liste,CL);
        // Inserer un element de la liste 2
        CL = courant2;
        courant2 = courant2->suivant;
        CL->suivant = NULL;
        liste = InsererListeOrdonnee(liste,CL);
    }
    while (courant1)
    {   // Inserer le reste des elements de la liste 1
        CL = courant1;
        courant1 = courant1->suivant;
        CL->suivant = NULL;
        liste = InsererListeOrdonnee(liste,CL);
    }
    while (courant2)
    {   // Inserer le reste des elements de la liste 2
        CL = courant2;
        courant2 = courant2->suivant;
        CL->suivant = NULL;
        liste = InsererListeOrdonnee(liste,CL);
    }
    return ((Cellule *)liste);
}