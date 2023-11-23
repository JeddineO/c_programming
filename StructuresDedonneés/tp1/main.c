#include <stdio.h>
#include <stdlib.h>

//Le minimum
int Min(int a,int b,int c)
{
    if(a>b && a>c) return a;
    if(b>a && b>c) return b;
    return c;
}

//Des nombres encore des nombres

int Sum(int N)
{
    int i,sum=0;
    for(i=0;i<=N;i++)sum+=i;
}

int SumNotZero(int N)
{
    int i,sum=0;
    for(i=0;i<=N;i++)if((i%10)!=0)sum+=i;
    return ((int)N);
}


//Somme d'entiers

//fonction pour verifier que le nombre ne contiene pas des 0

int  Check(int nbr)
{
    int n=nbr;
    int x;
    int result=0;
    int test=0;

    while(n!=0)
        {
        x=n%10;
        n=n/10;
        if(x==0) test=1;
        result=result*10+x;

    }

    if(!test)return ((int)result);
    return ((int)0);
}


int SumN(int N)
{
    int i,sum=0;
    for(i=0;i<=N;i++)sum+=Check(i);
    return ((int)sum);
}

//Le plus gran deviseur

int PGCD(int a,int b)
{
    int i,pcgd=0;
    for(i=1;i<=a/2;i++)
    {
        if(((a%i)==0) && ((b%i)==0) ) pcgd=i;
    }
    return ((int)pcgd);
}
//Le plus petit deviseur

int PPMC(int a,int b)
{
    int i,ppmc=0;
    for(i=a/2;i>1;i--)
    {
        if(((a%i)==0) && ((b%i)==0) ) ppmc=i;
    }
    return ((int)ppmc);
}


int main()
{
    int sum=0;
    printf("%d",SumN(10));

}




