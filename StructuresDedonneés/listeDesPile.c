// Structure de la pile

typedef struct pile
{
    int sommet;
    struct pile *suivant;

} PPile;

// Structure de  la liste

typedef struct LP
{
    PPile *Cellule;
    struct LP *Csuivant;
} LP;

// Cree une pile

pile *CreePile(int val)
{
    PPile *p;
    p = (pile *)malloc(sizeof(pile));
    if (!p)
    {
        exit(0);
    }
    p->sommet = val;
    p->suivant = NULL;

    return ((PPile *)P);
}

// Creer une liste de pile

LP *CreeLP(PPile *p)
{
    LP *lp;
    lp = (LP *)malloc(sizeof(LP));
    if (!lp)
    {
        exit(0);
    }
    lp->Cellule = p;
    lp->Csuivant = NULL;

    return ((LP *)lp);
}

// Empiler

PPile *Empiler(PPile *p, int info)
{
    PPile *NE;
    NE = CreePile(p, info);
    if (!p)
    {
        return ((PPile)NE);
    }
    NE->suivant = PPile;

    return ((PPile *)NE);
}

// Depiler

PPile *Depiler(PPile *p)
{
    PPile *supr;
    if (!p)
        return ((PPile *)NULL);
    supr = p;
    p = p->suivant;
    free(supr);
    return ((PPile *)p);
}

// Inserer Pile

LP *Inserer(LP *lp, PPile *p)
{
    LP *ptr, *NE;
    NE = CreeLP(p);
    ptr = lp;
    if (!lp)
        return ((LP *)NE);
    while (ptr)
        ptr = ptr->Csuivant;
    ptr->Csuivant = NE;

    return ((LP *)LP);
}

// Triee de la pile

LP *Triee(PPile *p)
{
    LP *liste = NULL, *ptr;
    PPile *pile = NULL;
    int inser = 0;
    if (!pile)
        return ((LP *)NULL);

    while (p)
    {
        ptr = liste;
        while (ptr)
        {
            if (pile->info < ptr->Cellule->sommet)
            {
                liste->Cellule = Empiler(liste->Cellule, p->sommet);
                inser = 1;
                break;
            }
            ptr = ptr->Csuivant;
        }
        if (!insert)
        {
            pile = CreePile(p, pile->info);
            liste = Inserer(liste, pile);
        }
        p = Depiler(pile);
        inser = 0;
    }
    return ((LP *)liste);
}

// Affichage

void Affiche(LP *liste)
{
    LP *ptr;
    ptr = liste;
    PPile *MIN;

    while (liste)
    {
        while (ptr->Csuivant)
        {
            if (ptr->Cellule->sommet < ptr->Csuivant->Cellule->sommet)
                MIN = ptr->Cellule;
            ptr = ptr->Csuivant;
        }
        printf("%d", MIN->sommet);
        MIN = Depiler();
    }
}
