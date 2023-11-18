#include "sort.h"
/**
 * counting_sort - sorts an array using Counting sort algo
 * @array: array to be sorted
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int  n, max, index;
	int *countArray, *new;

	if (array == NULL || size < 2)
		return;
	/*step1: Find the max item*/
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	printf("max is: %d\n", max);
	countArray = malloc(sizeof(int) * (max + 1));
	if (countArray == NULL)
		return;
	/*step 2 create countArray*/
	for (n = 0; n < max + 1; n++)
		countArray[n] = 0;
	/* Step 3 store counting items*/

	for (i = 0; i < size ; i++)
		countArray[array[i]]++;

	/* Step 4 update count array*/
	for (n = 1; n < max + 1; n++)
		countArray[n] += countArray[n - 1];
	print_array(countArray, max + 1);

	new = malloc(sizeof(int) * size);
	if (new == NULL)
	{
		free(countArray);
		return;
	}
	/*find the index of element then sort the list*/
	for (i = 0 ; i < size ; i++)
	{
		index = countArray[array[i]] - 1;
		new[index] = array[i];
		countArray[array[i]]--;
	}
	/*Sort the original array*/
	for (i = 0; i < size; i++)
		array[i] = new[i];

	free(countArray);
	free(new);
}
