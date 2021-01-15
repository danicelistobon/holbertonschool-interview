#include "sandpiles.h"
/**
* sandpiles_sum - computes the sum of two sandpiles
* @grid1: grid to sum
* @grid2: grid to sum
* Return: nothing
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grid(grid1, grid2);

	while (!is_stable(grid1))
	{
		p_grid(grid1);
		toppling(grid1);
	}
}
/**
* sum_grid - sum two sandpiles
* @grid1: grid to sum
* @grid2: grid to sum
* Return: nothing
*/
void sum_grid(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
}
/**
* is_stable - checks if the grid is stable
* @grid: grid to check
* Return: 0 for true, otherwise 1
*/
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				return (0);
			}
		}
	}
	return (1);
}
/**
* p_grid - print 3x3 grid
* @grid: 3x3 grid
* Return: nothing
*/
void p_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
			{
				printf(" ");
			}
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
* toppling - topple the grid
* @grid: grid
* Return: nothing
*/
void toppling(int grid[3][3])
{
	int i, j;
	int gridnext[3][3] = {
	{0, 0, 0},
	{0, 0, 0},
	{0, 0, 0}
	};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				grid[i][j] -= 4;

				if (i - 1 >= 0 && i - 1 < 3)
				{
					gridnext[i - 1][j] += 1;
				}
				if (j - 1 >= 0 && j - 1 < 3)
				{
					gridnext[i][j - 1] += 1;
				}
				if (i + 1 >= 0 && i + 1 < 3)
				{
					gridnext[i + 1][j] += 1;
				}
				if (j + 1 >= 0 && j + 1 < 3)
				{
					gridnext[i][j + 1] += 1;
				}
			}
		}
	}
	sum_grid(grid, gridnext);
}
