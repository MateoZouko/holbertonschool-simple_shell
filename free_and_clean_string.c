#include "main.h"

void free_str(char **argument)
{
    unsigned int a = 0;

    if (!argument)
        return;
    if (!*argument)
        return;

    for (; argument[a]; a++)
    {
        free(argument[a]);
    }
    free(argument);
}

int cleaningstring(char *l)
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
