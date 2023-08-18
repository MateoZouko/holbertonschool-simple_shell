#include "main.h"

int tokenindent(char *string, char *del);
char **tokstr(char *ln, char *del);
int substring_length(char *string, char *del);

/**
 * tokenident - counting the number of tokens
 * @string: string to tokenize
 * @del: delimiters to tokenize
 * Return: number of tokens
 */

int tokenident(char *string, char *del)
{
	int tot_tok = 0, a, ln = 0;

	ln = strlen(string);

	for (a = 0; a < ln; a++)
	{
		if (string[a] && string[a] != del[0] && string[a] != del[1])
		{
			tot_tok++;
			a += substring_length(string + a, del);
		}
	}
	return (tot_tok);
}

/**
 * substring_length - calculates the longitude of a substring
 * @string: string
 * @del: delimiters to tokenize
 * Return: calculated length of the substring.
 */

int substring_length(char *string, char *del)
{
	int a = 0;

	while (string[a] && string[a] != del[0] && string[a] != del[1])
	{
		a++;
	}
	return (a);
}
