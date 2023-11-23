#include<stdio.h>
#include<stdlib.h>

typedef struct ND
{
    int info;
    struct ND *fgc;
    struct ND *fdt;
}Noeud;

typedef struct cel
{
    int info;
    struct cel *svt;
}Cellule;


Noeud *CreerNoeud(int val)
{
    Noeud *NE = (Noeud *)malloc(sizeof(Noeud));
    NE->info = val;
    NE->fdt = NE->fgc = NULL;
    return ((Noeud *)NE);
}
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
    CL->svt = NULL; // Initialiser le pointeur suivant par NULL
    return ((Cellule *)CL); // retourne CL
}
Cellule *InsererPListeFin(Cellule *liste, int val)
{
    Cellule *CL, *courant;
    CL = CreerCellule(val); // Creer l'element
    if (!liste) return ((Cellule *)CL); // tester si la liste existe
    courant = liste; // Initialiser courant a la tete de la liste
    while (courant->svt) // tant que courant a un suivant
        courant = courant->svt; // passer a l'element suivant
    courant->svt = CL; // Inserer l'element
    return ((Cellule *)liste); 
}

Cellule *TransfereArbBinListe(Noeud *Arb, Cellule *liste)
{
    if (!Arb) return ((Cellule *)NULL);
    liste= InsererPListeFin(liste,Arb->info);
    if (Arb->fgc) liste = TransfereArbBinListe(Arb->fgc,liste);
    if (Arb->fdt) liste = TransfereArbBinListe(Arb->fdt,liste);
    return ((Cellule *)liste);
}
void AfficherListe(Cellule *liste)
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
            courant = courant->svt; // passer au suivant
        }
    }
}

void main()
{
    Noeud *Arb = NULL;
    Cellule *liste = NULL;
    
    Arb = CreerNoeud(12);
    Arb->fgc = CreerNoeud(7);
    Arb->fdt = CreerNoeud(9);
    Arb->fgc->fgc = CreerNoeud(6);
    Arb->fgc->fgc->fdt = CreerNoeud(2);
    Arb->fgc->fdt = CreerNoeud(8);
    Arb->fgc->fdt->fgc = CreerNoeud(3);
    Arb->fgc->fdt->fdt = CreerNoeud(5);
    Arb->fgc->fdt->fdt->fgc = CreerNoeud(1);
    Arb->fgc->fdt->fdt->fdt = CreerNoeud(2);
    Arb->fdt->fdt = CreerNoeud(14);

    liste = TransfereArbBinListe(Arb,liste);
    AfficherListe(liste);

}