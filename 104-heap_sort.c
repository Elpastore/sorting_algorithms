#include "sort.h"
/**
 * swap - function that swap two element
 * @x: first element
 * @y: second element
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
/**
 * heapify - heapify operation
 * @array: the array
 * @size: size of array
 * @index: the index
 */
void heapify(int array[], int size, int index)
{
	int largest = index;
	int left = (index * 2) + 1;
	int right = (index * 2) + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;
	if (largest != index)
	{
		swap(&array[index], &array[largest]);
		heapify(array, size, largest);
	}

}
/**
 * heap_sort - sort array using heap algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1 ; i >= 0; i--)
	{
		heapify(array, size, i);
	}

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0);

	}
}
