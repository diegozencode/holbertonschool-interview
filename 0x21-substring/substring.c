#include "substring.h"
#include <string.h>

/**
 * find_substring - finds a substring in a string
 * @s: string to scan
 * @words: array of words to search for
 * @nb_words: number of words to search for
 * @n: address of the number of words found
 * Return: allocated array storing each index in s or NULL if not found
 **/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i, j, k;
	int current, count, validate;
	int len, words_len;
	int *index, *match;

	if (s == NULL || words == NULL || nb_words < 1 || n == NULL)
		return (NULL);

	len = strlen(s);
	words_len = strlen(words[0]);
	index = malloc(sizeof(int) * len);
	if (index == NULL)
		return (NULL);
	match = malloc(sizeof(int) * nb_words);
	if (match == NULL)
		return (NULL);
	for (i = count = 0; i <= len - nb_words * words_len; i++)
	{
		memset(match, 0, sizeof(int) * nb_words);
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				current = i + j * words_len;
				validate = strncmp(s + current, words[k], words_len);
				if (!*(match + k) && !validate)
				{
					*(match + k) = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			*(index + count++) = i;
	}
	free(match);
	*n = count;
	return (index);
}
