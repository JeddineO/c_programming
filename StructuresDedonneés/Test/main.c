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
    return ((int)T.NbElem==-1);
}

int Tab_est_saturee(Tableau T)
{
    return ((int)T.NbElem==Max-1);
}

//----------------Insertion à la bonne place--------------------//

int Insert_Ordonee(Tableau *MonTableau, int value)
{
    int i,n;

    if (Tab_est_saturee(*MonTableau))
        return ((int)0);

    MonTableau->Tab[++MonTableau->NbElem] = value;

    for (i = MonTableau->NbElem; i >0 ; i--)
    {
        if (MonTableau->Tab[i] < MonTableau->Tab[i-1])
        {
            n=MonTableau->Tab[i-1];
            MonTableau->Tab[i-1]=MonTableau->Tab[i];
            MonTableau->Tab[i]=n;
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
    int i,j,x,n;
    if (Tab_est_Vide(*MonTableau)) return ((int)0);

    for (i = 0; i <= MonTableau->NbElem-1; i++)
    {
        j=i;
        while(MonTableau->Tab[i]*2<MonTableau->Tab[j])j++;

        if ((MonTableau->Tab[j]) == (MonTableau->Tab[i] * 2))
        {
            //printf("Yrs");

            n = MonTableau->Tab[j];
            for (x = j; x  >i + 2; x--)
            {
                printf("Yrs");


                MonTableau->Tab[x] = MonTableau->Tab[x - 1];
            }

            MonTableau->Tab[i + 1] = n;
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

void Inverse()
{
    char c;
    if((c=getchar())!='\n')
    {
        Inverse();
        printf("%c",c);
    }
}


void Coder()
{
    char c;
    int cle = 2;
    while ((c = getchar()) != '\n')
    {
        c = (char)('a' + (((int)c-(int) 'a' + cle) % 26));
        printf("%c", c);
    }
}

void Decoder()
{
    char c;
    int cle = 2;
    while ((c = getchar()) != '\n')
    {
        c = (char)('a' + (((int) c-(int) 'a' - cle)+26)%26 );
        printf("%c", c);
    }
}

// transforme chaine

void check(char c)
{
    switch(c)
    {
    case ' ' :
        printf("%s","BL");
        break;
    case '  ' :
        printf("%s","\\t");
        break;
    case ',' :
        printf("%s","\\vrgig");
        break;
    case ':' :
        printf("%s","DBlPt");
        break;


    }
}

void Num(char c)
{
    switch(c)
    {
    case '1' :
        printf("%s","UN");
        break;
    case '2' :
        printf("%s","DEUX");
        break;
    case '3' :
        printf("%s","TROIS");
        break;
    case '4' :
        printf("%s","QUATRE");
        break;
    case '5' :
        printf("%s","CINQ");
        break;
    case '6' :
        printf("%s","SIX");
        break;
    case '7' :
        printf("%s","SEPT");
        break;
    case '8' :
        printf("%s","HUIT");
        break;
    case '9' :
        printf("%s","NEUF");
        break;
   }
}




void trans()
{
    char c;

    while ((c = getchar() )!= '\n')
    {
        Num(c);
    }
    printf("%c%c",'\\','n');
}


int main()
{
    printf("Entrer votre chaine : ");
    trans();
    return 0;
}
