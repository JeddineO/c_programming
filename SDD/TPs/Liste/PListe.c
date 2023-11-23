#include<stdio.h>
#include<stdlib.h>
// Definition de la structure
typedef struct Liste
{
    int info; 
    struct Liste *suivant; // Pointeur vers l'element suivant
}Cellule;

/* ***********************************************************************
    Nom de la fonction: CreerCellule;
    Entree: int val : la valeur de l'element a creer
    Sortie: Cellule *CL : l'element creer contient la valeur entree val
    La fonction permet de creer un element et de le retourne
**************************************************************************/
Cellule *CreerCellule(int val)
{
    Cellule *CL;
    CL = (Cellule *)malloc(sizeof(Cellule)); // Allocation de la memoire
    if (!CL) 
    {   // Erreur d'allocation de la memoire
        printf("\nErreur d'allocation de la memoire!");
        exit(0); // Quitter le programme
    }
    CL->info = val; // Affecter la valeur
    CL->suivant = NULL; // Initialiser le pointeur suivant par NULL
    return ((Cellule *)CL); // retourne CL
}
/* ***********************************************************************
    Nom de la fonction: TaillePListe;
    Entree: Cellule *liste : la liste
    Sortie: int taille : la taille de la liste entree
    La fonction permet de calculer la taille de la liste entree et de la 
    retournee
**************************************************************************/
int TaillePListe(Cellule *liste)
{
    int taille = 0; 
    Cellule *courant = liste;
    while (courant)
    {   // tant que courant != NULL
        taille++; // Incrementer la taille
        courant = courant->suivant; // passer a l'element suivant
    }
    return ((int)taille); 
}
/* ***********************************************************************
    Nom de la fonction: EstVide;
    Entree: Cellule *liste : la liste
    Sortie: entier pour indiquer si la liste est vide ou pas
    La fonction permet de s'avoir si une liste est vide (retourne 1) ou 
    non (retourn 0)
**************************************************************************/
int EstVide(Cellule *liste)
{
    if (!liste) return ((int)1); // tester si la liste existe
    return ((int)0); // liste non vide
}
/* ***********************************************************************
    Nom de la fonction: AfficherPListe;
    Entree: Cellule *liste : la liste
    La fonction permet d'afficher les elements de la liste entree en 
    parametre
**************************************************************************/
void AfficherPListe(Cellule *liste)
{
    Cellule *courant;
    // si la liste est vide
    if (EstVide(liste)) printf("\nLa liste est vide");
    else
    {
        courant = liste; // initialiser courant par la tete de la liste
        printf("\nListe : ");
        while (courant)
        {   // tant qu'on a un element dans la liste
            printf("%d\t",courant->info); // afficher l'element
            courant = courant->suivant; // passer au suivant
        }
    }
}
/* ***********************************************************************
    Nom de la fonction: ViderPListe;
    Entree: Cellule *liste : la liste qui sera vider
    Sortie: Cellule *liste : la liste vide
    La fonction permet de supprimer tous les elements de la liste
**************************************************************************/
Cellule *ViderPListe(Cellule *liste)
{
    Cellule *courant;
    while (liste) // Tant qu'il existe un element
    {
        courant = liste; // Affecter l'element a courant
        liste = liste->suivant; // passer liste a l'element suivant
        free(courant); // Detruire l'element courant
    }
    return ((Cellule *)liste);
}
/* ***********************************************************************
    Nom de la fonction: InsererPListeDebut;
    Entree: Cellule *liste : la liste pour inserer un element en tete
            int val : la valeur de l'element qui sera inserer
    Sortie: Cellule *liste : la nouvelle liste contient l'element insere
    La fonction permet d'inserer un element a la tete de la liste et 
    retourne la nouvelle liste
**************************************************************************/
Cellule *InsererPListeDebut(Cellule *liste, int val)
{
    Cellule *CL;
    CL = CreerCellule(val); // Creer l'element
    if (!liste) return ((Cellule *)CL); // tester si la liste existe
    CL->suivant = liste; // Inserer a la tete
    return ((Cellule *)CL); // retourner la nouvelle liste
}
/* ***********************************************************************
    Nom de la fonction: InsererPListeFin;
    Entree: Cellule *liste : la liste pour inserer un element en queue
            int val : la valeur de l'element qui sera inserer
    Sortie: Cellule *liste : la nouvelle liste contient l'element insere
    La fonction permet d'inserer un element a la queue de la liste
**************************************************************************/
Cellule *InsererPListeFin(Cellule *liste, int val)
{
    Cellule *CL, *courant;
    CL = CreerCellule(val); // Creer l'element
    if (!liste) return ((Cellule *)CL); // tester si la liste existe
    courant = liste; // Initialiser courant a la tete de la liste
    while (courant->suivant) // tant que courant a un suivant
        courant = courant->suivant; // passer a l'element suivant
    courant->suivant = CL; // Inserer l'element
    return ((Cellule *)liste); 
}
/* ***********************************************************************
    Nom de la fonction: InsererPlistePos;
    Entree: Cellule *liste : la liste pour inserer un element a une 
                position
            int pos : la position pour inserer l'element
            int val : la valeur de l'element qui sera inserer
    Sortie: Cellule *liste : la nouvelle liste contient l'element insere
    La fonction permet d'inserer un element a la position donne en 
    parametre dans la liste
**************************************************************************/
Cellule *InsererPlistePos(Cellule *liste, int Pos, int val)
{
    int i = 1;
    Cellule *CL, *courant;
    if ((Pos <= 0) || (TaillePListe(liste) < Pos-1))
    {   
        printf("\nErreur : Position incorrecte!");
        exit(0); // Quitter le programme
    }
    if (!liste) return ((Cellule *)CreerCellule(val)); // tester si la liste existe
    // Insertion en debut
    if (Pos == 1) return ((Cellule *)InsererPListeDebut(liste,val));
    // Insertion en fin
    if (Pos == TaillePListe(liste)+1) return ((Cellule *)InsererPListeFin(liste,val));
    // Insertion en milieu
    CL = CreerCellule(val); // Creer l'element
    courant = liste; // Pointer sur la tete de la liste
    while (++i < Pos) // tant qu'on n'a pas atteind la position
        courant = courant->suivant; // pointer sur l'element suivant
    CL->suivant = courant->suivant; // affecter le suivant de courant au suivant de l'element 
    courant->suivant = CL; // Affecter l'element au suivant de courant
    return ((Cellule *)liste);
}
/* ***********************************************************************
    Nom de la fonction: InsererPListeOrdonnee;
    Entree: Cellule *liste : la liste ordonne pour inserer un element
            int val : la valeur de l'element qui sera inserer
    Sortie: Cellule *liste : la nouvelle liste contient l'element insere
    La fonction permet d'inserer un element dans la liste ordonnee
**************************************************************************/
Cellule *InsererPListeOrdonnee(Cellule *liste, int val)
{
    Cellule *CL, *courant;
    // tester si la liste existe
    if (!liste) return ((Cellule *)CreerCellule(val)); 
    // insertion en tete
    if (val < liste->info) return ((Cellule *)InsererPListeDebut(liste,val));
    CL = CreerCellule(val);
    courant = liste; // pointer courant en tete
    while (courant->suivant) // tant que courant a un suivant
    {
        if (val < courant->suivant->info )
        {   // Insertion en milieu
            CL->suivant = courant->suivant;
            courant->suivant = CL;
            return ((Cellule *)liste);
        }
        courant = courant->suivant;
    }
    // Insertion en queue
    courant->suivant = CL;
    return ((Cellule *)liste);
}
/* ***********************************************************************
    Nom de la fonction: SupprimerPListeDebut;
    Entree: Cellule *liste : la liste pour supprimer un element en tete
    Sortie: Cellule *liste : la nouvelle liste qui ne contient pas 
                l'element en tete
    La fonction permet de supprimer l'element en tete de la liste 
**************************************************************************/
Cellule *SupprimerPListeDebut(Cellule *liste)
{
    Cellule *Supp;
    if (!liste) return ((Cellule *)NULL); // tester si la liste existe
    Supp = liste; // Element a supprime
    liste = liste->suivant; // passer liste au suivant
    free(Supp); // liberer la memoire
    return ((Cellule *)liste);
}
/* ***********************************************************************
    Nom de la fonction: SupprimerPListeFin;
    Entree: Cellule *liste : la liste pour supprimer un element en queue
    Sortie: Cellule *liste : la nouvelle liste qui ne contient pas 
                l'element en queue
    La fonction permet de supprimer l'element en queue de la liste 
**************************************************************************/
Cellule *SupprimerPListeFin(Cellule *liste)
{
    Cellule *courant, *Supp;
    if (!liste) return ((Cellule *)NULL); // tester si la liste existe
    Supp = liste; // initialiser Supp a la tete de la liste
    while (Supp->suivant)
    {   // tant qu'on a le suivant de Supp
        courant = Supp;
        Supp = Supp->suivant;
    }
    courant->suivant = NULL; 
    free(Supp); // liberer la zone memoire 
    return ((Cellule *)liste);
}
/* ***********************************************************************
    Nom de la fonction: SupprimerPListePos;
    Entree: Cellule *liste : la liste pour supprimer un element 
            int pos : la position de supprission
    Sortie: Cellule *liste : la nouvelle liste qui ne contient pas 
                l'element supprimer
    La fonction permet de supprimer l'element en position donnee en 
    parametre dans la liste 
**************************************************************************/
Cellule *SupprimerPListePos(Cellule *liste, int Pos)
{
    Cellule *courant, *Supp;
    int i = 1;
    if (!liste) return ((Cellule *)NULL); // tester si la liste existe
    if ((Pos <= 0) || (TaillePListe(liste) < Pos-1))
    {   // Position incorrect
        printf("\nErreur : Position incorrecte!");
        exit(0); // Quitter le programme
    }
    // Suppression en tete
    if (Pos == 1) return ((Cellule *)SupprimerPListeDebut(liste));
    // Suppression en queue
    if (Pos == TaillePListe(liste)) return ((Cellule *)SupprimerPListeFin(liste));
    // Suppression en milieu
    courant = liste;
    // tant qu'on n a pas arriver a la position
    while (++i < Pos) courant = courant->suivant; 
    Supp = courant->suivant; // pointer Supp sur l'element a supprimer
    courant->suivant = courant->suivant->suivant; 
    free(Supp); // liberer la memoire
    return ((Cellule *)liste);
}
/* ***********************************************************************
    Nom de la fonction: SupprimerPListeOccurence;
    Entree: Cellule *liste : la liste pour supprimer toutes occurences 
                d'un element 
            int val : la valeur de l'element qui sera supprimer
    Sortie: Cellule *liste : la nouvelle liste qui ne contient pas 
                les elements supprimers
    La fonction permet de supprimer toutes occurences d'un element dans 
    la liste 
**************************************************************************/
Cellule *SupprimerPListeOccurence(Cellule *liste, int val)
{
    Cellule *courant, *Supp;
    if (!liste) return ((Cellule *)NULL); // tester si la liste existe
    while (liste->info == val)
    {   // Suppression en tete
        Supp = liste;
        liste = liste->suivant;
        free(Supp);
    }
    courant = liste; // pointe courant en tete de la liste
    while (courant->suivant)
    {   // tant que courant a un suivant
        if (courant->suivant->info == val)
        {   // si on a trouve un element a supprimer
            Supp = courant->suivant;
            courant->suivant = courant->suivant->suivant;
            free(Supp); // liberer la zonz memoire
            continue; // tester l'element suivant
        }
        courant = courant->suivant;
    }
    return ((Cellule *)liste);    
}
/* ***********************************************************************
    Nom de la fonction: RechechePListe;
    Entree: Cellule *liste : la liste pour chercher un element 
            int val : la valeur de l'element a chercher sa position
    Sortie: int pos : la position de l'element cherche dans la liste s'il 
                existe
    La fonction permet de determiner la position d'un element donne dans la
    liste
**************************************************************************/
int RechechePListe(Cellule *liste, int val)
{
    Cellule *courant;
    int pos = 1;
    if (!liste) return ((int)-1);          // la liste n existe pas
    if (EstVide(liste)) return ((int)-2);  //  la liste est vide
    courant = liste;
    while (courant)
    {
        if (courant->info == val) return ((int)pos);
        pos++;
        courant = courant->suivant;
    }
    return ((int)-3);                   // element non trouve
}
/* ***********************************************************************
    Nom de la fonction: ConcatenationPListe;
    Entree: Cellule *liste1 : la premiere liste 
            Cellule *liste2 : la deuxieme liste
    Sortie: Cellule *liste : la liste composee des deux listes entree
    La fonction permet de concatener deux listes entree en parametres
**************************************************************************/
Cellule *ConcatenationPListe(Cellule *liste1, Cellule *liste2)
{
    Cellule *courant;
    if (!liste1) return ((Cellule *)liste2);
    if (!liste2) return ((Cellule *)liste1);
    liste1->suivant = liste2;
    return ((Cellule *)liste1);
}

