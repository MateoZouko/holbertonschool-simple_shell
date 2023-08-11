#include "main.h"

void our_shell(void);

int main(char **argv, int argc, char **environment)
{
    char **array_tok = NULL, **array_paths = NULL;
    size_t l = 0;
    int n = 0, op = 0;
    char *ln = NULL, *path = NULL;
    (void)argv;
    (void)argc;

    while (true)
    {
        if (isatty(STDIN_FILENO))
            printf("$: ");

        if (getline(&ln, &l, stdin) == -1)
        {
            break;
        }

        string_cleaning(ln);

        if (!number_of_token(ln, " "))
            continue;

        array_tok = string_tok(ln, "\n\t");

        if (strcmp(array_tok[0], "environment") == 0)
        {
            for (n = 0; environment[n] != NULL; n++)
            {
                printf("%s\n", environment[n]);
            }
            free_str(array_tok);
            continue;
        }
    }
}