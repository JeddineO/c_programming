#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


//Les listes à l'aide des pointeur

//Définition de la structure
typedef struct liste
{
    int info;
    struct list *suivant;
}Liste;
//Insertion au début d'une liste
Liste *InsertDebut(Liste *MaListe,int val)
{
    Liste *NE;
    NE=(Liste *)malloc(sizeof(Liste));
    if(!NE)
    {
        printf("\n Erreur d'allocation ");
        exit(0);
    }
    NE->info=val;
    NE->suivant=MaListe;
    return ((Liste *)MaListe);

}
//Inserrtion a la fin
Liste *InsertFin(Liste *MaListe,int val)
{
    Liste *NE,*ptr;
    NE=(Liste *)malloc(sizeof(Liste));
    if(!NE)
    {
        printf("\n Erreur d'allocation ");
        exit(0);
    }
    ptr=MaListe;

    NE->info=val;
    NE->suivant=NULL;

    while(ptr)
    {
        ptr=ptr->suivant;
    }
    ptr->suivant=NE;

    return ((Liste *) MaListe);

}
//Insertion a une position donnée

Liste *InsertPos(Liste *MaListe,int val,int pos)
{
    int indice=0;
    Liste *NE,*ptr;
    NE=(Liste *)malloc(sizeof(Liste));
    if(!NE)
    {
        printf("\n Erreur d'allocation ");
        exit(0);
    }
    ptr=MaListe;
    if(!MaListe)
    {
        InsertDebut(MaListe,val);
    }
    while(ptr)
    {
        if((indice+1)==pos)
        {
            NE->info=val;
            ptr->suivant=NE;
            NE->suivant=ptr;
            return((Liste *)MaListe);
        }
    }

    InsertFin(MaListe,val);

}

//Suprimer un element de la liste

Liste *SuppElem(Liste *MaListe,int pos)
{
    int indice;
    Liste *ptr,*SuppElem;
    ptr=MaListe;
    if(MaListe)
    {
        printf("La liste est vide ");
        exit(0);
    }

    while(ptr)
    {
        if((indice+1)==pos)
        {
            SuppElem=ptr->suivant;
            ptr->suivant=SuppElem->suivant;
            return ((Liste *)MaListe);
        }
    }
}

int AfficherListe(Liste MaListe)
{
    Liste *ptr;
    ptr=&MaListe;
    if(!ptr) return ((int)0);
    while(ptr)
    {
        printf("%d\t",ptr->info);
    }
    return ((int)1);
}




int main()
{
    printf("Hello world!\n");
    return 0;
}

