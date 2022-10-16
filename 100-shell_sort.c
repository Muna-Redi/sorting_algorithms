#include "sort.h"

/**
 * shell_sort - sorts an array of integers in
 * ascending order using shell sort algorithm
 * @ar: array to be sorted
 * @siz: size of the array
 * Return: void
 */
void shell_sort(int *ar, size_t siz)
{
	int gap, i, j, z, size;

	size = siz;
	gap = get_gap(size);

	while (gap >= 1)
	{
		i = 0;
		for (j = gap; j < size; j++)
		{
			z = i;
			if (ar[j] < ar[i])
				swap(&ar[i], &ar[j]);
			while (z - gap >= 0)
			{
				if (ar[z] < ar[z - gap])
				{
					swap(&ar[z], &ar[z - gap]);
				}
				z -= gap;
			}
			i++;
		}
		gap = (gap / 3);
		print_array(ar, siz);
	}
}
/**
* swap - swaps two integers
* @a: first integer
* @b: second intrger
* Return: void
*/
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * get_gap - gets the gap using knuth sequence
 * @size: size of the array
 * Return: gap to be used
 */
int get_gap(int size)
{
	int gap;

	if (size <= 0 || size == 1)
		return (0);
	if (size > 1 && size <= 3)
		return (1);

	gap = 1;
	while (gap <= size / 3)
	{
		gap = (gap * 3 + 1);
	}
	return (gap);
}
