//--------

void Coder()
{
    char c;
    int cle = 2;
    while ((c = getchar()) != '\n')
    {
        c = (char)('a' + (c + cle) % 26);
        printf("%c", c);
    }
}