#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int info;
    struct list *suivant;
}Cellule;

Cellule *SupprimerDoublons(Cellule *liste)
{
    Cellule *courant, *ptr, *pred;
    if(!liste) return ((Cellule *)NULL);
    courant = liste;
    while (courant)
    {
        ptr = courant->suivant;
        pred = courant;
        while (ptr)
        {
            if (ptr->info == courant->info)
            {
                pred->suivant = pred->suivant->suivant;
                free(ptr);
                ptr = pred;
            }
            pred = ptr;
            ptr = ptr->suivant;
        }
        courant = courant->suivant;   
    }
    return ((Cellule *)liste);
}