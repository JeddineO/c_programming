#include <stdio.h>
#include <stdlib.h>
#define Max 40

//D�finition de la structure

typedef struct
{
    int Tab[Max];
    int sommet;
} TPile;

//Initialisation de la pile

TPile *InitPile()
{
    TPile *pile;
    pile=(TPile *)malloc(sizeof(TPile));
    if(!pile)
    {
        printf("\n Erreur d'allocation ");
        exit(0);
    }
    pile->sommet=-1;
    return ((TPile *)pile);
}

//Pile est pliene

int PileSaturee(TPile MaPile)
{
    if(MaPile.sommet=Max-1)return ((int)1);
    return ((int)0);
}

//Empiler

int Empiler(TPile *Mapile,int valeur)
{
    Mapile->Tab[++Mapile->sommet]=valeur;
    return ((int)1);
}

//D�piler

int Depile(TPile *Mapile)
{
    --Mapile->sommet;
    return ((int)1);
}

//Afficher

void AfficherPile(TPile MaPile)
{
    int indice;
    for(indice=MaPile.sommet; indice>=0; indice--)
        printf("%d\t",MaPile.Tab[indice]);

}


int main()
{

    TPile *P;
    int choix,n;

    do
    {
        printf("\n-------------------------------------Entrez votre choix :-------------------------------------\n\n\n");
        printf("Initialiser la pile-------------------------------------------------1 \n");
        printf("ins�rer un �l�ment dans la pile (empiler)---------------------------2 \n");
        printf("supprimer un �l�ment dans la pile (d�piler)-------------------------3 \n");
        printf("afficher la pile ---------------------------------------------------4\n");
        printf("Quiter le programme ------------------------------------------------5\n");
        scanf("%d",&choix);

        switch(choix)
        {
        case 1:
            P=InitPile();
            printf("La pile est bien initialiser\n");

            break;
        case 2:
            printf("entrez une valeur a insirer :\n");
            scanf("%d",&n);
            Empiler(P,n);
            printf("Inisialisation effuctu� :\n");

            break;
        case 3:
            Depile(P);
            printf("Op�ration effuctu� :\n");

            break;
        case 4:
            printf("Affichage des �l�mnets :\n");
            AfficherPile(*P);
            break;
        default :
            printf("choix incorrecte ! \n");
        }
    }while(choix!=0);



    return 0;
}
