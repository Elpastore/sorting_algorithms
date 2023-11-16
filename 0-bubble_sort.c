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
 * bubble_sort - sort an array using Bubble sort algo
 * @array: array to be sorted
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	if (array != NULL && size > 2)
	{
		for (i = 0; i < size - 1; i++)
		{
			swapped = false;
			for (j = 0; j < size - 1 - i; j++)
			{
				if (array[j] > array[j + 1])
				{
					swap(&array[j], &array[j + 1]);
					print_array(array, size);
					swapped = true;
				}
			}
			if (swapped == false)
				break;
		}
	}
}
