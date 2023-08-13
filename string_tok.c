#include "main.h"

char **string_tok(char *ln, char *del);

char **string_tok(char *ln, char *del)
{
    char **Storage_of_Tok;
    int a, b = 0, c, totaltoken, stringlength = 0;

    if (!ln)
        return (NULL);
    if (!(*ln))
        return (NULL);

    totaltoken = number_of_token(ln, del);
    Storage_of_Tok = malloc(sizeof(char *) * (totaltoken + 1));

    for (a = 0; a < totaltoken; a++)
    {
        while (ln[b] == *del || ln[b] == del[1])
            b++;

        stringlength = substringLength(ln + b, del);

        Storage_of_Tok[a] = malloc(sizeof(char) * (stringlength + 1));

        for (c = 0; c < stringlength; c++, b++)
            Storage_of_Tok[a][c] = ln[b];
        Storage_of_Tok[a][c] = '\0';
    }
    Storage_of_Tok[a] = NULL;

    return (Storage_of_Tok);
}
