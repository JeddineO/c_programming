#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Definition des structues de la file
typedef struct cellule
{
    int info;
    struct suivant *suivant;
} cellule;

typedef struct
{
    cellule *Debut;
    cellule *fin;
} PFile;

// Initialisation de la file

PFile *InitFile()
{
    PFile *NE;

    NE = (PFile *)malloc(sizeof(PFile));
    if (!NE)
    {
        printf("\n Erreur d'allocation ");
        exit(0);
    }
    NE->Debut = NE->fin = NULL;
    return ((PFile *)NE);
}

// Enfiler

int Enfiler(PFile *MaFile, int valeur)
{
    cellule *NE;
    NE = (cellule *)malloc(sizeof(cellule));
    NE->info = valeur;
    MaFile->fin->suivant = NE;
    MaFile->fin = NE;

    return ((int)1);
}

// Defiler

PFile *Defiler(PFile *MaFile)
{
    PFile *SupElem;
    SupElem = MaFile->Debut;
    MaFile->Debut = MaFile->Debut->suivant;
    free(SupElem);
    return ((PFile *)MaFile);
}
// Affichage de la file

void AfficheFile(PFile *MaFile)
{
    cellule *ptr1, *ptr2;
    ptr1 = MaFile->Debut;
    ptr2 = MaFile->fin;
    while (ptr1 != ptr2)
    {
        printf("%d", MaFile->Debut->info);
        Defiler(MaFile);
        ptr1 = ptr1->suivant;
    }
}

int main()
{
    PFile *MaFile;
    MaFile = InitFile();
    MaFile = Enfiler(MaFile, 1);
    MaFile = Enfiler(MaFile, 1);
    MaFile = Enfiler(MaFile, 1);

    AfficheFile(MaFile);

    return 0;
}
