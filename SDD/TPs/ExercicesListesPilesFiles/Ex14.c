#include<stdio.h>
#include<stdlib.h>
// La taille Max des tableaux
#define NbElem 25
// Pile a l'aide de tableau
typedef struct 
{
    int Tab[NbElem];
    int Sommet;
}TPile;
// Pile a l'aide de pointeur
typedef struct pile
{
    int info;
    struct pile *suivant;
}Cellule;
/* **************** Mise en oevre a l'aide des tableaux **************** */ 
/************************************************************************/
int Init_TPile(TPile *pile)
{
    if (!pile) return ((int)0); // test si la zone memoire existe
    pile->Sommet = -1; // La pile est vide
    return ((int)1);
}
int EstVide(TPile *pile)
{
    if (!pile) return ((int)-1); // test si la zone memoire existe
    return ((int)(pile->Sommet == -1));
}
int EstSaturee(TPile *pile)
{
    if (!pile) return ((int)-1); // test si la zone memoire existe
    return ((int)pile->Sommet == (NbElem-1));
}
int EmpilerTPile(TPile *pile, int val)
{
    if (!pile) return ((int)-1); // tester si la zone memoire existe
    if (EstSaturee(pile)) return ((int)0); // test er si la pile est saturee
    pile->Tab[++pile->Sommet] = val; // Inserer la valeur
    return ((int)1);
}
int DepilerTPile(TPile *pile)
{
    if (!pile) return ((int)-1); // tester si la zone memoire existe
    if (EstVide(pile)) return ((int)0); // tester si la pile est vide
    pile->Sommet--;
    return ((int)1);
}
void AfficherTPile(TPile *pile)
{
    int i;
    if (!pile) // test si la zone memoire existe
    {
        printf("\nPile inexiste!");
        exit(0);
    }
    if (EstVide(pile)) printf("\nLa pile est vide");
    else
    {
        printf("\nPile : ");
        for (i = pile->Sommet; i >= 0; i--)
            printf("%d\t",pile->Tab[i]);
    }
}

int MinTPile(TPile pile, int *Min, int *Rang)
{
    int cmpt = 1, rt;
    TPile tmp;
    Init_TPile(&tmp);
    // pile vide
    if(EstVide(&pile)) return ((int)0);
    *Min = pile.Tab[pile.Sommet];
    *Rang = cmpt;
    rt = EmpilerTPile(&tmp,*Min);
    rt = DepilerTPile(&pile);
    while (!EstVide(&pile))
    {
        cmpt++;
        if (pile.Tab[pile.Sommet] < *Min) 
        {
            *Min = pile.Tab[pile.Sommet];
            *Rang = cmpt;
        }
        rt = EmpilerTPile(&tmp,pile.Tab[pile.Sommet]);
        rt = DepilerTPile(&pile);
    }
    while (!EstVide(&tmp))
    {
        rt = EmpilerTPile(&pile,tmp.Tab[tmp.Sommet]);
        rt = DepilerTPile(&tmp);
    }
    return ((int)1);
}
/* *************** Mise en oevre a l'aide des pointeurs *************** */ 
/************************************************************************/
Cellule *CreerCellule(int val)
{
    Cellule *CL;
    CL = (Cellule *)malloc(sizeof(Cellule)); // Allocation de la memoire
    if (!CL) 
    {   // Erreur d'allocation de la memoire
        printf("\nErreur d'allocation de la memoire!");
        exit(0); // Quitter le programme
    }
    CL->info = val; // Affecter la valeur
    CL->suivant = NULL; // Initialiser le pointeur suivant par NULL
    return ((Cellule *)CL); // retourne CL
}

// Inserer un element au sommet de la pile
Cellule *EmpilerPPile(Cellule *pile, int val)
{
    Cellule *CL;
    CL = CreerCellule(val);
    if (!pile) return ((Cellule *)CL); // tester si la pile existe
    CL->suivant = pile; // Inserer au sommet
    return ((Cellule *)CL);
}
// Supprimer un element au sommet de la pile
Cellule *DepilerPPile(Cellule *pile)
{
    Cellule *Supp;
    if (!pile) return ((Cellule *)NULL); // tester si la pile existe
    Supp = pile;
    pile = pile->suivant;
    free(Supp);
    return ((Cellule *)pile);
}
void AfficherPPile(Cellule *pile)
{
    Cellule *pile2 = NULL;
    if (!pile) // tester si la pile existe
    {
        printf("\nPile inexiste ou vide!");
        exit(0);
    }
    printf("\nPile : ");
    while (pile) // tant qu'on a un element dans la pile
    {   // Afficher l'element et le depiler
        printf("%d\t",pile->info);
        pile2 = EmpilerPPile(pile2, pile->info);
        pile = DepilerPPile(pile);
    }
    while (pile2)
    {   // Récupperer la pile
        pile = EmpilerPPile(pile, pile2->info);
        pile2 = DepilerPPile(pile2);
    }
}

Cellule *MinPPile(Cellule *pile, int *Min, int *Rang)
{
    Cellule *tmp = NULL;
    int min, rang, i = 1;
    if (!pile) return ((Cellule *)NULL);
    min = pile->info;
    rang = 1;
    while (pile->suivant)
    {
        tmp = EmpilerPPile(tmp, pile->info);
        pile = DepilerPPile(pile);
        i++;
        if (pile->info < min)
        {
            min = pile->info;
            rang = i;
        }
    }
    while (tmp)
    {
        pile = EmpilerPPile(pile,tmp->info);
        tmp = DepilerPPile(tmp);
    }
    *Rang = rang;
    *Min = min;
    return ((Cellule *)pile);    
}

void main()
{
    /* Test sur la pile statique */
    printf("\n*** Pile a l'aide de tableau ***");
    TPile Spile;
    int rt, Min, Rang;
    rt = Init_TPile(&Spile);
    rt = EmpilerTPile(&Spile,13);
    rt = EmpilerTPile(&Spile,12);
    rt = EmpilerTPile(&Spile,15);
    rt = EmpilerTPile(&Spile,14);
    AfficherTPile(&Spile);
    rt = MinTPile(Spile,&Min,&Rang);
    printf("\nLe Min : %d - Son rang : %d",Min,Rang);
    AfficherTPile(&Spile);

    /* Test sur la pile dynamique */
    printf("\n*** Pile a l'aide de tableau ***");
    Cellule *Dpile = NULL;
    Dpile = EmpilerPPile(Dpile,13);
    Dpile = EmpilerPPile(Dpile,12);
    Dpile = EmpilerPPile(Dpile,13);
    Dpile = EmpilerPPile(Dpile,11);
    Dpile = MinPPile(Dpile,&Min,&Rang);
    printf("\nLe min : %d - Son rang : %d",Min,Rang);
    AfficherPPile(Dpile);
    
}