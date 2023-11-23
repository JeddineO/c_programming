#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int info;
    struct list *suivant;
}Cellule;

// Recuperer la cellule du minimum
Cellule *RecupererMin(Cellule *liste, Cellule *AddMin[1])
{
    Cellule *courant, *ptMin;
    int min;
    // existance de la liste
    if (!liste)
    {
        AddMin[0] = NULL;
        return ((Cellule *)NULL);
    }
    min = liste->info;
    courant = liste;
    while (courant->suivant)
    {
        if (courant->suivant->info < min)
        {
            ptMin = courant;
            min = courant->suivant->info;
        }
        courant = courant->suivant;
    }
    // le min est en tete
    if (min == liste->info)
    {
        AddMin[0] = liste;
        liste = liste->suivant;
        AddMin[0]->suivant = NULL;
        return ((Cellule *)liste);
    }
    AddMin[0] = ptMin->suivant;
    ptMin->suivant = ptMin->suivant->suivant;
    AddMin[0]->suivant = NULL;
    return ((Cellule *)liste);  
}