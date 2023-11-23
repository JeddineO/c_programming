#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int info;
    struct list *suivant, *precedent;
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
    CL->precedent = NULL; // Initialiser le pointeur precedent par NULL
    return ((Cellule *)CL); // retourne CL
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

Cellule *InsererPListeFin(Cellule *liste, int val)
{
    Cellule *CL, *courant;
    CL = CreerCellule(val); // Creer l'element
    if (!liste) return ((Cellule *)CL); // tester si la liste existe
    courant = liste; // Initialiser courant a la tete de la liste
    while (courant->suivant) // tant que courant a un suivant
        courant = courant->suivant; // passer a l'element suivant
    courant->suivant = CL; // Inserer l'element
    CL->precedent = courant;
    return ((Cellule *)liste); 
}

Cellule *ConcatenationDeuxListes(Cellule *liste1, Cellule *liste2)
{
    Cellule *courant;
    if (!liste1) return ((Cellule *)liste2);
    if (!liste2) return ((Cellule *)liste1);
    courant = liste1;
    while (courant->suivant) courant = courant->suivant;
    courant->suivant = liste2;
    liste2->precedent = courant;
    return ((Cellule *)liste1);    
}

Cellule *CouperListe(Cellule *liste, int pos, Cellule *liste2[1])
{
    Cellule *courant;
    int i = 1;
    if (!liste) 
    {
        liste2[0] = NULL;
        return ((Cellule *)NULL);
    }
    courant = liste;
    while (courant->suivant)
    {
        if (i == pos-1)
        {
            liste2[0] = courant->suivant;
            courant->suivant = NULL;
            liste2[0]->precedent = NULL;
            return ((Cellule *)liste);    
        }
        i++;
        courant = courant->suivant;
    }
    liste2[0] = NULL;
    return ((Cellule *)liste);
}

int TaiileLite(Cellule *liste)
{
    Cellule *courant = liste;
    int taille = 0;
    while (courant)
    {
        taille++;
        courant = courant->suivant;
    }
    return ((int)taille);
}

void main()
{
    Cellule *liste = NULL, *liste2 = NULL, *liste3[1];
    liste = InsererPListeFin(liste,10);
    liste = InsererPListeFin(liste,11);
    liste = InsererPListeFin(liste,12);
    liste2 = InsererPListeFin(liste2,20);
    liste2 = InsererPListeFin(liste2,21);
    liste2 = InsererPListeFin(liste2,22);
    liste = ConcatenationDeuxListes(liste,liste2);
    printf("\n*****************************");
    liste = CouperListe(liste,4,liste3);
    AfficherPListe(liste);
    AfficherPListe(liste3[0]);
}