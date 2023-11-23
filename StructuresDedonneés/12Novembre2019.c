#define MaxElem 20
/*------------------------------------------------Exercice1-----------------------------*/
/*
Fonction Maj_To_Min pour transformer un caractere
ecrit en majuscule a un en minuscule
*/
char Maj_To_Min(char c)
{
    int d;                        // distance entre 'A' et le caractere donné;
    d = (int)((int)c - (int)'A'); // distance entre le caractere 'a' et c
    c = (char)((int)'a' + d);
    return ((char))c;
}
/*
Fonction Min_To_Maj pour transformer un caractere
ecrit en minuscule a un en majuscule
*/
char Min_To_Maj(char c)
{
    int d;                        // distance entre 'A' et le caractere donné;
    d = (int)((int)c - (int)'a'); // distance entre le caractere 'a' et c
    c = (char)((int)'A' + d);
    return c;
}
/*
Fonction Car_To_Tab pour transformer une tabulation
 a une chine de caractere "TAB"
*/
int Car_To_Tab(char c, char t[4])
{

    t[0] = 'T';
    t[1] = 'A';
    t[2] = 'B';
    t[3] = '\0';
    return ((int)1);
}
/*
Fonction Car_To_BLC pour transformer une blanc
 a une chaine de caractere "BLC"
*/
char Car_To_Blc(char c, char t[4])
{
    t[0] = 'B';
    t[1] = 'L';
    t[2] = 'C';
    t[3] = '\0';
    return ((int)1);
}
/*
Fonction Trans_Num pour transformer un caractere
numérique donné
*/
char Trans_Num(char c)
{
    int Tab[10]; // Tableau de 10 élément pour contenir les valeur de transformation
    int i;       // indice pour parcourir le tableau
    int d;       // pour transformer notre caractere à un entier
    for (i = 0; i <= 4; i++)
    {
        Tab[i] = i + 5; // initialiasation de notre tableau
        Tab[i + 5] = i;
    }
    if ((c >= '0') && (c <= '9'))
    {
        d = (int)((int)c - (int)'0');  // distance entre le caractere '0' et c
        c = (char)((int)'0' + Tab[d]); // changer le valeur de c selon la valeur difinit dans le tableau
    }
    return ((char)c);
}

/*
Fonction Type_Carac pour deturminer le type du caractere
*/

int Type_Carac(char c)
{
    if ((c >= '0') && (c <= '9'))
        return ((int)1); // c ets un numérique retourne 1
    if ((c >= 'a') && (c <= 'z'))
        return ((int)2); // c ets un miniscule retourne 2
    if ((c >= 'A') && (c <= 'Z'))
        return ((int)3); // c ets un majiscule retourne 3
    if (c == ' ')
        return ((int)4); // c ets un blan retourne 4
    if (c == ' ')
        return ((int)5); // c ets une tabulation retourne 5
    return ((int)0);     // autre type  retourne 0
}

char Trans_Phrase(char phrase[10])
{
    while (c = getchar())
    {
        /* code */
    }

    int i = 0;
    int test;
    while (phrase[0] != '\0')
    {
        test = Type_Carac(phrase[i]);

        switch (test)
        {
        case 1:
            phrase[i] = Trans_Num(phrase[i]);
            break;
        case 2:
            phrase[i] = Min_To_Maj(phrase[i]);
            break;
        case 3:
            phrase[i] = Maj_To_Min(phrase[i]);
            break;
        case 4:
            phrase[i] = Car_To_Tab(phrase[i]);
            i = i + 2;
            break;
        case 5:
            phrase[i] = Car_To_Blc(phrase[i]);
            i = i + 2;
            break;
        default:
            break;
        }
    }
    return ((char)phrase[10]) :
}
/*------------------------------------------------Exercice2-----------------------------*/

// Definition de la strucutre d'un tableau
typedef struct
{
    int Nbelem;       // indice du dernier élément
    int Tab[MaxElem]; // Tableau
} MonTableau;

