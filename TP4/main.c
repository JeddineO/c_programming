#include <stdio.h>
#include <stdlib.h>
#define N 24

typedef struct
{
    char nom[10];
    float a;
}Module;

typedef struct
{
    char nom[20];
    char prenom[30];
    char cne[10];
    Module Md[15];
    float Moyenne_Annee;
    int reserve;
}Etudiant;

void lire(char tab[N])
{
    char c;
    int i=0;
    while((c=getchar())!='\n')
    {
        tab[i]=c;
        i++;
    }
    tab[i]='\0';

}

int main()
{
    Etudiant Etud[47][3];
    printf("Entrez le nom du module : ");
    lire(Etud[0][0].Md[0].nom);
    printf("Entrez la note du module : ");
    scanf("%f",&Etud[0][0].Md[0].a);
    printf("\n%s : %f",Etud[0][0].Md[0].nom,Etud[0][0].Md[0].a);
    return 0;
}
