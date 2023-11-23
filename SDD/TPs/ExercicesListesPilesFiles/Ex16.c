#include<stdio.h>
#include<stdlib.h>

typedef struct liste
{
    int info;
    struct liste *suivant;
}Cellule;

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
Cellule *InsererPListeFin(Cellule *liste, int val)
{
    Cellule *CL, *courant;
    CL = CreerCellule(val); // Creer l'element
    if (!liste) return ((Cellule *)CL); // tester si la liste existe
    courant = liste; // Initialiser courant a la tete de la liste
    while (courant->suivant) // tant que courant a un suivant
        courant = courant->suivant; // passer a l'element suivant
    courant->suivant = CL; // Inserer l'element
    return ((Cellule *)liste); 
}
void AfficherPListe(Cellule *liste)
{
    Cellule *courant;
    // si la liste est vide
    if (!liste) printf("\nLa liste est vide");
    else
    {
        courant = liste; // initialiser courant par la tete de la liste
        printf("\nListe : ");
        while (courant)
        {   // tant qu'on a un element dans la liste
            printf("%d\t",courant->info); // afficher l'element
            courant = courant->suivant; // passer au suivant
        }
    }
}
int GrandeOccurenceListe(Cellule *liste, int *composant, int *nbElem)
{
    Cellule *courant;
    int i = 1, cmpt = 1, val, rang;
    if (!liste) 
    {
        *composant = 0;
        *nbElem = 0;
        return ((int)0);
    }
    courant = liste;
    val = liste->info;
    *composant = val;
    *nbElem = 1;
    rang = 1;
    while (courant->suivant)
    {
        if (courant->suivant->info != val)
        {
            if (*nbElem < cmpt)
            {
                *composant = val;
                *nbElem = cmpt;
                rang = i-cmpt+1;
            }
            cmpt = 0;
            val = courant->suivant->info;
        }
        cmpt++;
        i++;
        courant = courant->suivant;
    }
    if (courant->info == val)
    {
        if (*nbElem < cmpt)
        {
            *composant = val;
            *nbElem = cmpt;
            rang = i-cmpt+1;
        }
    }
    return ((int)rang);
}

void main()
{
    Cellule *liste = NULL;
    int rang, nb, comp;
    liste = InsererPListeFin(liste,12);
    liste = InsererPListeFin(liste,12);
    liste = InsererPListeFin(liste,13);
    liste = InsererPListeFin(liste,13);
    liste = InsererPListeFin(liste,14);
    liste = InsererPListeFin(liste,14);
    liste = InsererPListeFin(liste,14);
    rang = GrandeOccurenceListe(liste,&comp,&nb);
    printf("\n%d apparait %d fois a partir de la position %d",comp,nb,rang);
}