// Recuperer la cellule du minimum
Cellule *RecupererMin(Cellule *liste, Cellule *AddMin[1])
{
    Cellule *courant, *ptMin;
    int min;
    // existance de la liste
    if (!liste)
    {
        AddMin[0] = NULL;
        return ((Cellule *)NULL);
    }
    min = liste->info;
    courant = liste;
    while (courant->suivant)
    {
        if (courant->suivant->info < min)
        {
            ptMin = courant;
            min = courant->suivant->info;
        }
        courant = courant->suivant;
    }
    // le min est en tete
    if (min == liste->info)
    {
        AddMin[0] = liste;
        liste = liste->suivant;
        AddMin[0]->suivant = NULL;
        return ((Cellule *)liste);
    }
    AddMin[0] = ptMin->suivant;
    ptMin->suivant = ptMin->suivant->suivant;
    AddMin[0]->suivant = NULL;
    return ((Cellule *)liste);  
}


Cellule *InsererListeOrdonnee(Cellule *liste, int val)
{
    Cellule *courant, *cell;
    cell = CreerCellule(val);
    // tester si la liste existe
    if (!liste) return ((Cellule *)cell); 
    // insertion en tete
    if (cell->info < liste->info)
    {
        cell->suivant = liste;
        return ((Cellule *)cell);
    }
    courant = liste; // pointer courant en tete
    while (courant->suivant) // tant que courant a un suivant
    {
        if (cell->info < courant->suivant->info )
        {   // Insertion en milieu
            cell->suivant = courant->suivant;
            courant->suivant = cell;
            return ((Cellule *)liste);
        }
        courant = courant->suivant;
    }
    // Insertion en queue
    courant->suivant = cell;
    return ((Cellule *)liste);
}

