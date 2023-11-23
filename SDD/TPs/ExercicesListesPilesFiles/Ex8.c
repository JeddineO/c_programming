#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct list
{
    int val;
    struct list *suivant;
}Cellule;
void main()
{
    
}
// MinRangListe retourne le rang du min 
int MinRangListe(Cellule *liste, int *min)
{
    Cellule *courant;
    int Min, Rang;
    if (!liste) return ((int)-1);
    Min = liste->val;
    Rang = 1;
    courant = liste;
    while (courant)
    {
        Rang++;
        if (courant->val < Min) 
            Min = courant->val;
        courant = courant->suivant;
    }
    *min = Min;
    return ((int)Rang);
}