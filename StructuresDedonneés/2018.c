#include <stdio.h>
#include <stdlib.h>
#define RC '\n'
#define Max 50

//---------------Définition de la structure----------------------//

typedef struct
{
    int NbElem;
    int Tab[Max];
} Tableau;

int Tab_est_Vide(Tableau T)
{
    return ((int)T.NbElem == -1);
}

int Tab_est_saturee(Tableau T)
{
    return ((int)T.NbElem == Max - 1);
}

//----------------Insertion à la bonne place--------------------//

int Insert_Ordonee(Tableau *MonTableau, int value)
{
    int i, n;

    if (Tab_est_saturee(*MonTableau))
        return ((int)0);

    MonTableau->Tab[++MonTableau->NbElem] = value;

    for (i = MonTableau->NbElem; i > 0; i--)
    {
        if (MonTableau->Tab[i] < MonTableau->Tab[i - 1])
        {
            n = MonTableau->Tab[i - 1];
            MonTableau->Tab[i - 1] = MonTableau->Tab[i];
            MonTableau->Tab[i] = n;
        }
        else
        {
            return ((int)1);
        }
    }
    return ((int)1);
}

//----------------Insertion à la bonne place--------------------//

int Insert_Double(Tableau *MonTableau)
{
    if (Tab_est_Vide(MonTableau))
        return ((int)0);

    for (i = 0; i < MonTableau->NbElem; i++)
    {
        for (j = i + 1; i < MonTableau->NbElem; j++)
        {
            if ((MonTableau->Tab[j]) == (MonTableau->Tab[i] * 2))
            {
                n = MonTableau->Tab[j];
                for (x = j; x > i + 1; x++)
                {

                    MonTableau->Tab[x] = MonTableau[x - 1];
                }

                MonTableau[i + 1] = n;
            }
        }
    }

    return ((int)1);
}

// Exercice 2
//---------------Définition de la structure----------------------//

typedef struct Cellule
{
    int info;
    struct Cellule *suivant;
} Cellule;

//----------------Insertion à la bonne place--------------------//

Cellule *InsertOrdonee(Cellule *Liste, int value)
{
    if (!Liste)
    {
        Liste->info = value;
        Liste->suivant = NULL;
        return ((Cellule *)Liste);
    }

    Cellule *NE, *ptr;
    NE = (Cellule *)malloc(sizeof(Cellule));
    NE->info = value;
    // condition

    while (ptr)
    {
        if ((ptr->suivant->info) > value)
        {

            NE->suivant = ptr->suivant;
            ptr->suivant = NE;

            return ((Cellule *)Liste);
        }

        ptr = ptr->suivant;
    }

    ptr->suivant = NE;
    NE->suivant = NULL;
    return ((Cellule *)Liste);
}

//----------------Insertion à la bonne place--------------------//

Cellule *InsertDouble(Cellule *Liste)
{
    Cellule *ptr1, *ptr2, *tmp;
    while (ptr1)
    {
        ptr2 = ptr1;
        while (ptr2)
        {
            if ((ptr1->info * 2) == (ptr2->suivant)->info)
            {
                tmp = ptr2->suivant;
                ptr2->suivant = (ptr2->suivant)->suivant;
                tmp->suivant = ptr1->suivant;
                ptr1->suivant = tmp;
            }
        }
    }

    return ((Cellule *)Liste);
}
