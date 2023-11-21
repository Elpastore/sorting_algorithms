#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void cocktail(int *array, int size)
{
	int start = 0;
	int end = size - 1;
	int i;
	int swaped = 1 ; 
	while (swaped)
	{
		swaped = 0;
		for (i = start; i < end; i++)
		{
			if (array[i] > array[i + 1])
			{	
				swap(&array[i], &array[i + 1]);
				swaped = 1;
			}
		}
		if (swaped == 0)
			break;
	
		end = end - 1;
		swaped = 0;
		for (i = end - 1; i >= start; i--)
		{
			if(array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
				swaped = 1;
			}

		}
		start = start + 1;
	}
}
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    printArray(array, n);

    cocktail(array, n);

    printf("Sorted array: ");
    printArray(array, n);

    return 0;
}
