#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//Définition de la liste
typedef struct liste
{
    int info;
    struct liste *suivant;//Pointeur sur l'élément suivant
} Cellule;

//Creation d'une cellule
Cellule *InitListe(int valeur)
{
    Cellule *NE;//creation d'un nouveau element
    NE=(Cellule *)malloc(sizeof(Cellule));//allocation dynamique de la memeoire
    if(!NE)
    {
        printf("\n Erreur d'allocation !");
        exit(0);
    }
    NE->info=valeur;//Affecter la valeur
    NE->suivant=NULL;

    return ((Cellule *)NE);//retourne la cellule
}

//La Taille d'une liste
int TailleListe(Cellule *liste)
{
    int count=0;
    Cellule *ptr;//declaration d'un pointeur
    ptr=liste;//pointeur sue la liste
    while(ptr)
    {
        ptr=ptr->suivant;//Pointer sur l'elemnt suivant
        count++;//Incrementer le compteur
    }
    return ((int)count);
}


//affichage de la liste
void AfficheListe(Cellule *liste)
{
    Cellule *ptr;//Pointer sur l'elemnt suivant
    ptr=liste;//pointeur sue la liste
    while(ptr)
    {
        printf("%d \t",ptr->info);
        ptr=ptr->suivant;//pointer sur l'elemnet suivant
    }
}

//Vider la liste
Cellule *ViderListe(Cellule *liste)
{
    Cellule *ptr;//declaration d'un pointeur

    while(liste)
    {
        ptr=liste;//pointeur sue la liste
        liste=liste->suivant;;//pointer sur l'elemnet suivant
        free(ptr);//liberre d'espace memoire
    }

    return ((Cellule *)NULL);
}

//Trier la liste

int *TrierListe(Cellule *liste)
{
    int change;
    Cellule *ptr1,*ptr2;//déclaration d'un poinetrur
    ptr1=ptr2=liste;//pointeur sue la liste

    while(ptr1)
    {
        ptr2=liste;//pointer sue la liste de base
        while(ptr2)//
        {
            if(ptr2->info > ptr1->info)//cas ou un elemnt est inférieur d'un elemnt suivant dans laliste
            {
                //change de place entre deux valeur
                change=ptr1->info;
                ptr1->info=ptr2->info;
                ptr2->info=change;

            }
            ptr2=ptr2->suivant;//elemnt suivant
        }
        ptr1=ptr1->suivant;//elemnt suivant
    }
    return ((int)1);
}

//insertion dans une liste debut d'une liste
Cellule *Insert(Cellule *liste,int value,int pos)
{
    //insertion au debut
    if(!liste)
    {
        liste->info=value;
        liste->suivant=NULL;
        return ((Cellule *)liste);
    }
    Cellule *ptr,*NE;
    NE=(Cellule *)malloc(sizeof(Cellule));
    int i=0;
    ptr=liste;

    //insertion au melieu
    while(ptr->suivant)
    {
        if(i==pos-1)
        {
            NE->info=value;
            NE->suivant=(ptr->suivant);
            ptr->suivant=NE;
            return ((Cellule *)NE);
        }
        i++;
        ptr=ptr->suivant;
    }
   //insertion a la fin
    NE->info=value;
    NE->suivant=NULL;
    ptr->suivant=NE;
    return ((Cellule *)NE);


}
Cellule *SppElem(Cellule *liste,int pos)
{
    Cellule *ptr;
    ptr=liste;
    int i=0;
    while(ptr)
    {
        if(pos==i+1)
        {
            ptr->suivant=(ptr->suivant)->suivant;
        }
        i++;
        ptr=ptr->suivant;
    }
}


int main()
{


    int choix,n,pos;
    Cellule *liste,*elm2;
    int Taille;
    liste=(Cellule *)malloc(sizeof(Cellule));

    do
    {
        printf("\n-------------------------------------Entrez votre choix :-------------------------------------\n\n\n");
        printf("Initialiser la liste avec une valeur-------------------------------------------------1 \n");
        printf("insérer un élément dans la liste ----------------------------------------------------2 \n");
        printf("supprimer un élément dans la liste --------------------------------------------------3 \n");
        printf("afficher la taille de la liste ------------------------------------------------------4\n");
        printf("afficher  la liste ------------------------------------------------------------------5\n");
        printf("Trie la liste   ---------------------------------------------------------------------6\n");
        printf("Quiter le programme -----------------------------------------------------------------0\n");

        scanf("%d",&choix);

        switch(choix)
        {
        case 1:

            printf("Entrez la valeur pour initialiser la liste :\n");
            scanf("%d",&n);
            liste=InitListe(n);
            printf("Inisialisation effuctué :\n");

            break;
        case 2:
            printf("entrez une valeur a insirer :\n");
            scanf("%d",&n);
            printf("entrez la position");
            scanf("%d",&pos);
            Insert(liste,n,pos);
            printf("Insertion effuctué :\n");

            break;
        case 3:
            printf("entrez la position");
            scanf("%d",&pos);
            SppElem(liste,pos);
            printf("Opération effuctué :\n");
            break;
        case 4:
            n=TailleListe(liste);
            printf("Taille de la liste : %d\n",n);

            break;

        case 5:
            printf("Affichage des élémnets :\n");
            AfficheListe(liste);
            break;
        case 6:
            TrierListe(liste);
            printf("Opération effuctué :\n");
            break;
        default :
            printf("choix incorrecte ! \n");
        }
    }
    while(choix!=0);














//
//    liste=InitListe(5);
//    AfficheListe(liste);
//    Taille=TailleListe(liste);
//    printf("\t %d",Taille);
//    //ViderListe(liste);
//    Insert(liste,10,1);
//    Insert(liste,145,1);
//    Insert(liste,136,1);
//    Insert(liste,130,1);
//    Insert(liste,101,100);
//
//    printf("\n");
//
//
//    AfficheListe(liste);
//    // SppElem(liste,5);
//    printf("\n");
//
//    TrierListe(liste);
//    AfficheListe(liste);


    return 0;
}
