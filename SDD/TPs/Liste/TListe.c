#include<stdio.h>
#include<stdlib.h>
// Declaration des constantes
#define MaxElem 30 // Taille maximale des tableaux
// Definition de la structure
typedef struct
{
    int info[MaxElem]; // Tableau des elements
    int IDE; // Indice du Dernier Element
}TListe;

// 1- Initialiser la liste
int Init_TListe(TListe *liste)
{
    if (!liste) return ((int)0); // test si la zone memoire existe
    liste->IDE = -1; // la liste est vide
    return ((int)1); 
}
// 2- S'avoir si la liste est vide
int EstVide(TListe *liste)
{
    if (!liste) return ((int)-1); // test si la zone memoire existe
    return ((int)(liste->IDE == -1));
}
// 3- S'avoir si la liste est saturee
int EstSaturee(TListe *liste)
{
    if (!liste) return ((int)-1); // test si la zone memoire existe
    return ((int)(liste->IDE == (MaxElem-1)));
}
// 4- La taille de la liste
int TailleTListe(TListe *liste)
{
    if (!liste) return ((int)-1); // test si la zone memoire existe
    return ((int)liste->IDE+1);
}
// 5- Afficher la liste
void AfficherListe(TListe *liste)
{
    int i;
    if (!liste)
    {
        printf("\nListe inexiste!");
        exit(0); // Quitter le programme
    }
    if (EstVide(liste)) printf("\nLa liste est vide"); // liste vide
    else
    {
        printf("\nListe : ");
        for (i = 0; i <= liste->IDE; i++) // parcourir la liste
            printf("%d\t",liste->info[i]); // afficher element par element
    }  
}
// 6- Inserer un element a la liste
int InsererTListe(TListe *liste, int Elem)
{
    if (!liste) return ((int)-1); // test si la zone memoire existe
    if (EstSaturee(liste)) return ((int)0); // test si la liste est saturee
    liste->info[++liste->IDE] = Elem; // Insertion a la fin de la liste
    return ((int)1);
}
// 7- Inserer un element dans une position donnee a la liste
int InsererTListePos(TListe *liste, int Pos, int Elem)
{
    int i;
    if (!liste) return ((int)-1); // Tester si la zone memoire existe
    if (EstSaturee(liste)) return ((int)0); // Tester si la liste est sature
    if ((0 > Pos) || (Pos >= MaxElem)) return ((int)-2); // La position entree doit etre appartient a [0,MaxElem[
    i = ++liste->IDE; // incrementer IDE et l'affecter a i
    while (i > Pos) // tant qu'on a pas encore arriver a la position Pos
        liste->info[i--] = liste->info[i]; // Tasser les elements apres la position d'une case
    liste->info[Pos] = Elem; // affecter Elem dans la position Pos
    return ((int)1);
}
// 8- Inserer un element dans une liste ordonnee
int InsererTListeOrdonnee(TListe *liste, int Elem)
{
    int i;
    if (!liste) return ((int)-1); // Tester si la zone memoire existe
    if (EstSaturee(liste)) return ((int)0); // Tester si la liste est sature
    i = ++liste->IDE;
    while ((0 <= i) && (liste->info[--i] > Elem)) // tant qu'on n'a pas arriver a un element <= Elem 
        liste->info[i+1] = liste->info[i]; // Tasser l'element 
    liste->info[i+1] = Elem; // Inserer l'element 
    return ((int)1);
}
// 9- Supprimer le dernier element de la liste
int SupprimerElem(TListe *liste)
{
    if (!liste) return ((int)-1); // Tester si la zone memoire existe
    liste->IDE--; // decrimenter l'indice du dernier element
    return ((int)1);
}
// 10- Supprimer un element donne de la liste (la premiere occurence)
int SupprimerElemDonne(TListe *liste, int Elem)
{
    int i = 0;
    if (!liste) return ((int)-1); // Tester si la zone memoire existe
    // tant qu'on n'a pas trouver Elem incrementer i
    while ((liste->info[i]!=Elem) && (i<= liste->IDE)) i++; 
    if (liste->info[i]!=Elem) return ((int)0); // si Elem n'existe pas dans la liste
    while (i < liste->IDE)
    {
        liste->info[i] = liste->info[i+1]; // tasser les elements apres l'element d'une case en arriere
        i++;
    }
    liste->IDE--; // decrimenter l'indice du dernier element
    return ((int)1);
}
// 11- Supprimer toutes les occurences d'un element dans la liste
int SupprimerOccurenceElem(TListe *liste, int Elem)
{
    int i = 0, tmpIDE = -1; // la variable occ pour stocker le nombre d'occurence
    if (!liste) return ((int)-1); // Tester si la zone memoire existe
    for (i = 0; i <= liste->IDE; i++) // parcourir la liste
    {
        // si on trouve un element a supprimer
        if(liste->info[i] != Elem) liste->info[++tmpIDE] = liste->info[i];
    }
    liste->IDE = tmpIDE; // changer l'indice du dernier element
    return ((int)1);
}
// 12- Recherche d'un element dans la liste
int RechercheTListe(TListe *liste, int Elem)
{
    int i = 0;
    if (!liste) return ((int)-1); // Tester si la zone memoire existe
    if (EstVide(liste)) return ((int)-2); // Tester si la liste est vide
    while ((liste->info[i] != Elem) && (i <= liste->IDE))
        i++;
    if (liste->info[i]==Elem) return ((int)i); // retourner la position 
    return ((int)-3); // element non trouve
}
// 13- Recherche d'un element dans une liste ordonnee
int RechercheTListeOrdonnee(TListe *liste, int Elem)
{
    int gauche = 0, droite = liste->IDE; // borne gauche et droite
    int i;
    if (!liste) return ((int)-1); // Tester si la zone memoire existe
    if (EstVide(liste)) return ((int)-2); // Tester si la liste est vide
    while (gauche < droite)
    {
        i = (gauche + droite)/2;
        if (liste->info[i] == Elem) return ((int)i); // Element trouve
        if (liste->info[i] < Elem) gauche = i+1; // changer la borne gauche
        else droite = i; // changer la borne droite 
    }
    return ((int)-3); // element non trouve
}

