#include "sandpiles.h"
/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: grid 3x3 of integers
 * @grid2: grid 3x3 of integers
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int valid_grid1;
	int i, j;

	valid_grid1 = sandpiles_test(grid1);

	if (valid_grid1 == 0)
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				grid1[i][j] = grid2[i][j];
			}
		}
	}
}

/**
 * sandpiles_test - validate that all grid is 0
 * @grid1: grid 3x3 of integers 
 * Return: validation 0 for true and 1 for false
 */
int sandpiles_test(int grid1[3][3])
{
	int valid = 0;
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] != 0)
			{
				valid = 1;
			}
			break;
		}
	}
	return (valid);
}
