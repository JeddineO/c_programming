// Declaration des bibliotheques
#include<stdio.h>
#include<stdlib.h>
// Declaration des constantes
#define MaxElem 30
// Declaration des structures
typedef struct      // Structure d'un tableau
{
    int info[MaxElem];
    int IdElem;
}TAB;
// typedef struct CEL  // Structure d'une cellule
// {
//     int info;
//     struct CEL *suivant;
// }Cellule;
typedef struct FL   // Structure d'une file
{
    Cellule *Tete, *Queue;
}File;
typedef struct ND   // Structure d'un arbre
{
    int info;
    struct ND *fgc, *fdt;
}Noeud;
/* ********************************************************************** */
/* ************************* Tableau ************************************ */
int Init_Tab(TAB *tab)
{
    if (!tab) return ((int)0);
    tab->IdElem = -1;
    return ((int)1);
}
int Est_Vide(TAB *tab)
{
    if (!tab) return ((int)-1);
    return ((int)(tab->IdElem == -1 ? 1:0));
}
int Est_Sature(TAB *tab)
{
    if (!tab) return ((int)-1);
    return ((int)(tab->IdElem == (MaxElem-1) ? 1:0));
}
int vider_Tab(TAB *tab) 
{
    if (!tab) return ((int)0);
    tab->IdElem = -1;
    return ((int)1);
}
void Afficher_Tab(TAB *tab)
{
    int i;
    if (!tab) printf("\nTableau n'existe pas");
    else
    {
        if (tab->IdElem == -1) printf("\nTableau vide");
        else
        {
            printf("\nTAB :\t");
            for (i = 0; i <= tab->IdElem; i++) printf("%d\t",tab->info[i]);
        }
    }
}
int Insert_Tab(TAB *tab, int val)
{   
    if (!tab) return ((int)-1);
    if (Est_Sature(tab)) return ((int)0);
    tab->info[++tab->IdElem] = val; 
    return ((int)1);
}
int Insert_Tab_Debut(TAB *tab, int val)
{   
    int i;
    if (!tab) return ((int)-1);
    if (Est_Sature(tab)) return ((int)0);
    tab->IdElem++;
    for (i = tab->IdElem; i > 0; i--) tab->info[i] = tab->info[i-1];
    tab->info[0] = val; 
    return ((int)1);
}
int Insert_Tab_Pos(TAB *tab, int val, int pos)
{
    int i;
    if (!tab) return ((int)-1);
    if (Est_Sature(tab)) return ((int)0);
    if (pos < 0 || pos > tab->IdElem+1) return ((int)-2);
    tab->IdElem++;
    for (i = tab->IdElem; i > pos; i--) tab->info[i] = tab->info[i-1];
    tab->info[i] = val;
    return ((int)1);
}
int Insert_Tab_Ordonne(TAB *tab, int val)
{
    int i;
    if (!tab) return ((int)-1);
    if (Est_Sature(tab)) return ((int)0);
    i = ++tab->IdElem;
    while ((i > 0) && (val < tab->info[i-1])) 
    {
        tab->info[i] = tab->info[i-1];
        i--;
    }
    tab->info[i] = val;
    return ((int)1);    
}
int Supprimer_Tab(TAB *tab)
{
    if (!tab) return ((int)-1); 
    if (Est_Vide(tab)) return ((int)0);
    tab->IdElem--;
    return ((int)1);
}
int Supprimer_Tab_Elem(TAB *tab, int val)
{
    int i = 0;
    if (!tab) return ((int)-1); 
    if (Est_Vide(tab)) return ((int)0);
    while (i <= tab->IdElem)
    {
        if (tab->info[i] == val) break;
        i++;
    }
    if (tab->info[i] != val) return ((int)0); 
    while (i < tab->IdElem)
    {
        tab->info[i] = tab->info[i+1];
        i++;
    }
    tab->IdElem--;
    return ((int)1);
}
int Supprimer_Tab_Occ(TAB *tab, int val)
{
    int i = 0, tmpId = -1; 
    if (!tab) return ((int)-1); 
    for (i = 0; i <= tab->IdElem; i++) 
        if(tab->info[i] != val) tab->info[++tmpId] = tab->info[i];
    tab->IdElem = tmpId; 
    return ((int)1);
}
int Supprimer_Tab_Doublons(TAB *tab)
{
    int i = 0, j, tmpId;
    if (!tab) return ((int)-1);
    while (i < tab->IdElem)
    {
        tmpId = i;
        for (j = i+1; j <= tab->IdElem; j++) 
            if (tab->info[j] != tab->info[i]) tab->info[++tmpId] = tab->info[j];
        tab->IdElem = tmpId;
        i++;
    }
    return ((int)1);
}
int Recherche_Tab(TAB *tab, int val)
{
    int i;
    if (!tab) return ((int)-1);                     // tableau n'existe pas
    for (i = 0; i <= tab->IdElem; i++)
        if (tab->info[i] == val) return ((int)i);   // Valeur trouvee
    return ((int)-2);                               // Valeur non trouvee  
}

/* ********************************************************************** */
/* ************************* Liste ************************************** */

/* ********************************************************************** */
/* ************************* Main *************************************** */
void main()
{
    int rt;
    TAB *tab = (TAB *)malloc(sizeof(TAB));
    rt = Init_Tab(tab);
    printf("\nInitialisation : %d",rt);
}
