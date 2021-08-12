#!/usr/bin/python3
"""
Given a 2D grid of 1s and 0s, find the perimeter of the island.
"""


def island_perimeter(grid):
    """
    :param grid: list of list of 1s and 0s
    """
    if not grid:
        return 0
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2
    return perimeter
