#include<stdio.h>
#include<stdlib.h>
// Definition des structures
typedef struct File
{
    int info; 
    struct File *suivant; // Pointeur vers l'element suivant
}Cellule;
typedef struct 
{
    Cellule *Tete, *Queue; // pointeur tete et queue de la file
}PFile;

// 1- Creer une file
PFile *CreerPFile()
{
    PFile *PF;
    PF = (PFile *)malloc(sizeof(PFile));
    if (!PF)
    {   // Erreur d'allocation de la memoire
        printf("\nErreur d'allocation de la memoire!");
        exit(0);
    }
    PF->Tete = NULL;
    PF->Queue = NULL;
    return ((PFile *)PF);
}
// 2- Creer une cellule de la file
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
// 3- s'avoir si la file est vide
int EstVide(PFile *file)
{
    if (!file) return ((int)-1); // tester si la file existe
    return ((int)(!file->Tete && !file->Queue));
}
// 4- Inserer un element en queue de la file
int EmfilerPFile(PFile *file, int val)
{
    Cellule *CL;
    if (!file) return ((int)-1); // tester si la file existe
    CL = CreerCellule(val); // creer l'element
    if (!file->Tete) file->Tete = CL;
    else file->Queue->suivant = CL;
    file->Queue = CL;    
    return ((int)1);
}
// 5- Supprimer un element en tete de la file
int DefilerPFile(PFile *file)
{
    Cellule *Supp;
    if (!file) return ((int)-1); // tester si la file existe
    if (!file->Tete) return ((int)0); // tester si la file est vide
    Supp = file->Tete; // pointer sur la tete de la file
    file->Tete = file->Tete->suivant; // affecter au tete l'element suivant
    if (!file->Tete) file->Queue = NULL;
    free(Supp); // liberer la memoire
    return ((int)1);
}
// 6- la taille de la file
int TaillePFile(PFile *file)
{
    int taille = 0;
    Cellule *DCL; // pour memoriser la derniere cellule
    if (!file) return ((int)-1); // tester si la file existe
    if (EstVide(file)) return ((int)0); // si la file est vide
    DCL = file->Queue;
    while (file->Tete != DCL)
    {
        taille++;
        EmfilerPFile(file,file->Tete->info);
        DefilerPFile(file);
    }
    EmfilerPFile(file,file->Tete->info);
    DefilerPFile(file);
    return ((int)++taille);
}
// 7- Vider une file
int ViderPFile(PFile *file)
{
    int d;
    if (!file) return ((int)-1); // tester si la file existe
   // if (EstVide(file)) return ((int)0); // tester si la file est vide
    while (file->Tete)    d = DefilerPFile(file);
    return ((int)1);
}
// 8- Afficher la file
void AfficherPFile(PFile *file)
{
    int i, taille = TaillePFile(file);
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
            EmfilerPFile(file,file->Tete->info);
            DefilerPFile(file);
        }
    }
}
// 9- Chercher un element dans la file
int RecherchePFile(PFile *file, int val)
{
    int i, taille = TaillePFile(file), pos = 0;
    if (!file) return ((int)-1); // tester si la file existe
    if (EstVide(file)) return ((int)-2); // tester si la file est vide
    for (i = 0; i < taille; i++)
    {   // on memorise la premiere occurence de l'element
        if ((file->Tete->info == val) && pos==0) pos = i+1;
        EmfilerPFile(file,file->Tete->info);
        DefilerPFile(file);
    }
    return ((int)pos); // retourne la position de l'element s'il existe, 0 sinon
}
int Enfiler_File_Ordonnee(PFile *file, int val)
{
    int rt;
    Cellule *ptr;
    if (!file) return ((int)-1);
    if (!file->Tete) rt = EmfilerPFile(file,val);
    else if (val >= file->Queue->info) rt = EmfilerPFile(file,val);
    else
    {
        ptr = file->Queue;
        while (file->Tete->info < val)
        {
            rt = EmfilerPFile(file,file->Tete->info);
            rt = DefilerPFile(file);
        }
        rt = EmfilerPFile(file,val);
        while (file->Tete != ptr)
        {
            rt = EmfilerPFile(file,file->Tete->info);
            rt = DefilerPFile(file);
        }
        rt = EmfilerPFile(file,file->Tete->info);
        rt = DefilerPFile(file);
    }
    return ((int)1);   
}

void main()
{
    PFile *file = CreerPFile();
    PFile *file_o = CreerPFile();
    int a, r;
    r = EmfilerPFile(file,10);
    r = EmfilerPFile(file,11);
    r = EmfilerPFile(file,12);
    r = EmfilerPFile(file,13);
    r = EmfilerPFile(file,12);
    AfficherPFile(file);
    printf("\nTaille de la file: %d", TaillePFile(file));
    a = 12; r =RecherchePFile(file,a);
    if (r == -1) printf("\nFile non existe");
    else if (r == -2) printf("\nFile vide");
    else if (r == 0) printf("\n%d n'existe pas dans la file",a);
    else printf("\nLa position de %d est : %d",a,r);
    r = DefilerPFile(file);
    printf("\nUn defillement effectue");
    AfficherPFile(file);
    printf("\n*********************");
    r = Enfiler_File_Ordonnee(file_o,12);
    r = Enfiler_File_Ordonnee(file_o,10);
    r = Enfiler_File_Ordonnee(file_o,13);
    r = Enfiler_File_Ordonnee(file_o,2);
    r = Enfiler_File_Ordonnee(file_o,5);
    r = Enfiler_File_Ordonnee(file_o,7);
    AfficherPFile(file_o);
}