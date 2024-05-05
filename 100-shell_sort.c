#include "sort.h"

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < size / 3; gap = 3 * gap + 1)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i < size; i -= gap)
			{
				if (array[i + gap] > array[i])
					break;
				{
					temp = array[i + gap];
					array[i + gap] = array[i];
					array[i] = temp;
				}
			}

		}
		print_array(array, size);
	}
}
