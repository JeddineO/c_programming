#include<stdio.h>
#include<stdlib.h>

#define MaxElem 30

typedef struct
{
    int info[MaxElem]; // tableau d'entiers
    int IdElem; // Indice du dernier element
}TAB;
typedef struct CL
{
    int info;
    struct CL *svt;
}Cellule;
typedef struct
{
    Cellule *Tete, *Queue;
}File;
typedef struct ND
{
    int info;
    struct ND *fgc, *fdt;
}Noeud;

// Tableau
void AffichageTAB(TAB tab)
{
    if (tab.IdElem == -1) printf("\nTAB vide");
    else
    {
        printf("\nTAB : ");
        for (int i = 0; i <= tab.IdElem; i++) printf("%d\t",tab.info[i]);
    }
}
int InsertionBonnePlaceTAB(TAB *tab, int val)
{
    int i;
    if (!tab) return ((int)-1);
    if (tab->IdElem == MaxElem-1) return ((int)0);
    i = tab->IdElem;
    while ((i >= 0) && (val < tab->info[i]))
    {
        tab->info[i+1] = tab->info[i];
        i--;
    }
    tab->info[i+1] = val;
    ++tab->IdElem;
    return ((int)1);
}

// Liste (Pointeur)
Cellule *CreerCellule(int val)
{
    Cellule *CL = (Cellule *)malloc(sizeof(Cellule));
    if (!CL)
    {
        printf("\nErreur d'allocation de la memoire pour la cellule!");
        exit(0);
    }
    CL->info = val;
    CL->svt = NULL;
    return ((Cellule *)CL);
}
Cellule *InsertionBonnePlaceListe(Cellule *liste, int val)
{
    Cellule *courant, *CL;
    CL = CreerCellule(val);
    if (!liste) return ((Cellule *)CL);
    // Insertion en tete
    if (val < liste->info)
    {
        CL->svt = liste;
        return ((Cellule *)CL);
    }
    courant = liste;
    while (courant->svt)
    {
        // Insertion en milieu
        if (val < courant->svt->info)
        {
            CL->svt = courant->svt;
            courant->svt = CL;
            return ((Cellule *)liste);
        }
        courant = courant->svt;
    }
    // Insertion en queue
    courant->svt = CL;
    return ((Cellule *)liste);
}
void AffichageListe(Cellule *liste)
{
    Cellule *courant;
    if (!liste) printf("\nListe vide");
    else
    {
        printf("\nListe :  ");
        courant = liste;
        while (courant)
        {
            printf("%d\t",courant->info);
            courant = courant->svt;
        }
    }
}
Cellule *Inserer_Liste_Debut(Cellule *liste, int val)
{
    Cellule *CL;
    CL = CreerCellule(val); 
    if (!liste) return ((Cellule *)CL); 
    CL->svt = liste; 
    return ((Cellule *)CL); 
}
Cellule *Inserer_Liste_Fin(Cellule *liste, int val)
{
    Cellule *CL, *courant;
    CL = CreerCellule(val); 
    if (!liste) return ((Cellule *)CL); 
    courant = liste; 
    while (courant->svt) courant = courant->svt; 
    courant->svt = CL; 
    return ((Cellule *)liste); 
}

// Pile
Cellule *Empiler(Cellule *pile, int val)
{
    Cellule *CL;
    CL = CreerCellule(val);
    if (!pile) return ((Cellule *)CL); // tester si la pile existe
    CL->svt = pile; // Inserer au sommet
    return ((Cellule *)CL);
}
Cellule *Depiler(Cellule *pile)
{
    Cellule *Supp;
    if (!pile) return ((Cellule *)NULL); // tester si la pile existe
    Supp = pile;
    pile = pile->svt;
    free(Supp);
    return ((Cellule *)pile);
}
void AfficherPile(Cellule *pile)
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
        pile2 = Empiler(pile2, pile->info);
        pile = Depiler(pile);
    }
    while (pile2)
    {   // Récupperer la pile
        pile = Empiler(pile, pile2->info);
        pile2 = Depiler(pile2);
    }
}

// File
File *CreerFile()
{
    File *PF;
    PF = (File *)malloc(sizeof(File));
    if (!PF)
    {   // Erreur d'allocation de la memoire
        printf("\nErreur d'allocation de la memoire!");
        exit(0);
    }
    PF->Tete = NULL;
    PF->Queue = NULL;
    return ((File *)PF);
}
int EstVide(File *file)
{
    if (!file) return ((int)-1); // tester si la file existe
    return ((int)(!file->Tete && !file->Queue));
}
int EnfilerFile(File *file, int val)
{
    Cellule *CL;
    if (!file) return ((int)-1); // tester si la file existe
    CL = CreerCellule(val); // creer l'element
    if (!file->Tete) file->Tete = CL;
    else file->Queue->svt = CL;
    file->Queue = CL;    
    return ((int)1);
}
int DefilerFile(File *file)
{
    Cellule *Supp;
    if (!file) return ((int)-1); // tester si la file existe
    if (!file->Tete) return ((int)0); // tester si la file est vide
    Supp = file->Tete; // pointer sur la tete de la file
    file->Tete = file->Tete->svt; // affecter au tete l'element suivant
    if (!file->Tete) file->Queue = NULL;
    free(Supp); // liberer la memoire
    return ((int)1);
}
int TailleFile(File *file)
{
    int taille = 0;
    Cellule *DCL; // pour memoriser la derniere cellule
    if (!file) return ((int)-1); // tester si la file existe
    if (EstVide(file)) return ((int)0); // si la file est vide
    DCL = file->Queue;
    while (file->Tete != DCL)
    {
        taille++;
        EnfilerFile(file,file->Tete->info);
        DefilerFile(file);
    }
    EnfilerFile(file,file->Tete->info);
    DefilerFile(file);
    return ((int)++taille);
}
void AfficherFile(File *file)
{
    int i, taille = TailleFile(file);
    if (!file) // tester si la file existe
    {
        printf("\nFile inexiste!");
        exit(0);
    }
    if(EstVide(file)) printf("\nLa file est vide");
    else {
        printf("\nFile : ");
        for (i = 0; i < taille; i++)
        {
            printf("%d\t",file->Tete->info);
            EnfilerFile(file,file->Tete->info);
            DefilerFile(file);
        }
    }
}

// Arbre binaire
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
