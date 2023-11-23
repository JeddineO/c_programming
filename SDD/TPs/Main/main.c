#include<stdio.h>
#include<stdlib.h>


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

