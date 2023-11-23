#include <stdio.h>
#include <stdlib.h>
#define CS '\n'

int main()
{
    int entier;
    float reel;
    char caractere;
    char phrase[12];
    puts("Entrez un entier : ");
	scanf("%d", &entier);
	printf("L'entier est %d : ", entier);

	puts("\n\nEntrez un reel : ");
	scanf("%f", &reel);
	printf("Le reel est %.3f : ", reel);

	getchar();
	puts("\n\nEntrez un caractere : ");
	scanf("%c", &caractere);
	printf("Le caractere est %c : ", caractere);

	puts("\n\nEntrez une chaine de caractere : ");
	scanf("%s", phrase);
	printf("La chaine est %s : ", phrase);   // si la chaine contient des espace en utilise  gets(chaine);
    return 0;
}
