#include "holberton.h"
/**
 * wildcmp - compare two strings
 * @s1: pointer to the first element
 * @s2: number of elements in array
 * Return: 1 if the pattern matches, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (!*s1)
	{
		if (*s2 == '*')
		{
			return (wildcmp(s1, s2 + 1));
		}
		return (!*s2);
	}
	if (*s2 == '*')
	{
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	}
	if (*s1 != *s2)
	{
		return (0);
	}

	return (wildcmp(s1 + 1, s2 + 1));
}
