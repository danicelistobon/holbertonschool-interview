#include "menger.h"
/**
* menger - draws a 2D Menger Sponge
* @level: level of the Menger Sponge to draw
*/
void menger(int level)
{
	int i, j, lim;

	if (level < 0)
	{
		return;
	}

	for (i = 0, lim = pow(3, level); i < lim; i++)
	{
		for (j = 0; j < lim; j++)
		{
			One(i, j) == 1 ? printf("%c", '#') : printf("%c", ' ');
		}
		printf("\n");
	}
}
/**
* One - checks if indices are (1, 1)
* @r: row index
* @c: column index
* Return: 1 if (1, 1), 0 otherwise
*/

int One(int r, int c)
{
	while (r != 0 && c != 0)
	{
		if (r % 3 == 1 && c % 3 == 1)
		{
			return (0);
		}
		r /= 3;
		c /= 3;
	}
	return (1);
}
