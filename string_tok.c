#include "main.h"

char **string_tok(char *line, char *delimits);

/**
 * string_tok - tokenizes strings into substrings
 * @line: string to tokenize
 * @delimits: delimiters to tokenize
 * Return: token array
 */

char **string_tok(char *line, char *delimits)
{
	char **tokenStor;
	int i, l = 0, n, tokentot, slen = 0;

	if (!line)
		return (NULL);
	if (!(*line))
		return (NULL);

	tokentot = tokenident(line, delimits);

	tokenStor = malloc(sizeof(char *) * (tokentot + 1));

	for (i = 0; i < tokentot; i++)
	{
		while (line[l] == *delimits || line[l] == delimits[1])
			l++;

		slen = substring_length(line + l, delimits);

		tokenStor[i] = malloc(sizeof(char) * (slen + 1));

		for (n = 0; n < slen; n++, l++)
			tokenStor[i][n] = line[l];
		tokenStor[i][n] = '\0';
	}
	tokenStor[i] = NULL;

	return (tokenStor);
}
