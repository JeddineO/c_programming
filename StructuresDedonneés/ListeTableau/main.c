#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define Max 40


//deinition du tableau
typedef struct
{
    int Ltab[Max];
    int NbE;
}Tliste;

//Initialisation de la liste

Tliste *InitListe()
{
    Tliste *MaListe;
    MaListe=(Tliste *)malloc(sizeof(Tliste));
    if(!MaListe)
    {
        printf("\n Erreur d'allocation");
        exit(0);
    }
    return ((Tliste *)MaListe);
}

//Verifier que la liste n'est pas saturée

int ListSaturee(Tliste MaListe)
{
    if((MaListe.NbE)==Max-1) return((int)1);
    return ((int)0);
}

//Insertion dans la liste

int InsetTListe(Tliste *MaListe,int valeur,int pos)
{
    if(!MaListe) return ((int)-1);
    if(ListSaturee(*MaListe)) return((int)0);
    if(0>pos|| pos>MaListe->NbE) return ((int)-2);

    int indice;
    for(indice=(MaListe->NbE);indice>=pos;indice--)
        MaListe->Ltab[indice+1]=MaListe->Ltab[indice];
    MaListe->NbE++;

    MaListe->Ltab[pos]=valeur;

    return ((int)1);

}

//Suppression des elemnts


int SuppElem(Tliste *Maliste,int pos)
{
    int indice;
    if(!Maliste) return ((int)-1);
    if(0>pos|| pos>Maliste->NbE) return ((int)-2);
    for(indice=pos;indice<Maliste->NbE;indice++)
        Maliste->Ltab[indice]  = Maliste->Ltab[indice+1];

    Maliste->NbE--;
    return ((int)1);

}

//Affichage de la liste

void AfficheListe(Tliste Maliste)
{

}
int main()
{
    printf("Hello world!\n");
    return 0;
}
