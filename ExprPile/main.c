#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>



union MonType
{
    int a;
    char b;
};

typedef struct Cellule
{
    union MonType info;
    struct Cellule *suivant;
} Pile;


Pile  *Enpiler(Pile *P,union MonType x)
{
    Pile *NE;
    NE=(Pile *)(malloc(sizeof(Pile)));
    NE->info=x;
    NE->suivant=NULL;
    if(!P)
        return ((Pile*)NE);

    NE->suivant=P;
    return ((Pile *)NE);
}

Pile  *Depiler(Pile *P)
{
    Pile *tmp;
    if(!P)
        return ((Pile*)NULL);
    tmp=P;
    P=P->suivant;
    free(tmp);
    return ((Pile *)P);
}
float Eval(int a,char b,int c)
{
    switch(b)
    {
    case '+' :
        return ((float)a+c);
    case '-' :
        return ((float)a-c);
    case '*' :
        return ((float)a*c);
    case '/' :
        return ((float)a/c);
    }
}

int Est_un_oprande(char c)
{
    if((c=='+')||(c=='*')||(c=='/')||(c='-'))
        return ((int)1);
    return ((int)0);
}
int result(Pile *P1,Pile *P2)
{
    int a;
    float s=0;
    a=P1->info.a;
    P1=Depiler(P1);
    s=Eval(a,P2->info.b,P1->info.a);
    P2=Depiler(P2);
    while(P1)
    {
        P1=Depiler(P1);
        s=Eval(s,P2->info.b,P1->info.a);
        P2=Depiler(P2);
    }
    return ((float)s);
}


int lire()
{
    union MonType c;
    int x;
    Pile *P1,*P2;
    printf("Entrez votre expression : ");
    while((c.b=getchar())!='\n')
    {
        if(Est_un_oprande(c.b))
        {
            P2=Enpiler(P2,c);
        }
        else
        {
            c.a=(int)c.b-'0';
            P1=Enpiler(P1,c);
        }
    }
    printf("a");
    x=result(P1,P2);
    return ((int)x);

}


int main()
{
    int x;
    x=lire();
    printf("%d",x);
    return 0;
}
