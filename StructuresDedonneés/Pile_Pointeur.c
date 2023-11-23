

//-------------------Définition de la Cellule------------//

typedef struct Cellule
{
    int info;                // la valeur de l'élément
    struct Cellule *suivant; // pointeur sur la cellule suivant
} Cellule;

//-------------------Initialisatio de la Cellule------------//
Cellule *InitCellule(int valeur)
{
    Cellule *NE;
    NE = (Cellule *)malloc(sizeof(Cellule));
    if (!NE)
    {
        printf("Erreur d'allocation !");
        exit(0);
    }
    NE->info = valeur;
    NE->suivant = NULL;

    return ((Cellule *)NE);
}

//-------------------Empiler un élément------------------//

Cellule *Empiler(Cellule *Pile, int val)
{
    Cellule *NE;
    NE = InitCellule(val);
    if (!Pile)
        return ((Cellule *)NE);
    NE->suivant = Pile;

    return ((Cellule *)NE);
}

//-------------------Dépiler un élément------------------//

Cellule *Depiler(Cellule *Pile)
{
    Cellule *SuppElem = NULL;
    SuppElem = Pile;
    Pile = Pile->suivant;
    free(SuppElem);
    return ((Cellule *)Pile);
}

//-----------------Supprimer le max d'une pile-----------//

Cellule *SuppMin(Cellule *Pile, int *Min, int *occur)
{
    Cellule *tmp = NULL;
    *Min = Pile->info;
    *occur = 0;

    while (Pile)
    {
        if (*Min > Pile->info)
        {
            *Min = Pile->info;
            *occur = 0;
        }
        if ((Pile->info) == (*Min))
            (*occur)++;
        tmp = Empiler(tmp, Pile->info);

        Pile = Depiler(Pile);
    }

    while (tmp)
    {
        if ((tmp->info) != (*Min))
            Pile = Empiler(Pile, tmp->info);
        tmp = Depiler(tmp);
    }
    return ((Cellule *)Pile);
}

//-------------------Trier une pile----------------------//

Cellule *TrieePile(Cellule *Pile)
{
    Cellule *tmp = NULL;
    int Min;
    int n, i;
    while (Pile)
    {
        Pile = SuppMin(Pile, &Min, &n);
        for (i = 0; i < n; i++)
            tmp = Empiler(tmp, Min);
    }
    while (tmp)
    {
        Pile = Empiler(Pile, tmp->info);
        tmp = Depiler(tmp);
    }

    return ((Cellule *)Pile);
}

Cellule *print_Pile(Cellule *Pile)
{
    Cellule *tmp = NULL;

    while (Pile)
    {
        printf("%d\t", Pile->info);
        tmp = Empiler(tmp, Pile->info);
        Pile = Depiler(Pile);
    }
    printf("\n");

    while (tmp)
    {

        Pile = Empiler(Pile, tmp->info);
        tmp = Depiler(tmp);
    }

    return ((Cellule *)Pile);
}

//-------------------Insertion Trier des element ------------------//

Cellule *Insert_Triee(Cellule *Pile, int val)
{
    Cellule *NE, *tmp = NULL;
    int i = 0;
    NE = InitCellule(val);

    if (!Pile)
        return ((Cellule *)NE);

    while (Pile)
    {
        if (((Pile->info) > val) && (i != 1))
        {
            tmp = Empiler(tmp, val);
            i = 1;
        }

        tmp = Empiler(tmp, Pile->info);
        Pile = Depiler(Pile);
    }

    if (i != 1)
    {
        tmp = Empiler(tmp, val);
    }

    while (tmp)
    {
        Pile = Empiler(Pile, tmp->info);
        tmp = Depiler(tmp);
    }
    return ((Cellule *)Pile);
}

//-------------------Insertion a une position ---------------------//

Cellule *Insert_Val_Pos(Cellule *Pile, int val, int pos)
{
    Cellule *tmp;
    int i = 0;

    while (Pile)
    {
        if (i == pos)
            tmp = Empiler(tmp, val);
        tmp = Empiler(tmp, Pile->info);
        Pile = Depiler(Pile);
        i++;
    }

    while (tmp)
    {
        Pile = Empiler(Pile, tmp->info);
        tmp = Depiler(tmp);
    }

    return ((Cellule *)Pile);
}

//---------------------Programme Principale----------------------//

int main()
{
    Cellule *N1;
    N1 = InitCellule(1);
    int max, i;

    N1 = Empiler(N1, 9);
    N1 = Empiler(N1, 8);
    N1 = Empiler(N1, 1);
    N1 = Empiler(N1, 10);
    N1 = Empiler(N1, 4);
    N1 = Empiler(N1, 2);

    N1 = print_Pile(N1);

    N1 = Depiler(N1);

    N1 = print_Pile(N1);

    N1 = SuppMin(N1, &max, &i);

    N1 = print_Pile(N1);
    printf("\n Max : %d\tOccurence : %d", max, i);

    N1 = TrieePile(N1);

    printf("\n");
    N1 = print_Pile(N1);

    return 0;
}
