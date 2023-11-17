#include "sort.h"
/**
 * swap - function that swap two element
 * @x: first el
 * @y: second el
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * selection_sort - sorts a array using Selection sort alg
 * @array: array to be sorted
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t  i, j, min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j =  i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(&array[min], &array[i]);
			print_array(array, size);

		}
	}
}
