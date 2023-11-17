#include "sort.h"
/**
 * shell_sort - sorts an array using shell sort alg
 * @array: array to be sorted
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 0;
	size_t i, j;
	int key;

	if (array == NULL && size < 2)
		return;

	while (gap < size / 3)
		gap = (gap * 3) + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			key = array[i];
			j = i;
			while (j >= gap && array[j - gap] > key)
			{
				array[j] = array[j - gap];

				j = j - gap;
			}
			array[j] = key;
		}
		gap = gap / 3;
		print_array(array, size);
	}
}
