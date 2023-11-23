#include<stdio.h>
#include<stdlib.h>
// Definition de la structure
typedef struct Pile
{
    int info; 
    struct Pile *suivant; // Pointeur vers l'element suivant
}Cellule;

// 1- Creer une cellule de la pile
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
// 4- vider une pile
Cellule *ViderPPile(Cellule *pile)
{
    Cellule *Supp;
    if (!pile) return ((Cellule *)NULL); // tester si la pile existe
    while (pile)        pile = DepilerPPile(pile);
    return ((Cellule *)pile);
}
// 5- Afficher la pile
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
// 5- la taille de la pile
int TaillePPile(Cellule *pile)
{
    int taille = 0;
    Cellule *pile2 = NULL;
    if (!pile) return ((int)-1);
    while (pile)
    {   // depiler dans la pile et calculer la taille
        taille++;
        pile2 = EmpilerPPile(pile2,pile->info);
        pile = DepilerPPile(pile);
    }
    while (pile2)
    {   // Récuperer la pile
        pile = EmpilerPPile(pile,pile2->info);
        pile2 = DepilerPPile(pile2);
    }
    return ((int)taille);
}
// 6- Chercher un element dans la pile
int RecherchePPile(Cellule *pile, int val)
{
    int i = 0, pos = 0;
    Cellule *pile2 = NULL;
    if (!pile) return ((int)-1);
    while (pile && (pile->info != val))
    {   // tant qu'on a un element dans la pile
        i++;
        pile2 = EmpilerPPile(pile2,pile->info);
        pile = DepilerPPile(pile); 
    }
    if (pile) pos = i+1;
    while (pile2)
    {   // Récuperer la pile
        pile = EmpilerPPile(pile,pile2->info);
        pile2 = DepilerPPile(pile2);
    }
    return ((int)pos);
}

int MinPile(Cellule *pile, int *Rang)
{
    Cellule *tmp = NULL;
    int min, rang, i = 1;
    if (!pile)
    {
        *Rang = 0;
        return ((int)0);
    }
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
    return ((int)min);    
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

void main()
{
    Cellule *pile = NULL;
    int a, r;
    pile = EmpilerPPile(pile,12);
    pile = EmpilerPPile(pile,17);
    pile = EmpilerPPile(pile,14);
    pile = EmpilerPPile(pile,15);
    pile = EmpilerPPile(pile,11);
    pile = EmpilerPPile(pile,15);
    pile = EmpilerPPile(pile,16);
    AfficherPPile(pile);
    printf("\nLa taille de la pile : %d",TaillePPile(pile));
    a = 17; r = RecherchePPile(pile,a);
    if (r == -1) printf("\nPile vide ou non existe");
    else if (r == 0) printf("\n%d n'existe pas dans la pile",a);
    else printf("\nLa position de %d est : %d",a,r);
    pile = DepilerPPile(pile);
    printf("\nUn depilement effectuer :");
    AfficherPPile(pile);
    printf("\n*******************************");
    int Rang, Min;
    Min = MinPile(pile,&Rang);
    printf("\nLe min : %d et son rang est : %d",Min,Rang);
    AfficherPPile(pile);
    printf("\n*******************************");
    Cellule *pile1 = NULL;
    pile1 = EmpilerPPile(pile1, 3);
    pile1 = EmpilerPPile(pile1, 2);
    pile1 = EmpilerPPile(pile1, 3);
    pile1 = EmpilerPPile(pile1, 2);
    pile1 = EmpilerPPile(pile1, 1);
    pile1 = EmpilerPPile(pile1, 2);
    pile1 = EmpilerPPile(pile1, 1);
    pile1 = SupprimerPileDoublons(pile1);
    AfficherPPile(pile1);
}