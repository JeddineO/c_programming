// Declaration des librairies
#include<stdio.h>
#include<stdlib.h>
// Declaration des constantes
#define MaxElem 25
/* ************************************************************************ */
// Declaration des types et des structures
typedef struct   // Definition de la structure d'un arbre binaire
{
    int info[MaxElem];       // Tableau d'entiers
    int fils[2][MaxElem];
    int IdArb;              // Indice de la racine de l'arbre
}Arbre;

/* ************************************************************************
    Nom         : InitTArbre;
    Entrees     : Arbre *Arb : l'arbre a initialiser
    Sorties     : Arbre *Arb : l'arbre initialise
    Description : la fonction permet d'initialiser les champs de l'arbre.
                Elle retourne 0 si l'arbre n'existe pas, sinon retourne 1.
************************************************************************ */
int InitTArbre(Arbre *Arb)
{
    int i;
    if (!Arb) return ((int)0);  // Arbre n'existe pas
    for (i = 0; i < MaxElem; i++) Arb->info[i] = -1;
    Arb->IdArb = 0;             // Initialiser l'indice de la racine par 0
    return ((int)1);
}
/* ************************************************************************
    Nom         : InsererTArbreOrdonne;
    Entrees     : Arbre *Arb : un arbre
                  int val : la valeur a inserer
                  int id : indice de la racine
    Sorties     : Arbre *Arb : l'arbre apres l'insertion
    Description : la fonction permet d'inserer un element a l'arbre ordonne.
                Elle retourne -1 si l'arbre n'existe pas, 0 si l'insertion
                n'est pas effectuee et 1 si l'insertion est bien effectuee.
************************************************************************ */
int InsererTArbreOrdonne(Arbre *Arb, int val, int id)
{
    if (!Arb) return ((int)-1);         // Arbre n'existe pas
    if (!Arb->IdArb) Arb->info[++Arb->IdArb] = val; // Arbre vide
    else
    {
        if (val < Arb->info[id])
        {
            if (!Arb->fils[0][id])
            {
                if (MaxElem <= (2*id)) return ((int)0); // Arbre Sature
                Arb->fils[0][id] = 2*id;  // Mettre l'indice du fils gauche
                Arb->info[2*id] = val;  // Insertion de la valeur
            }
            else return ((int)InsererTArbreOrdonne(Arb,val,Arb->fils[0][id]));
        }
        else
        {
            if (!Arb->fils[1][id])
            {
                if (MaxElem <= ((2*id)+1)) return ((int)0); // Arbre Sature
                Arb->fils[1][id] = (2*id)+1;  // Mettre l'indice du fils gauche
                Arb->info[(2*id)+1] = val;  // Insertion de la valeur
            }
            else return ((int)InsererTArbreOrdonne(Arb,val,Arb->fils[1][id]));
        }
    }  
    return ((int)1);
}
/* ************************************************************************
    Nom         : AffichagePrefixeTArbre;
    Entrees     : Arbre *Arb : un arbre
                  int id : indice de la racine
    Description : la fonction permet d'afficher l'arbre par un parcours 
                prefixe, elle commence par l'affichage de la racine, puis 
                elle effectue un parcours prefixe du sous arbre gauche puis
                du sous arbre droit.
************************************************************************ */
void AffichagePrefixeTArbre(Arbre *Arb, int id)
{
    if (id != 0)
    {
        printf("\n%d",Arb->info[id]);
        AffichagePrefixeTArbre(Arb,Arb->fils[0][id]);
        AffichagePrefixeTArbre(Arb,Arb->fils[1][id]);
    }
}
/* ************************************************************************
    Nom         : AffichageInfixeTArbre;
    Entrees     : Arbre *Arb : un arbre
                  int id : indice de la racine
    Description : la fonction permet d'afficher l'arbre par un parcours 
                infixe des noeud de l'arbre, elle commence par le parcours 
                infixe du sous arbre gauche puis affiche la racine et puis
                le parcours infixe du sous arbre droit.
************************************************************************ */
void AffichageInfixeTArbre(Arbre *Arb, int id)
{
    if (id != 0)
    {
        AffichageInfixeTArbre(Arb,Arb->fils[0][id]);
        printf("\n%d",Arb->info[id]);
        AffichageInfixeTArbre(Arb,Arb->fils[1][id]);
    }
}
/* ************************************************************************
    Nom         : AffichagePostfixeTArbre;
    Entrees     : Arbre *Arb : un arbre
                  int id : indice de la racine
    Description : la fonction permet d'afficher l'arbre par un parcours 
                postfixe des noeud de l'arbre, elle commence par le parcours 
                postfixe du sous arbre gauche puis du sous arbre droit et 
                puis affiche la racine.
************************************************************************ */
void AffichagePostfixeTArbre(Arbre *Arb, int id)
{
    if (id != 0)
    {
        AffichagePostfixeTArbre(Arb,Arb->fils[0][id]);
        AffichagePostfixeTArbre(Arb,Arb->fils[1][id]);
        printf("\n%d",Arb->info[id]);
    }
}
/* ************************************************************************
    Nom         : AffichageHorizontalTArbre;
    Entrees     : Arbre *Arb : un arbre
                  int id : indice de la racine
                  int n : niveau de la racine pour le nombre de tabulation
    Description : la fonction permer d'afficher l'arbre graphiquement, elle
                commence par l'affichage de noeud le plus a droite , puis la
                racine puis le noeud a gauche.
************************************************************************ */
void AffichageHorizontalTArbre(Arbre *Arb, int id, int n)
{
    if (id != 0)
    {
        AffichageHorizontalTArbre(Arb,Arb->fils[1][id],n+1);
        printf("\n");
        for (int i = 0; i < n; i++) printf("\t");
        printf("%d",Arb->info[id]);
        AffichageHorizontalTArbre(Arb,Arb->fils[0][id],n+1);
    }
}
/* ************************************************************************
    Nom         : AffichageArbre;
    Entrees     : Arbre *Arb : un arbre
    Description : la fonction rassemble 4 types d'affichage d'un arbre
                Affichage Prefixe, Infixe, Postfixe et Affichage horizontal
************************************************************************ */
void AffichageTArbre(Arbre *Arb)
{
    int choix;
    if (!Arb) printf("\nArbre n'existe pas");
    else if (!Arb->IdArb) printf("\nArbre Vide");
    else
    {
        printf("\n---------- Taper votre choix : ----------");
        printf("\n1  : Affichage Prefixe");
        printf("\n2  : Affichage Infixe");
        printf("\n3  : Affichage Postfixe");
        printf("\n4  : Affichage Horizontal");
        printf("\n--> Choix : ");
        scanf("%d",&choix);
        switch (choix)
        {
            case 0: break;
            case 1:
                AffichagePrefixeTArbre(Arb,Arb->IdArb);
                break;
            case 2:
                AffichageInfixeTArbre(Arb,Arb->IdArb);
                break;
            case 3:
                AffichagePostfixeTArbre(Arb,Arb->IdArb);
                break;
            case 4:
                AffichageHorizontalTArbre(Arb,Arb->IdArb,0);
                break;
            default : printf("\nChoix invalide");
        }
    }    
}
/* ************************************************************************
    Nom         : TailleTArbre;
    Entrees     : Arbre *Arb : un arbre
                  id : indice de la racine
    Sorties     : taille de l'arbre
    Description : la fonction retourne le nombre de noeuds de l'arbre.
************************************************************************ */
int TailleTArbre(Arbre *Arb, int id)
{
    if (!Arb) return ((int)-1);
    if (!id) return ((int)0);  
    return ((int)1+TailleTArbre(Arb,Arb->fils[0][id])+TailleTArbre(Arb,Arb->fils[1][id]));
}


