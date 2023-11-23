#include<stdio.h>
#include<stdlib.h>

typedef struct nd
{
    int info;
    struct nd *fils, *frere;
}Noeud;

typedef struct cel
{
    Noeud *noeud;
    struct cel *svt;
}Cellule;

Noeud *CreerNoeud(int val)
{
    Noeud *ND = (Noeud *)malloc(sizeof(Noeud));
    if (!ND)
    {
        printf("\nErreur d'allocation de la memoire !");
        exit(0);
    }
    ND->info = val;
    ND->fils = ND->frere = NULL;
    return ((Noeud *)ND);
}
Cellule *CreerCellule(Noeud *noeud)
{
    Cellule *CL = (Cellule *)malloc(sizeof(Cellule));
    if (!CL) 
    {
        printf("\nErreur d'allocation !");
        exit(0);
    }
    CL->noeud = noeud;
    CL->svt = NULL;
    return ((Cellule *)CL);
}
Cellule *Empiler(Cellule *pile, Noeud *noeud)
{
    Cellule *CL = CreerCellule(noeud);
    CL->svt = pile;
    return ((Cellule *)CL);
}

void AffichagePrefixe(Noeud *Arb)
{
    Noeud *courant;
    Cellule *pile = NULL, *tmp;
    if (!Arb) printf("\nArbre vide");
    else 
    {
        pile = Empiler(pile,Arb);
        while (pile)
        {
            printf("%d\n",pile->noeud->info);
            courant = pile->noeud;
            tmp = pile;
            pile = pile->svt;
            free(tmp);
            if (courant->frere) pile = Empiler(pile,courant->frere);
            if (courant->fils) pile = Empiler(pile,courant->fils);
        }
    }
}

void main()
{
    Noeud *Arbre;
    Arbre = CreerNoeud(8);
    Arbre->fils = CreerNoeud(3);
    Arbre->fils->frere = CreerNoeud(2);
    Arbre->fils->frere->frere = CreerNoeud(11);
    Arbre->fils->fils = CreerNoeud(1);
    Arbre->fils->fils->frere = CreerNoeud(5);
    Arbre->fils->fils->frere->frere = CreerNoeud(9);
    Arbre->fils->fils->frere->fils = CreerNoeud(0);
    Arbre->fils->frere->fils = CreerNoeud(6);
    Arbre->fils->frere->fils->frere = CreerNoeud(10);

    AffichagePrefixe(Arbre);

}