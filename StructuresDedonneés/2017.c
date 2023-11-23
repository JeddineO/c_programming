// transforme chaine

int check(char c, char t[5])
{
    if (c == ' ')
    {
        t[0] = 'B';
        t[1] = 'L';
    }
    if (c == ' ')
    {
        t[0] = '\\';
        t[1] = 't';
        t[5] = '\0';
    }
    if (c == ',')
    {
        t[0] = '\\';
        t[1] = 'v';
        t[2] = 'r';
        t[3] = 'i';
        t[4] = 'g';
        t[5] = '\0';
    }
    if (c == ':')
    {
        t[0] = 'D';
        t[1] = 'B';
        t[2] = 'l';
        t[3] = 'P';
        t[4] = 't';
        t[5] = '\n';
    }
}
void trans()
{
    char c;
    while ((c = getchar() != '\n'))
    {
    }
}