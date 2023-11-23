#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include<math.h>
 //structure d'un arbre � l'aide des pointeurs
typedef struct Ned
{
 int info;//�tiquette
 struct Ned * left;//pointeur sur fils gauche
 struct Ned * right;//pointeur sur fils droit
}Noeud;//structure noeud


Noeud*creer_noeud(int val)
{
    Noeud *Nd;//declaration du nouveua noeud
    Nd      =(Noeud*)malloc(sizeof(Noeud));
    if(!Nd)//echec d'allocation
    {
        printf("erreur d'allocation");
        exit(-1);//sortir du programme
    }//fin if
    //initialisation du n�ud cr�e
    Nd->info=val;
    Nd->left=Nd->right=NULL;
    return ((Noeud*)Nd);
}

void Prefix_aff(Noeud *Arbre)
{
    if(Arbre)
    {
        printf("%d\t",Arbre->info);
        Prefix_aff(Arbre->left);
        Prefix_aff(Arbre->right);
    }
}//fin fonction


void infix_aff(Noeud *Arbre)
{
    if(Arbre)
    {
        infix_aff(Arbre->left);
        printf("%d\t",Arbre->info);
        infix_aff(Arbre->right);
    }
}//fin fonction


void postfix_aff(Noeud*Arbre )
{
    if(Arbre)
    {
        postfix_aff(Arbre->left);
        postfix_aff(Arbre->right);
        printf("%d\t",Arbre->info);
    }
}//fin fonction



int taille_Arbre(Noeud*Arbre)
{
    if(!Arbre) return((int)0);//arbre vide
//retourner le nombre des fils gauche et droit et la racine
    return ((int)(1+taille_Arbre(Arbre->left)+taille_Arbre(Arbre->right)));
}//fin fonction

int hauteur_Arbre(Noeud*Arbre)
{
    int hg,//pour stocker la hauteur max gauche
        hd;//pour stocker la hauteur max droit
    if(!Arbre) return((int)0);//arbre vide
//retourner le nombre des fils gauche et droit et la racine
    else
    {
        hg=hauteur_Arbre(Arbre->left);//hauteur gauche max
        hd=hauteur_Arbre(Arbre->right);//hauteur droite max
//retourner la plus grande entre les deux
        return((hd<hg)?((int)hg+1):((int)hd+1));
    }
}//fin fonction



int max_arbre(Noeud* Arbre)
{
    int max = Arbre->info;// max prend la valeur du racine
    if (Arbre->left)
    {
        //determiner le max du sous arbre gauche
        int gauche = max_arbre (Arbre->left);
//comparer et affecter le max avec le max gauche
        max = (max > gauche ) ? max : gauche;
    }
//refait la m�me proc�dure avec le sous arbre droit
    if (Arbre->right)
    {
        int droit = max_arbre (Arbre->right);
        max = (max > droit ) ? max : droit;
    }
    return max;
}

int min_arbre(Noeud* Arbre)
{
    int min = Arbre->info;// min prend la valeur du racine
    if (Arbre->left)
    {
        //determiner le min du sous arbre gauche
        int gauche = min_arbre (Arbre->left);
//comparer et affecter le min avec le min gauche

        min = (min< gauche ) ? min : gauche;
    }
//refait la meme procedure avec le sous arbre droit
    if (Arbre->right)
    {
        int droit = min_arbre (Arbre->right);
        min = (min < droit ) ? min : droit;
    }
    return min;
}

void aff_feuilles(Noeud*Arbre )
{
    if(Arbre)
    {
        aff_feuilles(Arbre->left);
//si le noeud n'a pas des fils c'est une feuille
        if((!Arbre->left)&&(!Arbre->right))
//afficher la feuille
            printf(" \t\t\t%d\n",Arbre->info);
        aff_feuilles(Arbre->right);

    }
}//fin


void Aff_Arbre_horiz(Noeud *Arbre,int Niv)
{
    int esp; //Pour l'affichage des espaces
    if (Arbre) //Condition d'arret
    {
        //Affichage des fils droits
        Aff_Arbre_horiz(Arbre->right,Niv+1);
        printf("\n");
        for (esp = 0; esp < Niv; esp++)
        printf("\t");
        printf("%d",Arbre->info);
        //Affichage des fils gauches
        Aff_Arbre_horiz(Arbre->left,Niv+1);
    }
}//fin fonction


