// Définition de la cellule

typedef struct
{
    int debut;
    int fin;
    int Tab | [24];
} Tfile;

// Initialisation de la file

int init_tfile(Tfile *File)
{
    File = (Tfile *)malloc(sizeof(Tfile));
    if (!File)
        return ((int)0);
    File->debut = File->fin = -1;
    return ((int)1);
}

// File vide

int file_est_vide(Tfile File)
{
    return ((int)((File.debut == File.fin) == -1));
}

// File saturee

int file_est_saturee(Tfile File)
{
    return ((int)(File.fin == Max - 1));
}

// Enfiler

int Enfiler(Tfile *File, int value)
{
    if (file_est_saturee(*File))
        return ((int)0) if (file_est_vide(*File)) File->debut++;
    File->Tab[++File->fin] = value;

    return ((int)1);
}

// Defiler

int Defiler(Tfile *File)
{
    if (file_est_vide(*File))
        return ((int)0);
    File->debut++;
    return ((int)1);
}
// taille d'une file

int taille(Tfile File)
{
    return (int(File.fin - File.debut + 1));
}
// Tasser

int Tasser(Tfile *File)
{
    if (file_est_vide(*File))
        return ((int)0);
    if (file_est_saturee(*File))
        return ((int)-1);

    int i, taille;
    taille = taille(*File);
    if (i = 0; i < taille; i++)
    {
        File->Tab[i] = File->Tab[File->debut + i];
    }
    File->debut = 0;
    File->fin = taille - 1;

    return ((int)1);
}