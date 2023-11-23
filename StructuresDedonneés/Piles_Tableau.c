//-------------------Définition de la Cellule------------//

typedef struct
{
    int sommet; // Indice du sommet
    int Tab[MaxNb];
} TPile;

//-------------------Initialisatio de la Pile------------//

int init_Pile(TPile *MaPile)
{
    if (!MaPile)
        return ((int)0);
    MaPile->sommet = -1;
    return ((int)1);
}

//-------------------Pile Saturee---------------------//

int Pile_Saturee(TPile MaPile)
{
    return ((int)MaPile.sommet == (MaxNb - 1));
}

//-------------------Pile Saturee---------------------//

int Pile_Vide(TPile MaPile)
{
    return ((int)MaPile.sommet == -1);
}

//-------------------Empiler------------------------//

int Empiler(TPile *MaPile, int val)
{

    if (Pile_Saturee(*MaPile))
        return ((int)0);
    MaPile->Tab[++MaPile->Sommet] = val;
    return ((int)1);
}

//-------------------Depiler------------------------//

int Depiler(TPile *MaPile, int val)
{
    if (Pile_Vide(*MaPile))
        return ((int)0);
    --MaPile->Sommet;
    return ((int)1);
}

//-------------------Affichage------------------------//

void Print_Pile(TPile *MaPile)
{
    TPile *tmp;
    if (Pile_Vide(*MaPile))
        return ((int)0);

    while (!Pile_Vide(*MaPile))
    {
        printf("%d\t", MaPile->sommet);
        Empiler(tmp, MaPile->sommet);
        Depiler(MaPile);
    }

    while (!Pile_Vide(*tmp))
    {
        Empiler(MaPile, tmp->sommet);
        Depiler(tmp);
    }

    return ((int)1);
}
