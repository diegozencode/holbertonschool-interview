#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "menger.h"

/**
 * menger - draws a 2D Meger Sponge
 * @level: the level of the Menger Sponge to draw
 */
void menger(int level)
{
	if (level == 0)
	{
		printf("#\n");
	}
	if (level >= 1)
	{
		size_t row;
		size_t col;
		size_t size = (size_t)pow(3, level);

		for (row = 0; row < size; row++)
		{
			for (col = 0; col < size; col++)
			{
				if (check(row, col))
				{
					printf("#");
				}
				else
				{
					printf(" ");
				}
			}
			printf("\n");
		}
	}
}

/**
 * check - check print character
 * @row: row menger
 * @col: col menger
 * Return: 1 to print the character, 0 to print space
 */
size_t check(size_t row, size_t col)
{
	while (row > 0 || col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
		{
			return (0);
		}
		row = row / 3;
		col = col / 3;
	}
	return (1);
}