int rechercher(Noeud*Arbre,int val)
{
    int test=0;//test initialiser par 0
    if(Arbre)
    {
        //si la valeur est trouve test=0+1 sinon reste �gal 0
        if(Arbre->info==val) return 1;
//chercher dans le sous arbre gauche
        if (Arbre->left) test+= rechercher(Arbre->left,val);
// chercher dans le sous arbre droit
        if(Arbre->right) test+= rechercher(Arbre->right,val);
    }
//retourner test
    return test;
}

Noeud*Inserer_Arbre_horiz(Noeud*Arbre,int val)
{
    Noeud*Nd;
    if(!Arbre)//arbre vide ou (sous-arbre vide)
    {
        Nd=creer_noeud(val);
        return((Noeud*)Nd);
    }
    if(Arbre->info>val)//val inferieur a l'�tiquette du noeud
//insertion a gauche
        Arbre->left=Inserer_Arbre_horiz(Arbre->left,val);
    else// sinon
//insertion a droit
        Arbre->right=Inserer_Arbre_horiz(Arbre->right,val);
    return((Noeud*)Arbre);
}//fin fonction
/*
void affichage(Noeud*arbre)
{
    int aff,val;
    printf("\nQuelle type d'affichage voulez vous ?\n");
    printf("\t\t1 affichage prefixe \n");
    printf("\t\t2 affichage infixe \n");
    printf("\t\t3 affichage postfixe \n");
    printf("\t\t4 affichage schematise\n");
    printf("\t\t5 affichage des feuilles de l'arbre\n");
    scanf("%d",&aff);
    if(!arbre) printf("l'arbre est vide\n");
    else
    {
        //cas o� l�arbre est no vide
        switch (aff)
        {
        case 1:
            printf("-------\n");
            Prefix_aff(arbre);
            break;
        case 2:
            printf("-------\n");
            infix_aff(arbre);
            break;
        case 3:
            printf("-------\n");
            postfix_aff(arbre);
            break;
        case 4:
            printf("-------\n");
            Aff_Arbre_horiz(arbre,0);
            break;
        case 5:

            printf("\t\tvoici tous les feuilles de l'arbre\n");
            aff_feuilles(arbre);
            break;

        default:
            printf("choix invalide\n");
            break;
        }
    }//fin sinon
}*/
//Supprimer un element dans un arbre de recherche

//seccesseure
Noeud* successeure(Noeud*Arbre)
{
 Arbre =Arbre->right ;
 if(Arbre!=NULL)
 while(Arbre->right!=NULL)
 {
    Arbre = Arbre->right;
 }
  return((Noeud*)Arbre);

}

//  predecesseure
Noeud* predecesseure(Noeud*Arbre)
{
 Arbre =Arbre->left ;
 if(Arbre!=NULL)
 while(Arbre->left!=NULL)
 {
    Arbre = Arbre->left;
 }
  return((Noeud*)Arbre);

}

Noeud* eliminer(Noeud* Arbre,int ver)
{
    Noeud* temp=Arbre;//pointeur de suppression
//ver=1 pas de fils droit, 0 pas de fils gauche
    ver==1?(Arbre=Arbre->left):(Arbre=Arbre->right);
    free(temp);//supprimer le n�ud voulu
    return ((Noeud*)Arbre);
}


Noeud* supp_Arbre(Noeud*Arbre,int val)
{
    if (!Arbre) return NULL;
//si l'element est dans l'arbre gauche
    else if(val<(Arbre->info)) Arbre->left=supp_Arbre(Arbre->left,val);
//si l'element est dans l'arbre droit
    else if(val>(Arbre->info))Arbre->right=supp_Arbre(Arbre->right,val);
    else //val==Arbre->info
    {
// s'il n y a pas de fils droit
        if(!(Arbre->right)) Arbre=eliminer(Arbre,1);
// s'il n y a pas de fils gauche

        else if(!(Arbre->left)) Arbre=eliminer(Arbre,0);
//si il y a les deux (droit et gauche)
        else
            Arbre->right=supp_Arbre(Arbre->right,((Arbre->info)=min_arbre(Arbre->right)));
    }
    return ((Noeud*)Arbre);
}//fin fonction


