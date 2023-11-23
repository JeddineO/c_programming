#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//Difinition de la structure de l'arbre
typedef struct Nd
{
    int info;//Information
    struct Nd *fgch;//pointeur sur le fils gauche
    struct Nd *fdrt;//pointeur sur le fils droit
}Noeud;

//Initialisation d'un arbre
Noeud *creer_Noeud(int val)
{
    Noeud *Arb;
    Arb=(Noeud *)malloc(sizeof(Noeud));
    if(!Arb)
    {
        printf("\nErreur d'allocation ");
        exit(1);
    }
    //Initialisation d'un noeud
    Arb->info=val;
    Arb->fdrt=Arb->fgch=NULL;

    return ((Noeud *)Arb);
}

//Recherche dans un arbre binaire ordonné horizontalemnt

int recherche_arb_bin(Noeud *Arb,int val)
{
    if(!Arb) return ((int)-1);
    //cas egal ou noeud courant
    if(Arb->info==val)return ((int)1);
    //Recherche de la branche à suivre
    if(val<Arb->info)
    {
        if(Arb->fgch)
            return(recherche_arb_bin(Arb->fgch,val));
        else
            return ((int)0);
    }
    else
    {
        if(Arb->fdrt)
        return(recherche_arb_bin(Arb->fdrt,val));
        else
            return ((int)0);

    }
}

//Parcours préfixé

void Prefixe(Noeud *Arb)
{
    //Affichage prifixe d'un arbre
    if(Arb)
    {
        printf("\n %d",Arb->info);
        Prefixe(Arb->fgch);
        Prefixe(Arb->fdrt);
    }
}

//Parcours infixé

void Infixe(Noeud *Arb)
{
    if(Arb)
    {
        Infixe(Arb->fgch);
        printf("\n %d",Arb->info);
        Infixe(Arb->fdrt);
    }
}

void Pos_fixe(Noeud *Arb)
{
    if(Arb)
    {

        Pos_fixe(Arb->fgch);
        Pos_fixe(Arb->fdrt);
        printf("\n %d",Arb->info);
    }
}

int MinArb(Noeud *Arb,int *min)
{
    min=Arb;
    if(!Arb) return ((int)0);
    if(min<Arb->fgch)
        return(MinArb(Arb->fgch,min));
    else
        return (MinArb(Arb->fdrt,min));
}

int main()
{
    Noeud *Arb;
    Arb=creer_Noeud(1);
    Arb=creer_Noeud(2);
    Arb=creer_Noeud(4);
    Arb=creer_Noeud(6);

    Pos_fixe(Arb);

    return 0;
}
