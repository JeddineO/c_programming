#include<stdio.h>
#include<stdlib.h>
// Constantes
#define BL ' '
#define RC '\n'
#define NbElem 30
// Prototype
void lire_str(char mot[NbElem]);
int long_str(char chaine[NbElem]);
int Comp_str(char str1[NbElem], char str2[NbElem]);

void main()
{
    char chaine[NbElem], chaine2[NbElem];
    lire_str(chaine);
    lire_str(chaine2);
    printf("\nTaille : %d",long_str(chaine));
    printf("\n%d",Comp_str(chaine,chaine2));
   
}

void lire_str(char mot[NbElem])
{
    int i = 0;
    char c;
    // Eprouvez les blancs
    while ((c=getchar())==BL);
    do
    {
        mot[i++] = c;
        c = getchar();
    } while ((c!=BL) && (c!=RC));
    mot[i] = '\0';   
    printf("\n%s",mot); 
}
int long_str(char chaine[NbElem])
{
    int l = 0;
    while (chaine[l] != '\0') l++;
    return ((int)l);
}
int Comp_str(char str1[NbElem], char str2[NbElem])
{
    int i = 0;
    // test des caracteres des deux mots
    while ((str1[i]==str2[i])&&(str1[i]!='\0')&&(str2[i]!='\0'))
        i++;
    if (!i) return ((int)-1);
    if (str1[i]==str2[i]) return ((int)0);
    return ((int)i);
}