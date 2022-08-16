#include "sort.h"
#include <stdio.h>
void Swap(int *arr, int a, int b);
void qsorter(int *arr, int l, int r, size_t size);
int partition(int *arr, int l, int r, size_t size);

/**
 * quick_sort - sorts an array using the quicksort algo
 * @size: length of the array
 * @array: the array to be sorted
 */
void quick_sort(int *array, size_t size)
{
	qsorter(array, 0, size - 1, size);
}
/**
 * qsorter - a recurssive function that ensures the
 * array is sorted
 * @arr: array to be sorted
 * @l: first index of the array
 * @size: length of the array
 * @r: last index of the array
 */
void qsorter(int *arr, int l, int r, size_t size)
{
	int pindex;

	if (l < r)
	{
		pindex = partition(arr, l, r, size);

		qsorter(arr, l, pindex - 1, size);
		qsorter(arr, pindex + 1, r, size);
	}
}
/**
 * partition - separates the array into two sides using the pivot
 * @arr: array to be partitioned
 * @l: the first index of the section of the array to be partitioned
 * @r: the last index of the section of the array to be partitioned
 * @size: length of the array
 * Return: the index of the pivot after it is properly positioned
 */
int partition(int *arr, int l, int r, size_t size)
{
	int pivot = arr[r];
	int pindex = l;
	int i;

	for (i = l; i < r; i++)
	{
		if (arr[i] <= pivot)
		{
			if (pindex < i)
			{
				Swap(arr, i, pindex);
				print_array(arr, size);
			}
			pindex++;
		}
	}

	if (arr[pindex] > pivot)
	{
		Swap(arr, pindex, r);
		print_array(arr, size);
	}
	return (pindex);
}
/**
 * Swap - simply swaps the element at two array indices
 * @a: index of element to be swapped
 * @b: index of element to be swapped
 * @arr: the array whose index is to be swapped
 */
void Swap(int *arr, int a, int b)
{
	int tmp = arr[a];

	arr[a] = arr[b];
	arr[b] = tmp;
}
