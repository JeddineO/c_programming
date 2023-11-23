/*------------------------------------------------Exercice1-----------------------------*/
int Cmpt_Car(char c, int Alpha[26], int Num[10], int *autres)
{
    int i, d;
    for (i = 0; i < 26; i++)
        Alpha[i] = 0;
    for (i = 0; i < 10; i++)
        Num[i] = 0;

    if ((c >= 0) && (c <= 9))
    {
        d = (int)((int)c - (int)'0');
        Num[d]++;
        return ((int)1);
    }

    if ((c >= 'a') && (c <= 'z'))
    {
        d = (int)((int)c - (int)'a');
        Alpha[d]++;
        return ((int)2);
    }

    if ((c >= 'A') && (c <= 'Z'))
    {
        d = (int)((int)c - (int)'0');
        Alpha[d]++;
        return ((int)2);
    }

    *autres++;
    return ((int)0);
}

/*------------------------------------------------Exercice2-----------------------------*/
typedef struct Cellule
{
    int info;
    struct Cellule *suivant;

} Cellule;

// Suppresion d'une valeur dans une pile

Cellule *Elimener_Elem(Cellule *Pile, int Val)
{
    if (!Pile)
        return ((Cellule *)NULL);
    Cellule *tmp;

    tmp = (Cellule *)malloc(sizeof(Cellule));
    if (!tmp)
    {
        printf("Erreur d'allocation");
        exit(0);
    }

    while (Pile)
    {
        if ((Pile->info) != Val)
            tmp = Empiler(tmp, Pile->info);
        Pile = Deiler(Pile);
    }
    while (tmp)
    {
        Pile = Empiler(Pile, tmp->info);
        tmp = depiler(tmp);
    }
    return ((Cellule *)Pile);
}

int Supp_Double(tab T, int val)
{

    for (i = 0; i < NbElem; i++)
    {
        if (i = val)
        {
            supp(i);
        }
    }
}

liste : les nbr positive impair 3 5 9 13 Tab;
positive pair 2 4 8 12 18

    pile : negative impair
               file : negatif pair

                      int
                      Affiche_Triee(Tab *MonTableau, Cellule *Pile, Cellule *Liste, File *File)
{
    Cellule *tmpp = NULL;
    File *tmpf = NULL;

    while ((Pile != NULL) && (File != NULL))
    {
        if ((Pile->info) < (File->tete->info))
        {
            printf("%d", Pile->info);
            tmpp = Enpiler(tmpp, Pile->info);
            P = depiler(P);
        }
        else
        {
            printf("%d", File->tete->info);
            Enfiler(tmpf, F->tete->info);
            Defiler(F);
        }
    }

    while (Pile)
    {
        printf("%d", P->info);
        tmpp = Empiler(tmpp, P->info);
        Pile = Depiler(P);
    }

    while (File)
    {
        printf("%d", P->info);
        tmpp = Empiler(tmpp, P->info);
        Pile = Depiler(P);
    }
}