Cellule *ConcatenationOrdonneeListes(Cellule *liste1, Cellule *liste2)
{
    Cellule *liste = NULL, *courant;
    int l2 = 0;
    courant = liste1;
    while (courant)
    {        
        liste = InsererListeOrdonnee(liste,courant->info);
        courant = courant->suivant;
        if (!courant && !l2) 
        {
            l2 = 1;
            courant = liste2;
        }
    }
    return ((Cellule *)liste);
}

Cellule *SupprimerDoublons(Cellule *liste)
{
    Cellule *courant, *ptr, *pred;
    if(!liste) return ((Cellule *)NULL);
    courant = liste;
    while (courant)
    {
        ptr = courant->suivant;
        pred = courant;
        while (ptr)
        {
            if (ptr->info == courant->info)
            {
                pred->suivant = pred->suivant->suivant;
                free(ptr);
                ptr = pred;
            }
            pred = ptr;
            ptr = ptr->suivant;
        }
        courant = courant->suivant;   
    }
    return ((Cellule *)liste);
}

// Test
void main()
{
    Cellule *liste = NULL, *liste2 = NULL;
    int r,a;
    printf("\nInsertion en tete : ");
    liste = InsererPListeDebut(liste,12);
    AfficherPListe(liste);
    printf("\nInsertion en queue : ");
    liste = InsererPListeFin(liste,18);
    AfficherPListe(liste);
    printf("\nInsertion a la position 2 :");
    liste = InsererPlistePos(liste,2,16);
    AfficherPListe(liste);
    printf("\nInsertion Ordonnee");
    liste = InsererPListeOrdonnee(liste,14);
    AfficherPListe(liste);
    printf("\nLa taille de la liste : %d",TaillePListe(liste));
    a = 18; r = RechechePListe(liste,a);
    if (r == -1) printf("\nListe non existe");
    else if (r == -2) printf("\nListe vide");
    else if (r == -3) printf("\n%d n'existe pas dans la liste",a);
    else printf("\nLa position de %d est : %d",a,r);
    printf("\nInsertion en queue : ");
    liste = InsererPListeFin(liste,12);
    AfficherPListe(liste);
    printf("\nInsertion a la position 6 :");
    liste = InsererPlistePos(liste,6,23);
    AfficherPListe(liste);
    printf("\nSuppression de toutes les occurences de 12 : ");
    liste = SupprimerPListeOccurence(liste,12);
    printf("\nSuppression en tete : ");
    liste = SupprimerPListeDebut(liste);
    AfficherPListe(liste);
    printf("\nSuppression a la position 2 : ");
    liste = SupprimerPListePos(liste,2);
    AfficherPListe(liste);
    printf("\nSuppression en queue : ");
    liste = SupprimerPListeFin(liste);
    AfficherPListe(liste);  
    printf("\nConcatenation de deux listes : ");
    printf("\nListe 1 : ");
    AfficherPListe(liste);
    liste2 = InsererPListeDebut(liste2,13);
    liste2 = InsererPListeFin(liste2,14);
    liste2 = InsererPListeFin(liste2,23);
    liste2 = InsererPListeFin(liste2,30);
    printf("\nListe 2 :");
    AfficherPListe(liste2);
    liste = ConcatenationPListe(liste, liste2);
    AfficherPListe(liste);
    printf("\n**********************************");
    // liste = InsererPListeFin(liste,10);
    // AfficherPListe(liste);
    // Cellule *cell[1];
    // liste = RecupererMin(liste,cell);
    // AfficherPListe(liste);
    // printf("\nLe Min : %d",cell[0]->info);
    printf("\n**********************");
    Cellule *liste3 = NULL, *liste4 = NULL;
    liste3 = InsererPListeFin(liste3,3);
    liste3 = InsererPListeFin(liste3,4);
    liste3 = InsererPListeFin(liste3,3);
    liste3 = InsererPListeFin(liste3,3);
    liste3 = InsererPListeFin(liste3,4);
    liste3 = InsererPListeFin(liste3,4);
    liste3 = InsererPListeFin(liste3,2);
    liste3 = InsererPListeFin(liste3,3);
    liste3 = InsererPListeFin(liste3,1);
    liste3 = InsererPListeFin(liste3,2);
    AfficherPListe(liste3);
    liste3 = SupprimerDoublons(liste3);
    // liste4 = ConcatenationOrdonneeListes(liste3,liste2);
    // AfficherPListe(liste4);
    // AfficherPListe(liste2);
    AfficherPListe(liste3);

}