int rechercherValeur(Noeud*Arbre,int val)
{
    int test=0;//test initialiser par 0
    if(Arbre)
    {
        //si la valeur est trouve test=0+1 sinon reste �gal 0
        if(Arbre->info==val) return 1;
//chercher dans le sous arbre gauche
        if (Arbre->left) return rechercher(Arbre->left,val);
// chercher dans le sous arbre droit
        if(Arbre->right) return rechercher(Arbre->right,val);
    }
//retourner test
    return 0;
}
int rechercheDoubles(Noeud *Arbre,int val)
{
    if(rechercherValeur(Arbre,val)||
       rechercherValeur(Arbre,val*2)||
       rechercherValeur(Arbre,val*4))
        return ((int)1);
    else
        return ((int)0);
}


void aff_Inerval(Noeud *Arbre,int a,int b)
{
    if(Arbre)
    {
        aff_Inerval(Arbre->left,a,b);
        if((a<=Arbre->info) && (Arbre->info<=b))
        {
            printf("%d\t",Arbre->info);
        }
        aff_Inerval(Arbre->right,a,b);
    }
}//fin fonction
int main ()
{
    Noeud*arbre =creer_noeud(8);

    printf("*******************************Insrtion de 4:*******************************\n");
    Inserer_Arbre_horiz(arbre,4);
    infix_aff(arbre);
    printf("\n");
    printf("*******************************Insrtion de 19:*******************************\n\n");
    Inserer_Arbre_horiz(arbre,19);
    infix_aff(arbre);
    printf("\n");
    printf("*******************************Insrtion de 17:*******************************\n\n");
    Inserer_Arbre_horiz(arbre,17);
    infix_aff(arbre);
    printf("\n");
    printf("*******************************Insrtion de 22:*******************************\n\n");
    Inserer_Arbre_horiz(arbre,22);
    infix_aff(arbre);
    printf("\n");
    printf("*******************************Insrtion de 21:*******************************\n\n");
    Inserer_Arbre_horiz(arbre,21);
    infix_aff(arbre);
    printf("\n");
    printf("*******************************Insrtion de 0:*******************************\n\n");
    Inserer_Arbre_horiz(arbre,0);
    infix_aff(arbre);
    printf("\n");
    printf("*******************************Insrtion de 6:*******************************\n\n");
    Inserer_Arbre_horiz(arbre,6);
    infix_aff(arbre);
    printf("\n");

    printf("*******************************Insrtion de 5:*******************************\n\n");
    Inserer_Arbre_horiz(arbre,5);
    infix_aff(arbre);
    printf("\n");
    printf("*******************************Insrtion de 16:*******************************\n\n");
    Inserer_Arbre_horiz(arbre,16);
    infix_aff(arbre);
    printf("\n");
    printf("*******************************Insrtion de 18:*******************************\n\n");
    Inserer_Arbre_horiz(arbre,18);
    infix_aff(arbre);
    printf("\n");
    printf("*******************************Insrtion de -1:*******************************\n\n");
    Inserer_Arbre_horiz(arbre,-1);
    infix_aff(arbre);
    printf("\n");
    printf("*******************************Affichage horizontale:**************************\n\n");
    Aff_Arbre_horiz(arbre,1);
    printf("\n*******************************Suppression de 4:*******************************\n\n");
    arbre=supp_Arbre(arbre,4);
    infix_aff(arbre);
    printf("\n");
    printf("*******************************Affichage horizontale:*******************************\n");
    Aff_Arbre_horiz(arbre,1);
  printf("\n*******************************Suppression de 19:*******************************\n\n");
    arbre=supp_Arbre(arbre,19);
    infix_aff(arbre);
    printf("\n");
    printf("*******************************Affichage horizontale:*******************************\n");
    Aff_Arbre_horiz(arbre,0);


    int n;
    n=rechercheDoubles(arbre,1);
    printf("\n%d",n);
    n=rechercher(arbre,5);
    printf("\n%d",n);
    printf("\n");
    printf("\n");
    aff_Inerval(arbre,2,11);


    /*Prefix_aff(arbre);
    printf("\n");
    postfix_aff(arbre);
    printf("\n");
    infix_aff(arbre);
  */
    /*affichage(arbre);*/
   // arbre=supp_Arbre(arbre,5);

  //  infix_aff(arbre);
}
