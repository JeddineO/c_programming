#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int check(char phrase[],char car[])
{
    int i=0;
    char test[];
    while(phrase[i]!='\0')
    {
        while(phrase[i]!=' ')
        {
           int j=0;
           test [j]=phrase[i];
           j++;
        }
    }
}

int main()
{
    char *phrase=" la vie est belle  ";
    *phrase=(char *)malloc(sizeof(char));
    gets(phrase);
    printf("%s",*phrase);
    return 0;
}
