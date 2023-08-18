#include "main.h"
#include <sys/stat.h>

/**
 * finding_the_path - find the operation checking a path
 * @path: strings array with directiories
 * @args_array: array of arguments
 * Return: 1/0
 */
int finding_the_path(char **path, char **args_array)
{
	int a = 0;
	char *t = NULL;

	while (path[a] != NULL)
	{
		t = malloc(strlen(args_array[0]) + strlen(path[a]) + 2);

		strcpy(t, path[a]);
		strcat(t, "/");
		strcat(t, args_array[0]);

		if (access(t, F_OK) == 0)
		{
			executing(t, args_array);
			free(t);
			return (0);
		}
		free(t);
		a++;
	}
	return (127);
}
