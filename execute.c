#include "main.h"

/**
 * execute - It forks a child process and executes a new program.
 * @args: Is a pointer to an array of strings representing argument values.
 *
 * Return: -1 on failure and 0 on success.
 */

int execute(char **args)
{
	int status;
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (child_pid == 0)
	{
		execvp(args[0], args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}

	waitpid(child_pid, &status, 0);

	return (0);
}