int TArb_TrouverElement_Impl(Arbre *arb, int valeur, int idx)
{
    if (idx == -1)
        return (int)-1;
    // si l'arbre contient la valeur
    if (arb->info[idx] == valeur)
        return (int)idx;
    // si la valeur du noeund est plus grand que la valeur recherchee
    if (arb->info[idx] > valeur)
        return (int)TArb_TrouverElement_Impl(arb, valeur, arb->fils[0][idx]);
    else
        return (int)TArb_TrouverElement_Impl(arb, valeur, arb->fils[1][idx]);
}

int TArb_TrouverElement(Arbre *arb, int valeur)
{
    return TArb_TrouverElement_Impl(arb, valeur, arb->IdArb);
}

int TArb_ContientElement(Arbre *arb, int valeur)
{
    return TArb_TrouverElement(arb, valeur) != -1;
}

int TArb_Supprimer_Impl(Arbre *arb, int val, int idx)
{
    if (idx == -1)
    {
        return (int)-1;
    }

    int gauche = arb->fils[0][idx];
    int droit  = arb->fils[1][idx];

    if (arb->info[idx] > val)
    {
        arb->fils[0][idx] = TArb_Supprimer_Impl(arb, val, gauche);
    }
    else if (arb->info[idx] < val)
    {
        arb->fils[1][idx] = TArb_Supprimer_Impl(arb, val, droit);
    }
    else
    {
        if (gauche != -1 && droit != -1)
        {
            int min = droit;
            while (arb->fils[0][min] != -1)
            {
                min = arb->fils[0][min];
            }

            arb->info[idx] = arb->info[min];
            arb->fils[1][idx] = TArb_Supprimer_Impl(arb, arb->info[idx], droit);
        }
        else if (droit != -1)
        {
            arb->fils[0][idx] = -1;
            arb->fils[1][idx] = -1;

            idx = droit;
        }
        else
        {
            arb->fils[0][idx] = -1;
            arb->fils[1][idx] = -1;

            idx = gauche;
        }
    }

    return (int)idx;
}

void TArb_Supprimer(Arbre *arb, int val)
{
    if (arb)
        arb->IdArb = TArb_Supprimer_Impl(arb, val, arb->IdArb);
}

void TArb_Supprimer_Occurence(Arbre *arb, int val)
{
    if (arb)
    {
        int idx = TArb_TrouverElement(arb, val);
        while (idx != -1)
        {
            int nv_idx = TArb_Supprimer_Impl(arb, val, idx);

            if (arb->IdArb == idx) arb->IdArb = nv_idx;

            idx = TArb_TrouverElement(arb, val);
        }
    }
}
