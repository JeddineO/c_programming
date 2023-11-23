typedef struct liste
{
    int info;
    struct liste *suivant; // Pointeur sur l'�l�ment suivant
} Cellule;

// Creation d'une cellule
Cellule *InitListe(int valeur)
{
    Cellule *NE;                             // creation d'un nouveau element
    NE = (Cellule *)malloc(sizeof(Cellule)); // allocation dynamique de la memeoire
    if (!NE)
    {
        printf("\n Erreur d'allocation !");
        exit(0);
    }
    NE->info = valeur; // Affecter la valeur
    NE->suivant = NULL;

    return ((Cellule *)NE); // retourne la cellule
}
Cellule *Insert(Cellule *liste, int value, int pos)
{
    // insertion au debut
    if (!liste)
    {
        liste->info = value;
        liste->suivant = NULL;
        return ((Cellule *)liste);
    }
    Cellule *ptr, *NE;
    NE = (Cellule *)malloc(sizeof(Cellule));
    int i = 0;
    ptr = liste;

    // insertion au melieu
    while (ptr->suivant)
    {
        if (i == pos - 1)
        {
            NE->info = value;
            NE->suivant = (ptr->suivant);
            ptr->suivant = NE;
            return ((Cellule *)NE);
        }
        i++;
        ptr = ptr->suivant;
    }
    // insertion a la fin
    NE->info = value;
    NE->suivant = NULL;
    ptr->suivant = NE;
    return ((Cellule *)NE);
}

typedef struct pile
{
    int val;
    struct pile *suivant;
} PPile;
// Creation et initialistaion de la liste
PPile *InitPPlie(int valeur)
{
    // Creation d'un nouveau element
    PPile *NE;
    NE = (PPile *)malloc(sizeof(PPile));
    if (!NE)
    {
        printf("\n Erreur d'allocation ");
        exit(0);
    }
    NE->val = valeur; // Donnez la valeur
    NE->suivant = NULL;

    return ((PPile *)NE);
}

// Empiler un element
PPile *Empiler(PPile *MaPile, int elem)
{
    PPile *NE;
    NE = InitPPlie(elem); // Creer un element
    NE->suivant = MaPile; // Pointer su le premier element de la pile
    MaPile = NE;          // Donner l'element a la tete de la pile
    return ((PPile *)MaPile);
}
// Depiler un element
PPile *Depiler(PPile *Mapile)
{
    PPile *SupElem;
    SupElem = Mapile;         // Stocker l'element a supprimer
    Mapile = Mapile->suivant; // Changer la tete de la pile
    free(SupElem);
    return ((PPile *)Mapile);
}

// Afficher la pile
void AffichePile(PPile *Mapile)
{
    // int val;
    PPile *P;
    P = (PPile *)malloc(sizeof(PPile));

    while (Mapile)
    {
        printf("%d", Mapile->val);
        P = Empiler(P, Mapile->val);
        Mapile = Depiler(Mapile);
    }

    while (P)
    {
        Empiler(Mapile, P->val);
        P = Depiler(P);
    }
}

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

PPile *Trie_Pile_File(Cellule *L, PPile *P)
{
    Cellule *ptr;
    PFile *F;
    F = InitFile();

    ptr = L;

    while (ptr)
    {
        if (P)
        {
            while (ptr->info > P->val)
            {
                F = Enfiler(F, P->val);
                P = Depiler(P);
            }
        }
        P = Empiler(P, ptr->info);
    }

    while (F)
    {
        if (F)
        {
            while (F->Debut > P->val)
            {
                F = Enfiler(F, P->val);
                P = Depiler(P);
            }
        }
        P = Empiler(P, F->Debut);
    }

    return ((PPile *)P);
}
