#include<stdio.h>
#include<stdlib.h>

#define NbElem 10
void ComptageChiffre(int TabFreq[NbElem]);

int main()
{
    int Tab[NbElem];
    ComptageChiffre(Tab);
}

void MiseAjour(int TabFreq[NbElem],int val)
{
    TabFreq[val]++;
}
void InitTab(int Tab[NbElem])
{
    int i;
    for (i = 0; i< NbElem; Tab[i++] = 0);
}
void AfficherTab(int Tab[NbElem])
{
    for (int i = 0; i < NbElem; i++)
        printf("\n%d apparait %d fois.",i,Tab[i]);
}
void ComptageChiffre(int TabFreq[NbElem])
{
    int val;
    InitTab(TabFreq);
    do
    {
        printf("\nEntrer l'entier a lire : ");
        scanf("%d",&val);
        if (0 <= val && val <=9)
            MiseAjour(TabFreq,val);
        printf("\nVous voulez ajouter un nouveau entier a lire ? TAPER 1 SI OUI.");
        scanf("%d",&val);
    } while (val == 1);
    AfficherTab(TabFreq);
}