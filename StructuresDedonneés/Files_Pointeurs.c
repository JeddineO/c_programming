// Déinition de la cellule

typedef struct Cellule
{
    int info;
    struct Cellule *suivant;
} Cellule;

// Définition de la file

typedef struct
{
    Cellule *Debut;
    Cellule *Fin;
} PFile;

// Initialisation de la file

PFile *init_File(PFile *File)
{
    File->Debut = File->Fin = NULL;
    return ((PFile *)File);
}

// Create file

PFile *Create(PFile *File)
{
    File = (PFile *)malloc(sizeof(PFile));
    if (!PFile)
    {
        printf("Erreur d'allocation ");
        exit(0);
    }
    File = init
        _File(File);

    return ((PFile *)File);
}

// Create Cellule

Cellule *Create_Cellule(int valeur)
{
    Cellule *NE;
    NE = (Cellule *)malloc(sizeof(Cellule));
    if (!NE)
    {
        printf("\n Erreur d'allocation");
        exit(0);
    }
    NE->info = valeur;
    NE->suivant = NULL;

    return ((Cellule *)NE);
}

// File est vide

int File_est_vide(PFile File)
{
    if ((File.Debut == NULL) && (File.Fin == NULL))
        return ((int)1);
    return ((int)0);
}

// Enfiler

int Enfiler(PFile *File, int valeur)
{
    Cellule *NE;
    NE = Create_Cellule(valeur);

    if (!File)
        return ((int)-1);

    if (File_est_vide(File))
    {
        File->Fin = File->Debut = NE;
    }
    else
    {
        File->Fin->suivant = NE;
    }

    return ((int)1);
}

// Defile

int Defiler(PFile *File)
{
    PFile Supp;
    if (!File)
        return ((int)-1);
    if (File_est_vide(*File))
        return ((int)0);
    if (File->Debut == File->Fin)
    {
        Free(File);
    }
    else
    {
        Supp = File->Debut;
        File->Debut = File->Debut->suivant;
        free(Supp);
    }

    return ((int)1);
}

// Affichage de la file

void affiche_file(PFile *File)
{
    PFile *tmp;
    while (File_est_vide(File))
    {
        printf("%d"; File->Debut->info);
        Enfiler(tmp, File->Debut->info);
        Defiler(File);
    }
    while (tmp)
    {
        Enfiler(File, tmp->Debut->info);
        Defiler(tmp);
    }
}

// triee une liste
