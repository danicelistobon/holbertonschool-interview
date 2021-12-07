#!/usr/bin/python3
""" Island Perimeter
"""


def island_perimeter(grid):
    """Function that returns the perimeter of the island described in grid
    """
    if not grid:
        return 0
    if not all(type(arr) == list for arr in grid):
        return 0
    width = len(grid[0]) - 1
    if not all(len(arr) == width + 1 for arr in grid):
        return 0
    islands = connections = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j]:
                islands += 1
                if j < len(grid[0]) - 1 and grid[i][j + 1] == 1:
                    connections += 1
                if i < len(grid) - 1 and grid[i + 1][j] == 1:
                    connections += 1

    return 4 * islands - 2 * connections
