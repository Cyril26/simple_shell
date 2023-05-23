#include "main.h"

/**
 * isBuiltInCommand - searches the builtins for their functions
 * @args: command
 * Return: 0 on success, -1 on failure
 */

int isBuiltInCommand(char **args)
{
	builtin builtins[] = {
		{"env", print_environment_variables},
		{NULL, NULL}
	};

	int i = 0, isBuiltin = -1;

	while (builtins[i].name != NULL)
	{
		if (_strcmp(builtins[i].name, args[0]) == 0
				&& _strlen(builtins[i].name) == _strlen(args[0]))
		{
			isBuiltin = builtins[i].func();
			break;
		}
		i++;
	}

	return (isBuiltin);
}

/**
 * search_dirs - searches directories until a command is found
 * @dirs: directories to search
 * @args: command to search in the directories
 * Return:  0 on success, -1 on failure
 */

int search_dirs(char **dirs, char **args)
{
	char *cwd = getcwd(NULL, 0);
	struct stat sb;
	int i;

	for (i = 0; dirs[i] != NULL; i++)
	{
		if (args[0][0] == '/' || _strcmp(args[0], "./") == 0)
			break;

		chdir(dirs[i]);
		if (stat(args[0], &sb) == 0)
		{
			args[0] = _strconcat(dirs[i], args[0]);
			if (args[0] == NULL)
			{
				free(cwd);
				free_memory(2, dirs);
				return (-1);
			}
			break;
		}
	}
	chdir(cwd);
	free(cwd);
	if (dirs[i] == NULL)
	{
		free_memory(2, dirs);
		return (-1);
	}
	return (0);
}

/**
 * search - search for command in directories specified
 * by the "PATH" environment variable
 * @args: contains the commands to search for
 * Return: 0 on success, -1 on failure
 */

int search(char **args)
{
	char **command;
	char *path = _strdup(find_matching_env_var("PATH"));
	int count = argsCount(path);

	if (path == NULL)
		return (-1);
	if (count == -1)
	{
		free(path);
		return (-1);
	}
	replace_equal_sign(&path);
	command = tokenize(path, count);
	if (command == NULL)
	{
		free(path);
		return (-1);
	}
	if (search_dirs(command, args) == -1)
	{
		free(path);
		return (-1);
	}
	free(path);
	return (0);
}
