#include "sort.h"
#include <time.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[1000], i;
	size_t n = sizeof(array) / sizeof(array[0]);
	time_t t;

	srand(time(&t));

	for (i = 0; i < 999; i++)
		array[i] = rand() %  99 + 1;
	print_array(array, n);
	printf("\n");
	selection_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
