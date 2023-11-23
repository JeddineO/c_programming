//-------------------Exercice 1 ------------//

#define RC '\n'

int Check_Validity(char c)
{
    if ((c >= '0') && (c <= '9'))
        return ((int)1); // cas d'un caractere numerique on retourne 1
    if ((c >= 'A') && (c <= 'Z'))
        return ((int)1); // cas d'un caractere minuscule on retourne 1
    if ((c >= 'a') && (c <= 'z'))
        return ((int)1); // cas d'un caractere majuscule on retourne 1
    return ((int)0);     // pour tous les autres caracteres caractere  on retourne 0
}

void Reecrire_Phrase()
{
    char c;
    printf("Entrez une phrase : ");

    while ((c = getchar()) != RC)
    {
        if (Check_Validity(c))
            printf("%c", c);
    }
}

//-Structure adobté-

typedef struct
{
    int NbElem;
    int Tab[Max];
} MonTableau;

//-Retrouver les doublons

void Find_doubles(MonTableau T)
{
    int i, j, test;
    MonTableau Rang;
    Rang.NbElem = -1;

    for (i = 0; i < T.NbElem - 1; i++)
    {
        test = 0;
        Rang.NbElem = -1;
        for (j = i + 1; j < T.NbElem; j++)
        {
            if ((T.Tab[i] * 2) == (T.Tab[j]))
            {
                test = 1;
                Rang.Tab[++(Rang.NbElem)] = j;
            }
        }

        if (test)
        {
            printf("\n L'element :%d\tSon indice %d ,\tRang des doublons :", T.Tab[i], i);
            for (j = 0; j <= Rang.NbElem; j++)
            {
                printf("%d", Rang.Tab[i]);
            }
        }
    }
}
//-----------------Exercice 3 -----------//

Cellule *Cellule(Cellule *Liste,int value)
{

}
//-----------------Exercice 4 -----------//

Cellule *Supp(Cellule *Pile, int val)
{
    Cellule *tmp = NULL;
    while (Pile)
    {
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

