// Déclaration des bibliotheques
#include<stdio.h>
#include<stdlib.h>
// Declaration des constantes
#define NbElem 25
// Definition de la structure
typedef struct 
{
    int Tab[NbElem]; // Le tableau des elements
    int IdElem; // Indice de dernier element du tableau
}MaTab; // Definition liee a une structure de tableau
// Prototype
int InitTab(MaTab *MonTableau);
int TabVide(MaTab *MonTableau);
int TabSature(MaTab *MonTableau);
int InsererTab(MaTab *MonTableau, int Elem);
int InsererTabPos(MaTab *MonTableau, int Pos, int Elem);
int SupprimerElem(MaTab *MonTableau);
int SupprimerElemDonne(MaTab *MonTableau, int Elem);
int InsererElemTabOrdonne(MaTab *MonTableau, int Elem);
int RechercheTabOrdonne(MaTab *MonTableau, int Elem);
int SupprimerTabOccurence(MaTab *MonTableau, int Elem);
// Programme principale
void main()
{
    MaTab t;
    printf("%d",InitTab(&t));
    printf("%d",InsererTab(&t,5));
    printf("%d",InsererTab(&t,7));
    printf("%d",InsererTab(&t,7));
    printf("%d",InsererTab(&t,8));
    printf("%d",InsererTab(&t,9));
    printf("%d",InsererTab(&t,12));
    printf("%d",InsererTab(&t,8));
    printf("%d",InsererTab(&t,8));
    printf("%d",InsererTab(&t,8));
    printf("%d",InsererTab(&t,15));
    // printf("%d",InsererTabPos(&t,3,20));
    // printf("%d",SupprimerElem(&t));
    printf("%d",SupprimerElemDonne(&t,8));
    // printf("%d",InsererElemTabOrdonne(&t,10));
    // printf("%d",RechercheTabOrdonne(&t,10));
    // printf("%d\n",SupprimerTabOccurence(&t,8));
    int i = 0;
    while (i <= t.IdElem)
    {
        printf("%d\t",t.Tab[i++]);
    }
}
int InitTab(MaTab *MonTableau)
{
    if (!MonTableau) return ((int)0); // Tester si la zone memoire existe
    MonTableau->IdElem = -1; // Le tableau est vide
    return ((int)1);
}
int TabVide(MaTab *MonTableau)
{   
    if (!MonTableau) return ((int)-1); // Tester si la zone memoire existe
    // le tableau est vide lorsque l'indice du dernier element egal a -1
    return ((int)(MonTableau->IdElem == -1));    
}
int TabSature(MaTab *MonTableau)
{   
    if (!MonTableau) return ((int)-1); // Tester si la zone memoire existe
    // Le tableau est sature lorsque l'indice du dernier element egal a NbElem-1
    return ((int)(MonTableau->IdElem == (NbElem-1)));
}
int InsererTab(MaTab *MonTableau, int Elem)
{   
    if (!MonTableau) return ((int)-1); // Tester si la zone memoire existe 
    if (TabSature(MonTableau)) return ((int)0); // Tester si le tableau est sature
    MonTableau->Tab[++MonTableau->IdElem] = Elem; // Insertion à la derniere case du tableau
    return ((int)1);
}
int InsererTabPos(MaTab *MonTableau, int Pos, int Elem)
{
    int i;
    if (!MonTableau) return ((int)-1); // Tester si la zone memoire existe
    if (TabSature(MonTableau)) return ((int)0); // Tester si le tableau est sature
    if ((0 > Pos) || (Pos >= NbElem)) return ((int)-2); // La position entree doit etre appartient a [0,NbElem[
    i = ++MonTableau->IdElem; // incrementer IdElem et l'affecter a i
    while (i > Pos) // tant qu'on a pas encore arriver a la position Pos
        MonTableau->Tab[i--] = MonTableau->Tab[i]; // Tasser les elements apres la position d'une case
    MonTableau->Tab[Pos] = Elem; // affecter Elem dans la position Pos
    return ((int)1);
}
int SupprimerElem(MaTab *MonTableau)
{
    if (!MonTableau) return ((int)-1); // Tester si la zone memoire existe
    MonTableau->IdElem--; // decrimenter l'indice du dernier element
    return ((int)1);
}
int SupprimerElemDonne(MaTab *MonTableau, int Elem)
{
    int i = 0, j;
    if (!MonTableau) return ((int)-1); // Tester si la zone memoire existe
    // tant qu'on n'a pas trouver Elem incrementer i
    while ((MonTableau->Tab[i] != Elem) && (i <= MonTableau->IdElem)) i++;
    if (MonTableau->Tab[i]!=Elem) return ((int)0); // si Elem n'existe pas dans la MonTableau
    for (j = i; j < MonTableau->IdElem; j++)
        MonTableau->Tab[j] = MonTableau->Tab[j+1]; // tasser les elements apres l'element d'une case en arriere

    while ()
    MonTableau->IdElem--; // decrimenter l'indice du dernier element
    return ((int)1);
}
int InsererElemTabOrdonne(MaTab *MonTableau, int Elem)
{
    int i;
    if (!MonTableau) return ((int)-1); // Tester si la zone memoire existe
    if (TabSature(MonTableau)) return ((int)0); // Tester si le tableau est sature
    i = MonTableau->IdElem; // initialiser i par l'indice du dernier element 
    while ((i >=0) && (MonTableau->Tab[i] > Elem))
    {
        MonTableau->Tab[i+1] = MonTableau->Tab[i]; // Deplacer chaque element a la case qui le suive
        i--;
    }
    MonTableau->Tab[i+1] = Elem;
    ++MonTableau->IdElem; // Incrementer l'indice du dernier element
    return ((int)1);
}
int RechercheTabOrdonne(MaTab *MonTableau, int Elem)
{
    int i = 0;
    if (!MonTableau) return ((int)-1); // Tester si la zone memoire existe 
    while ((i <= MonTableau->IdElem) && (MonTableau->Tab[i] <= Elem))
    {
        if (MonTableau->Tab[i++] == Elem)
            return ((int)1); // Element trouve
    }
    return ((int)0); // Element n'existe pas dans le tableau
    /* // Methode Dichotomie
    int gauche = 0, droite = MonTableau->IdElem, indice;
    while (gauche < droite)
    {
        indice = (gauche + droite)/2;
        if (MonTableau->Tab[indice] == Elem)
            return ((int)1);
        if (MonTableau->Tab[indice] < Elem)
            gauche = indice + 1;
        else 
            droite = indice;
    }
    return ((int)0);
    */
}
int SupprimerTabOccurence(MaTab *MonTableau, int Elem)
{
    int i, occ = 0;
    if (!MonTableau) return ((int)-1); // Tester si la zone memoire existe
    for (i = 0; i <= MonTableau->IdElem; i++) // parcourir le tableau
    {
        if(MonTableau->Tab[i] == Elem) 
        {   // si on trouve un element a supprimer
            occ++; // incrementer le nombre d'occurence d'apparition de l'element a supprimer
            continue; // passer a l'element suivant
        }
        if (occ != 0) // si on a deja trouver une occurence de l'element a supprimer
            MonTableau->Tab[i-occ] = MonTableau->Tab[i]; 
    }
    if (occ == 0) return ((int)0); // Element non trouve
    MonTableau->IdElem -= occ; // changer l'indice du dernier element
    return ((int)1);
}