#include <stdio.h>
#include <stdlib.h>
#define Max 50
// Définition de la structure
typedef struct
{
    int Infos[Max]; // table des info
    int Exist[Max]; // table pour savoir si la case est vide ou non
} TArbre;

/*
Nom Fonction :Init_Arbre
Entrée : Rien(Procedure)
Sortie : structure d'arbre static initialiser
Description : la fonction initialise notre arbre
*/
TArbre *Init_Arbre()
{
    int i;                                 // indice pour parcourir le tableau
    TArbre *TA;                            // La structure a retourner
    TA = (TArbre *)malloc(sizeof(TArbre)); // Allocation de la mémoire
    if (!TA)
    {
        // Verifier l'allocation est ce qu'il a été bien effectuer
        printf("\nErreur d'allocation ");
        exit(0);
    }
    // Initialiser tous les cellule de  tableaux à 0
    for (i = 0; i < Max; i++)
        TA->Exist[i] = 0;

    return ((TArbre *)TA); // Retourne l'arbre
}

/*
Nom Fonction :arbre_est_vide
Entrée : Structure d'Arbre
Sortie : 1 si l'arbre est vide,sinon 0
Description : verifier si l'arbre est vide
*/
int arbre_est_vide(TArbre TA)
{
    return ((int)TA.Exist[0] == 0);
}

/*
Nom Fonction :Insert_Arbre
Entrée : L'arbre et la valeur à inserer
Sortie : O en cas d'echec d'insertion, sinon 1
Description : la fonction d'insertion d'un élément dans l'arbre
*/
int Insert_Arbre(TArbre *TA, int value)
{
    int indice, i = 0;

    // Si l'arbre est vide on insere dans la premiere case
    if (arbre_est_vide(*TA))
    {
        TA->Infos[0] = value;
        TA->Exist[0] = 1;
        return ((int)1);
    }

    // L'arbre n'est pas vide
    // tanque l'indice inferieur à la taille du tableau
    while ((i < Max))
    {
        // si la case du fils droit est vide on fait l'insertion
        if (TA->Exist[2 * i + 1] == 0)
        {
            TA->Infos[2 * i + 1] = value;
            TA->Exist[2 * i + 1] = 1;
            return ((int)1);
        }

        // si la case du fils gauche est vide on fait l'insertion
        if (TA->Exist[2 * i + 2] == 0)
        {
            TA->Infos[2 * i + 2] = value;
            TA->Exist[2 * i + 2] = 1;
            return ((int)1);
        }

        // charche la sous arbre convenable pour l'insertion

        if (TA->Infos[2 * i + 1] > value)
            i = (2 * i) + 1;
        else
            i = (2 * i) + 2;
    }

    return ((int)0); // L'insertion n'est pas effectuer
}

/*
Nom Fonction :Vider_Arbre
Entrée : L'arbre et la valeur à vider
Sortie : O si l'arbre est déja vide, sinon 1
Description : la fonction pour détruire l'arbre
*/
int Vider_Arbre(TArbre *TA)
{
    int i; // variable pour parcourir le tableau
    // cas d'un arbre vide
    if (arbre_est_vide(*TA))
        return ((int)0);
    // mettre tous les case à 0
    for (i = 0; i < Max; i++)
        TA->Exist[i] = 0;
    // retourne 1
    return ((int)1)
}

/*
Nom Fonction :Supp_Val_Arbre
Entrée : L'arbre et la valeur à supprimer
Sortie : O en cas d'echec d'insertion, sinon 1
Description : la fonction de suppression d'un élément dans l'arbre
*/
int Supp_Val_Arbre(TArbre *TA, int value)
{
    int i, j;
    for (i = 0; i < Max; i++)
    {
        if (TA->Infos[i] = value)
        {
            if (!TA->Exist[2 * i + 1] && !TA->Exist[2 * i + 1])
                TA->Exist[i] = 0;
            else
            {
                if (TA->Exist[2 * i + 1])
                {
                    j = i;
                    while (TA->Exist[2 * j + 1])
                    {
                        j = 2 * j + 1;
                    }
                }
                else
                {
                    j = i;
                    while (TA->Exist[2 * j + 2])
                    {
                        j = 2 * j + 2;
                    }
                }

                TA->Infos[i] = TA->Infos[j];
                TA->Exist[j] = 0;
            }
        }
    }
}

/*
Nom Fonction :Recherhce_Arbre
Entrée : L'arbre et la valeur à rechercher
Sortie : O si la valeur n'existe pas, sinon 1
Description : la fonction verifier l'existance d'une valeur dans l'arbre
*/
int Recherhce_Arbre(TArbre *TA, int value)
{
    int i;
    for (i = 0; i < Max; i++)
    {
        if (TA->Infos[i] = value)
            return ((int)1);
    }
    return ((int)0);
}
int main()
{
    TArbre *Monarbre;

    Monarbre = Init_Arbre();
    Insert_Arbre(Monarbre, 6);
    Insert_Arbre(Monarbre, 2);
    Insert_Arbre(Monarbre, 3);

    printf("%d\t%d\n\t%d", Monarbre->Infos[0], Monarbre->Infos[1], Monarbre->Infos[2]);

    return 0;
}

/*
Nom Fonction :Supp_Val_Arbre
Entrée : L'arbre et la valeur à supprimer
Sortie : retourne 1
Description : la fonction de suppression d'un élément dans l'arbre
*/
int Supp_Val_Arbre(TArbre *TA, int value)
{
    int i, j;
    for (i = 0; i < Max; i++)
    {
        if (TA->Infos[i] == value && TA->Exist[i] != 0)
        {
            // Si le noeud n'a pas des fils
            if ((TA->Exist[2 * i + 1] == 0) && (TA->Exist[2 * i + 1] == 0))
            {
                TA->Exist[i] = 0;
            }
            else
            {
                // Si le noeud a un fils gauche
                if (TA->Exist[2 * i + 1] == 1)
                {
                    j = i;
                    while (TA->Exist[2 * j + 1])
                    {
                        j = 2 * j + 1;
                    }
                }
                else
                {
                    // Si le noeud a un fils  droit
                    j = i;
                    while (TA->Exist[2 * j + 2] == 1)
                    {
                        j = 2 * j + 2;
                    }
                }

                TA->Infos[i] = TA->Infos[j];
                TA->Exist[j] = 0;
            }
        }
    }

    return ((int)1);
}
