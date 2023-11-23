//Définition de la structure 

typedef struct Cellule
{
    int info;
    struct Cellule *filsGauche;
    struct Cellule *filsDroit;
}Arbre;


//Initialisation d'une arbre

Arbre *InitArbre()
{
    Arbre *NE;
    if(!NE)
    {
        printf("\n Erreur d'allocation ! ");
        exit(0);
    }
    NE->info=NE->filsDroit=NE->filsGauche=NULL;

    return ((Arbre *)NE);
}

//Insertion d'un element dans un arbre

Arbre AddElemnt(Arbre *MonArabre,int value)
{
    if (!MonArabre)
    {
        MonArabre->info=value;
        MonArabre->filsDroit=MonArabre->filsGauche=NULL;
        return ((Arbre *)MonArabre);
    }

    
    
}
