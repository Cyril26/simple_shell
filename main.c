#include "main.h"

/**
 * main - Is the entry point which continuously takes input from user.
 * @argv: Are the arguments.
 * @argc: Are the number of aguments.
 * Return: Exit program on failure and 0 on success.
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	int count;
	int *line;
	char **args;
	size_t n = 0;

	signal(SIGINT, handle_sigint);
	while (1)
	{
		int loops;
		loops++;
		line = NULL;
		args = NULL;

		/* reading input from user */

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		if (getline(&line, &n, stdin) == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_FAILURE);
		}

		/* tokenizing input and printing error message */

		count = argsCount(line);
		args = tokenize(line, count);

		if (args != NULL && args[0] != NULL)
		{
			if (_strcmp(args[0], "exit") == 0)
			{
				if (shell_exit(args, line) == -1)
					print_command_error(argv, args, loops);
			}
			else
			{
				if (executeCommand(args) == -1)
					print_command_error(argv, args, loops);
			}
		}

		free(line);
		free_memory(2, args);
	}

	return (0);
}
