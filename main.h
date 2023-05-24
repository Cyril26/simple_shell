#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/**
 * struct builtin - It stores information about various built-in functions,
 * including their names and corresponding function pointers.
 * @name: This is a pointer to a character.
 * @func: This is a function pointer.
 */

typedef struct builtin
{
	char *name;
	int (*func)(void);
} builtin;

int argsCount(char *line);
char **tokenize(char *line, int size);
int _atoi(char *string);
int _strcmp(char *string1, char *string2);
char *_strdup(char *string);
char *_strconcat(char *string1, char *string2);
int _strlen(char *string);
void print_command_error(char **argv, char **args, int count);
void print_error_number(int count);
int print_environment_variables(void);
void free_memory(int count, ...);
int executeCommand(char **args);
int shell_exit(char **args, char *line);
int execute(char **args);
void replace_equal_sign(char **string);
char *find_matching_env_var(char *name);
int search(char **args);
int isBuiltInCommand(char **args);
void handle_sigint(int sig);

extern char **environ;

#endif
