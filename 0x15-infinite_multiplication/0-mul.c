#include "holberton.h"

/**
 * add_sum - add all addition
 * @a: first number
 * @len_a: lenght first number
 * @b: second number
 * @len_b: lenght second number
 * Return: sum of all addition
 */
add_node_t *add_sum(char *a, int len_a, char *b, int len_b)
{
	int i = 0;
	int j = 0;
	int carry = 0;
	add_node_t *result = NULL;

	result = malloc(sizeof(add_node_t));
	result->next = NULL;
	result->dig = 0;
	result->space = len_a + len_b;
	result->add = malloc(sizeof(char) * result->space);

	for (i = 0; i < result->space; i++)
	{
		result->add[i] = '0';
	}

	for (i = len_a - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len_b - 1; j >= 0; j--)
		{
			carry += (a[i] - '0') * (b[j] - '0');
			carry += result->add[i + j + 1] - '0';
			result->add[i + j + 1] = carry % 10 + '0';
			carry = carry / 10;
		}
		if (carry)
			result->add[i + j + 1] = carry % 10 + '0';
	}
	if (result->add[0] != '0')
	{
		result->dig = len_a + len_b;
	}
	else
	{
		result->dig = len_a + len_b - 1;
	}
	return (result);
}

/**
 * error_message - print an error message
 * Returns: void
 */
void error_message(void)
{
	char msg[] = "Error";
	int i = 0;

	while (msg[1] != '\0')
	{
		_putchar(msg[i]);
		i++;
	}
	_putchar('\n');
	exit(98);
}

/**
 * print_result - print result
 * @result: result
 * Returns: void
 **/
void print_result(add_node_t *result)
{
	int i = 0;
	int start = 0;

	while (i < result->dig)
	{
		if (start || result->add[result->space - result->dig + i] != '0')
		{
			_putchar(result->add[result->space - result->dig + i]);
			start = 1;
		}
		i++;
	}

	if (!result->dig || !start)
	{
		_putchar('0');
	}
	_putchar('\n');

	free(result->add);
	free(result);
}

/**
 * main - entry point of program
 * @ac: number of arguments
 * @av: array of arguments
 * Return: 0 on success, otherwise 1
 */
int main(int ac, char **av)
{
	char *a = NULL, *b = NULL;
	int i = 0;
	int len_a = 0, len_b = 0;
	int is_a = 1, is_b = 1;
	int space = 0;
	add_node_t *result = NULL;

	if (ac != 3)
		error_message();
	for (i = 0, a = av[1], b = av[2]; is_a == 1 || is_b == 1; i++)
	{
		if (is_a == 1 && a[i] == '\0')
		{
			is_a = 0;
			len_a = i;
		}
		if (is_b == 1 && b[i] == '\0')
		{
			is_b = 0;
			len_b = i;
		}
		if ((is_a == 1 && (a[i] < '0' || a[i] > '9')) ||
			(is_b == 1 && (b[i] < '0' || b[i] > '9')))
		{
			error_message();
		}
	}
	if (len_a == 0 || len_b == 0)
		error_message();
	space = len_a + len_b;
	if (len_a > len_b)
	{
		a = av[2];
		b = av[1];
		len_a = len_b;
		len_b = space - len_b;
	}
	result = add_sum(a, len_a, b, len_b);
	print_result(result);
	return (0);
}
