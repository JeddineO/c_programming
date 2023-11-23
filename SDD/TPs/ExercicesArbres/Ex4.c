#include<stdio.h>
#include<stdlib.h>

typedef struct ND
{
    int info;
    struct ND *fils;
    struct ND *frere;
}Noeud;

void AffichagePrefixe(Noeud *Arb)
{
    if (Arb)
    {
        printf("\n%d",Arb->info);
        AffichagePrefixe(Arb->fils);
        AffichagePrefixe(Arb->frere);
    }
}
void AffichageInfixe(Noeud *Arb)
{
    if (Arb)
    {
        AffichageInfixe(Arb->fils);
        printf("\n%d",Arb->info);
        AffichageInfixe(Arb->frere);
    }
}
void AffichagePostfixe(Noeud *Arb)
{
    if (Arb)
    {
        AffichagePostfixe(Arb->fils);
        AffichagePostfixe(Arb->frere);
        printf("\n%d",Arb->info);
    }
}