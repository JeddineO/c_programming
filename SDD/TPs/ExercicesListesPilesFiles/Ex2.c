#include<stdio.h>
#include<stdlib.h>

#define MOD(x) x%10
// Prototype
int Somme_1_N(int);
int Somme2_1_N(int);
int Somme_1_N_Ss_Div_0(int);
int Somme2_1_N_Ss_Div_0(int);
// Programme principale
void main()
{
    printf("\n%d",Somme_1_N(10));
    printf("\n%d",Somme2_1_N(10));
    printf("\n%d",Somme_1_N_Ss_Div_0(10));
    printf("\n%d",Somme2_1_N_Ss_Div_0(10));
}
// a- Calcule la somme de N entiers positifs allant de 1 a N
int Somme_1_N(int N)
{
    int i, somme = 0;
    if (N < 1)
    {   // si N est negatif ou null
        printf("\nErreur: le nombre passe est negatif ou null!"); // afficher un message d'erreur
        exit(0); // quitter
    }
    for (i = 1; i <= N; i++) // pour i allant de 1 à N
        somme += i; // ajouter la valeur de i a la variable somme
    return ((int)somme);
}
int Somme2_1_N(int N)
{
    // if(!N) return ((int)0);
    // return ((int) N+Somme2_1_N(N-1));
    return ((int)((N*(N+1))/2));
}

// b- Calcule la somme des entiers positifs parmis les N, [1,N], en evitant ceux se terminent par 0
int Somme_1_N_Ss_Div_0(int N)
{
    int i, somme = 0;
    if (N < 1)
    {   // si N est negatif ou null
        printf("\nErreur: le nombre passe est negatif ou null!"); // afficher un message d'erreur
        exit(0); // quitter
    }
    for (i = 1; i <= N; i++) // pour i allant de 1 à N 
        if(MOD(i)) somme += i; // ajouter la valeur de i a la variable somme 
    return ((int)somme);
}
int Somme2_1_N_Ss_Div_0(int N)
{
    if (!N) return ((int)0);
    if (MOD(N)==0) return ((int)Somme2_1_N_Ss_Div_0(N-1));
    return ((int)(N+Somme2_1_N_Ss_Div_0(N-1)));
}