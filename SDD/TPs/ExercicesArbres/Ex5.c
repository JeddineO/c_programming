#include<stdio.h>
#include<stdlib.h>

#define NbElem 25

typedef struct 
{
    int info[NbElem];       // Tableau d'entiers
    int fils[2][NbElem];    // Tableau d'indices (1er dim: fils, 2dim: frere)
    int IdAr;               // Indice de la racine
    int IdElem;             // Indice du dernier element dans le tableau
}Arbre;

int InitTArbre(Arbre *Arb)
{
    int i;
    if (!Arb) return ((int)0);
    for (i = 0; i < NbElem; i++)
    {
        Arb->fils[0][i] = -1; // Initialiser les indices des fils
        Arb->fils[1][i] = -1; // Initialiser les indices des freres
    }
    Arb->IdAr = -1;         // Initialiser l'indice de la racine
    Arb->IdElem = -1;       // Initialiser l'indice du dernier element
    return ((int)1);
}

int InsererArbre(Arbre *Arb, int val, int id)
{
    int ff;
    if (!Arb) return ((int)-1);
    if (Arb->IdElem == NbElem-1) return ((int)0);
    if (Arb->IdAr == -1) 
    {
        Arb->info[++Arb->IdElem] = val;
        Arb->IdAr = Arb->IdElem;
    }
    else
    {
        if (Arb->fils[0][Arb->IdAr] == -1)
        {
            Arb->fils[0][Arb->IdAr] = ++Arb->IdElem;
            Arb->info[Arb->IdElem] = val;
        }
        else
        {
            do
            {
                printf("\nTaper 1 pour inserer fils, 2 pour inserer frere");
                scanf("%d",&ff);
                if (ff == 1)
                {
                    if (Arb->fils[0][id] == -1)
                    {
                        Arb->fils[0][id] = ++Arb->IdElem;
                        Arb->info[Arb->IdElem] = val;
                    }
                    else return ((int)InsererArbre(Arb,val,Arb->fils[0][id]));
                }
                else 
                {
                    if (ff == 2)
                    {
                        if (Arb->fils[1][id] == -1)
                        {
                            Arb->fils[1][id] = ++Arb->IdElem;
                            Arb->info[Arb->IdElem] = val;
                        }
                        else return ((int)InsererArbre(Arb,val,Arb->fils[1][id]));
                    }
                    else printf("\nChoix invalide !");
                }while (ff!=1 && ff!=2);
            }
        }
    }
    return ((int)1);
}

int ConstructionArbre(Arbre *Arb)
{
    int val;
    if (!Arb) return ((int)-1);
    printf("\n");
}

void AffichagePrefixe(Arbre *Arb, int id)
{
    if (id!=-1)
    {
        printf("%d\t",Arb->info[id]);
        AffichagePrefixe(Arb,Arb->fils[0][id]);
        AffichagePrefixe(Arb,Arb->fils[1][id]);
    }
}

void main()
{
    Arbre *Arb = (Arbre *)malloc(sizeof(Arbre));
    int rt, val, choix;
    do
    {
        printf("\n------------------------");
        printf("\n1 : Initialiser");
        printf("\n2 : Construction");
        printf("\n3 : Affichage");
        printf("\n--> Choix : ");
        scanf("%d",&choix);
        switch (choix)
        {
            case 1: 
                rt = InitTArbre(Arb);
                if (!rt) printf("\nInitialisation echouee");
                else printf("\nInitialisation avec succes");
                break;
            case 2:
                printf("\nTaper la valeur : ");
                scanf("%d",&val);
                rt = ConstructionArbre(Arb,val,1); 
                if (!rt) printf("\nInsertion echouee");
                else printf("\nInsertion bien effectuee");
                break;
            case 3: AffichagePrefixe(Arb,Arb->IdAr); break;
            default : break;
        }
    } while (choix);
    
}