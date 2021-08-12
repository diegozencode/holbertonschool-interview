#include "regex.h"

/**
 * regex_match - checks if a patter matches a given string
 * @str: the string to scan
 * @pattern: the regular expression
 * Return: 1 if the pattern matches, 0 otherwise
 **/
int regex_match(char const *str, char const *pattern)
{
	int check_dot = 0;
	int check_asterisk = 0;

	if (str == NULL || pattern == NULL)
	{
		return (0);
	}

	check_dot = *str && (*str == *pattern || *pattern == '.');
	check_asterisk = *(pattern + 1) == '*';

	if (!*str && !check_asterisk)
	{
		return (*pattern ? 0 : 1);
	}

	if (check_dot && check_asterisk)
	{
		return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
	}
	else if (check_dot && !check_asterisk)
	{
		return (regex_match(str + 1, pattern + 1));
	}
	else if (check_asterisk)
	{
		return (regex_match(str, pattern + 2));
	}

	return (0);
}
