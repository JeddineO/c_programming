#include<stdio.h>
#include<stdlib.h>

#define MOD(x,y) x%y
#define DIV(x,y) x/10
// Prototype
float SommeInverse_1_N(int);
int ExisteZero(int);
// Programme principale
void main()
{
    printf("\n%f",SommeInverse_1_N(2));
}

int ExisteZero(int val)
{
    while (MOD(val,10) && DIV(val,10))
        val = DIV(val,10);
    if (MOD(val,10)==0) return ((int)1);
    if (DIV(val,10)==0) return ((int)0);
}
float SommeInverse_1_N(int N)
{
    float somme = 0;
    for (int i = 1; i <= N; i++)
        if (!ExisteZero(i))
            somme += (float)(1/(float)i);
    return ((float)somme);    
}