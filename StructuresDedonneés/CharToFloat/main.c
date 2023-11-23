#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define CS '\n'

int main()
{

  char car;
  int i=1,j=0,signe=1,checksign=0,entier;
  double valeur=0;

  printf("Entrer votre chaine : ");

  while((car=getchar()) != CS)
  {
    //Verifier que le signe - ne se repete plusieur fois
    if(car=='-' && checksign==1)
    {
        return ((int)2);
    }
    //Verifier que le signe - existe
    if(car=='-' && checksign==0)
    {
        checksign=1;
        signe=-1;
    }
    //Verifier que la chaine est un symbole numerique
    if(('0'<=car)&&(car<='9'))
        {
            entier=(int)((int)car-(int)'0');
            valeur = valeur*10+entier;
        }

     //L'indice de la virgule
     i++;
     if(car=='.') j=i;

  }
  valeur=valeur*signe;
  //Diviser la valeur sur 10^(le nombre de caractere apres la virgule)
  if(j)valeur=valeur/pow(10,i-j);
  printf("%f",valeur);



    return 0;
}
