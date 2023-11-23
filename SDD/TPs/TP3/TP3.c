// Déclaration des bibliotheques
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Declaration des constantes
#define NbElem 20
#define RC '\n'
// Prototype
void Lire_15Car(char chaine[NbElem]);
void Lire_10Car(char chaine[NbElem]);
void Saisir_Chaine(char chaine[NbElem]);
void AfficherTab(char chaine[NbElem]);
// Programme principale
void main()
{
    char c, chaine[NbElem];
    Lire_15Car(chaine); 
    fflush(stdin); // pour vider le buffer pour une prochaine lecture 
    Lire_10Car(chaine);
    fflush(stdin); // pour vider le buffer pour une prochaine lecture 
    Saisir_Chaine(chaine);
    AfficherTab(chaine);
}
void Lire_15Car(char chaine[NbElem])
{
    int i;
    printf("\nDonner une chaine de 15 caracteres : ");
    while (((chaine[i++]=getchar())!=RC) && (i<=15)); // lecture de 15 caracteres
    chaine[i-1] = '\0'; // une chaine de caractere se termine par '\0'
    printf("Affichage : %s",chaine); // Affichage de la chaine en tant que String
}
void Lire_10Car(char chaine[NbElem])
{
    int i;
    printf("\nSaisir une chaine de 10 caracteres : ");
    while (((chaine[i++]=getchar())!=RC) && (i<=10)); // lecture de 10 caracteres
    chaine[i-1] = '\0'; // une chaine de caractere se termine par '\0'
    printf("Affichage : %s",chaine); // Affichage de la chaine en tant que String
}
void Saisir_Chaine(char chaine[NbElem])
{
    int i = 0;
    printf("\nSaisir une chaine de caracteres : ");
    scanf("%s",chaine); // Lecture d'une chaine à l'aide de %s
    while (chaine[i] != '\0')
        printf("%c",chaine[i++]);
}
void AfficherTab(char chaine[NbElem])
{
    int i;
    printf("\nAffichage du tableau : ");
    for (i = 0; i < NbElem; i++) //parcourir le tableau jusqu'à NbElem et afficher son contenu
        printf("%c",chaine[i]); 
}