#include "main.h"

/**
 * print_command_error - prints "not found" when there is an error
 *
 * @argv: argument variables
 * @args: the arguments returned after tokenizing the command
 * @count: number of times infinite loop executed
 *
 * Return: Nothing
 */

void print_command_error(char **argv, char **args, int count)
{
	char *space = ": ";
	char *error = "not found";

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, space, _strlen(space));
	print_error_number(count);
	write(STDERR_FILENO, space, _strlen(space));
	write(STDERR_FILENO, args[0], _strlen(args[0]));
	write(STDERR_FILENO, space, _strlen(space));
	write(STDERR_FILENO, error, _strlen(error));
	write(STDERR_FILENO, "\n", 1);
}

/**
 * print_error_number - prints an integer value as an error number
 * @count: integer input
 * Return: Nothing
 */

void print_error_number(int count)
{
	char buffer[20];
	int i = 0;
	int x = count;

	/**
	 * ensures that at least one digit is stored
	 * in the buffer array whether it's 0
	 */
	do {
		buffer[i++] = '0' + (x % 10);
		x /= 10;
	} while (x > 0);

	while (i > 0)
	{
		write(STDERR_FILENO, &buffer[--i], 1);
	}
}

/**
 * free_memory - frees malloc'd spaces of double pointers
 * @count: number of pointer = 2
 * Return: Nothing
 */

void free_memory(int count, ...)
{
	int j;
	va_list args;

	va_start(args, count);

	if (count == 2)
	{
		char **ptr = va_arg(args, char **);

		if (ptr != NULL)
		{
			for (j = 0; ptr[j] != NULL; j++)
				free(ptr[j]);

			free(ptr);
		}
		return;
	}

	va_end(args);
}

/**
 * executeCommand - determines which function to use to execute a command
 * @args: command
 * Return: Nothing
 */

int executeCommand(char **args)
{
	struct stat commandInfo;

	if (isBuiltInCommand(args) == 0)
		return (0);

	search(args);

	if (stat(args[0], &commandInfo) == -1)
		return (-1);

	if (stat(args[0], &commandInfo) == 0 && S_ISREG(commandInfo.st_mode) == 0)
		return (-1);

	if (execute(args) == -1)
		return (-1);

	return (0);
}

