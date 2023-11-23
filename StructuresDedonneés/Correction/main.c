#include <stdio.h>
#include <stdlib.h>
//#define Min((x),(y)) (x)<(y>?(x):(y);


//Le minimum
int Min2Nbr(int a,int b)
{
    if(a>b)return ((int)a);
    return ((int)b);
}

int Min3Nbr(int a,int b,int c)
{
    return ((int)Min2Nbr(Min2Nbr(a,b),c));
}

//Des nombre encore des nombres

int Somme1_N(int N)
{
    int i;
    for(i=0;i)
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
