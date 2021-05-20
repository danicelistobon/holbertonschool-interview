#include "holberton.h"
/**
* main - multiplies two numbers
* @argc: number of things in the command line
* @argv: array of string values
* Return: 0 in success
*/
int main(int argc, char *argv[])
{
	if (argc != 3 || !_isdigit(argv[1]) || !_isdigit(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}
	multiply(argv[1], argv[2]);
	return (0);
}

/**
* _isdigit - Checks for a digit (0 through 9)
* @c: digit
* Return: return 1 if c is a digit or 0 otherwise
*/
int _isdigit(char *c)
{
	if (*c >= '0' && *c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
* multiply - multiplies two numbers
* @a: first num
* @b: second num
*/
void multiply(char *a, char *b)
{
	int i, len_a, len_b, total, a_number, b_number, res = 0, tmp;
	int *ptr;

	len_a = _strlen(a);
	len_b = _strlen(b);
	tmp = len_b;
	total = len_a + len_b;
	ptr = malloc(sizeof(int) * total);
	if (!ptr)
	{
		return;
	}
	for (len_a--; len_a >= 0; len_a--)
	{
		a_number = a[len_a] - '0';
		res = 0;
		len_b = tmp;
		for (len_b--; len_b >= 0; len_b--)
		{
			b_number = b[len_b] - '0';
			res += ptr[len_b + len_a + 1] + (a_number * b_number);
			ptr[len_a + len_b + 1] = res % 10;
			res /= 10;
		}
		if (res)
			ptr[len_a + len_b + 1] = res % 10;
	}
	while (*ptr == 0)
	{
		ptr++;
		total--;
	}
	for (i = 0; i < total; i++)
		printf("%i", ptr[i]);
	printf("\n");
}

/**
* _strlen - returns the length of a string
* @s: pointer
* Return: length
*/
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
