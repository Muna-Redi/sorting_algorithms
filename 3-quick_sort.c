#include "sort.h"

/**
* quick_sort - sorts an array of integers in ascending order using
* quick sort algorithm
* @array: the array of integers
* @size: size of the array
* Return: void
*/

void quick_sort(int *array, size_t size)
{
	int s;

	s = size;
	sort(array, 0, (size - 1), s);

}
/**
* partition - partitions an array using lomuto partition
* @array: the array to be partitioned
* @size: size of the array
* Return: partion index
*/
int partition(int *array, int lo, int hi, int size)
{
	int j, i, pivot;

	j = lo;
	i = lo;
	pivot = array[hi];

	for (; j < hi; j++)
	{
		if (pivot > array[j])
		{
			if (array[i] > array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i += 1;
		}
	}
	if (array[i] > array[hi])
	{
		swap(&array[i], &array[hi]);
		print_array(array, size);
	}
	return (i);
}
/**
* sort - sorts the array recursively with lomuto partition
* @arr: the array tot be sorted
* @low: first index of the array
* Return: void
*/
void sort(int *arr, int lo, int high, int size)
{
	int part;

	if (lo < high)
	{
		part = partition(arr, lo, high, size);
		sort(arr, lo, (part - 1), size);
		sort(arr, (part + 1), high, size);
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
