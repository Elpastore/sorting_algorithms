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
 * partition - rearrange the array based on pivot
 * @array: the array;
 * @low: low index;
 * @high: high index
 * @size: size of array
 * Return: return the last sorted
 */
int partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot  = array[high];
	ssize_t i;
	ssize_t j = low - 1;

	for (i =  low; i < high; i++)
	{
		if (array[i] < pivot)
		{
			j++;
			if (j != i)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[j + 1])
	{
		swap(&array[j + 1], &array[high]);
		print_array(array, size);
	}
	return (j + 1);

}
/**
 * lomoto -quick sort  algo using lomoto
 * @array: the array
 * @low: low index;
 * @high: high index
 * @size: size of array
 */
void lomoto(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pos;

	if (low < high)
	{
		pos = partition(array, low, high, size);
		lomoto(array, low, pos - 1, size);
		lomoto(array, pos + 1, high, size);
	}
}
/**
 * quick_sort - sort using quick sort algo
 * @array: array to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomoto(array, 0, size - 1, size);
}
