#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Cellule
{
    int elem;
    struct Cellule *suivant;
    struct Cellule *precedent;
} Cellule;

void echange(int *a,int *b)
{
    int aux;

    aux=*a;
    *a=*b;
    *b=aux;
}

Cellule *Init_liste(int a)
{
    Cellule *NE;
    NE=(Cellule *)malloc(sizeof(Cellule));
    if(!NE)
    {
        printf("Erreur d'alocation !");
        exit(0);
    }
    NE->elem=a;
    NE->precedent=NULL;
    NE->suivant=NULL;
    return ((Cellule *)NE);
}



Cellule *InsertCel(Cellule *Liste,int val)
{
    Cellule *NE,*ptr;
    ptr=Liste;
    NE=Init_liste(val);
    if(!Liste)
    {
        return((Cellule *)NE);
    }
    while(ptr->suivant)ptr=ptr->suivant;

    ptr->suivant=NE;
    NE->precedent=ptr;

    return ((Cellule *)Liste);

}

void affiche(Cellule *Liste)
{
    Cellule *ptr;
    ptr=Liste;
    while(ptr)
    {
        printf("%d\t",ptr->elem);
        ptr=ptr->suivant;
    }
}
Cellule *dernier(Cellule *Liste)
{
    Cellule *ptr;
    ptr=Liste;
    while(ptr->suivant)ptr=ptr->suivant;
    return ((Cellule *)ptr);
}
Cellule *triABullesPoint(Cellule *liste)
{
    Cellule *crt1,
            *crt2,
            *dernierElem;
    int trie=0;

    while(!trie)
    {
        trie=1;
        dernierElem=dernier(liste);
///la position où on s'arrête.
        for(crt1=dernierElem; crt1->precedent; crt1=crt1->precedent)
        {
///on parcours la table.
            for(crt2=liste; crt2!=crt1; crt2=crt2->suivant)
///si l'element est sup à son successeur.
                if(crt2->elem>crt2->suivant->elem)
                {
///on échange et on met tri à 0.
                    echange(&crt2->elem,&crt2->suivant->elem);
                    trie=0;
                }
        }///fin for.

    }///fin while(!trie).
    return (Cellule*)liste;
}


Cellule *triInsertPoint(Cellule *liste)
{
    Cellule *crt1,
            *crt2;
///on commence le tri.
    for(crt1=liste->suivant; crt1; crt1=crt1->suivant)
    {
        crt2=crt1;
///tant que l'élément est inf à son précedeur.
        while(crt2->elem<crt2->precedent->elem)
        {
///on les échange.
            echange(&crt2->elem,&crt2->precedent->elem);
            crt2=crt2->precedent;
            if(!crt2->precedent) break;
        }
    }
    return (Cellule*)liste;
}

Cellule *emp_min_point(Cellule *lst)
{
    Cellule *crt,//pour le parcour
            *min;//pour garder le min
    min=lst;//initialisation
//recherche du min
    for(crt=lst->suivant; crt; crt=crt->suivant)
    {
        if((crt->elem)<(min->elem)) min=crt;
    }
    return (Cellule *)min;

}

Cellule *tri_par_selection_point(Cellule *liste)
{
    Cellule *crt,//pour le parcour
            *min;//pour garder le min
    int tmp;//pour l'echange
    for(crt=liste; crt; crt=crt->suivant)
    {
        min=emp_min_point(crt);
        if(min!=crt)
        {
            tmp=min->elem;
            min->elem=crt->elem;
            crt->elem=tmp;
        }
    }
    return (Cellule*)liste;
}

int main()
{
    Cellule *Liste;
    Liste=Init_liste(3);
    Liste=InsertCel(Liste,1);
    Liste=InsertCel(Liste,10);
    Liste=InsertCel(Liste,7);
    Liste=InsertCel(Liste,3);
    Liste=InsertCel(Liste,21);
    affiche(Liste);
    printf("\nTrie isnsersion \n");


    Liste=triInsertPoint(Liste);
    Liste=Init_liste(3);
    Liste=InsertCel(Liste,1);
    Liste=InsertCel(Liste,10);
    Liste=InsertCel(Liste,7);
    Liste=InsertCel(Liste,3);
    Liste=InsertCel(Liste,21);
    affiche(Liste);
    printf("\nTri selection \n");
    Liste=tri_par_selection_point(Liste);
    Liste=Init_liste(3);
    Liste=InsertCel(Liste,1);
    Liste=InsertCel(Liste,10);
    Liste=InsertCel(Liste,7);
    Liste=InsertCel(Liste,3);
    Liste=InsertCel(Liste,21);
    affiche(Liste);
    printf("\nTrie bulles\n");
    Liste=triABullesPoint(Liste);
    affiche(Liste);
    return 0;
}
