#define Max 24
/*
Définition de la structure
Initialisation du tableaux
Taille du tableaux
Tableaux est vide
Tableaux est saturee
insertion a la fin du Tableau
insertion a une position
Suppresion  d'un élément
Insertion Ordonné
Afficher tableaux
Ind_Elem(retourne l'indice de la premiere apparition d'un entier)
Ecahnge_Elem(chnger les valeurs du deux indices)
Ind_Min_Relatif(Le min entre un indice et la dernier case du tableaux)
Tri_Double
*/

//--------------------------------------Définition de la structure------------------------------------------//

typedef struct
{
    int Tab[Max]; // Tableaux des éléments
    int NbElem;   // Nombre des éléments du tableaux
} STableaux;

//--------------------------------------Initialisation du tableaux------------------------------------------//

STableaux *InitTableaux()
{
    STableaux *tmp;
    // Allocation de la mémoire
    tmp = (STableaux *)malloc(sizeof(STableaux));
    // cas d'échec d'allocation
    if (!tmp)
    {
        printf("\nErreur d'allocation !");
        exit(0);
    }
    // initialiser le nombre des élément à 0
    tmp->NbElem = 0;
    // Retourne la structure du tableaux
    return ((STableaux *)tmp);
}

//--------------------------------------------Taille du tableaux--------------------------------------------//

int Taille_Stab(STableaux Stab)
{
    return Stab.NbElem;
}

//--------------------------------------------Tableaux est vide--------------------------------------------//

int Tab_est_vide(STableaux Stab)
{
    return ((int)Stab.NbElem == 0);
}

//--------------------------------------------Tableaux est saturee-----------------------------------------//

int Tab_est_saturee(STableaux Stab)
{
    return ((int)Stab.NbElem == Max);
}

//---------------------------------------insertion a la fin du Tableau-------------------------------------//

int Inserer_tab_fin(STableaux *Stab, int value)
{
    if (!Stab)
        return ((int)-1);
    if (Tab_est_saturee(*Stab))
        return ((int)0);
    Stab->Tab[Stab->NbElem++] = value;
    return ((int)1);
}

//---------------------------------------insertion a une position-------------------------------------------//

int Inserer_tab_pos(STableaux *Stab, int value, int pos)
{
    int i, j;
    if (!Stab)
        return ((int)-1);
    if (Tab_est_saturee(*Stab))
        return ((int)0);
    if ((pos > Stab->NbElem - 1) || (pos < 0))
        return ((int)-2);

    for (i = 0; i < Stab->NbElem; i++)
    {
        if (i == pos)
        {
            for (j = Stab->NbElem - 1; j < i; j--)
            {
                Stab->Tab[j + 1] = Stab->Tab[j];
            }
            Stab->NbElem++;
            Stab->Tab[i] = value;

            return ((int)1);
        }
    }
}

//---------------------------------------Suppresion  d'un élément-------------------------------------------//

int Supp_tab_pos(STableaux *Stab, int pos)
{
    int i, j;
    if (!Stab)
        return ((int)-1);
    if (Tab_est_vide(*Stab))
        return ((int)0);
    if ((pos > Stab->NbElem - 1) || (pos < 0))
        return ((int)-2);
    for (i = 0; i < Stab->NbElem; i++)
    {
        if (i == pos)
        {
            for (j = i; i < Stab->NbElem - 1; i++)
            {
                Stab->Tab[i] = Stab->Tab[i + 1];
            }
            Stab->NbElem--;
            return ((int)1);
        }
    }
}

//-------------------------------------------Insertion Ordonné-----------------------------------------------//
int Iserer_tab_ord(STableaux *Stab, int value)
{
    int i, echange;
    if (!Stab)
        return ((int)-1);
    if (Tab_est_saturee(*Stab))
        return ((int)0);
    Stab->Tab[Stab->NbElem++] = value;
    for (i = Stab->NbElem - 1; i > 0; i--)
    {
        if (Stab->Tab[i] > Stab->NbElem[i - 1])
        {
            echange = Stab->Tab[i];
            Stab->Tab[i] = Stab->Tab[i - 1];
            Stab->Tab[i - 1] = echange;
        }
    }

    return ((int)1);
}
//-------------------------------------------Afficher tableaux-----------------------------------------------//

void Affichage_tab(STableaux Stab)
{
    int i;
    if (!Stab)
        return ((int)-1);
    if (Tab_est_vide(*Stab))
        return ((int)0);
    for (i = 0; i < Stab.NbElem; i++)
    {
        printf("\t %d", Stab.Tab[i]);
    }
}

//--------------------------------------------------Ind_Elem-----------------------------------------------//

int Ind_Elem(STableaux Stab, int Ind)
{
    int i;
    if (Tab_est_vide(*Stab))
        return ((int)0);
    for (i = 0; i < Stab.NbElem; i++)
    {
        if (Stab.Tab[i] == Ind)
            return ((int)i);
    }

    return ((int)-1);
}

//-------------------------------------------Echange Element-----------------------------------------------//

int Echange_Elem(STableaux *Stab, int Ind1, int Ind2)
{
    int echange;
    if (Tab_est_vide(*Stab))
        return ((int)0);
    echange = Stab->Tab[Ind1];
    Stab->Tab[Ind1] = Stab->Tab[Ind2];
    Stab->Tab[Ind2] = echange;

    return ((int)1);
}

//-------------------------------------------Ind_Min_Relatif-----------------------------------------------//

int Ind_Min_Relatif(STableaux Stab, int IndD)
{
    int Min, indice;
    if (Tab_est_vide(*Stab))
        return ((int)0);

    Min = Stab.Tab[IndD];
    indice = IndD;

    for (i = IndD; i < Stab.NbElem; i++)
    {
        if (Stab.Tab[i] < Min)
            indice = i;
    }

    return ((int)i);
}

//-------------------------------------------Tri Double-----------------------------------------------//

int Tri_Double(STableaux *Stab)
{
    if (Tab_est_vide(*Stab))
        return ((int)0);
    while ()
    {
    }
}