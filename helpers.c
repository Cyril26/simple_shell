#include "main.h"

/**
 * _atoi - It converts string to integers.
 * @string: Is the input string.
 * Return: -1 on failure or converted string.
 */

int _atoi(char *string)
{
	int i;
	unsigned int number = 0;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] >= '0' && string[i] <= '9')
			number = number * 10 + (string[i] - '0');
		else
			return (-1);
	}

	return (number);
}

/**
 * _strlen - It counts the size of string.
 * @string: Is the input string.
 * Return: size
 */

int _strlen(char *string)
{
	int count = 0;

	while (string[count] != '\0')
	{
		count++;
	}
	return (count);
}

/**
 * _strdup - It creates a duplicate of a string.
 * @string: Is the input string.
 * Return: NULL on failure or pointer to duplicate string
 */

char *_strdup(char *string)
{
	int length, i;
	char *copy;

	length = _strlen(string);

	if (string == NULL)
		return (NULL);

	copy = malloc((length + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
	{
		copy[i] = string[i];
	}

	return (copy);
	free(copy);
}

/**
 * _strcmp - It compares two strings.
 * @string1: Is the first input string.
 * @string2: Is the second input string.
 * Return: -1 on failure or diffrence between ASCII values in both strings
 */

int _strcmp(char *string1, char *string2)
{
	int i = 0, sub;

	if (string1 == NULL || string2 == NULL)
		return (-1);

	while (string1[i] != '\0' && string2[i] != '\0')
	{
		sub = string1[i] - string2[i];
		if (sub != 0)
			break;
		i++;
	}

	return (sub);
}

/**
 * _strconcat - It concatenates 2 strings.
 * @string1: Is the first input string.
 * @string2: Is the second input string.
 * Return: NULL on failure or pointer to concatenated string
 */

char *_strconcat(char *string1, char *string2)
{
	int i, j = 0;

	int totalLen = _strlen(string1) + _strlen(string2) + 2;
	/* +2 for '/' and '\0' */

	char *result = malloc(sizeof(char) * totalLen);

	if (result == NULL)
		return (NULL);

	for (i = 0; string1 && string1[i] != '\0'; i++)
	{
		result[j] = string1[i];
		j++;
	}

	if (j != 0)
	{
		result[j] = '/';
		j++;
	}

	for (i = 0; string2 && string2[i] != '\0'; i++)
	{
		result[j] = string2[i];
		j++;
	}

	result[j] = '\0';
	free(string2);
	return (result);
	free(result);
}
