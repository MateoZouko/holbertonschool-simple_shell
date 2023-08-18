#include "main.h"

/**
* free_str - Free the array of strings
* @argument: The array
* Return: void
*/
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

/**
 * cleaningstring - removes the newline from the input
 * @l: pointer to input
 * Return: 0/1
 */
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
