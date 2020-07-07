#include "slide_line.h"

/**
 * slide_line - slide and merge it
 * @line: head of the array
 * @size: lenght of the array
 * @direction: 0 to the left 1 o the right
 * Return: 1 if success or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	size_t head = 0;

	if (line == NULL || size < 1 || (direction < 0 || direction > 1))
	{
		return (0);
	}

	if (size == 1)
		return (1);

	for (size_t i = 1; i < size; i++)
	{
		if (line[i] > 0)
		{
			if (line[i] == line[head])
			{
				line[head] = line[i] + line[i];
				line[i] = 0;
				head = head + 1;
			}
			else
			{
				if (line[head] == 0)
				{
					line[head] = line[i];
					line[i] = 0;
				}
				else
				{
					head = head + 1;
				}
			}
		}
	}
	return (1);
}
