#include "sort.h"

/*
 * swap_int - swaps two integers
 * 
 * @a: first integer
 * @b: second integer
 * Return: void
*/

void swap_int(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * 
 * @array: array to be sorted
 * @size: size of array
 * Return: void 
*/

void selection_sort(int *array, size_t size)
{
    int *min;
    size_t i, j;

    if (!array || size < 2 || !size)
        return;

    for (i = 0; i < size - 1; i++)
    {
        min = array + i;

        for (j = i + 1; j < size; j++)
        {
            if (array[j] < *min)
                min = array + j;
        }
        swap_int(array + i, min);
        print_array(array, size);
    }
}