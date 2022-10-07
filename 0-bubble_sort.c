#include "sort.h"

/**
* bubble_sort - This sorts an array in ascending order using the bubble
* sort algorithm
* @array: the array to be sorted
* @size: size of the array
* return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, siz;
	int tmp;

	siz = size;
	for (i = 0; i < (siz - 1); i++)
	{
		for (j = 0; j < (siz - (i + 1)); j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
		siz--;
	}
}
