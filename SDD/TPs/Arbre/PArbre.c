// Declaration des librairies
#include<stdio.h>
#include<stdlib.h>
// Declaration des types et des structures
typedef struct ND   // Definition de la structure d'un arbre binaire
{
    int info;       // information
    struct ND *fgc; // Pointeur sur le fils gauche
    struct ND *fdt; // Pointeur sur le fils droite
}Noeud;

Noeud *CreerNoeud(int val)
{
    Noeud *NE;
    NE = (Noeud *)malloc(sizeof(Noeud));    // Allocation de la memoire
    if (!NE)
    {   
        printf("\nErreur d'allocation de la memoire!");
        exit(0);
    }
    NE->info = val;             // Affectation de la valeur du noeud
    NE->fgc = NE->fdt = NULL;   // Initialiser les fils au NULL
    return ((Noeud *)NE);
}

void AffichagePrefixe(Noeud *Arb)
{
    if (Arb)
    {
        printf("\n%d",Arb->info);
        AffichagePrefixe(Arb->fgc);
        AffichagePrefixe(Arb->fdt);
    }
}

void AffichageInfixe(Noeud *Arb)
{
    if (Arb)
    {
        AffichageInfixe(Arb->fgc);
        printf("\n%d",Arb->info);
        AffichageInfixe(Arb->fdt);
    }
}

void AffichagePostfixe(Noeud *Arb)
{
    if (Arb)
    {
        AffichagePostfixe(Arb->fgc);
        AffichagePostfixe(Arb->fdt);
        printf("\n%d",Arb->info);
    }
}

void AffichageHorizontal(Noeud *Arb, int n)
{
    if (Arb)
    {
        if (Arb->fdt) AffichageHorizontal(Arb->fdt,n+1); 
        printf("\n");
        for (int i = 0; i < n; i++) printf("\t");
        printf("%d",Arb->info);
        if (Arb->fgc) AffichageHorizontal(Arb->fgc,n+1); 
    }
}

int TailleArbre(Noeud *Arb)
{
    if (!Arb) return ((int)0);  // Arbre vide
    // 1 de la racine plus nombre de noeuds gauches et droits de la racine
    return ((int)(1+TailleArbre(Arb->fgc)+TailleArbre(Arb->fdt)));
}

int HauteurArbre(Noeud *Arb)
{
    int HG = 0, HD = 0; // Hauteur gauche et Hauteur droite
    if (!Arb) return ((int)0);  // Arbre vide
    if (Arb->fgc) HG = 1 + HauteurArbre(Arb->fgc);
    if (Arb->fdt) HD = 1 + HauteurArbre(Arb->fdt);
    return ((int)((HG < HD) ? HD : HG));
}

Noeud *ViderArbre(Noeud *Arb)
{
    if (!Arb) return ((Noeud *)NULL); // Arbre Vide
    Arb->fgc = ViderArbre(Arb->fgc); // Vider sous arbre gauche
    Arb->fdt = ViderArbre(Arb->fdt); // Vider sous arbre droit
    free(Arb);                       // Liberer la memoire
    return ((Noeud *)NULL); 
}

int MinArbre(Noeud *Arb, int *Min)
{
    int rt, min;
    if (!Arb) return ((int)0);
    *Min = Arb->info;
    if (Arb->fgc)
    {
        rt = MinArbre(Arb->fgc,&min);
        if (min < *Min) *Min = min;
    }
    if (Arb->fdt)
    {
        rt = MinArbre(Arb->fdt,&min);
        if (min < *Min) *Min = min;
    }
    return ((int)1);
}

int MaxArbre(Noeud *Arb, int *Max)
{
    int rt, max;
    if (!Arb) return ((int)0);
    *Max = Arb->info;
    if (Arb->fgc)
    {
        rt = MaxArbre(Arb->fgc,&max);
        if (*Max < max) *Max = max;
    }
    if (Arb->fdt)
    {
        rt = MaxArbre(Arb->fdt,&max);
        if (*Max < max) *Max = max;
    }
    return ((int)1);
}

Noeud *InsererArbre(Noeud *Arb, int val)
{
    Noeud *NE;
    int dir;
    if (!Arb)
    {
        NE = CreerNoeud(val);
        return ((Noeud *)NE);
    }
    do 
    {
        printf("\nTaper 1 si vous voulez inserer a gauche, 2 si a droit : ");
        scanf("%d",&dir);
        if (dir == 1) Arb->fgc = InsererArbre(Arb->fgc,val);
        else if (dir == 2) Arb->fdt = InsererArbre(Arb->fdt,val);
        else printf("\nChoix invalide !");
    }while (dir!=1 && dir!=2);
    return ((Noeud *)Arb);
}

