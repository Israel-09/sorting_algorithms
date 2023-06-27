#include "sort.h"

/**
 * partition - partitions the array and sorts each partition.
 * @array: array to be sorted.
 * @start: lowest index of the partition.
 * @stop: highest index of the partition
 *
 * Return: the index of the pivot.
 */
size_t partition(int *array, int start, int stop, size_t n)
{
	int j, temp;
	int pivot, i;

	(void)n;
	pivot = array[stop];
	i = start - 1;
	for (j = start; j <= stop -1; j++)
	{
		if (array[j] < pivot)
		{
			++i;
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}
	}
	i++;
	temp = array[i];
	array[i] = pivot;
	array[stop] = temp;
	print_array(array, n);
	return (i);
}

/**
 * real_sort - performs the real quick sort function.
 * @array: the array to be sorted.
 * @stop: the highest index of the partition
 * @stop: lowest index of the partition.
 */

void real_sort(int *array, int start, int stop, size_t n)
{
	int pindex;

	if (start >= stop)
		return;
	pindex = partition(array, start, stop, n);
	real_sort(array, start, pindex - 1, n);
	real_sort(array, pindex + 1, stop, n);

}

/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm.
 *
 * @array: the array to be sorted.
 * @size: size to be sorted.
 */
void quick_sort(int *array, size_t size)
{
	if (array)
		real_sort(array, 0, (int)(size - 1), (int)(size));
}
