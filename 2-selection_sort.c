#include "sort.h"

/**
* selection_sort - sorts an array of integers in an ascending order
* using selection sort algorithm
* @array: array of integers to be sorted
* @size: size of the array
* Return: void
*/
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, swap;
	int tmp, on_off;

	for (i = 0; i < size; i++)
	{
		j = i + 1;
		tmp = array[i];
		on_off = 0;
		while (j < size)
		{
			if (array[j] < tmp)
			{
				tmp = array[j];
				swap = j;
				on_off = 1;
			}
			if (j == size - 1 && on_off == 1)
			{
				array[swap] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
			j++;
		}
	}
}