int RechercheArbre(Noeud *Arb, int val)
{
    int rt;
    if (!Arb) return ((int)-1);
    if (Arb->info == val) return ((int)1);
    if (Arb->fgc) 
    {
        rt = RechercheArbre(Arb->fgc,val);
        if (rt == 1) return ((int)1);
    }
    if (Arb->fdt)
    {
        rt = RechercheArbre(Arb->fdt,val);
        if (rt == 1) return ((int)1);
    }
    return ((int)0);
}

Noeud *SupprimerArbre(Noeud *Arb, int val, int *supp)
{
    int rt;
    Noeud *pred, *courant, *tmp;
    *supp = 0;
    if (!Arb) return ((Noeud *)NULL);
    if (Arb->info == val)
    {
        tmp = Arb;
        if (!Arb->fgc) Arb = Arb->fdt;
        else if (!Arb->fdt) Arb = Arb->fgc;
        else
        {
            courant = Arb->fgc;
            if (courant->fdt) 
            {
                pred = Arb;
                while (courant->fdt)
                {
                    pred = courant;
                    courant = courant->fdt;
                }
                pred->fdt = courant->fgc;
                courant->fgc = Arb->fgc;
            }
            courant->fdt = Arb->fdt;
            Arb = courant;
        }
        free(tmp);
        *supp = 1;
    }
    else
    {
        Arb->fgc = SupprimerArbre(Arb->fgc,val,supp);
        if (*supp == 0) Arb->fdt = SupprimerArbre(Arb->fdt,val,supp);
    }
    return ((Noeud *)Arb);
}

void AffichageArbre(Noeud *Arb)
{
    int choix;
    if (!Arb) printf("\nArbre vide");
    else
    {
        printf("\nChoisir le type d'affichage : ");
        printf("\n1 : Affichage Prefixe");
        printf("\n2 : Affichage Infixe");
        printf("\n3 : Affichage Postfixe");
        printf("\n4 : Affichage Horizontal");
        printf("\n--> Choix : ");
        scanf("%d",&choix);
        switch (choix)
        {
            case 1: 
                AffichagePrefixe(Arb); 
                break;
            case 2: 
                AffichageInfixe(Arb); 
                break;
            case 3: 
                AffichagePostfixe(Arb); 
                break;
            case 4: 
                AffichageHorizontal(Arb,0); 
                break;
            default : printf("\nChoix invalide !");
        }
    }
}

/* ************************************************************************
   *            Arbres Binaires Ordonnes Horizontalement                  *
   ************************************************************************ */

int MinArbreOrdonne(Noeud *Arb, int *Min)
{
    int rt;
    if (!Arb) return ((int)0);
    *Min = Arb->info;
    if (Arb->fgc) rt = MinArbreOrdonne(Arb->fgc,Min);
    return ((int)1);
}
int MaxArbreOrdonne(Noeud *Arb, int *Max)
{
    int rt;
    if (!Arb) return ((int)0);
    *Max = Arb->info;
    if (Arb->fdt) rt = MaxArbreOrdonne(Arb->fdt,Max);
    return ((int)1);
}
Noeud *InsererArbBinOrdonne(Noeud *Arb, int val)
{
    Noeud *NE;
    if (!Arb)                   // Arbre vide
    {
        NE = CreerNoeud(val);   // Creer un noued
        return ((Noeud *)NE);
    }
    // Insertion dans la partie gauche
    if (val < Arb->info) Arb->fgc = InsererArbBinOrdonne(Arb->fgc,val);
    // Insertion dans la partie droite
    else Arb->fdt = InsererArbBinOrdonne(Arb->fdt,val);
    return ((Noeud *)Arb);
}

int RechercheArbBinOrdonne(Noeud *Arb, int val)
{
    if (!Arb) return ((int)-1);             // Arbre vide
    if (Arb->info == val) return ((int)1);  // Element trouve
    if (val < Arb->info)
    {
        if (!Arb->fgc) return ((int)0);
        return ((int)RechercheArbBinOrdonne(Arb->fgc,val));
    }
    if (!Arb->fdt) return ((int)0);
    return ((int)RechercheArbBinOrdonne(Arb->fdt,val));
}

