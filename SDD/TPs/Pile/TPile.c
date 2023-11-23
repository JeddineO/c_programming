#include<stdio.h>
#include<stdlib.h>
// Declaration des constantes
#define NbElem 30 // Taille maximale des tableaux
// Definition de la structure
typedef struct
{
    int info[NbElem]; // Tableau des elements
    int Sommet; // Indice du Dernier Element 
}TPile;

// 1- Initialiser la pile
int Init_TPile(TPile *pile)
{
    if (!pile) return ((int)0); // test si la zone memoire existe
    pile->Sommet = -1; // La pile est vide
    return ((int)1);
}
// 2- S'avoir si la pile est vide
int EstVide(TPile *pile)
{
    if (!pile) return ((int)-1); // test si la zone memoire existe
    return ((int)(pile->Sommet == -1));
}
// 3- S'avoir si la pile est saturee
int EstSaturee(TPile *pile)
{
    if (!pile) return ((int)-1); // test si la zone memoire existe
    return ((int)pile->Sommet == (NbElem-1));
}
// 4- La taille de la pile
int TaiileTPile(TPile *pile)
{
    if (!pile) return ((int)-1); // test si la zone memoire existe
    return ((int)pile->Sommet+1);
}
// 5- Afficher la pile
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
            printf("%d\t",pile->info[i]);
    }
}
// 6- Inserer un element au sommet de la pile
int EmpilerTPile(TPile *pile, int val)
{
    if (!pile) return ((int)-1); // tester si la zone memoire existe
    if (EstSaturee(pile)) return ((int)0); // test er si la pile est saturee
    pile->info[++pile->Sommet] = val; // Inserer la valeur
    return ((int)1);
}
// 7- Supprimer un element au sommet de la pile
int DepilerTPile(TPile *pile)
{
    if (!pile) return ((int)-1); // tester si la zone memoire existe
    if (EstVide(pile)) return ((int)0); // tester si la pile est vide
    pile->Sommet--;
    return ((int)1);
}
// 8- Vider la pile
int ViderTPile(TPile *pile)
{
    if (!pile) return ((int)-1); // tester si la zone memoire existe
    //if (EstVide(pile)) return ((int)0); // tester si la pile est vide
    pile->Sommet = -1;
    return ((int)1);
}
// 9- Chercher un element dans la pile
int RechercheTPile(TPile *pile, int val)
{
    int i;
    if (!pile) return ((int)-1); // test si la zone memoire existe
    if (EstVide(pile)) return ((int)-2);
    i = pile->Sommet;
    while (i >= 0)
        if (pile->info[i--] == val) return ((int)(i+1));
    return ((int)-3); // element non trouve
}


void main()
{
    TPile pile;
    int r, a;
    r = Init_TPile(&pile);
    if (r == 1) printf("\nInitialisation avec succes");
    else printf("\nInitialisation echouee");
    a = 12; r = EmpilerTPile(&pile, a);
    if (r==1) printf("\n%d est empiler avec succes",a);
    else printf("%d n'est pas empiler!!",a);
    a = 14; r = EmpilerTPile(&pile, a);
    if (r==1) printf("\n%d est empiler avec succes",a);
    else printf("%d n'est pas empiler!!",a);
    a = 15; r = EmpilerTPile(&pile, a);
    if (r==1) printf("\n%d est empiler avec succes",a);
    else printf("%d n'est pas empiler!!",a);
    a = 19; r = EmpilerTPile(&pile, a);
    if (r==1) printf("\n%d est empiler avec succes",a);
    else printf("%d n'est pas empiler!!",a);
    AfficherTPile(&pile);
    a = 14; r =RechercheTPile(&pile,a);
    if (r == -1) printf("\nPile non existe");
    else if (r == -2) printf("\nPile vide");
    else if (r == -3) printf("\n%d n'existe pas dans la pile",a);
    else printf("\nLa position de %d est : %d",a,r);
    r = DepilerTPile(&pile);
    if (r) printf("\nUn depilement effectuer");
    AfficherTPile(&pile);
    printf("\nVider la pile :");
    ViderTPile(&pile);
    AfficherTPile(&pile);
}