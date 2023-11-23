#include<stdio.h>
#include<stdlib.h>
// Prototype
int PGCD(int a, int b);
int PPMC(int a, int b);
// Programme principale
void main()
{
    printf("\n%d",PGCD(20,5));
    printf("\n%d",PPMC(10,6));
}

int PGCD(int a, int b)
{
    int r;
    if (b == 0) return ((int)a); // si b = 0, le PGCD est a
    while (b != 0) // tant que b != 0
    {
        r = a%b; // affecter a r le reste de la devision euclidienne de a par b
        a = b; // affecter a a la valeur de b
        b = r; // affecter a b la vaaleur de r
    }
    return ((int)a);    
}

int PPMC(int a, int b)
{
    // return ((int)(a*b)/(PGCD(a,b)));
    int i = 0;
    if (a*b == 0) return ((int)0);
    while (((a*++i)%b) != 0);
    return ((int)(a*i));
}