Noeud *SupprimerArbBinOrdonne(Noeud *Arb, int val, int *supp)
{
    Noeud *pred, *courant, *tmp;
    *supp = 0;
    if (!Arb) return ((Noeud *)NULL);   // Arbre vide
    if (val < Arb->info)        // Recherche dans la sous arbre gauche
    {
        if (!Arb->fgc) return ((Noeud *)Arb); // Pas de fils gauche
        Arb->fgc = SupprimerArbBinOrdonne(Arb->fgc,val,supp); 
    }
    else
    {
        if (Arb->info < val)    // Recherche dans la sous arbre droit
        {
            if (!Arb->fdt) return ((Noeud *)Arb); // Pas de fils droit
            Arb->fdt = SupprimerArbBinOrdonne(Arb->fdt,val,supp);
        }
        else                // Valeur trouvee
        {
            tmp = Arb;      // pour liberer la memoire
            if (!Arb->fgc) Arb = Arb->fdt;  // Pas de fils gauche
            else
            {
                if (!Arb->fdt) Arb = Arb->fgc;  // Pas de fils droit
                else
                {
                    courant = Arb->fgc; 
                    if (courant->fdt) // si le fils gauche a un fils droit 
                    {
                        pred = Arb;
                        while (courant->fdt) // Tant qu'on a un fils droit
                        {
                            pred = courant;
                            courant = courant->fdt;
                        }
                        pred->fdt = courant->fgc;
                        courant->fgc = Arb->fgc;
                    }
                    courant->fdt = Arb->fdt;
                    Arb = courant;
                }
            }
            free(tmp);      // liberer la memoire
            *supp = 1;      // Suppression effectuee
        }
    }
    return ((Noeud *)Arb);
}

void Affichage_Infixe_Bornee(Noeud *Arb, int Inf, int Sup)
{
    if (Arb)
    {
        if (Inf <= Arb->info) Affichage_Infixe_Bornee(Arb->fgc,Inf,Sup);
        if (Inf <= Arb->info && Arb->info <= Sup) printf("%d\t",Arb->info);
        if (Arb->info <= Sup) Affichage_Infixe_Bornee(Arb->fdt,Inf,Sup);
    }   
}

void ManipArbreBinaireQlq(Noeud *Arbre)
{
    int choix, val, rt;
    printf("\n*********************************************************");
    printf("\n*     Manipulation des arbres binaires quelconques      *");
    printf("\n*********************************************************");
    do
    {    
        printf("\n---------- Taper votre choix : ----------");
        printf("\n0  : Retour au menu principal");
        printf("\n1  : Affichage de l'arbre");
        printf("\n2  : La taiile de l'arbre");
        printf("\n3  : La hauteur de l'arbre");
        printf("\n4  : Vider l'arbre");
        printf("\n5  : Le minimum de l'arbre");
        printf("\n6  : Le maximum de l'arbre");
        printf("\n7  : Inserer une valeur dans l'arbre");
        printf("\n8  : Rechercher une valeur dans l'arbre");
        printf("\n9  : Supprimer une valeur dans l'arbre");
        printf("\n--> Choix : ");
        scanf("%d",&choix);
        switch (choix)
        {
            case 0: break;
            case 1:
                AffichageArbre(Arbre); 
                break;
            case 2:
                printf("\nLa taiile de l'arbre : %d",TailleArbre(Arbre));
                break;
            case 3:
                printf("\nLa hauteur de l'arbre : %d",HauteurArbre(Arbre));
                break;
            case 4:
                Arbre = ViderArbre(Arbre); 
                break;
            case 5:
                rt = MinArbre(Arbre,&val);
                if (!rt) printf("\nArbre vide");
                else printf("\nLe min : %d",val); 
                break;
            case 6:
                rt = MaxArbre(Arbre,&val);
                if (!rt) printf("\nArbre vide");
                else printf("\nLe max : %d",val);
                break;
            case 7:
                printf("\nEntrer la valeur du noeud a inserer : ");
                scanf("%d",&val);
                Arbre = InsererArbre(Arbre,val);
                break;
            case 8:
                printf("\nTaper la valeur a chercher : ");
                scanf("%d",&val);
                rt = RechercheArbre(Arbre,val);
                if (rt == -1) printf("\nArbre vide");
                else if (rt == 0) printf("\nLa valeur %d n'existe pas dans l'arbre",val);
                else printf("\nLa valeur %d existe dans l'arbre",val);
                break;
            case 9:
                printf("\nTaper la valeur a supprimer : ");
                scanf("%d",&val);
                Arbre = SupprimerArbre(Arbre,val,&rt);
                if (rt) printf("\nLa valeur %d a ete supprimer dans l'arbre",val);
                else printf("\nLa valeur %d n'existe pas dans l'arbre",val);
                break;
            default:
                printf("\nChoix invalide!");
        }
        printf("\n*********************************************************");
    } while (choix);
}

