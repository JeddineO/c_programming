#include<stdio.h>
#include<stdlib.h>

typedef struct ND
{
    int info;
    struct ND *fgc;
    struct ND *fdt;
}Noeud;

Noeud *CreerNoeud(int val)
{
    Noeud *NE = (Noeud *)malloc(sizeof(Noeud));
    NE->info = val;
    NE->fdt = NE->fgc = NULL;
    return ((Noeud *)NE);
}

int MinArbBin(Noeud *Arb, int *Min)
{
    int rt, min;
    if (!Arb) return ((int)0);
    *Min = Arb->info;
    if (Arb->fgc)
    {
        rt = MinArbBin(Arb->fgc,&min);
        if (min < *Min) *Min = min;
    }
    if (Arb->fdt)
    {
        rt = MinArbBin(Arb->fdt,&min);
        if (min < *Min) *Min = min;
    }
    return ((int)1);
}

void main()
{
    Noeud *Arb = NULL;
    int min, rt;
    
    Arb = CreerNoeud(12);
    Arb->fgc = CreerNoeud(7);
    Arb->fdt = CreerNoeud(9);
    Arb->fgc->fgc = CreerNoeud(6);
    Arb->fgc->fgc->fdt = CreerNoeud(2);
    Arb->fgc->fdt = CreerNoeud(8);
    Arb->fgc->fdt->fgc = CreerNoeud(3);
    Arb->fgc->fdt->fdt = CreerNoeud(5);
    Arb->fgc->fdt->fdt->fgc = CreerNoeud(1);
    Arb->fgc->fdt->fdt->fdt = CreerNoeud(2);
    Arb->fdt->fdt = CreerNoeud(14);

    rt = MinArbBin(Arb,&min);
    printf("\nLe min : %d",min);
}