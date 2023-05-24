#include "main.h"

/**
 * handle_sigint - It checks if signal is SIGINT and prints newline and prompt.
 * @signal: Is the signal number.
 * Return: nothing.
 */

void handle_sigint(int signal)
{
	if (signal == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * shell_exit - It exits shell.
 * @line: A dinamically allocated string that needs to be freed before exiting.
 * @args: Are the arguments passed to the exit command.
 * Return: does not return (the shell is terminated).
 */

int shell_exit(char **args, char *line)
{
	int exit_code = 0;

	if (args[1] != NULL)
	{
		exit_code = _atoi(args[1]);

		/* additional check incase atoi fails */
		if (exit_code == 0 && args[1][0] != '0')
		{
			return (-1);
		}
	}

	free(line);
	free_memory(2, args);
	exit(exit_code);
}

/**
 * print_environment_variables - It prints environment variables.
 * Return: 0
 */

int print_environment_variables(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		size_t len = _strlen(environ[i]);

		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	return (0);
}
