/*
Réécriture d'une phrase en la codant
*/

char CoderPhrase(int CleMaj, int CleMin, int CleNum)
{
    char c;
    while ((c = getchar()) != '\n')
    {
        c = c + CleMaj;
    }
    return ((char)c);
}

char DeCoderPhrase(int CleMaj, int CleMin, int CleNum)
{
    char c;

    while ((c = getchar()) != '\n')
    {
        c = c - CleMaj;
    }
    return ((char)c);
}