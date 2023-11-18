#include "sort.h"

void counting_sort(int *array, size_t size)
{

	/*step1: Count occurrences*/
	int i, n, max;
	int *countArray;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	printf("max is: %d\n", max);
	countArray = malloc(sizeof(int) * (max + 1));
	/*step 2 create countArray*/
	for (i = 0; i < max + 1; i++)
	{
		countArray[i] = 0;
	}

	/* Step 3 store counting items*/

	for (n = 0; n < size ; n++)
	{
		countArray[array[n]]++;
	}

	/* Step 4 update count array*/
	for (i = 1; i < max + 1; i++)
		countArray[i] += countArray[i-1];
	int index;
	int new[size];
	for (i = 0; i < size; i++)
		new[i] = 0;
	for (i = size - 1; i >= 0; i--)
	{
		index = --countArray[array[i]];
		new[index] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = new[i];

}
int main()
{
    /*int arr[] = {4, 2, 2, 8, 3, 3, 1};*/
    int arr[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print_array(arr, size);

    printf("Sorted array: ");
    counting_sort(arr, size);

    print_array(arr, size);
    return 0;
}