// Tableau saturee
int Tab_Est_Saturee(MonTableau ST)
{
    return (ST.Nbelem == MaxElem - 1);
}
// insertion à la fin d'un tableau
int Insert_End(MonTableau *ST, int valeur)
{
    if (Tab_Est_Saturee(*ST))
        return ((int)0);
    ST->Nbelem++;
    ST->Tab[ST->Nbelem] = valeur;
    return ((int)1);
}
// insertion à une position donnée
int Insert_Pos(MonTableau *ST, int valeur, int pos)
{
    int indice;
    if (Tab_Est_Saturee(*ST))
        return ((int)0);

    for (indice = ST->Nbelem; indice >= pos; indice--)
    {
        ST->Tab[indice + 1] = ST->Tab[indice];
    }
    ST->Nbelem++;
    ST->Tab[pos] = valeur;
    return ((int)1);
}
// insertion dans une position
int Remp_Pos(MonTableau *ST, int valeur, int pos)
{
    // test pos
    ST->Tab[pos] = valeur;
    return ((int)1);
}
// Transfer des element d'un tabeau à un autre
int Trans_Pos_IJ(MonTableau *ST1, int i, MonTableau *ST2, int j)
{
    int temp;
    if ((i > ST1->Nbelem) || (i < 0))
        return ((int)0);
    if ((j > ST2->Nbelem) || (j < 0))
        return ((int)-1);
    temp = ST2->Tab[j];
    ST2->Tab[j] = ST1->Tab[i];
    ST1->Tab[i] = temp;

    return ((int)1);
}
// Tasser tableau
int Tasser(MonTableau *ST1, int pos)
{
    int indice;

    for (indice = ST1->Nbelem; indice >= 0; indice--)
    {
        ST1->Tab[indice + 1] = ST1->Tab[indice];
    }
    return ((int)1);
}
// Transfer positif / Négative
int Separer_Pos_Neg(MonTableau *ST1, MonTableau *ST2)
{
    int i;
    for (i = 0; i <= ST1->Nbelem; i++)
    {
        if ((ST1->Tab[i]) < 0)
        {
            Insert_End(ST2, ST1->Tab[i]);
            Tasser(ST1, i);
        }
    }

    for (i = 0; i <= ST2->Nbelem; i++)
    {
        if ((ST2->Tab[i]) > 0)
        {
            Insert_End(ST1, ST2->Tab[i]);
            Tasser(ST2, i);
        }
    }
    return ((int)1);
}

/*------------------------------------------------Exercice3-----------------------------*/

typedef struct Cellule
{
    int info;
    struct Cellule *suivant;
} Cellule;

// Dépiler

Cellule *Depiler(Cellule *Pile)
{
    Cellule *Supp;
    Supp = Pile;
    Pile = Pile->suivant;
    Free(Supp);
    return ((Cellule *)Pile);
}

// Empiler

Cellule *Empiler(Cellule *Pile, int valeur)
{
    Cellule *NE;
    NE->info = valeur;
    NE->suivant = Pile;
    return ((Cellule *)Pile);
}

Cellule *Delete_Elem(Cellule *Liste, int pos)
{
    int i;
    Cellule *ptr;
    ptr = Liste;
    if (pos == 0)
    {
        Liste = Liste->suivant;
    }
    while (ptr)
    {
        if ((i + 1) == pos)
        {
            ptr = (ptr->suivant)->suivant;
            return ((Cellule *)Liste);
        }
        i++;
        ptr = ptr->suivant;
    }
}

Cellule *Min(Cellule *l, int *Min)
{
    *Min = l->info;
    Cellule *ptr;
    ptr = l;
    int i = 0, pos;
    while (ptr)
    {
        if (ptr->info < *Min)
            pos = i;
        i++;
        ptr = ptr->suivant;
    }
    l = Delete_Elem(l, pos);
    return ((Cellule *)l);
}

Cellule *TransListePile(Cellule *l, Cellule *p)
{
    Cellule *tmp;
    int *Min;
    while (l)
    {
        l = MinElemnt(l, Min);
        tmp = (Empiler, Min);
    }
    while (tmp)
    {
        p = Empiler(p, tmp->info);
        tmp = Depiler(tmp);
    }
    return ((Cellule *)p);
}

Cellule *Supp_Min(Cellule *p, int *Min)
{

    Cellule *tmp;
    *Min = p->info;
    while (p)
    {
        if (p->info < *Min)
            *Min = p->info;

        tmp = Empiler(tmp, p->info);
        p = Depiler(p);
    }

    while (tmp)
    {
        if (tmp->info != *Min)
            p = Empiler(p, tmp->info);
        tmp = Depiler(tmp);
    }

    return ((Cellule *)p);
}

Cellule *TransPileListe(Cellule *p)
{
    int *Min;
    Cellule *NE;
    while (p)
    {
        p = Supp_Min(p, Min);
        NE->info = Min;
        NE->suivant = l;
    }
    return ((Cellule *)l);
}