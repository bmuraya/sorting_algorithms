#include "sort.h"

/**
 * heapify - Heapify a subtree rooted at idx in the array
 * @array: The array to be heapified
 * @idx: The index of the parent node
 * @size: The size of the array
 */
void heapify(int *array, size_t idx, size_t size)
{
size_t max = idx;
size_t left = 2 * idx + 1;
size_t right = 2 * idx + 2;
int tmp;

if (left < size && array[left] > array[max])
max = left;
if (right < size && array[right] > array[max])
max = right;
if (max != idx)
{
tmp = array[idx];
array[idx] = array[max];
array[max] = tmp;
print_array(array, size);
heapify(array, max, size);
}
}

/**
 * heap_sort - Heap sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
int i, tmp;

/*Build the heap (rearrange the array)*/
for (i = size / 2 - 1; i >= 0; i--)
heapify(array, i, size);

/*One by one extract an element from the heap*/
for (i = size - 1; i >= 0; i--)
{
/*Move the current root to the end*/ 
tmp = array[0];
array[0] = array[i];
array[i] = tmp;

/*Call heapify on the reduced heap*/
heapify(array, 0, i);
}
}
