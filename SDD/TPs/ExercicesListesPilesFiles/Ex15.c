#include<stdio.h>
#include<stdlib.h>

typedef struct pile
{
    int info;
    struct pile *suivant;
}Cellule;

// 2- Inserer un element au sommet de la pile
Cellule *EmpilerPPile(Cellule *pile, int val)
{
    Cellule *CL;
    CL = CreerCellule(val);
    if (!pile) return ((Cellule *)CL); // tester si la pile existe
    CL->suivant = pile; // Inserer au sommet
    return ((Cellule *)CL);
}
// 3- Supprimer un element au sommet de la pile
Cellule *DepilerPPile(Cellule *pile)
{
    Cellule *Supp;
    if (!pile) return ((Cellule *)NULL); // tester si la pile existe
    Supp = pile;
    pile = pile->suivant;
    free(Supp);
    return ((Cellule *)pile);
}

Cellule *SupprimerPileDoublons(Cellule *pile)
{
    Cellule *tmpSD = NULL, *tmpAD = NULL;
    if (!pile) return ((Cellule *)pile);
    while (pile)
    {
        tmpSD = EmpilerPPile(tmpSD,pile->info);
        pile = DepilerPPile(pile);
        while (pile)
        {
            if (pile->info != tmpSD->info) tmpAD = EmpilerPPile(tmpAD,pile->info);
            pile = DepilerPPile(pile);
        }
        while (tmpAD)
        {
            pile = EmpilerPPile(pile,tmpAD->info);
            tmpAD = DepilerPPile(tmpAD);
        }
    }
    while (tmpSD)
    {
        pile = EmpilerPPile(pile,tmpSD->info);
        tmpSD = DepilerPPile(tmpSD);
    }
    return ((Cellule *)pile);
}