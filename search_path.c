#include "main.h"

/**
 * find_matching_env_var - finds environment variables
 * @name: name of env variable to find
 * Return: PATH value
 */

char *find_matching_env_var(char *name)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strcmp(environ[i], name) == 0)
			break;
		else if (environ[i + 1] == NULL)
			perror("Matching environment variable not found");
	}

	return (environ[i]);
}
