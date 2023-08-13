#include "main.h"

int finding_the_path(char **array_path, char **arguments)
{
    int n = 0;
    char *temporary_pointer = NULL;

    while (array_path[n] != NULL)
    {
        temporary_pointer = malloc(strlen(arguments[0]) + strlen(array_path[n]) + 2);

        strcpy(temporary_pointer, array_path[n]);
        strcat(temporary_pointer, "/");
        strcat(temporary_pointer, arguments[0]);

        if (access(temporary_pointer, F_OK) == 0)
        {

            executing(temporary_pointer, arguments);
            free(temporary_pointer);
            return (0);
        }
        free(temporary_pointer);
        n++;
    }
    return (127);
}