// Programme Principale
void main()
{
    TListe liste;
    int r, a, pos, c;
    printf("\n********** Manipulation des Liste à l'aide des tableaux **********");
    do 
    {   
        printf("\n----------------entrer un choix----------------\n");
        printf("\n0- Arreter le programme");
        printf("\n1- Creer une liste");
        printf("\n2- Inserer un element a la fin de la liste");
        printf("\n3- Inserer un element a une position");
        printf("\n4- Inserer un element dans une liste ordonnee");
        printf("\n5- Supprimer un element a la fin de la liste");
        printf("\n6- Supprimer un element donne de la liste");
        printf("\n7- Supprimer tous les occurences d'un element");
        printf("\n8- Determiner la position d'un element dans une liste");
        printf("\n9- Determiner la position d'un element dans une liste ordonnee");
        printf("\n10- Determiner la taille de la liste ");
        printf("\n11- Afficher les element de la liste");
        printf("\nVotre choix : ");
        scanf("%d",&c);
        switch (c)
        {
            case 0:
                printf("\n-----------------------------------------------");
            case 1:
                r = Init_TListe(&liste);
                if (r == 1) printf("\nLa liste est initialiser avec succes");
                else printf("\nLa liste n'est pas initialiser");
                break;
            case 2:
                printf("\nEntrer la valeur de l'element que vous voulez inserer : ");
                scanf("%d",&a);
                r = InsererTListe(&liste,a);
                if (r == 1) printf("\nInsertion bien effectuee");
                else if(r == 0) printf("\nLa liste est saturee");
                else printf("\nLa liste non existe");
                break;
            case 3:
                printf("\nEntrer la valeur de l'element que vous voulez inserer : ");
                scanf("%d",&a);
                printf("\nEntrer la position : ");
                scanf("%d",&pos);
                r = InsererTListePos(&liste,pos,a);
                if (r == 1) printf("\nInsertion bien effectuee");
                else if (r == 0) printf("\nLa liste est saturee");
                else if (r == -2) printf("\nLa position n'est pas valide");
                else printf("\nLa liste non existe");
                break;
            case 4:
                printf("\nEntrer la valeur de l'element que vous voulez inserer : ");
                scanf("%d",&a);
                r = InsererTListeOrdonnee(&liste,a);
                if (r == 1) printf("\nInsertion bien effectuee");
                else if(r == 0) printf("\nLa liste est saturee");
                else printf("\nLa liste non existe");
                break;
            case 5:
                r = SupprimerElem(&liste);
                if(r == 1) printf("\nSuppression bien effectuee");
                else printf("\nSuppression non effectuee");
            case 6:
                printf("\nEntrer la valeur de l'element que vous voulez supprimer : ");
                scanf("%d",&a);
                r = SupprimerElemDonne(&liste,a);
                if (r == 1) printf("\nSuppression bien effectuee");
                else if(r == 0) printf("\nL'element n'existe pas dans la liste");
                else printf("\nLa liste non existe");
                break; 
            case 7:
                printf("\nEntrer la valeur de l'element que vous voulez supprimer : ");
                scanf("%d",&a);
                r = SupprimerOccurenceElem(&liste,a);
                if (r == 1) printf("\nSuppression bien effectuee");
                else if(r == 0) printf("\nL'element n'existe pas dans la liste");
                else printf("\nLa liste non existe");
                break;
            case 8:
                printf("\nEntrer la valeur de l'element que vous voulez chercher sa position : ");
                scanf("%d",&a);
                r = RechercheTListe(&liste,a);
                if (r == -1) printf("\nListe non existe");
                else if (r == -2) printf("\nListe vide");
                else if (r == -3) printf("\n%d n'existe pas dans la liste",a);
                else printf("\nLa position de %d est : %d",a,r);
                break;
            case 9:
                printf("\nEntrer la valeur de l'element que vous voulez chercher sa position : ");
                scanf("%d",&a);
                r = RechercheTListeOrdonnee(&liste,a);
                if (r == -1) printf("\nListe non existe");
                else if (r == -2) printf("\nListe vide");
                else if (r == -3) printf("\n%d n'existe pas dans la liste",a);
                else printf("\nLa position de %d est : %d",a,r);
                break;
            case 10:
                printf("\n%d",TailleTListe(&liste));
                break;
            case 11:
                AfficherListe(&liste);
                break;
            default:
                printf("\nChoix invalid");
        }
    } while (c);
}