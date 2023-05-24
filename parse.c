#include "main.h"

/**
 * argsCount - counts number of arguments in the string returned by getline.
 *
 * @line: input string
 *
 * Return: count on success, -1 on failure
 */

int argsCount(char *line)
{
	int i, j, flag, count = 1;
	char *delim = " :";

	flag = i = 0;

	if (!line)
		return (-1);

	for (i = 0; line[i] != '\0'; i++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (line[i] == delim[j] && flag == 0)
			{
				count++;
				flag = 1;
				break;
			}
		}
		if (delim[j] == '\0')
			flag = 0;
	}

	/* 1 added to make space for NULL*/
	return (count + 1);
}

/**
 * tokenize - tokenizes the arguments
 *
 * @line: input string from the cli
 * @size: number of arguments.
 *
 * Return: pointer to list of tokens on success, NULL on failure
 */

char **tokenize(char *line, int size)
{

	char *token;
	int i = 0;
	char *delim = " :'\n''\t'";
	char **list_of_tokens = malloc(sizeof(char *) * size);

	if (line == NULL || list_of_tokens == NULL)
		return (NULL);

	token = strtok(line, delim);

	while (token)
	{
		list_of_tokens[i] = _strdup(token);
		if (list_of_tokens[i] == NULL)
		{
			free_memory(2, list_of_tokens); /* Free previously allocated tokens */
			free(list_of_tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		i++;
	}
	list_of_tokens[i] = NULL;

	return (list_of_tokens);
}

/**
 * replace_equal_sign - removes all chars before
 * equal sign and equal sign itself
 *
 * @string: input string
 * Return: Nothing
 */

void replace_equal_sign(char **string)
{
	int i = 0;

	while (string[0][i] != '=')
	{
		string[0][i] = ':';
		i++;
	}
	string[0][i] = ':';
}
