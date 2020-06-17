#include "palindrome.h"

/**
 * is_palindrome - checks if a unsigned int given is palindrome or not
 * @n: unsigned integer
 * Return: 1 if n is palindorme and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long digit;
	unsigned long number;

	if (n == 0)
		return (1);

	digit = n % 10;
	number = n;

	while (number / 10 != 0)
	{
		number = number / 10;
		digit = digit * 10;
	}

	if (number != n % 10)
		return (0);

	n = (n - digit) / 10;
	return (is_palindrome(n));
}
