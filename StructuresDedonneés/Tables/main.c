#include <stdio.h>
#include <stdlib.h>
#define NbElem 25

//Définition de la structure d'un tableau

typedef struct
{
    int Tab[NbElem];
    int IdElem;//Indice du dernier element du tableau
}MaTable;

//Fonction d'initialisation d'un tableau

int InitTab(MaTable *MonTableau)
{
    if(!MonTableau)return((int)0);
    MonTableau->IdElem=-1;//Dire que le tableau est vide
    return (int)1;
}
 //Fonction verifier que le tabeau est vide ou non

 int TabVide(MaTable MonTableau)
 {
     if(MonTableau.IdElem==-1)return((int)1);
     return ((int)-1);
 }

//

int TabSaturee(MaTable MonTableau)
{
    if(MonTableau.IdElem==NbElem)return((int)1);
    return ((int)0);
}

//Function d'insertion dans un tableau

int InsertTab(MaTable *MonTableau,int entier)
{
    //Vérifier que la zone memoire est resirver
    if(!MonTableau)return ((int)-1);
    //Verifier que le tableau n'est pas saturée
    if(TabSaturee(*MonTableau))return ((int)0);
    //Insertion dans le tableau
    MonTableau->Tab[++MonTableau->IdElem]=entier;
    return ((int)1);
}

//Fonction d'insersion dans un indice donné

int InsertPos(MaTable *MonTableau,int entier,int pos)
{
    int i;
    //Vérifier que la zone memoire est resirver
    if(!MonTableau)return ((int)-1);
    //Verifier que le tableau n'est pas saturée
    if(TabSaturee(*MonTableau))return ((int)0);
    //Verifier que la position ne depassse pas la taille du tableu
    if(MonTableau->IdElem<pos)return ((int)2);
    //Tasser les element du tableau
    for(i=MonTableau->IdElem;i<pos;i--)
    {
        MonTableau->Tab[i]=MonTableau->Tab[i+1];
    }
    //Affecter la varible à l'indice donnée
     MonTableau->Tab[pos]=entier;
     //Incrementer la taille du tableau
     MonTableau->IdElem++;

     return ((int)1);
}




//Supression d'un élément d'indice donné


int SupElem(MaTable *MonTableau,int pos)
{
    int i;
    //Vérifier que la zone memoire est resirver
    if(!MonTableau)return ((int)-1);
        //Verifier que la position ne depassse pas la taille du tableu
    if(MonTableau->IdElem<pos)return ((int)2);
    //Tasser les element du tableau
    for(i=pos ;i<MonTableau->IdElem;i++)
        MonTableau->Tab[i]=MonTableau->Tab[i+1];


       MonTableau->IdElem--;

    return ((int)1);
}


//Fonction pour supprimer tous les occurence d'un élément dans un tableau

int SupOcur(MaTable *MonTableau,int occu)
{
    int indice;
    for(indice=0;indice<=MonTableau->IdElem;indice++)
    {
        if(MonTableau->Tab[indice]==occu) SupElem(MonTableau,indice);
    }
}


//Insertion dans un tableau ordonné

int InsertOrdTab(MaTable *MonTableau,int entier)
{
    int i=0;
    //Vérifier que la zone memoire est resirver
    if(!MonTableau)return ((int)-1);
    //Verifier que le tableau n'est pas saturée
    if(TabSaturee(*MonTableau))return ((int)0);
    //chercher l'indice de l'insertion
    while(MonTableau->Tab[i++]<entier);

    InsertPos(MonTableau,entier,i);

    return ((int)1);

}


//Recherche dans un tableau ordonné

int RechercheTab(MaTable MonTableau,int entier)
{
    int i,n=0;
    for(i=0;i<=MonTableau.IdElem;i++)
    {
        if(MonTableau.Tab[i]==entier)n=1;
    }
    return ((int)n);
}



int main()
{
    printf("Les Tableau!\n");
    return 0;
}
