#include "sort.h"
/**
 * selection_sort - sorts an array of integer using the selection algo
 * @array: the array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j;
	size_t lowest, tmp;

	while (i < size)
	{
		lowest = i;
		j = i + 1;
		while (j < size)
		{
			if (array[lowest] > array[j])
				lowest = j;
			j++;
		}
		if (i != lowest)
		{
			tmp = array[i];
			array[i] = array[lowest];
			array[lowest] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