void ManipArbreBinaireOrdonneHorzontal(Noeud *Arbre)
{
    int choix, val, rt;
    printf("\n*********************************************************");
    printf("\n*  Manipulation des arbres binaires Ordonne Horizontal  *");
    printf("\n*********************************************************");
    do
    {    
        printf("\n---------- Taper votre choix : ----------");
        printf("\n0  : Retour au menu principal");
        printf("\n1  : Affichage de l'arbre");
        printf("\n2  : La taiile de l'arbre");
        printf("\n3  : La hauteur de l'arbre");
        printf("\n4  : Vider l'arbre");
        printf("\n5  : Le minimum de l'arbre");
        printf("\n6  : Le maximum de l'arbre");
        printf("\n7  : Inserer une valeur dans l'arbre");
        printf("\n8  : Rechercher une valeur dans l'arbre");
        printf("\n9  : Supprimer une valeur dans l'arbre");
        printf("\n--> Choix : ");
        scanf("%d",&choix);
        switch (choix)
        {
            case 0: break;
            case 1:
                AffichageArbre(Arbre); 
                break;
            case 2:
                printf("\nLa taiile de l'arbre : %d",TailleArbre(Arbre));
                break;
            case 3:
                printf("\nLa hauteur de l'arbre : %d",HauteurArbre(Arbre));
                break;
            case 4:
                Arbre = ViderArbre(Arbre); 
                break;
            case 5:
                rt = MinArbreOrdonne(Arbre,&val);
                if (!rt) printf("\nArbre vide");
                else printf("\nLe min : %d",val); 
                break;
            case 6:
                rt = MaxArbreOrdonne(Arbre,&val);
                if (!rt) printf("\nArbre vide");
                else printf("\nLe max : %d",val);
                break;
            case 7:
                printf("\nEntrer la valeur du noeud a inserer : ");
                scanf("%d",&val);
                Arbre = InsererArbBinOrdonne(Arbre,val);
                break;
            case 8:
                printf("\nTaper la valeur a chercher : ");
                scanf("%d",&val);
                rt = RechercheArbBinOrdonne(Arbre,val);
                if (rt == -1) printf("\nArbre vide");
                else if (rt == 0) printf("\nLa valeur %d n'existe pas dans l'arbre",val);
                else printf("\nLa valeur %d existe dans l'arbre",val);
                break;
            case 9:
                printf("\nTaper la valeur a supprimer : ");
                scanf("%d",&val);
                Arbre = SupprimerArbBinOrdonne(Arbre,val,&rt);
                if (rt) printf("\nLa valeur %d a ete supprimer dans l'arbre",val);
                else printf("\nLa valeur %d n'existe pas dans l'arbre",val);
                break;
            default:
                printf("\nChoix invalide!");
        }
        printf("\n*********************************************************");
    } while (choix);
}

void main()
{
    Noeud *Arb = NULL;
    Arb = InsererArbBinOrdonne(Arb,13);
    Arb = InsererArbBinOrdonne(Arb,5);
    Arb = InsererArbBinOrdonne(Arb,3);
    Arb = InsererArbBinOrdonne(Arb,4);
    Arb = InsererArbBinOrdonne(Arb,2);
    Arb = InsererArbBinOrdonne(Arb,1);
    Arb = InsererArbBinOrdonne(Arb,19);
    Arb = InsererArbBinOrdonne(Arb,7);
    Arb = InsererArbBinOrdonne(Arb,15);
    Arb = InsererArbBinOrdonne(Arb,14);
    Arb = InsererArbBinOrdonne(Arb,18);
    Arb = InsererArbBinOrdonne(Arb,12);
    Arb = InsererArbBinOrdonne(Arb,11);
    Arb = InsererArbBinOrdonne(Arb,9);

    AffichageHorizontal(Arb,0);
    int supp;
    Arb = SupprimerArbBinOrdonne(Arb,13,&supp);
    printf("\n******************\n");
    AffichageHorizontal(Arb,0);
    // Affichage_Infixe_Bornee(Arb,6,13);
}