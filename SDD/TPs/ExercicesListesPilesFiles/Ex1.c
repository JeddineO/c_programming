#include<stdio.h>
#include<stdlib.h>

#define Min2Nbre(a,b) a<b ? a: b
// Prototype
int Min_3_Entiers(int, int, int);
// Programme principale
void main()
{
    int a, b, c;
    printf("\nDonner 3 entiers : ");
    printf("\nLe premier : "); scanf("%d",&a);
    printf("\nLe deuxieme : "); scanf("%d",&b);
    printf("\nLe troisieme : "); scanf("%d",&c);
    printf("\nLe minimum de %d et %d et %d est : %d",a,b,c,Min_3_Entiers(a,b,c));    
}
// La fonction qui retourne le minimum de trois entiers
int Min_3_Entiers(int a, int b, int c)
{
    return ((int)(Min2Nbre(Min2Nbre(a,b),c)));
}