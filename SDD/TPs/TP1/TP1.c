/* Lire une suite de caractere numerique puis retoure le nombre equivalent */
// declaration des bibliotheques
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// Declaration des constante
#define RC '\n'
// Prototype
double Transforme();
int EstNumerique(char c);
// Programme principale
void main()
{
    double a = Transforme();
    printf("\nle reel extrait de la chaine numerique est : %f",a);
}
// la fonction qui retourn l'entier equivalent d'une suite de caractere numerique
double Transforme()
{
    char c;
    int control; // pour stocker la valeur retournee par la fonction "EstNumerique"
    int firstPass = 1; // pour tester la premiere lecture 
    int f = 0; // pour distinguer la partie entiere et la partie reel
    int signe = 1; // pour stocker le signe du nombre
    double result = 0; // pour stocker le nombre extrait
    printf("\nEntrer une chaine numerique : "); 
    while ((c = getchar())!= RC)
    {
        if(firstPass == 1){ // Lors de la lecture du premier caractere
            firstPass = 0; // pour indiquer qu'on a lu le premier caractere
            if ((c == '-') || (c == '+'))
            {   // recuperer le signe du nombre
                if (c == '-')
                    signe = -1; 
                continue; // passer a l'iteration suivante
            }        
        }
        control = EstNumerique(c); 
        switch (control)
        {
            case -1:
                printf("\nErreur: caractere non numerique!");
                exit(0);  
            case 11:
                return ((double)(result*signe));  
            case 12:
                if(f == 0) // on y encore dans la partie entiere
                {
                    f = -1; // passer a la partier reel
                    break;
                }
                printf("\nErreur: un autre point est tape!");
                exit(0);
            default:
                if (f == 0)
                    result = result*10 + (double)control;
                else
                    result += (double)((double)(control)*pow(10,f--));
        }
    }
    return ((double)(result*signe));
}
// fonction qui test le caractere en parametre s'il est numerique
int EstNumerique(char c)
{
    if(('0'<=c) && (c<='9')) // le caractere est un nombre
        return ((int)(c-'0'));
    if(c == ' ') // le caractere est un blanc
        return ((int)11);
    if(c == '.') 
        return ((int)12); // le caractere est un point
    return ((int)(-1)); // sinon
}