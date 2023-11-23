#include<stdio.h>
#include<stdlib.h>
#include"PArbre.c"
#include"TArbre.c"

/* ************************************************************************
   *                        Programme Principal                           *
   ************************************************************************ */
void main()
{
    Noeud *Arb = NULL;  
    Arbre *TArbre = (Arbre *)malloc(sizeof(Arbre));
    int choix;
    do
    {
        printf("\n*********************************************************");
        printf("\n*           Manipulation des arbres binaires            *");
        printf("\n*********************************************************"); 
        printf("\n0 : Arreter le programme");
        printf("\n1 : Manipulation des arbres binaires quelconques");
        printf("\n2 : Manipulation des arbres binaires ordonnes horizontalement");
        printf("\n3 : Manipulation des arbres binaires quelconques a l'aide des tableaux");
        printf("\n--> Choix : ");
        scanf("%d",&choix);
        switch (choix)
        {
            case 0: break;
            case 1:
                ManipArbreBinaireQlq(Arb);
                break;
            case 2:
                ManipArbreBinaireOrdonneHorzontal(Arb);
                break;
            case 3:
                ManipArbreTableaux(TArbre);
                break;
            default : printf("\nChoix invalide !");
        }
    } while (choix);    
}