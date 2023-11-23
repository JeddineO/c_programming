#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


//definition de la structure
typedef struct pile
{
    int val;
    struct pile *suivant;
}PPile;
//Creation et initialistaion de la liste
PPile *InitPPlie(int valeur)
{
    //Creation d'un nouveau element
    PPile *NE;
    NE=(PPile *)malloc(sizeof(PPile));
    if(!NE)
    {
        printf("\n Erreur d'allocation ");
        exit(0);
    }
    NE->val=valeur;//Donnez la valeur
    NE->suivant=NULL;

    return ((PPile *)NE);
}

//Empiler un element
PPile *Empiler(PPile *MaPile,int elem)
{
    PPile *NE;
    NE=InitPPlie(elem);//Creer un element
    NE->suivant=MaPile;//Pointer su le premier element de la pile
    MaPile=NE;//Donner l'element a la tete de la pile
    return ((PPile *)MaPile);
}
//Depiler un element
PPile *Depiler(PPile *Mapile)
{
    PPile *SupElem;
    SupElem=Mapile;//Stocker l'element a supprimer
    Mapile=Mapile->suivant;//Changer la tete de la pile
    free(SupElem);
    return ((PPile *)Mapile);
}


//Afficher la pile
void AffichePile(PPile *Mapile)
{
   // int val;
    PPile *P;
    P=(PPile *)malloc(sizeof(PPile));

    while(Mapile)
    {
        printf("%d",Mapile->val);
        P=Empiler(P,Mapile->val);
        Mapile=Depiler(Mapile);

    }

    while(P)
    {
        Empiler(Mapile,P->val);
        P=Depiler(P);
    }
}
int main()
{
    PPile *P;

    P=InitPPlie(2);
    P=Empiler(P,1);
    P=Empiler(P,1);
    P=Empiler(P,9);

    AffichePile(P);
    printf("\n");
    AffichePile(P);
    AffichePile(P);
    AffichePile(P);
    return 0;
}
