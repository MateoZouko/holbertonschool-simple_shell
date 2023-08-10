#include "main.h"

void free_str(char **input)
{
    unsigned int n = 0;

    if (!input)
    return;
    if(!*input)
    return;

    for (; input[n]; n++)
    {
        free(input[n]);
    }
    free(input);
}

int string_cleaning(char *l)
{
    int a = 0;

    while (l[a])
    {
        if (l[a] == '\n')
        {
            l[a] = '\0';
        }
        a++;
    }
    return (0);
}
