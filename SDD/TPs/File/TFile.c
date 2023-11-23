#include<stdio.h>
#include<stdlib.h>
// Declaration des constantes
#define NbElem 30 // Taille maximale des tableaux
// Definition de la structure
typedef struct
{
    int info[NbElem]; // Tableau des elements
    int Tete, Queue;
}TFile;

// 1- Initialiser la file
int InitTFile(TFile *file)
{
    if (!file) return ((int)0); // test si la file existe
    file->Tete = file->Queue = -1;
    return ((int)1);
}
// 2- s'avoir si la file est vide
int EstVide(TFile *file)
{
    if (!file) return ((int)-1); // test si la file existe
    if ((file->Tete == -1) && (file->Queue == -1))
        return ((int)1);
    return ((int)0);
}
// 3- s'avoir si la file est saturee
int EstSaturee(TFile *file)
{
    if (!file) return ((int)-1); // test si la file existe
    return ((int)(file->Queue == (NbElem-1)));
}
// 4- la taille de la liste
int TailleTFile(TFile *file)
{
    if (!file) return ((int)-1); // test si la file existe
    if (EstVide(file)) return ((int)0);
    return ((int)(file->Queue - file->Tete +1));
}
// 5- Tasser les elements de la file
int TasserTFile(TFile *file)
{
    int i, taille;
    if (!file) return ((int)-1); // test si la file existe
    if (EstSaturee(file)) return ((int)0);
    taille = TailleTFile(file);
    for (i = 0; i < taille; i++)    file->info[i] = file->info[i+file->Tete];
    file->Tete = 0;
    file->Queue = taille-1;
    return ((int)1);
}
// 6- Inserer un eleement en queue de la file
int EmfilerTFile(TFile *file, int val)
{
    int t;
    if (!file) return ((int)-1); // test si la file existe
    if (EstSaturee(file)) return ((int)0);
    if (file->Queue == (NbElem-1))    t = TasserTFile(file);
    if (EstVide(file)) file->Tete++;
    file->info[++file->Queue] = val;
    return ((int)1);
}
// 7- Supprimer un element en tete de la file
int DefilerTFile(TFile *file)
{
    if (!file) return ((int)-1); // test si la file existe
    if (EstVide(file)) return ((int)0); // test si la file est vide
    file->Tete++;
    return ((int)1);
}
// 8- Afficher la file
void AfficherTFile(TFile *file)
{
    int rt;
    TFile tmp;
    rt = InitTFile(&tmp);
    if (!file) // tester si la file existe
    {
        printf("\nFile inexiste!");
        exit(0);
    }
    if (EstVide(file)) printf("\nLa file est vide");
    else
    {
        printf("\nFile : ");
        while (file->Tete <= file->Queue)
        {
            printf("%d\t",file->info[file->Tete]);
            rt = EmfilerTFile(&tmp,file->info[file->Tete]);
            rt = DefilerTFile(file);
        }
        *file = tmp;
    }
}
// 9- Vider la file
int ViderTFile(TFile *file)
{
    if (!file) return ((int)-1); // tester si la file existe
   // if (EstVide(file)) return ((int)0); // tester si la file est vide
    file->Tete = -1; 
    file->Queue = -1;
    return ((int)1);
}
// 10- Chercher un element dans la file
int RechercheTFile(TFile *file, int val)
{
    int i;
    if (!file) return((int)-1); // tester si la file existe
    if (EstVide(file)) return ((int)-2); // tester si la file est vide
    i = file->Tete;
    while (i <= file->Queue)
        if (file->info[i++] == val) return ((int)(i-1));
    return ((int)-3); // element non trouve
    
}

void main()
{
    TFile file;
    int r,a;
    r = InitTFile(&file);
    if (r==1) printf("\nInitialisation evec success");
    else printf("\nIitialisation echouee!!");
    r = EmfilerTFile(&file,13);
    r = EmfilerTFile(&file,14);
    r = EmfilerTFile(&file,15);
    r = EmfilerTFile(&file,16);
    AfficherTFile(&file);
    printf("\nLa taille de la file : %d",TailleTFile(&file));
    a = 16; r =RechercheTFile(&file,a);
    if (r == -1) printf("\nFile non existe");
    else if (r == -2) printf("\nFile vide");
    else if (r == -3) printf("\n%d n'existe pas dans la file",a);
    else printf("\nLa position de %d est : %d",a,r);
    DefilerTFile(&file);
    printf("\nDefillement effectue");
    AfficherTFile(&file);
}