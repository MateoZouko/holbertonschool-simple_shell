#include "main.h"

void our_shell(void);

/**
 * main - the main with the main loop
 * @argc: num of args
 * @argv: array of pointers to the args
 * Return: 0/1
 */

int main(int argc, char **argv)
{
	char **array_of_tok = NULL, **paths = NULL;
	size_t ln = 0;
	int a = 0, op = 0;
	char *l = NULL, *path = NULL;
	(void)argc;
	(void)argv;

	while (true)
	{
		if (isatty(STDIN_FILENO))
			printf("$: ");

		if (getline(&l, &ln, stdin) == -1)
		{
			break;
		}

		cleaningstring(l);

		if (!tokenident(l, " "))
			continue;

		array_of_tok = string_tok(l, " \n\t");

		if (strcmp(array_of_tok[0], "env") == 0)
		{
			for (a = 0; environ[a] != NULL; a++)
			{
				printf("%s\n", environ[a]);
			}
			free_str(array_of_tok);
			continue;
		}

		if (strcmp(array_of_tok[0], "exit") == 0)
		{
			free_str(array_of_tok);
			break;
		}

		a = 0;

		while (environ[a] != NULL)
		{
			if (strncmp(environ[a], "PATH=", 5) == 0)
			{
				path = strdup((environ[a] + 5));
				break;
			}
			a++;
		}

		paths = string_tok(path, ":");
		free(path);

		if (access(array_of_tok[0], X_OK) == 0)
		{
			executing(array_of_tok[0], array_of_tok);
		}
		else
		{
			op = finding_the_path(paths, array_of_tok);
		}

		free_str(array_of_tok);
		free_str(paths);
	}
	if (l)
		free(l);

	return (op);
}
