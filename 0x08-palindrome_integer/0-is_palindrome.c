#include "palindrome.h"
/**
* is_palindrome - checks whether or not a given unsigned int is a palindrome
* @n: is the number to be checked
* Return: 1 if n is a palindrome, and 0 otherwise
*/
int is_palindrome(unsigned long n)
{
	unsigned long i = n, rev = 0;

	while (i != 0)
	{
		rev = rev * 10;
		rev = rev + i % 10;
		i = i / 10;
	}
	if (n == rev)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
