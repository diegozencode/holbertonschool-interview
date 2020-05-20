#include "sandpiles.h"
/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: grid 3x3 of integers
 * @grid2: grid 3x3 of integers
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	print_grid(grid1);
	print_grid(grid2);
}

/**
 * print_grid - iterates over the grid and prints it
 * @grid: grid 3x3 of integers
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
